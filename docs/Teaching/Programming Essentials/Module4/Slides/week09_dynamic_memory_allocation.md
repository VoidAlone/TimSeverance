---
title: "CS 1380 — Week 9: Dynamic Memory Allocation"
author: "CS 1380 · Modern Programming Essentials"
theme:
  name: dark
options:
  end_slide_shorthand: true
---

# Week 9: Dynamic Memory Allocation

## Stack, Heap, `malloc`, and `free`

Two lectures · C23

---

# This Week

**Day 1 — Stack, Heap, and Memory Leaks**

- Where variables live and how long they last
- Why allocate memory dynamically?
- Ownership and memory leaks

**Day 2 — `malloc`, `free`, and Common Mistakes**

- Allocate one value or an array
- Check failures and clean up
- Diagnose use-after-free, double-free, and leaks

---

# Day 1

## Stack, Heap, and Memory Leaks

**Question:** What happens to a variable when its function returns?

---

# Automatic Storage: Local Variables

```c
void visit_dungeon(void) {
    int health = 100;
    int loot[5] = {0};

    // Both exist during this function call.
}
```

- Local variables like these have **automatic storage duration**.
- Their lifetime ends when the function returns.
- You do not call `free` on them.

---

# The Heap: Memory You Request

```c
#include <stdlib.h>

void visit_dungeon(void) {
    int *health = malloc(sizeof *health);

    if (health == NULL)
        return;

    *health = 100;
    free(health);
}
```

The pointer is local; the **allocated object** lives until it is freed.

---

# Stack vs. Heap

| Automatic local storage | Dynamic allocated storage |
|:--|:--|
| Lifetime tied to scope/function execution | Lifetime controlled by `free` |
| No explicit allocation call | Requested with `malloc` |
| Typically implemented on the stack | Typically implemented on the heap |
| Convenient for small, temporary data | Useful for flexible size and lifetime |

**Important:** Stack and heap are useful implementation models; C formally specifies *storage durations*.

---

# Why Allocate Dynamically?

Imagine loading an unknown number of monsters from a file.

```c
int monster_count = 0;
// Read monster_count from input...

int *health = malloc(
    (size_t)monster_count * sizeof *health
);
```

Dynamic allocation is useful when:

- The amount of data is known only at runtime.
- Data must survive the function that created it.
- Data is too large to comfortably keep as a local array.

---

# A Pointer Is Not the Allocation

```c
int *p = malloc(sizeof *p);
```

Think of two separate things:

- `p` is a local pointer variable.
- `malloc` returns the address of a separately allocated block.

When `p` goes out of scope, **the allocated block is not automatically freed**.

---

# The Memory Lifecycle

**Allocate → Check → Use → Free**

```c
int *gold = malloc(sizeof *gold);
if (gold == NULL)
    return;

*gold = 50;
printf("Gold: %d\n", *gold);

free(gold);
gold = NULL;
```

Setting the pointer to `NULL` is optional, but helps prevent accidental reuse of **that pointer**.

---

# What Is a Memory Leak?

```c
void enter_room(void) {
    int *treasure = malloc(sizeof *treasure);
    if (treasure == NULL)
        return;

    *treasure = 100;
    // Forgot free(treasure)!
}
```

The function returns. The pointer disappears, but the allocated block remains allocated.

Repeat this enough times and memory usage can grow.

---

# Another Leak: Losing the Address

```c
int *p = malloc(sizeof *p);
if (p == NULL) return;

p = malloc(sizeof *p);  // Lost first address!
if (p == NULL) return;

free(p);  // Frees only the second block.
```

**Discussion:** Why can't `free(p)` recover the first block?

---

# Ownership: Who Frees It?

```c
int *create_health(void) {
    int *health = malloc(sizeof *health);
    if (health != NULL)
        *health = 100;
    return health;
}
```

The function returns the pointer, so the **caller** must eventually free the allocation.

```c
int *hp = create_health();
if (hp != NULL) {
    printf("%d\n", *hp);
    free(hp);
}
```

---

# Dangerous: Returning a Local Address

```c
int *bad_health(void) {
    int health = 100;
    return &health; // Invalid after return!
}
```

`health` stops existing when the function returns.

**Contrast:** Returning a pointer to a successful `malloc` allocation is valid, provided someone eventually frees it.

---

# Live Demo: Where Does It Live?

1. Create a local array of five integers.
2. Allocate five integers with `malloc`.
3. Print the addresses with `%p` (cast to `void *`).
4. Free the dynamic array.

```c
printf("local: %p\n", (void *)&local[0]);
printf("heap:  %p\n", (void *)&dynamic[0]);
```

**Discuss:** What do the addresses tell us? What *don't* they guarantee?

---

# Day 1 Wrap-up

- Local automatic objects stop existing when their lifetime ends.
- `malloc` creates storage that must be released explicitly.
- Losing the last usable pointer can leak an allocation.
- Decide **who owns** each allocation and who will free it.

