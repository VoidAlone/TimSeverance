---
title: "CS 1380: Modern Programming Essentials"
sub_title: "Week 4: Control Structures and Flow Control"
author: "Tim S."
---

# Week 4: Control Structures and Flow Control

Instructor: **Tim S.**

Textbook: Chapter 2 — Fundamentals (part 3)  
MIT Missing Semester: Data Wrangling

---

# Week 4 Overview

## Meeting 1 — Decisions and Logic

- Relational and logical operators
- `if`, `else if`, and `else`
- Nested conditionals
- `switch`
- Ternary operator

## Meeting 2 — Loops and Data Wrangling

- `while`, `do-while`, and `for`
- `break` and `continue`
- Common loop mistakes
- `grep`, `sed`, `awk`, and pipes
- Shell vs. C for processing data

---

# Learning Objectives

By the end of this week, you should be able to:

1. Write conditional statements with relational and logical operators
2. Choose between `if` / `else`, `switch`, and the ternary operator
3. Implement `while`, `do-while`, and `for` loops
4. Use `break` and `continue` to control loop execution
5. Process text data with basic shell wrangling tools

---

# Meeting 1: Decisions and Logic

## Agenda

1. Relational and logical operators
2. `if`, `else if`, and `else`
3. Nested conditionals and flattening
4. `switch`
5. Ternary expressions
6. Conditional practice

---

# Relational Operators

Relational operators compare two values.

```c
int a = 5;
int b = 10;

a == b;  // equal?            false
a != b;  // not equal?        true
a < b;   // less than?        true
a > b;   // greater than?     false
a <= b;  // less or equal?    true
a >= b;  // greater or equal? false
```

In C:

- `0` is logically **false**
- any non-zero value is logically **true**

---

# Comparison vs. Assignment

These are very different operations:

```c
x = 5;   // assign 5 to x
x == 5;  // compare x with 5
```

A classic bug:

```c
if (x = 5) {
    // ...
}
```

The assignment produces the value `5`, which is non-zero and therefore true.

Use `==` when you mean comparison.

---

# Logical Operators

```c
int x = 5;
int y = 10;
int z = 0;

x && y;  // AND: true
x && z;  // AND: false

x || z;  // OR: true

!x;      // NOT: false
!z;      // NOT: true
```

| Operator | Meaning |
| --- | --- |
| `&&` | logical AND |
| `||` | logical OR |
| `!` | logical NOT |

---

# Truth Tables

| A | B | `A && B` | `A || B` |
| --- | --- | -------- | -------- |
| 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 |
| 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 1 |

Logical NOT flips truth:

```text
!0 -> 1
!1 -> 0
```

---

# Short-Circuit Evaluation

C may stop evaluating a logical expression as soon as the result is known.

```c
a && f();
```

If `a` is false, `f()` is never called.

```c
a || f();
```

If `a` is true, `f()` is never called.

This is called **short-circuit evaluation**.

---

# Combining Comparisons

Suppose we want an age from 18 through 65:

```c
age >= 18 && age <= 65
```

And suppose the score must also be at least 60:

```c
age >= 18 && age <= 65 && score >= 60
```

When expressions become complicated, parentheses can make the intent clearer:

```c
(age >= 18 && age <= 65) && score >= 60
```

---

# Operator Precedence

For the logical operators:

```text
!
&&
||
```

Higher operators bind before lower ones.

But don't make your reader solve a precedence puzzle.

```c
if ((age >= 18 && age <= 65) || has_permission) {
    // ...
}
```

Use parentheses when they make the logic easier to read.

---

# `if` Statements

The simplest conditional:

```c
if (score >= 60) {
    printf("Passed\n");
}
```

The body runs only when the condition is true.

Course style: **use braces even for a single statement.**

---

# `if` / `else`

```c
if (score >= 60) {
    printf("Passed\n");
} else {
    printf("Not passed\n");
}
```

Exactly one branch executes.

---

# `else if`

```c
int score = 85;

if (score >= 90) {
    printf("Grade: A\n");
} else if (score >= 80) {
    printf("Grade: B\n");
} else if (score >= 70) {
    printf("Grade: C\n");
} else {
    printf("Grade: F\n");
}
```

Conditions are tested from top to bottom.

Once one succeeds, the remaining branches are skipped.

---

# Order Matters

Consider:

```c
if (score >= 70) {
    printf("C\n");
} else if (score >= 80) {
    printf("B\n");
} else if (score >= 90) {
    printf("A\n");
}
```

What happens when `score` is `95`?

The first condition is already true.

For ranges like grades, test from the most restrictive threshold downward.

---

# Nested Conditionals

A branch may contain another conditional:

```c
if (age >= 18) {
    if (income >= 30000) {
        printf("Eligible for loan\n");
    } else {
        printf("Income too low\n");
    }
} else {
    printf("Too young\n");
}
```

This can be useful when the second decision only makes sense after the first.

---

# Flattening Nested Conditionals

Sometimes nested conditions can be combined:

