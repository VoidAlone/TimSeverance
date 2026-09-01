---
title: "CS 1380 — Week 2, Day 1"
sub_title: "Anatomy of a C Program & Code Formatting"
author: "CS 1380: Modern Programming Essentials"
options:
  end_slide_shorthand: true
---

# Week 2, Day 1

## Anatomy of a C Program

Todo:

- What actually happens to a C source file?
- What does each part of a small C program mean?
- How do we read C syntax documentation?
- What is formatting, and what is style?

---

# Start With the Whole Program

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world!\n");
    return 0;
}
```

You've already written and compiled programs like this.

Today we're going to pull it apart.

---

# C Source Is Not the Executable

```text
hello.c
   │
   ▼
preprocessing
   │
   ▼
compilation
   │
   ▼
linking
   │
   ▼
executable
```

These are conceptually different stages.

You do **not** need to understand compiler internals yet.

---

# The Preprocessor

The preprocessor runs before the compiler processes the resulting C source.

Preprocessor directives begin with `#`.

```c
#include <stdio.h>
#define MAX_STUDENTS 30

#if DEBUG
    /* ... */
#endif
```

For now, the directive we care about most is:

```c
#include
```

---

# What Does `#include` Mean?

```c
#include <stdio.h>
```

Conceptually, `#include` makes the contents of a header available during preprocessing.

It is **not** the same idea as importing a Python module or Java package.

Two common forms:

```c
#include <stdio.h>       // standard/system header
#include "my_header.h"   // project/local header
```

---

# So What Is `stdio.h`?

`stdio.h` is the C standard input/output header.

It provides declarations for things such as:

```c
printf(...)
scanf(...)
puts(...)
```

A simplified view of `printf` might look like:

```c
int printf(const char *format, ...);
```

You do **not** need to understand all of that syntax yet.

The important idea:

> The compiler needs to know what `printf` is before we call it.

---

# `main`

```c
int main(void)
{
    /* ... */
}
```

A function definition has several pieces:

```text
int     main     (void)     { ... }
 │       │          │          │
 │       │          │          └─ function body
 │       │          └──────────── parameters
 │       └─────────────────────── function name
 └─────────────────────────────── return type
```

`main` is special: execution of a hosted C program begins there.

---

# Why `int main(void)`?

```c
int main(void)
```

`int`

: `main` returns an integer.

`main`

: the program's entry-point function.

`(void)`

: this version of `main` takes no arguments.

Later we'll see other functions with the same basic shape:

```c
int add(int a, int b)
{
    return a + b;
}
```

---

# Reading C Syntax References

You do not need to memorize every legal form of C syntax.

Reference documentation often describes syntax using a grammar-like notation.

For example, a function definition can be thought of as:

```text
return-type function-name(parameters)
{
    declarations / statements
}
```

Then:

```c
int main(void)
{
    return 0;
}
```

is one concrete instance of that pattern.

When you forget syntax, **look it up and map the grammar to real code**.

---

# Blocks, Statements, and Semicolons

Curly braces form a block:

```c
{
    /* statements live here */
}
```

Many C statements end with `;`:

```c
int count = 10;
printf("%d\n", count);
return 0;
```

But blocks themselves do not generally need a semicolon:

```c
if (count > 0) {
    printf("positive\n");
}
```

Indentation helps humans see the structure.

---

# Calling `printf`

```c
printf("Hello, world!\n");
```

This is a **function call**.

- `printf` — function name
- `(...)` — arguments passed to the function
- `"Hello, world!\n"` — string literal
- `\n` — newline escape sequence
- `;` — end of the statement

`printf` writes formatted output to standard output.

---

# Formatted Output

The format string can contain conversion specifications:

```c
int age = 20;

printf("Age: %d\n", age);
```

`%d` says:

> Format the corresponding argument as a signed decimal integer.

Another example:

```c
char grade = 'A';

printf("Grade: %c\n", grade);
```

We'll encounter more format specifiers as we learn C's data types.

