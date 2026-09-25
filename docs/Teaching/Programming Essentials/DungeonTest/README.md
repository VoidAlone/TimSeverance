# C Config Parsing Progression

This project can be developed in small stages. Each stage introduces one new C
idea while keeping the config format simple:

```text
hp=12
attack=2
```

For this fixed format, `fscanf` is enough. The goal is not to build a perfect
config parser, but to see how data and behavior can gradually be organized.

## 1. Load Config Data Into Globals

Start with global variables so the file-reading code is the only new concept:

```c
int enemy_hp;
int enemy_attack;

int load_enemy_config(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    int read = fscanf(file, "hp=%d attack=%d", &enemy_hp, &enemy_attack);
    fclose(file);
    return read == 2;
}
```

This is easy to understand, but globals allow only one current enemy and can be
changed from anywhere in the program.

## 2. Return Data Through a Struct

Group related values into a struct and let the caller instantiate it:

```c
typedef struct {
    int hp;
    int attack;
} EnemyStats;

int load_enemy_config(const char *filename, EnemyStats *stats)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    int read = fscanf(file, "hp=%d attack=%d", &stats->hp, &stats->attack);
    fclose(file);
    return read == 2;
}
```

The caller can now create multiple independent values:

```c
EnemyStats goblin;
EnemyStats skeleton;

load_enemy_config("goblin.cfg", &goblin);
load_enemy_config("skeleton.cfg", &skeleton);
```

This is often all a small C program needs.

## 3. Create an Enemy Type

Next, put the struct definition in `enemy.h` and its functions in `enemy.c`.
Because callers can see the fields, this is sometimes called a **public** or
**transparent struct**.

```c
/* enemy.h */
typedef struct {
    int hp;
    int attack;
} Enemy;

int enemy_load(Enemy *enemy, const char *filename);
void enemy_print(const Enemy *enemy);
```

Callers can allocate an `Enemy` directly and access `enemy.hp`. This stage is a
good introduction to headers, source files, and separating an interface from
its implementation.

## 4. Hide the Struct With an Opaque Type

If the header only declares the struct while `enemy.c` defines it, the type is
called an **opaque struct** or **incomplete type**. This is the C technique that
makes the fields effectively private.

```c
/* enemy.h */
typedef struct Enemy Enemy;

Enemy *enemy_create(const char *filename);
void enemy_destroy(Enemy *enemy);
int enemy_get_hp(const Enemy *enemy);
int enemy_get_attack(const Enemy *enemy);
```

```c
/* enemy.c */
#include "enemy.h"

#include <stdio.h>
#include <stdlib.h>

struct Enemy {
    int hp;
    int attack;
};

Enemy *enemy_create(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    Enemy *enemy = malloc(sizeof *enemy);
    if (enemy == NULL) {
        fclose(file);
        return NULL;
    }

    if (fscanf(file, "hp=%d attack=%d", &enemy->hp, &enemy->attack) != 2) {
        free(enemy);
        enemy = NULL;
    }

    fclose(file);
    return enemy;
}

void enemy_destroy(Enemy *enemy)
{
    free(enemy);
}
```

Because callers do not know the size or fields of `struct Enemy`, they must use
`enemy_create`, `enemy_destroy`, and accessor functions. This resembles
encapsulation in object-oriented languages.

## 5. Add Function Pointers for Different Behavior

Function pointers are a separate idea from data hiding. They can give different
enemy types different implementations of the same operation, similar to a
virtual method:

```c
/* Inside enemy.c */
struct Enemy {
    int hp;
    int attack;
    void (*take_turn)(struct Enemy *self);
};

void enemy_take_turn(Enemy *enemy)
{
    enemy->take_turn(enemy);
}
```

The constructor can assign `take_turn` to `slime_take_turn`,
`goblin_take_turn`, or `skeleton_take_turn`. The public function stays the same:

```c
enemy_take_turn(enemy);
```

This style is sometimes described as **object-oriented C**: the struct stores
state, functions operate on that state, an opaque declaration provides
encapsulation, and function pointers provide dynamic dispatch.

## Suggested Classroom Order

1. Parse one file into global variables.
2. Replace the globals with an `EnemyStats` value.
3. Load several enemies into separate struct instances.
4. Move the public struct and declarations into `enemy.h`.
5. Make the struct opaque and add create/destroy/accessor functions.
6. Add a function pointer only when enemies need different behavior.

Each step solves a limitation encountered in the previous step, which gives the
extra structure a reason to exist rather than introducing it all at once.
