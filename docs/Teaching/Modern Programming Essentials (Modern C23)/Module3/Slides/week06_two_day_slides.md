---
title: "CS 1380 — Week 6"
sub_title: "Function Definition and Calling"
author: "Modern Programming Essentials"
---

# Week 6

## Functions, Scope, Modularity, and Git

This week:

- Defining and calling functions
- Understanding execution flow
- Function prototypes
- Scope and variable lifetime
- Designing small, reusable functions
- Splitting programs into `.h` and `.c` files
- Basic Git workflow

---

# Day 1

## Functions and Scope

Today:

1. Why functions?
2. Defining and calling functions
3. Parameters and return values
4. Execution flow
5. Function prototypes
6. Scope and lifetime

---

# Why Functions?

So far, most of our programs have lived almost entirely inside `main`.

That works...

...until it doesn't.

```c
int main(void) {
    // read input
    // validate input
    // calculate stuff
    // print stuff
    // more calculations
    // more printing
    // ...
}
```

Functions let us break a program into **smaller named pieces**.

---

# A Function Is a Named Operation

We've already been using functions:

```c
printf("Hello\n");
fgets(buffer, sizeof buffer, stdin);
strcmp(a, b);
```

Someone else defined these.

We call them.

Now we're going to define our own.

---

# Function Definition

```c
int add(int a, int b) {
    return a + b;
}
```

There are four important pieces:

```text
 int     add     (int a, int b)    { ... }
  ^       ^            ^              ^
return   name      parameters        body
 type
```

---

# Return Type

```c
int add(int a, int b) {
    return a + b;
}
```

`int` says:

> Calling this function produces an `int`.

So:

```c
int sum = add(5, 3);
```

is conceptually similar to:

```c
int sum = 8;
```

The function call is an **expression that produces a value**.

---

# Parameters

```c
int add(int a, int b) {
    return a + b;
}
```

`a` and `b` are **parameters**.

When we call:

```c
add(5, 3);
```

`5` and `3` are **arguments**.

Inside this call:

```text
a = 5
b = 3
```

---

# Calling a Function

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int sum = add(5, 3);

    printf("Sum: %d\n", sum);

    return 0;
}
```

What happens when we reach `add(5, 3)`?

---

# Execution Flow

```c
int add(int a, int b) {
    return a + b;
}

int main(void) {
    int sum = add(5, 3);
    printf("%d\n", sum);
}
```

Execution does **not** simply continue downward.

```text
main()
  |
  | call add(5, 3)
  v
add()
  |
  | return 8
  v
main()
```

The caller pauses while the called function runs.

---

# Another Example

```c
void greet(void) {
    printf("Hello from greet()!\n");
}

int multiply(int x, int y) {
    return x * y;
}

int main(void) {
    printf("Starting main\n");

    greet();

    int result = multiply(4, 5);

    printf("Result: %d\n", result);
    printf("Ending main\n");

    return 0;
}
```

What order does this print in?

---

# Trace It

```text
main begins

    printf("Starting main")

    greet()
        printf("Hello from greet()!")
        return

    multiply(4, 5)
        return 20

    result = 20

    printf("Result: 20")
    printf("Ending main")

main returns
```

This nested sequence of active function calls is the beginning of what we mean by the **call stack**.

---

# `void` Functions

Not every function needs to produce a value.

```c
void print_line(int n) {
    for (int i = 0; i < n; i++) {
        putchar('-');
    }

    putchar('\n');
}
```

`void` means:

> This function does not return a value.

We call it for its **effect**.

```c
print_line(20);
```

---

# No Parameters?

In C:

```c
void greet(void) {
    printf("Hello!\n");
}
```

Use `void` when the function accepts no parameters.

```c
greet();
```

---

# Parameters Are Local Variables

Consider:

```c
int square(int x) {
    return x * x;
}