---

# `return 0`

```c
int main(void)
{
    /* ... */
    return 0;
}
```

`main` returns an integer status to the environment that launched it.

By convention:

```text
0       success
nonzero failure / some other status
```

In a shell:

```bash
./hello
echo $?
```

Printed program output and the program's exit status are different things.

---

# Put It Back Together

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, world!\n");
    return 0;
}
```

We can now identify:

- a preprocessor directive
- a standard header
- a function definition
- a function call
- a string literal
- a statement
- a block
- a return value

---

# The Compiler Does Not Care If This Is Ugly

```c
#include <stdio.h>
int main(void){int number=42;printf("number: %d\n",number);return 0;}
```

Assuming the syntax is valid, this can compile just fine.

So why do we format code?

---

# Formatting Is for Humans

Compare:

```c
int x=5+7;
```

with:

```c
int x = 5 + 7;
```

Formatting makes structure visually consistent:

- indentation
- whitespace
- brace placement
- line wrapping

Computers are very good at enforcing mechanical rules.

---

# `clang-format`

`clang-format` automatically formats source code.

Preview formatted output:

```bash
clang-format ugly.c
```

Modify the file in place:

```bash
clang-format -i ugly.c
```

Try different built-in styles:

```bash
clang-format --style=LLVM ugly.c
clang-format --style=Google ugly.c
```

Projects can also provide a `.clang-format` configuration file.

---

# Demo: Make It Ugly

Start with:

```c
#include <stdio.h>
int main(void){int number=42;printf("number: %d\n",number);return 0;}
```

Then:

```bash
clang-format ugly.c
clang-format -i ugly.c
```

Questions:

- What changed?
- What did **not** change?
- Did the behavior of the program change?

---

# Formatting ≠ Readability

`clang-format` can turn:

```c
int x=5+7;
```

into:

```c
int x = 5 + 7;
```

It cannot know that:

```c
int x;
```

would be clearer as:

```c
int student_count;
```

Formatting is mechanical.

Readability also depends on human decisions.

---

# Names Carry Meaning

Weak:

```c
int x = 24;
int y = 3;
int z = x / y;
```
Note: single letter variables are very common in older programs.

Better:

```c
int student_count = 24;
int group_count = 3;
int students_per_group = student_count / group_count;
```

Good names reduce the amount of explanation the reader needs.

Question: Why would oldschool programmers use terse names if longer/clearer names are better?

---

# Comments Should Add Information

Not very useful:

```c
student_count++; // increment student_count
```

More useful:

```c
// Include the instructor when calculating room capacity.
student_count++;
```

Prefer clear code when the code can explain itself.

Use comments for information the code **cannot clearly communicate on its own**.

---

# Formatting, Style, and Comments

Think of these as different layers:

```text
Formatting
    mechanical appearance
    ↓
Naming and structure
    communicates intent
    ↓
Comments
    explain context, decisions, and non-obvious behavior
```

`clang-format` can handle the first layer.

You are responsible for the rest.

---

# Demo: Editor Integration

Manually running:

```bash
clang-format -i program.c
```

is useful for understanding the tool.

In practice, editors can invoke formatters automatically.

Demo:

1. Write intentionally ugly C
2. Save / invoke formatter in Neovim
3. Watch `clang-format` normalize it

The command-line tool and editor integration are doing the same kind of work.

---

# What You Should Be Able to Explain

Given:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello!\n");
    return 0;
}
```

You should be able to explain, at a basic level:

- what `#include` is doing
- why `stdio.h` is involved
- why `main` exists
- what `printf` does
- why statements use semicolons
- what the braces mean
- what `return 0` communicates

---

# Homework Connection

Today's material directly supports:

- writing and explaining a basic C program
- identifying the elements of a C source file
- writing readable code
- using comments intentionally
- formatting code with `clang-format`
- explaining what automated formatting can and cannot do

Next class:

**variables, C data types, arithmetic, `sizeof`, limits, and shell tools**
