---
title: "CS 1380 — Week 8: Pointers"
sub_title: "Addresses, dereferencing, pointer arithmetic, and arrays"
author: "CS 1380 · Modern Programming Essentials"
options:
  end_slide_shorthand: true
---

# Week 8: Pointers

## Memory addresses • `&` • `*` • Arrays

Two meetings · 75 minutes each · C23

<!-- speaker_note: The original lecture has three 50-minute sessions. This version combines them into two 75-minute meetings. Pointer concepts come first; pointer arithmetic, arrays, and Git follow. -->

---

# This Week

**Day 1 — Pointer Fundamentals**

- Variables and memory addresses
- Declaring pointers; address-of `&` and dereference `*`
- Modifying values indirectly
- `NULL`, lifetime, and safe use

**Day 2 — Pointer Arithmetic and Arrays**

- Moving by elements, not bytes
- Array indexing and pointer expressions
- Traversal and bounds
- Git branches, merges, and conflicts

> Midterm 1 covers Weeks 1–7; pointers are **not** included.

---

# Day 1

## A variable has a value **and** an address

**Goal:** Explain and use pointers safely.

<!-- speaker_note: 0–5 min. Ask students what they think a variable actually represents in memory. -->

---

# A Variable Lives Somewhere

```c
int health = 100;

printf("value: %d\n", health);
printf("address: %p\n", (void *)&health);
```

- `health` evaluates to the stored integer.
- `&health` produces the address of the variable.
- `%p` prints an address; cast to `(void *)` for `printf`.

<!-- speaker_note: 5–15 min. Run the example twice and discuss why addresses might differ between runs. Avoid claiming specific addresses or sizes. -->

---

# A Pointer Stores an Address

```c
int health = 100;
int *target = &health;
```

```text
   health                   target
┌───────────────┐         ┌───────────────┐
│ value: 100    │◄────────│ &health       │
└───────────────┘         └───────────────┘
```

- `int *target` declares a pointer to `int`.
- `&health` obtains an address compatible with `int *`.
- `target` holds that address, **not** the integer `100`.

<!-- speaker_note: Distinguish the address stored inside target from the separate address of the pointer variable itself, &target. -->

---

# Three Expressions, Three Meanings

| Expression | Meaning |
|---|---|
| `health` | Integer value |
| `&health` | Address of `health` |
| `target` | Address stored in the pointer |
| `*target` | Integer at that address |

```c
int health = 100;
int *target = &health;

printf("%d %d\n", health, *target);
```

<!-- speaker_note: Have students predict output before running. The two integers are equal, but the expressions work differently. -->

---

# Dereferencing: Read and Write

```c
int score = 10;
int *p = &score;

printf("%d\n", *p); // 10

*p = 25;
printf("%d\n", score); // 25
```

**`*p` accesses the object to which `p` points.**

<!-- speaker_note: Show that modifying *p changes score itself. There is no copied second integer here. -->

---

# The `*` Symbol Has Two Jobs

```c
int value = 42;
int *p = &value; // declaration: p is a pointer
int copy = *p;   // expression: read pointed-to int
```

- In a **declaration**, `*` is part of a pointer declarator.
- In an **expression**, unary `*` dereferences an address.

```c
int *a, b; // a is a pointer; b is an int
```

> Read declarations carefully.

<!-- speaker_note: This is a common syntax trap. Optionally demonstrate one declaration per line as a readability convention. -->

---

# Pointers Can Be Redirected

```c
int a = 10;
int b = 20;
int *p = &a;

*p = 11;  // modifies a
p = &b;   // changes the address stored in p
*p = 21;  // modifies b
```

**Question:** What are `a`, `b`, and `*p` at the end?

<!-- speaker_note: Answer: a=11, b=21, *p=21. Distinguish changing the pointer from changing the pointee. -->

---

# Why Pass a Pointer to a Function?

```c
void set_zero(int *number) {
    *number = 0;
}

int main(void) {
    int x = 42;
    set_zero(&x);
    printf("%d\n", x); // 0
}
```

- C passes the **pointer value** by value.
- That value identifies an object the function can modify.

<!-- speaker_note: Relate to the previous week's pointer parameters. The pointer itself is copied into number; the object it points at is shared. -->

---

# An Uninitialized Pointer Is Not Safe

```c
int *bad;           // indeterminate value
int *empty = NULL;  // intentionally points nowhere

int x = 5;
int *good = &x;     // points at a live int
```

Never dereference an uninitialized pointer.

> Initialize pointers to a valid object or `NULL`.

<!-- speaker_note: Do not demonstrate dereferencing bad. Explain that an uninitialized local pointer has an indeterminate value and reading it can itself be undefined behavior. -->

---

# `NULL` Is Not a Valid Object

```c
void print_number(const int *p) {
    if (p == NULL) {
        puts("No number supplied");
        return;
    }
    printf("%d\n", *p);
}
```