```c
if (age >= 18 && income >= 30000) {
    printf("Eligible for loan\n");
} else if (age >= 18) {
    printf("Income too low\n");
} else {
    printf("Too young\n");
}
```

Prefer the version that makes the decision easiest to understand.

Deep nesting gets difficult to trace quickly.

---

# Common Conditional Mistakes

Assignment instead of comparison:

```c
if (x = 5) { }   // BUG
if (x == 5) { }  // comparison
```

Exact floating-point comparison:

```c
if (f == 0.1) { }  // may fail
```

A tolerance is often safer:

```c
if (fabs(f - 0.1) < 1e-9) {
    // approximately equal
}
```

---

# Quick Practice

Write a condition that prints `"Valid"` only when:

- `age` is between 18 and 65, inclusive
- `score` is at least 60

```c
if (/* ??? */) {
    printf("Valid\n");
}
```

Then consider:

- Which operators did you need?
- Where would parentheses improve readability?

---

# `switch`

`switch` is useful when one expression is compared against several discrete values.

```c
int day = 3;

switch (day) {
case 1:
    printf("Monday\n");
    break;
case 2:
    printf("Tuesday\n");
    break;
case 3:
    printf("Wednesday\n");
    break;
default:
    printf("Other day\n");
    break;
}
```

---

# How `switch` Works

```c
switch (expression) {
case CONSTANT:
    // ...
    break;

default:
    // ...
    break;
}
```

Key rules:

- the expression must have an integer-compatible type such as `int` or `char`
- `case` labels must be compile-time constants
- `break` prevents execution from continuing into the next case
- `default` handles values not matched by another case

---

# Switch Fall-Through

Sometimes multiple cases intentionally share behavior:

```c
switch (month) {
case 12:
case 1:
case 2:
    printf("Winter\n");
    break;

case 3:
case 4:
case 5:
    printf("Spring\n");
    break;

default:
    printf("Other season\n");
}
```

Here, fall-through is deliberate.

Make intentional fall-through obvious to the reader.

---

# `if` or `switch`?

Use `if` when the decision involves:

- ranges
- several variables
- complex boolean expressions

```c
if (age >= 18 && score >= 60) {
    // ...
}
```

Use `switch` when testing one value against discrete cases:

```c
switch (menu_choice) {
    // ...
}
```

---

# Ternary Operator

The conditional operator is a compact expression:

```c
condition ? value_if_true : value_if_false
```

Example:

```c
int x = 5;
int y = 10;

int max = (x > y) ? x : y;
```

Equivalent:

```c
if (x > y) {
    max = x;
} else {
    max = y;
}
```

---

# When to Use Ternary

Ternary works well for simple, stable choices:

```c
const char *label = active ? "active" : "inactive";
```

For logic that may grow, prefer `if` / `else`.

Avoid turning this:

```c
condition ? a : b
```

into a deeply nested puzzle.

Readability wins.

---

# Meeting 1 Recap

We can now express decisions using:

- relational operators
- logical operators
- `if` / `else if` / `else`
- nested or combined conditions
- `switch`
- the ternary operator

The important skill is not memorizing syntax.

It is translating a decision into clear program logic.

---

# Meeting 2: Loops and Data Wrangling

## Agenda

1. Why loops?
2. `while`
3. `do-while`
4. `for`
5. `break` and `continue`
6. Common loop mistakes
7. Unix data wrangling
8. Shell vs. C

---

# Why Loops?

Programs frequently need to repeat work:

- process every item
- count from one value to another
- retry until input is valid
- read until there is no more data
- search until something is found

C gives us three primary loop constructs:

```text
while
do-while
for
```

---

# `while` Loop

```c
int count = 1;

while (count <= 5) {
    printf("Count: %d\n", count);
    count++;
}
```

A `while` loop:

1. checks the condition
2. executes the body if true
3. repeats

If the condition begins false, the body runs **zero times**.

---

# Trace the Loop

```c
int count = 1;

while (count <= 3) {
    printf("%d\n", count);
    count++;
}
```

Trace:

| Before body | Printed | After `count++` |
| ---: | ---: | ---: |
| 1 | 1 | 2 |
| 2 | 2 | 3 |
| 3 | 3 | 4 |

Then:

```text
4 <= 3 -> false
```

The loop stops.

---

# Infinite Loops

What is wrong here?

```c
int i = 0;

while (i < 10) {
    printf("%d ", i);
}
```

Nothing changes `i`.

So:

```text
i < 10
```

remains true forever.

Every loop needs some path toward termination unless infinite repetition is intentional.

---

# `do-while` Loop

```c
int n;

do {
    printf("Enter a positive number: ");
    scanf("%d", &n);
} while (n <= 0);
```

Unlike `while`, the condition is checked **after** the body.

Therefore the body always executes at least once.

---

# When `do-while` Fits

A `do-while` loop is useful when the operation must happen before you can decide whether to repeat.

Examples:

- input validation
- menus
- retry prompts

Conceptually:

```text
do the thing
check whether we need to do it again
```

---

# `for` Loop

```c
for (int i = 1; i <= 5; i++) {
    printf("Iteration %d\n", i);
}
```