int main(void) {
    int n = 5;
    int result = square(n);
}
```

`square` receives its own `x`.

For ordinary values like `int`, C passes the value into the function.

Changing `x` does not change `n`.

---

# Pass By Value

This does **not** swap the caller's variables:

```c
void swap_wrong(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
```

```c
int x = 10;
int y = 20;

swap_wrong(x, y);
```

Afterward:

```text
x == 10
y == 20
```

The function changed its own copies.

We'll solve this with pointers later.

---

# A Compiler Problem

What if we write this?

```c
int main(void) {
    int result = add(10, 20);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

When the compiler reaches `add(10, 20)`, it hasn't seen `add` yet.

How does it know:

- Does `add` exist?
- What does it return?
- What parameters does it expect?

---

# Function Prototypes

We can declare the function before defining it.

```c
int add(int a, int b);

int main(void) {
    int result = add(10, 20);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

The first line is a **function prototype**.

---

# Declaration vs Definition

Declaration:

```c
int add(int a, int b);
```

> A function with this signature exists.

Definition:

```c
int add(int a, int b) {
    return a + b;
}
```

> Here is what the function actually does.

Notice the prototype ends with `;`.

---

# Parameter Names Are Optional

These are equivalent prototypes:

```c
int add(int a, int b);
```

```c
int add(int, int);
```

The compiler needs the **types**.

Names are still useful documentation.

---

# Scope

Where does a variable exist?

```c
void demo(void) {
    int local = 10;

    printf("%d\n", local);
}
```

`local` exists only inside `demo`.

Trying to use it elsewhere:

```c
int main(void) {
    printf("%d\n", local);
}
```

doesn't work.

---

# Local Scope

```c
void first(void) {
    int x = 10;
}

void second(void) {
    int x = 20;
}
```

These are two completely different variables.

The name `x` only has meaning within its scope.

---

# Block Scope

Scopes can exist inside functions too.

```c
void demo(void) {
    int outer = 10;

    {
        int inner = 20;

        printf("%d\n", outer); // okay
        printf("%d\n", inner); // okay
    }

    printf("%d\n", outer); // okay
    // printf("%d\n", inner); // not okay
}
```

Inner scopes can see outward.

Outer scopes cannot see inward.

---

# You've Already Used Block Scope

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

`i` belongs to the `for` loop's scope.

After the loop:

```c
printf("%d\n", i);
```

`i` no longer exists.

---

# Global / File Scope

Variables can also be declared outside functions.

```c
int global = 100;

void demo(void) {
    printf("%d\n", global);
}

int main(void) {
    demo();
}
```

`global` is visible much more broadly.

That convenience comes with a cost.

---

# Globals Create Hidden Dependencies

```c
int bonus = 10;

int calculate_score(int score) {
    return score + bonus;
}
```

From this call alone:

```c
calculate_score(80);
```

Can you determine the result?

Not without knowing the hidden global state.

Compare:

```c
int calculate_score(int score, int bonus) {
    return score + bonus;
}
```

The dependency is explicit.

---

# Scope vs Lifetime

These are related, but not identical.

**Scope**

> Where can I refer to this variable?

**Lifetime**

> How long does this variable exist?

Typical local variable:

```c
void demo(void) {
    int x = 10;
}
```

`x` becomes alive when execution reaches its declaration and its lifetime ends when execution leaves its block.

---

# `static` Local Variables

C gives us an interesting exception:

```c
void counter(void) {
    static int count = 0;

    count++;

    printf("Called %d time(s)\n", count);
}
```

Calling:

```c
counter();
counter();
counter();
```

prints:

```text
Called 1 time(s)
Called 2 time(s)
Called 3 time(s)
```

---

# `static`: Scope vs Lifetime

```c
static int count = 0;
```

`count` is still **local to the function**.

But its lifetime lasts for the entire program.

So:

```text
scope    → local
lifetime → entire program
```

This distinction becomes increasingly important as our programs get larger.

---

# Quick Function Exercise

Write:

```c
bool is_even(int n);
```

It should return:

```text
true   if n is even
false  otherwise
```

Then use it:

```c
if (is_even(42)) {
    printf("Even!\n");
}
```

What should the implementation look like?

---

# One Possible Solution

```c
#include <stdbool.h>

bool is_even(int n) {
    return n % 2 == 0;
}
```

Notice how little the caller needs to know:

```c
if (is_even(number)) {
    ...
}
```

The name communicates the intent.

---

# Day 1 Review

A function has:

```text
return type
name
parameters
body
```

Calling a function transfers execution to it and then returns to the caller.

Prototypes declare functions before use.

Variables have **scope** and **lifetime**.

Prefer explicit inputs and local state where possible.

---

# Day 2

## Function Design, Modularity, and Git

Today:

1. Designing useful functions
2. Function composition
3. Testing functions
4. Headers and source files
5. Compiling multiple files
6. Git fundamentals

---

# One Function, One Job

Compare:

```c
void process_all(void) {
    // read file
    // parse input
    // calculate results
    // print report
}
```

with:

```c
int read_scores(...);
int average(...);
void print_report(...);
```

The second design separates responsibilities.

---

# Why Split Things Up?

Small focused functions are generally easier to:

- understand
- test
- reuse
- debug
- replace

If something is wrong with the average:

```c
average(scores, count);
```

we know where to look.

---

# Function Names Are Interfaces

Consider:

```c
int f(int *x, int n);
```

versus:

```c
int find_maximum(int values[], int count);
```

A good name communicates intent before you even read the implementation.

---

# Naming Conventions

Useful patterns:

```c
calculate_average(...)
print_student_info(...)
find_maximum(...)
```

For boolean questions:

```c
is_even(...)
is_valid_email(...)
has_permission(...)
can_move(...)
```

In C, `lowercase_with_underscores` is a common convention.

---

# Function Composition

Functions can build on other functions.

```c
int multiply(int a, int b) {
    return a * b;
}

int area(int length, int width) {
    return multiply(length, width);
}

int volume(int length, int width, int height) {
    return multiply(area(length, width), height);
}
```

Complex behavior emerges from smaller building blocks.

---

# Pure Functions

Consider:

```c
int square(int x) {
    return x * x;
}
```

Given the same input:

```c
square(5);
```

we always get:

```text
25
```

No file state.

No global variable.

No hidden dependency.

This is a **pure function**.

---

# Pure Functions Are Easy to Test

```c
assert(square(2) == 4);
assert(square(5) == 25);
assert(square(-3) == 9);
```

Because the result depends only on the input, we can test it in isolation.

---

# Testing with `assert`

C provides:

```c
#include <assert.h>
```

Then:

```c
int square(int x) {
    return x * x;
}

int main(void) {
    assert(square(2) == 4);
    assert(square(5) == 25);

    printf("All tests passed.\n");
}
```

If an assertion is false, the program stops.

---

# Test the Weird Stuff

Don't only test:

```c
divide(10, 2);
```

Think about:

```text
zero
negative values
empty input
boundary values
division by zero
```

Bugs LOVE boundaries.

---

# Functions Let Us Build Modules

Eventually this:

```c
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
```

doesn't necessarily belong in `main.c`.

We can create a reusable module.

---

# Header Files

`math_utils.h`

```c
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int subtract(int a, int b);
double divide(double a, double b);

#endif
```

The header exposes the module's **interface**.

It tells other files what operations exist.

---

# Source Files

`math_utils.c`

```c
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

double divide(double a, double b) {
    return b != 0.0 ? a / b : 0.0;
}
```

The source file contains the **implementation**.

---

# Using Our Module

`main.c`

```c
#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int a = 12;
    int b = 4;

    printf("sum=%d\n", add(a, b));
    printf("diff=%d\n", subtract(a, b));
    printf("quot=%.2f\n", divide(a, b));

    return 0;
}
```

---

# Compiling Multiple Source Files

Now we have:

```text
main.c
math_utils.c
math_utils.h
```

Compile the `.c` files:

```bash
gcc -Wall -Wextra -std=c23 \
    -o demo main.c math_utils.c
```

Then:

```bash
./demo
```

We do **not** separately compile the header in this command.

---

# Interface vs Implementation

Think of the header as:

> Here's what you can do.

```c
int add(int a, int b);
```

And the source file as:

> Here's how it works.

```c
int add(int a, int b) {
    return a + b;
}
```

Users of the module shouldn't need to know its internal details.

---

# A Few Function Anti-Patterns

Too many responsibilities:

```c
void do_everything(...);
```

Vague names:

```c
void process(int x);
```

Huge parameter lists:

```c
void thing(int a, int b, int c,
           int d, int e, int f, int g);
```

Hidden global dependencies:

```c
int secret;

int compute(int x) {
    return x + secret;
}
```

---

# Function Practice

Let's build a small calculator module.

`calculator.h`

```c
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
```

We'll implement each operation in:

```text
calculator.c
```

and test them from:

```text
main.c
```

---

# Version Control

While we're building this, we want to answer:

> What changed?

> When did it change?

> Why did it change?

> Can I get the old version back?

That's what **version control** gives us.

For this course, we're using Git.

---

# Git Stores Project History

Git records snapshots called **commits**.

Imagine:

```text
[initial calculator]
        |
        v
[add addition]
        |
        v
[add subtraction]
        |
        v
[fix division by zero]
```

Each commit represents a meaningful state of the project.

---

# Create a Repository

Inside the project directory:

```bash
git init
```

This creates a hidden directory:

```text
.git/
```

That directory stores the repository's history and metadata.

Your normal files remain normal files.

---

# Ask Git What's Happening

```bash
git status
```

You might see:

```text
Untracked files:
    main.c
    calculator.c
    calculator.h
```

Git knows the files exist.

It is not yet tracking them in a commit.

---

# Three Useful Areas

A basic mental model:

```text
Working Directory
       |
       | git add
       v
Staging Area
       |
       | git commit
       v
Repository History
```

You edit files.

You choose what goes into the next snapshot.

Then you create the snapshot.

---

# Stage Changes

One file:

```bash
git add calculator.c
```

Several files:

```bash
git add main.c calculator.c calculator.h
```

Everything in the current directory:

```bash
git add .
```

Staging says:

> Include these changes in my next commit.

---

# Commit

```bash
git commit -m "Add calculator functions"
```

A commit records the staged snapshot.

Check the history:

```bash
git log --oneline
```

You now have a recoverable point in the project's history.

---

# The Basic Git Loop

Most of your daily Git usage begins here:

```text
edit
 ↓
git status
 ↓
git add
 ↓
git commit
 ↓
edit some more
 ↓
repeat
```

Git is much less mysterious when you think of it as a repeated loop.

---

# Commit Messages

Prefer messages describing the change:

```bash
git commit -m "Add divide function with zero check"
```

```bash
git commit -m "Fix off-by-one error in find_max loop"
```

Instead of:

```bash
git commit -m "stuff"
```

or the timeless classic:

```bash
git commit -m "asdf"
```

Future You deserves better.

---

# `.gitignore`

Some files don't belong in source control.

Example `.gitignore`:

```gitignore
*.o
*.exe
a.out
.DS_Store
```

Typically don't commit:

- compiler output
- temporary files
- editor swap files
- secrets

Do commit the `.gitignore` itself.

---

# Configure Your Identity

Git may ask who you are.

Configure once:

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

This information is attached to your commits.

---

# Functions + Git Exercise

Create:

```text
utils.h
utils.c
main.c
```

Implement:

```c
bool is_even(int n);
int find_max(int values[], int count);
void reverse_array(int values[], int count);
```

Test each from `main.c`.

Then:

```bash
git init
git add .
git commit -m "Add utility functions with tests"
```

---

# Week 6 Review

Functions:

```text
define → call → execute → return
```

Prototypes declare functions before use.

Scope controls where names are visible.

Lifetime controls how long objects exist.

Good functions have focused responsibilities and clear names.

Headers expose interfaces; source files provide implementations.

Git gives us a history of meaningful project snapshots.

---

# Coming Next

We'll keep expanding what functions can do:

- parameter behavior
- return values
- validation
- headers
- more complex function interactions

And soon, pointers will let functions work directly with caller-owned data.

Yes.

**The pointers are coming.**