- `NULL` means the pointer does not designate an object.
- Dereferencing a null pointer is undefined behavior.
- A non-null pointer is **not automatically valid**.

<!-- speaker_note: A pointer can be non-null and still be dangling or otherwise invalid. NULL checks are useful for nullable inputs, not a universal memory safety test. -->

---

# Lifetime Matters

```c
int *bad_address(void) {
    int local = 42;
    return &local; // invalid after function returns
}
```

A pointer is only useful while its pointed-to object is still alive.

- Local automatic objects generally end at scope exit.
- Do not keep pointers to objects whose lifetime has ended.
- We will revisit this with dynamic memory next week.

<!-- speaker_note: This example is intentionally incorrect. Do not call the function and dereference the result. -->

---

# Pointer Mistakes to Recognize

| Mistake | Why it is dangerous |
|---|---|
| Uninitialized pointer | No known valid target |
| `*NULL` | Undefined behavior |
| Dangling pointer | Target's lifetime ended |
| Wrong pointed-to type | May violate access/alignment rules |
| Out-of-bounds pointer | May point outside an array |

<!-- speaker_note: Mention that crashes are only one possible symptom of undefined behavior. A program appearing to work does not make it correct. -->

---

# Lab 1 — Observe and Modify

**15 minutes**

1. Declare `int x = 10;` and `int *p = &x;`.
2. Print `x`, `&x`, `p`, and `*p` with appropriate formats.
3. Assign `*p = 99;` and print `x` again.
4. Assign `p = NULL;` and safely skip dereferencing.
5. **Bonus:** Print `&p`. Is it equal to `p`?

<!-- speaker_note: Allow 15 minutes. Ask students to explain which expressions represent addresses and which represent integer values. -->

---

# Day 1 Checkpoint

```c
int a = 3, b = 7;
int *p = &a;
*p += 2;
p = &b;
```

- What is `a`?
- What is `b`?
- What is `*p`?
- What does `&p` refer to?

<!-- speaker_note: Answers: a=5, b=7, *p=7. &p is the address of the pointer variable p. Use remaining time for questions. -->

---

# Day 2

## Pointer Arithmetic and Arrays

**Goal:** Relate pointer movement to array indexing, then practice Git workflows.

<!-- speaker_note: 0–5 min. Quick recap of & and *. -->

---

# An Array Is a Sequence of Elements

```c
int values[] = {10, 20, 30, 40, 50};
int *p = values;
```

```text
 index       0     1     2     3     4
          ┌─────┬─────┬─────┬─────┬─────┐
 values   │ 10  │ 20  │ 30  │ 40  │ 50  │
          └─────┴─────┴─────┴─────┴─────┘
            ▲
            p
```

In this expression, `values` converts to a pointer to its first element.

<!-- speaker_note: Explain that the array itself is not a pointer variable. The conversion is often called array-to-pointer decay. -->

---

# `p + 1` Means the Next Element

```c
int values[] = {10, 20, 30, 40, 50};
int *p = values;

printf("%d\n", *p);       // 10
p++;
printf("%d\n", *p);       // 20
p += 2;
printf("%d\n", *p);       // 40
```

**Pointer arithmetic scales by the pointed-to type.**

<!-- speaker_note: Walk through each pointer position visually. p++ is not necessarily an increment of one byte. -->

---

# Scaling Depends on Type

```c
int    numbers[3] = {0};
double decimals[3] = {0};
char   letters[3] = {0};

int    *ip = numbers;
double *dp = decimals;
char   *cp = letters;
```

| Expression | Advances by |
|---|---|
| `ip + 1` | `sizeof(int)` bytes |
| `dp + 1` | `sizeof(double)` bytes |
| `cp + 1` | `sizeof(char)` bytes (1 byte) |

<!-- speaker_note: Avoid hardcoding platform-specific sizeof(int) or sizeof(double). Print sizeof to see the actual implementation sizes. -->

---

# Indexing Is Pointer Arithmetic

```c
int values[] = {10, 20, 30, 40, 50};
int *p = values;

printf("%d\n", values[2]);   // 30
printf("%d\n", *(values + 2)); // 30
printf("%d\n", *(p + 2));      // 30
printf("%d\n", p[2]);         // 30
```

**`a[i]` means `*(a + i)`** in C.

<!-- speaker_note: Show the parentheses: *(p + 2) differs from *p + 2. -->

---

# Arrays Are Not Pointer Variables

```c
int values[] = {10, 20, 30};
int *p = values;

p = &values[1]; // valid: reassign pointer
// values = p;  // invalid: array not assignable
```

- An array owns its elements and has an array type.
- A pointer variable stores an address and can be reassigned.
- `sizeof(values)` is the whole array size here.
- `sizeof(p)` is the size of the pointer itself.

<!-- speaker_note: Correct a common shortcut: an array is not a 'constant pointer.' Also mention array-to-pointer conversion has exceptions, including sizeof and unary &. -->

---

# Two Ways to Traverse

