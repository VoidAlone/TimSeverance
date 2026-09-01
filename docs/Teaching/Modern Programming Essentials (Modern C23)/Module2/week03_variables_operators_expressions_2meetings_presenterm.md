---
title: "CS 1380: Modern Programming Essentials"
sub_title: "Week 3: Variables, Operators, and Expressions"
author: "Tim S."
---

# Week 3: Variables, Operators, and Expressions

**CS 1380: Modern Programming Essentials**

Instructor: **Tim S.**

Textbook: Chapter 2 — Fundamentals (part 2)  
MIT Missing Semester: Editors (Vim)

---

# Week 3 Overview

| Meeting | Focus |
| --- | --- |
| Meeting 1 | Arithmetic and assignment operators, `++` / `--`, precedence, associativity |
| Meeting 2 | Type conversion, casting, constants and literals, Vim, expression practice |

---

# Learning Objectives

By the end of this week, you will be able to:

1. Apply arithmetic and assignment operators correctly
2. Evaluate expressions using precedence and associativity rules
3. Convert between types safely (implicit and explicit casting)
4. Use constants, literals, and Vim for efficient editing

---

# Meeting 1: Operators & Precedence

**75 minutes**

## Agenda

1. Arithmetic and assignment operators — `+`, `-`, `*`, `/`, `%`, compound assignment (25 min)
2. Increment and decrement — prefix vs postfix, common pitfalls (15 min)
3. Operator precedence and associativity (25 min)
4. Expression walkthrough / think-pair-share (10 min)

---

# Arithmetic Operators

```c
int a = 10, b = 3;

int sum  = a + b; // 13
int diff = a - b; // 7
int prod = a * b; // 30
int quot = a / b; // 3 (integer division — truncates!)
int rem  = a % b; // 1 (remainder; integers only)
```

Division by zero → **undefined behavior**. Always check divisors.

---

# Assignment Operators

```c
int x = 5;

x = x + 3; // same as:
x += 3;

x -= 2; // x = x - 2
x *= 4; // x = x * 4
x /= 2; // x = x / 2
x %= 3; // x = x % 3
```

Compound assignment is concise and often clearer about intent.

---

# Increment and Decrement

```c
int x = 5, y;

y = x++; // post: y=5, x→6
y = ++x; // pre: x→7, y=7
```

- `++x` / `--x` — update first, then use value
- `x++` / `x--` — use value first, then update
- In C, there is no reason to prefer `++x` over `x++` when the value is unused — same machine code
- Unlike C++, pre-increment does not avoid copies on user-defined types because C has no such types

Avoid multiple `++` / `--` operations on the same variable in one expression.

---

# Operator Precedence

```c
int result  = 2 + 3 * 4;     // 14, not 20
int result2 = (2 + 3) * 4;   // 20
```

High → low, partial list:

1. `()` grouping
2. Unary `+`, `-`, `++`, `--`, `!`
3. `*`, `/`, `%`
4. `+`, `-`
5. `=`, `+=`, `-=`, ...

**When in doubt, add parentheses.**

---

# Associativity

```c
int a = 10, b = 5, c = 2;

int r1 = a - b - c; // (a - b) - c → 3
int r2 = a = b = c; // a = (b = c) → all become 2
```

- Arithmetic: left-to-right
- Assignment: right-to-left

Use parentheses to make intent obvious to readers.

---

# Common Precedence Mistakes

```c
int x = 5, y = 3;

int bad  = x + y * 2;       // 11, not 16
int good = (x + y) * 2;     // 16

double avg  = 7 / 2;        // 3.0 — integer division!
double fix  = 7.0 / 2;      // 3.5
double cast = (double)7 / 2; // 3.5
```

Break complex expressions into multiple statements when readability suffers.

---

# Think-Pair-Share

Evaluate without a compiler, then check:

```c
int a = 10, b = 3, c = 2;
int result = a + b * c - a / b;
```

What is `result`?

Walk through precedence step by step with a partner.

---

# Meeting 2: Conversion, Literals, Vim & Expressions

**75 minutes**

## Agenda

1. Type conversion and casting — implicit and explicit (20 min)
2. Constants and literals (15 min)
3. Vim modes, navigation, and editing (20 min)
4. Expression evaluation and practice (20 min)

---

# Implicit Conversion (Promotion)

```c
int i = 5;
float f = 3.14f;

double d = i + f; // i promoted to float, then to double

char c = 100;
int result = c + 200; // char promoted to int before addition
```

The compiler widens smaller types to `int` or `float` / `double` automatically in mixed expressions.

---

# Explicit Casting

```c
double pi = 3.14159;
int whole = (int)pi; // truncates → 3

int a = 7, b = 2;
double avg = (double)a / b; // 3.5 (cast before division)

long long big = (long long)a * b; // avoid overflow
```

Cast when you need a specific type the compiler won't choose.