A `for` loop puts three pieces together:

```c
for (initialization; condition; update) {
    // body
}
```

---

# Anatomy of a `for` Loop

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

| Part | When it runs |
| --- | --- |
| `int i = 1` | once, before the loop |
| `i <= 5` | before each iteration |
| `i++` | after each iteration |

The body runs only when the condition is true.

---

# Choosing a Loop

| Loop | Good fit |
| --- | --- |
| `for` | known iteration pattern, counters |
| `while` | repeat while a condition remains true |
| `do-while` | body must execute at least once |

These are not fundamentally different powers.

Most loops can be rewritten using another loop form.

Choose the one that communicates the intent clearly.

---

# Off-by-One Errors

Compare:

```c
for (int i = 0; i <= 10; i++) {
}
```

Values of `i`:

```text
0 through 10 -> 11 iterations
```

Now:

```c
for (int i = 1; i < 10; i++) {
}
```

Values of `i`:

```text
1 through 9 -> 9 iterations
```

Trace your bounds when the exact count matters.

---

# `break`

`break` exits the innermost loop immediately.

```c
int n = 1;

while (1) {
    if (n % 3 == 0 && n % 5 == 0) {
        printf("Found: %d\n", n);
        break;
    }

    n++;
}
```

Without `break`, `while (1)` would continue forever.

---

# `continue`

`continue` skips the remainder of the current iteration.

```c
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) {
        continue;
    }

    printf("%d ", i);
}
```

Output:

```text
1 3 5 7 9
```

---

# `break` vs. `continue`

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;
    }

    if (i % 2 == 0) {
        continue;
    }

    printf("%d ", i);
}
```

Output:

```text
1 3
```

- `break` leaves the loop
- `continue` advances to the next iteration

---

# Loop Practice

Print the numbers from 1 through 100, but skip multiples of 7.

```c
for (int i = 1; i <= 100; i++) {
    if (i % 7 == 0) {
        continue;
    }

    printf("%d ", i);
}
```

What would change if we wanted to **stop** at the first multiple of 7 instead?

---

# Data Wrangling

Data wrangling means:

> cleaning, filtering, and transforming text data

Unix gives us small tools that compose well:

| Tool | Purpose |
| --- | --- |
| `grep` | find lines matching a pattern |
| `sed` | stream-edit or replace text |
| `awk` | column-oriented processing |
| `|` | chain commands together |

---

# `grep`

Find matching lines:

```bash
grep "Computer Science" students.txt
```

Count matching lines:

```bash
grep "error" log.txt | wc -l
```

The pipe sends the output of `grep` into `wc`.

Small tools become much more useful when combined.

---

# `sed`

Replace text:

```bash
sed 's/CS/Computer Science/g' students.txt
```

Delete blank lines:

```bash
sed '/^$/d' file.txt
```

Print only lines 1 through 5:

```bash
sed -n '1,5p' file.txt
```

---

# `awk`

Suppose `students.txt` contains:

```text
Alice,85,Computer Science
Bob,92,Mathematics
```

Compute the average of field 2:

```bash
awk -F',' \
    '{sum += $2; n++} END {print sum/n}' \
    students.txt
```

`-F','` tells `awk` that fields are separated by commas.

---

# Formatting with `awk`

```bash
awk -F',' \
    '{printf "%-10s %3d\n", $1, $2}' \
    students.txt
```

Possible output:

```text
Alice       85
Bob         92
```

`awk` is particularly useful when text has a predictable field structure.

---

# Pipes: Compose the Tools

Find mathematics students:

```bash
grep "Math" students.txt
```

Then reformat the separators:

```bash
grep "Math" students.txt |
    sed 's/,/ | /g'
```

Instead of building one giant tool, Unix encourages combining small tools.

---

# Shell or C?

Suppose `scores.txt` contains one integer per line.

We want the average score.

The shell can do it quickly:

```bash
awk '{sum += $1; n++} END {print sum/n}' scores.txt
```

We could also write a C program.

Which is the better choice?

---

# Shell vs. C

The shell is often convenient when:

- the data is already text
- the transformation is small
- existing tools already perform most of the work
- you need an answer quickly

C becomes useful when:

- the logic is more complex
- you need stronger control over data structures or behavior
- the task is part of a larger program
- performance or portability requirements justify it

Use the right level of tool for the job.

---

# Hands-On: Wrangling + Loops

Given `scores.txt`, with one integer per line:

1. Use `awk` to compute the average score.
2. Write a C loop that reads and sums values until EOF.
3. Compare the two solutions.

Discuss:

- Which took less code?
- Which is easier to modify?
- When would the shell solution stop being enough?

---

# Week 4 Recap

This week introduced two major forms of control flow.

**Decisions**

```text
if / else
switch
? :
```

**Repetition**

```text
while
do-while
for
break
continue
```

And we used Unix tools to process text without writing a full program.

---

# Next: Input/Output and File Basics

Next up:

- `printf`
- `scanf`
- file I/O
- error handling
- command-line environment

Questions?