```c
int values[] = {1, 2, 3, 4, 5};
int n = 5;

for (int i = 0; i < n; ++i) {
    printf("%d ", values[i]);
}

for (int *p = values; p < values + n; ++p) {
    printf("%d ", *p);
}
```

Both are valid. Choose the clearer form.

<!-- speaker_note: Compare loop variables: one tracks an index, the other an element address. -->

---

# The One-Past-the-End Rule

```c
int a[] = {10, 20, 30};
int *end = a + 3; // legal to form

// printf("%d", *end); // NOT legal to dereference
```

- Valid elements: `a[0]`, `a[1]`, `a[2]`.
- A pointer **one past** the final element may be formed.
- Do not dereference it or advance farther beyond the array.

<!-- speaker_note: Bounds are not checked automatically by C. Pointer arithmetic is only defined within an array object and its one-past position. -->

---

# Pointer Difference

```c
#include <stddef.h>
#include <stdio.h>

int a[] = {10, 20, 30, 40};
int *first = &a[0];
int *last = &a[3];

ptrdiff_t distance = last - first;
printf("%td\n", distance); // 3 elements
```

Subtraction gives the distance in **elements**, not bytes, for pointers into the same array.

<!-- speaker_note: Introduce ptrdiff_t briefly; this is the appropriate signed type for pointer differences. -->

---

# Passing Arrays to Functions

```c
void print_array(const int *a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}
```

- The function receives a pointer to the first element.
- It also needs the element count.
- `const int *` prevents modifying elements through `a`.

<!-- speaker_note: A pointer parameter does not carry an array's length. Mention that the caller must provide a correct size. -->

---

# Lab 2 — Find the Maximum

**15 minutes**

Implement:

```c
int find_max(const int *a, int n);
```

Requirements:

1. Traverse using pointer arithmetic.
2. Return the largest value in `{5, 2, 8, 1, 9}`.
3. Document the precondition: `a != NULL` and `n > 0`.
4. **Bonus:** Decide how your API should report invalid input.

<!-- speaker_note: Expected maximum: 9. Do not read a[0] for n<=0. Ask students whether a sentinel return value would be unambiguous. -->

---

# One Possible Implementation

```c
// Requires a != NULL and n > 0.
int find_max(const int *a, int n) {
    int max = *a;

    for (const int *p = a + 1; p < a + n; ++p) {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}
```

**Question:** What happens if the caller violates the precondition?

<!-- speaker_note: Review after lab. Discuss that dereferencing null or reading a zero-length array is undefined behavior; document or validate API contracts. -->

---

# Git: Branches Let Work Diverge

```bash
git switch -c pointer-lab
# edit files
git add .
git commit -m "Implement pointer traversal"

git switch main
git merge pointer-lab
```

**Branch → edit → commit → merge**

<!-- speaker_note: Roughly 15 minutes for Git demo. Check current branch with git branch --show-current. Use a throwaway demo repository. -->

---

# Merge Conflicts

When both branches change the same lines, Git may need help.

```text
<<<<<<< HEAD
printf("original\n");
=======
printf("new version\n");
>>>>>>> pointer-lab
```

1. Edit the file to the desired final code.
2. Remove conflict markers.
3. Test the result.
4. `git add file.c` and `git commit`.

<!-- speaker_note: Show a small conflict live if time permits. Conflict markers are not valid C syntax. -->

---

# Inspect Your History

```bash
git branch --show-current
git log --oneline
git log --oneline --graph --all
git log --stat
git log --grep="pointer"
```

Use history to understand what changed and when.

<!-- speaker_note: Show --graph --all to make branch relationships visible, even when the default log would hide other branch tips. -->

---

# Lab 3 — Git + Pointers

**10 minutes**

1. Create a `pointer-lab` branch.
2. Add your `find_max` implementation and a small test.
3. Commit your work.
4. Switch to `main` and merge.
5. Inspect the history with `git log --oneline --graph --all`.

<!-- speaker_note: Students may work with their existing class repository. Do not overwrite uncommitted work. -->

---

# Preview: Walking a C String

```c
int string_length(const char *str) {
    int count = 0;
    while (*str != '\0') {
        ++count;
        ++str;
    }
    return count;
}
```

A traditional C string is a character array terminated by `\0`.

<!-- speaker_note: Preview only. This implementation requires a valid pointer to a null-terminated string. String handling is covered later. -->

---

# Week 8 Recap

- Pointers store addresses; `&` takes an address, `*` dereferences.
- A pointer must designate a live, valid object before dereferencing.
- Pointer arithmetic advances by **elements**.
- `a[i]` is equivalent to `*(a + i)`.
- Arrays and pointer variables are different types of objects.
- Git branches support isolated work and deliberate merging.

**Next:** Dynamic allocation, `malloc`, `free`, and memory leaks.

<!-- speaker_note: Close with questions. Midterm 1 covers Weeks 1–7, not pointers. Original material references HW15/HW16; confirm the current combined homework number before announcing an assignment. -->