---

# Conversion Pitfalls

```c
// Pitfall 1: integer division
double wrong = 5 / 2;   // 2.0
double right = 5.0 / 2; // 2.5

// Pitfall 2: overflow before promotion
int x = 1000000, y = 1000000;
long long p = x * y; // may overflow as int first!

// Fix: cast before multiply
long long p2 = (long long)x * y;
```

---

# Numeric Literals

```c
int dec = 42;       // decimal
int oct = 052;      // octal → 42 decimal
int hex = 0x2A;     // hexadecimal → 42 decimal

long L = 100000L;
unsigned u = 42U;

float f = 3.14f;
double d = 3.14159;
double sci = 6.02e23;
```

C23 also supports binary literals:

```c
int binary = 0b1010; // 10
```

---

# Character and String Literals

```c
char c = 'A';
char nl = '\n';

char str[] = "Hello";     // mutable char array
const char *msg = "Hi";   // string literal (read-only)
```

Escape sequences:

- `\n` — newline
- `\t` — tab
- `\\` — backslash
- `\'` — quote

---

# Constants: `#define` vs `const`

```c
#define MAX_SIZE 100 // preprocessor macro — no type

const int MAX_SIZE = 100; // typed constant — preferred
const double PI = 3.14159;

constexpr int BUF = 1024; // C23: compile-time constant
```

| | `#define` | `const` / `constexpr` |
| --- | --- | --- |
| Type checking | No | Yes |
| Scope | File-wide (text replace) | Normal scope rules |

Prefer `const` unless you need a true macro.

---

# Hands-on: Casting Debug

Fix this program so it prints `3.50` and `1000000000000`:

```c
int a = 7, b = 2;
int x = 1000000, y = 1000000;

printf("%.2f\n", a / b);
printf("%lld\n", x * y);
```

Hint: where do you need casts? What format specifier should be used for `long long`?

---

# Vim Modes

| Mode | Key | What you do |
| --- | --- | --- |
| Normal | `Esc` | Navigate, delete, copy, paste |
| Insert | `i`, `a`, `o` | Type and edit text |
| Visual | `v`, `V` | Select text for operations |
| Command | `:` | Save, quit, search/replace |

Open a file:

```bash
vim hello.c
```

You start in **Normal mode**.

---

# Vim Navigation & Editing

| Command | Action |
| --- | --- |
| `h j k l` | left, down, up, right |
| `w b` | next / previous word |
| `0 $` | start / end of line |
| `gg G` | start / end of file |
| `i a o` | insert before, after, new line below |
| `dd` | delete line |
| `yy p` | yank (copy) line, paste |
| `x` | delete character |

---

# Vim Search & Replace

| Command | Action |
| --- | --- |
| `/pattern` | search forward |
| `n` / `N` | next / previous match |
| `:s/old/new/` | replace first on current line |
| `:%s/old/new/g` | replace all in file |
| `:%s/old/new/gc` | replace all with confirmation |
| `:wq` | save and quit |
| `:q!` | quit without saving |

Create `~/.vimrc` for persistent settings:

```vim
set number
set expandtab
set tabstop=4
```

---

# Vim Tips for C Code

Useful commands:

- `%` — jump to matching brace
- `[[` / `]]` — previous / next function
- `*` — search word under cursor

Useful `.vimrc` lines:

```vim
set number
set autoindent
set expandtab
set tabstop=4
syntax on
```

---

# Expression Practice

Work through step by step:

```c
int a = 5, b = 3, c = 2;

int r1 = a + b * c - a / b + c % b;
// b*c=6, a/b=1, c%b=2
// → 5+6-1+2 = 12
```

```c
int x = 10, y = 5, z = 2;

int r2 = x + y * z / 2 - x % y;
// y*z=10, /2=5, x%y=0
// → 10+5-0 = 15
```

Verify with a short program or calculator.

---

# Pair Activity: Expression Challenge

Write expressions that use at least four operators. Trade with a partner:

1. Evaluate on paper using precedence rules
2. Compile and print results to verify
3. Identify any overflow or integer-division traps

Example starter:

```c
int a = 10, b = 3, c = 5;
int result = a + b * c / 2 - a % b + ++c;
```

---

# Homework Preview

## Homework 5: Operators & Type Conversion

Due: **Wednesday, September 2, 2026**

Operator practice, precedence exercises, casting scenarios

## Homework 6: Expressions & Vim

Due: **Friday, September 4, 2026**

Complex expression analysis, Vim navigation and editing drills

Submit via Canvas · Late policy: 10% per business day

---

# Next Class — Week 4

**Week 4: Control Structures and Flow Control**

Textbook: Chapter 2 — Fundamentals (part 3)  
MIT Missing Semester: Data Wrangling

`if` / `else`, `switch`, loops, shell data tools

Questions? Ask now, email, or post on the discussion board.