**Next:** Let's allocate arrays and break some programs on purpose.

---

# Day 2

## `malloc`, `free`, and Common Mistakes

**Question:** What can go wrong when we manage memory ourselves?

---

# `malloc`: Allocate One Integer

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *hp = malloc(sizeof *hp);
    if (hp == NULL) {
        fprintf(stderr, "Allocation failed\n");
        return 1;
    }

    *hp = 100;
    printf("HP: %d\n", *hp);
    free(hp);
    return 0;
}
```

`malloc` returns uninitialized storage. **Write a value before reading it.**

---

# `sizeof`: Why Use It?

```c
int *scores = malloc(10 * sizeof *scores);
```

- We need space for **10 integers**, not 10 bytes.
- `sizeof *scores` tracks the pointed-to type.
- No explicit cast of `malloc`'s return value is needed in C.

**Ask:** What changes if `scores` becomes a `double *`?

---

# Allocate an Array at Runtime

```c
int count;
printf("How many monsters? ");
if (scanf("%d", &count) != 1 || count <= 0)
    return 1;

int *hp = malloc((size_t)count * sizeof *hp);
if (hp == NULL)
    return 1;

for (int i = 0; i < count; ++i)
    hp[i] = 100;

free(hp);
```

For very large counts, also check that the multiplication cannot overflow.

---

# Dynamic Arrays Still Use Indexing

```c
int *values = malloc(5 * sizeof *values);
if (values == NULL)
    return;

for (int i = 0; i < 5; ++i)
    values[i] = i * i;

for (int i = 0; i < 5; ++i)
    printf("%d ", values[i]);

free(values);
```

**Key idea:** `values[i]` works because pointer indexing and pointer arithmetic are related.

---

# `free`: End the Allocation's Lifetime

```c
int *p = malloc(sizeof *p);
if (p == NULL) return;

*p = 42;
free(p);
p = NULL;
```

- `free` releases a block allocated by the allocation functions.
- After `free`, pointers to that block must not be dereferenced.
- `free(NULL)` is safe.

---

# Bug 1: Use-After-Free

```c
int *p = malloc(sizeof *p);
if (p == NULL) return;

*p = 10;
free(p);

// printf("%d\n", *p); // UNDEFINED BEHAVIOR
```

The address might still look valid. The object no longer is.

**Discussion:** Why might this bug seem to work sometimes?

---

# Bug 2: Double Free

```c
int *p = malloc(sizeof *p);
if (p == NULL) return;

free(p);
// free(p); // UNDEFINED BEHAVIOR
```

Safer for a single local pointer:

```c
free(p);
p = NULL;
free(p); // Safe: free(NULL) does nothing.
```

**Caution:** Nulling one pointer does not fix other aliases to the same block.

---

# Bug 3: Freeing the Wrong Address

```c
int local = 42;
// free(&local); // INVALID

int *arr = malloc(5 * sizeof *arr);
if (arr == NULL) return;

// free(arr + 1); // INVALID
free(arr);       // Correct
```

Pass `free` the original allocated pointer (or `NULL`).

---

# Bug 4: Forgetting Error Paths

```c
int *a = malloc(10 * sizeof *a);
if (a == NULL) return 1;

int *b = malloc(20 * sizeof *b);
if (b == NULL) {
    free(a); // Don't leak a on failure!
    return 1;
}

// Use both allocations...
free(b);
free(a);
```

Every successful allocation needs a cleanup path.

---

# Spot the Bugs

```c
void bad(void) {
    int *a = malloc(sizeof *a);
    *a = 10;
    free(a);
    *a = 20;
    free(a);

    int *b = malloc(sizeof *b);
    if (b != NULL) *b = 1;
}
```

**Find:** Missing failure check, use-after-free, double-free, memory leak.

---

# Debugging Memory Problems

Compile with warnings and debug information:

```bash
cc -std=c23 -Wall -Wextra -g demo.c -o demo
```

Check for leaks with Valgrind (when available):

```bash
valgrind --leak-check=full ./demo
```

Or use AddressSanitizer for many invalid memory accesses:

```bash
cc -std=c23 -g -fsanitize=address demo.c -o demo
./demo
```

---

# Live Exercise: Monster HP Array

Write a program that:

1. Reads a positive monster count.
2. Allocates an integer HP array with `malloc`.
3. Sets each monster's HP to `100 + i * 10`.
4. Prints every monster's HP.
5. Frees the allocation.

**Bonus:** Deliberately remove `free`, then inspect the leak with Valgrind.

---

# Next Up

**Deferred to homework / Week 10:**

- `calloc` — allocate zero-initialized storage
- `realloc` — resize an existing allocation
- Linked lists — objects connected by pointers

**Remember:** Allocate → check → use → free.

Fall Break: October 15–18.
