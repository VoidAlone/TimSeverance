# Objects, Functions, and Just Enough Polymorphism

Object-oriented programming can make it feel natural to represent every variation in behavior as a different type. If a program has actions such as Up, Down, Select, and Quit, a traditional OO design might define an Action interface and create a separate class for every implementation:

```py
class Action:    
    def execute(self, game):        
        pass

class Up(Action):    
    def execute(self, game):        
        game.selected -= 1

class Down(Action):    
    def execute(self, game):        
        game.selected += 1
```

But if Up and Down contain no unique state and exist only to override one method, the objects themselves aren't buying us much. The abstraction we actually need is simply: “I have some behavior with a known signature, but I don't know which implementation will be used.” A function pointer already provides exactly that kind of polymorphism:

```c
typedef void (*ActionFn)(Game *);

void move_up(Game *game)
{
    game->selected--;
}

void move_down(Game *game)
{
    game->selected++;
}
```

Now ActionFn is effectively our one-method interface. Anything matching void(Game *) can be substituted for anything else matching that signature. If we need metadata, we can compose it with the function:

```c
typedef struct {
    const char *name;
    ActionFn execute;
} Action;

Action actions[] = {
    { "up",   move_up   },
    { "down", move_down },
};
```

Calling an action remains generic:
actions[i].execute(game);

The function does not have to “belong” to the struct. move_up() is independent behavior that happens to satisfy the contract required by Action. This is essentially Strategy or Command stripped down to its essential mechanism. The same option has always existed in languages with first-class functions, delegates, lambdas, or callables; interchangeable behavior does not inherently require polymorphic objects.

Objects become more meaningful when behavior is coupled to state that should be owned and hidden. Suppose a poison effect maintains damage, duration, and other internal bookkeeping. Exposing all of that as ordinary public data defeats information hiding:

```c
typedef struct {
    int damage;
    int turns_remaining;
    float modifier;
} PoisonAction;
```

If callers shouldn't know how a poison action represents or maintains those values, an opaque type gives us an object-like boundary:

```c
/* poison.h */

typedef struct PoisonAction PoisonAction;

PoisonAction *poison_new(int damage, int turns);
void poison_execute(PoisonAction *self, Game *game);
void poison_free(PoisonAction *self);

The actual representation exists only in the implementation:
/* poison.c */

struct PoisonAction {
    int damage;
    int turns_remaining;
    float modifier;
};

void poison_execute(PoisonAction *self, Game *game)
{
    damage_player(game, self->damage * self->modifier);
    self->turns_remaining--;
}
```

Now the rest of the program doesn't manipulate a bag of poison fields. It asks a thing that owns that information to perform operations on its behalf. This is much closer to the information-hiding and message-oriented motivation behind OO as initially conceived by Alan Kay.

It asks a thing that owns that information to perform operations on its behalf. Kay emphasized objects as independent components that communicate through messages, with their internal representation hidden from the rest of the system—not inheritance hierarchies as an end in themselves. 

In that sense, the justification for making PoisonAction an object is not simply that it has an execute() method. It is that PoisonAction owns knowledge and state that other parts of the program should not need to understand. They send it a request—effectively, “execute yourself”—and it decides how to fulfill that request using its private state. An UpAction containing nothing but an overridden method provides little of that benefit; a plain function can express the behavior directly

So the useful distinction isn't really “procedural versus object-oriented.” It's how much structure the problem requires:

```c
/* Behavior only */
typedef void (*ActionFn)(Game *);


/* Behavior + metadata */
typedef struct {
    const char *name;
    ActionFn execute;
} Action;


/* Behavior + private state */
typedef struct PoisonAction PoisonAction;
void poison_execute(PoisonAction *, Game *);


/* Several interchangeable behaviors */
typedef struct {
    void (*execute)(void *, Game *);
    void (*update)(void *, float dt);
    void (*destroy)(void *);
} ActionVTable;
```

C makes these layers unusually visible because it doesn't automatically bundle state, behavior, polymorphic dispatch, and information hiding into the single concept of a class. You can start with a function, add metadata when you need it, introduce opaque state when there is genuinely something worth encapsulating, and introduce a vtable only when multiple interchangeable operations justify one. Seen through Kay’s conception of OOP, an object earns its place when it represents a boundary around knowledge and behavior—not merely because two pieces of behavior need different implementations. In that sense, C lets you compose exactly as much “object” as the problem actually needs.
