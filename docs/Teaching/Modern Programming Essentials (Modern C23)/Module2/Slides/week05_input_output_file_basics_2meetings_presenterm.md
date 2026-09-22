---
author: Tim S.
sub_title: "Week 5: Input/Output Operations and File Basics"
title: "CS 1380: Modern Programming Essentials"
---

# Week 5: Input/Output Operations and File Basics

**CS 1380: Modern Programming Essentials**

Instructor: **Tim S.**

Textbook: Chapter 2 --- Fundamentals (part 4)\
MIT Missing Semester: Command-line Environment

------------------------------------------------------------------------

# Week 5 Overview

## Meeting 1 --- Console Input and Output

-   Formatted output with `printf`
-   Formatted input with `scanf`
-   Return values and input validation
-   `getchar` and `putchar`
-   Input buffers and safer string input

## Meeting 2 --- Files and the Command-Line Environment

-   Text and binary files
-   `fopen`, `fclose`, and file modes
-   Reading and writing files
-   Error handling
-   Environment variables and job control

------------------------------------------------------------------------

# Learning Objectives

By the end of this week, you should be able to:

1.  Format output and parse input with `printf` and `scanf`
2.  Handle character streams and input buffers safely
3.  Open and close files using appropriate modes
4.  Read and write text files
5.  Detect and report file errors
6.  Use environment variables and basic shell job control

------------------------------------------------------------------------

# Meeting 1: Console Input and Output

**75 minutes**

## Agenda

1.  `printf` and formatted output (15 min)
2.  `scanf` and formatted input (20 min)
3.  Character I/O with `getchar` / `putchar` (10 min)
4.  Input buffers and safer string input (20 min)
5.  Input validation practice (10 min)

------------------------------------------------------------------------

# `printf`: Formatted Output

``` c
printf("Name: %s, Age: %d, Height: %.2f\n",
       name, age, height);

printf("%5d\n", 42);       // width
printf("%05d\n", 42);      // zero-pad
printf("%10.3f\n", 3.14159); // precision
```

A format string describes how values should be displayed.

------------------------------------------------------------------------

# Common Format Specifiers

  Specifier    Type
  ------------ ----------------
  `%d`, `%i`   integer
  `%f`         floating-point
  `%c`         character
  `%s`         string
  `%x`         hexadecimal
  `%o`         octal

Formatting can also specify width and precision:

``` c
printf("%8d", value);
printf("%.2f", price);
```

------------------------------------------------------------------------

# `scanf`: Formatted Input

``` c
int age;
double height;
char name[50];

int result = scanf("%49s %d %lf",
                   name, &age, &height);
```

`scanf` tries to parse input according to its format string.

The return value tells us **how many values were successfully read**.

------------------------------------------------------------------------

# Why the `&`?

``` c
int age;

scanf("%d", &age);
```

`scanf` needs to modify `age`.

Instead of receiving its current value, it receives the **address**
where that value lives.

``` text
age      -> the value
&age     -> where the value is stored
```

Arrays such as strings behave differently:

``` c
char name[50];
scanf("%49s", name);
```

------------------------------------------------------------------------

# Always Check `scanf`

``` c
int age;

printf("Age: ");

if (scanf("%d", &age) == 1) {
    printf("You entered %d\n", age);
} else {
    printf("Invalid input\n");
}
```

Ignoring the return value means your program may continue using data
that was never successfully read.

Input is external data.

**Never assume it is valid.**

------------------------------------------------------------------------

# Character I/O

Sometimes we do not want formatted input at all.

``` c
int ch;

while ((ch = getchar()) != EOF) {
    putchar(ch);
}
```

-   `getchar()` reads one character from `stdin`
-   `putchar(ch)` writes one character to `stdout`
-   `getchar()` returns an `int` so it can also represent `EOF`

This is useful for stream-oriented processing.

------------------------------------------------------------------------

# Streams

Console I/O is already stream-based.

``` text
keyboard
   |
   v
 stdin ---> program ---> stdout
                    \
                     ---> stderr
```

C provides standard streams automatically:

-   `stdin` --- normal input
-   `stdout` --- normal output
-   `stderr` --- errors and diagnostics

Files will use the same general model.

------------------------------------------------------------------------

# The Input Buffer

Suppose the user types:

``` text
42<Enter>
```

The input stream contains:

``` text
'4' '2' '\n'
```

A function may consume only the characters it needs.

Anything left behind is still waiting for the next input operation.

This is the source of many mysterious "skipped input" bugs.

------------------------------------------------------------------------

# A Classic Buffer Problem

``` c
int age;
char name[50];

printf("Enter age: ");
scanf("%d", &age);

printf("Enter name: ");
fgets(name, sizeof(name), stdin);
```

`scanf` reads the number but can leave the newline behind.

Then `fgets` immediately sees that newline.

It looks like the second prompt was skipped.

------------------------------------------------------------------------

# Dealing with Leftover Input

One simple pattern is to consume through the newline:

``` c
int ch;

while ((ch = getchar()) != '\n' && ch != EOF) {
    // discard
}
```

For some `scanf` conversions, leading whitespace can also help:

``` c
scanf(" %c", &choice);
```

But for full lines of text, `fgets` is usually easier to reason about.

------------------------------------------------------------------------

# Safer String Input

``` c
char name[64];

if (fgets(name, sizeof(name), stdin) != NULL) {
    name[strcspn(name, "\n")] = '\0';
}
```

`fgets`:

-   knows the size of the destination buffer
-   can read spaces
-   reads an entire line when it fits

If you use `%s`, always specify a width:

``` c
scanf("%63s", name);
```

Never use unbounded `%s`.

------------------------------------------------------------------------

# Input Validation Pattern

``` c
int age;
int result;

do {
    printf("Enter age (1-120): ");
    result = scanf("%d", &age);

    if (result != 1) {
        printf("Please enter a number.\n");

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
} while (result != 1 || age < 1 || age > 120);
```

Validation means checking both:

1.  **Did parsing succeed?**
2.  **Is the parsed value acceptable?**

------------------------------------------------------------------------

# Think-Pair-Share

Consider:

``` c
int count;
scanf("%d", &count);

printf("%d\n", count);
```

What happens if the user enters:

``` text
potato
```

Discuss:

-   What does `scanf` return?
-   What happens to `count`?
-   What input remains in the stream?
-   Why is ignoring the return value dangerous?

------------------------------------------------------------------------

# Meeting 1 Recap

Console I/O is more than printing and typing.

``` text
printf  -> formatted output
scanf   -> formatted parsing
getchar -> character input
putchar -> character output
fgets   -> bounded line input
```

The important habits:

-   match format specifiers to types
-   check return values
-   limit string input
-   remember that unread characters remain in the stream

------------------------------------------------------------------------

# Meeting 2: Files and the Command-Line Environment

**75 minutes**

## Agenda

1.  Files, modes, `fopen`, and `fclose` (20 min)
2.  Reading and writing text files (20 min)
3.  Errors, `EOF`, and `stderr` (15 min)
4.  Environment variables and job control (15 min)
5.  File I/O practice (5 min)

------------------------------------------------------------------------

# Files Are Streams Too

The standard streams:

``` text
stdin
stdout
stderr
```

and a file opened by your program are all represented through C's stream
I/O system.

``` c
FILE *fp;
```

A `FILE *` represents an open stream.

That means many familiar operations have file-oriented relatives:

``` text
printf  -> fprintf
scanf   -> fscanf
getchar -> fgetc
putchar -> fputc
```

------------------------------------------------------------------------

# Text vs. Binary Files

                   Text                    Binary
  ---------------- ----------------------- -----------------------------
  Contents         characters              raw bytes
  Human-readable   usually                 usually not
  Examples         `.txt`, `.csv`, `.md`   `.jpg`, `.dat`, executables
  Modes            `"r"`, `"w"`, `"a"`     `"rb"`, `"wb"`, `"ab"`

Text files are still bytes on disk.

"Text mode" tells the C library that those bytes represent a text
stream.

------------------------------------------------------------------------

# Opening a File

``` c
FILE *fp = fopen("input.txt", "r");
```

`fopen` needs:

1.  a path
2.  an opening mode

Common modes:

  Mode     Meaning
  -------- ---------------------------
  `"r"`    read; file must exist
  `"w"`    write; create or truncate
  `"a"`    append; create if missing
  `"r+"`   read and write
  `"rb"`   read binary

------------------------------------------------------------------------

# `w` Can Destroy Data

This is worth remembering:

``` c
FILE *fp = fopen("important.txt", "w");
```

If `important.txt` already exists, `"w"` **truncates it**.

Its previous contents are discarded.

Compare:

``` text
r -> existing data
w -> replace contents
a -> add to the end
```

Choose the mode deliberately.

------------------------------------------------------------------------

# `fopen` Can Fail

``` c
FILE *fp = fopen("input.txt", "r");

if (fp == NULL) {
    fprintf(stderr,
            "Could not open input.txt\n");
    return 1;
}
```

Possible reasons include:

-   the file does not exist
-   permission was denied
-   the path is invalid
-   the system cannot allocate another file handle

Never use a `FILE *` before checking it.

------------------------------------------------------------------------

# Closing Files

When finished:

``` c
if (fclose(fp) != 0) {
    fprintf(stderr, "Error closing file\n");
    return 1;
}
```

`fclose` releases the file handle and flushes buffered output.

The basic lifecycle is:

``` text
open -> check -> use -> close
```

Open files are limited system resources.

------------------------------------------------------------------------

# Reading a Text File

``` c
char line[128];

while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
}
```

This reads the file one line at a time.

Other choices include:

``` c
fgetc(fp);
fscanf(fp, ...);
```

Use the operation that matches the structure of the data.

------------------------------------------------------------------------

# Writing to a File

``` c
FILE *out = fopen("summary.txt", "w");

if (out == NULL) {
    return 1;
}

fprintf(out, "Student Report\n");
fprintf(out, "Average: %.1f\n", average);
fputs("Done.\n", out);

fclose(out);
```

`fprintf` is essentially `printf` with an explicit destination stream.

------------------------------------------------------------------------

# The Same Functions, Different Streams

``` c
printf("Score: %d\n", score);
```

is equivalent in spirit to:

``` c
fprintf(stdout, "Score: %d\n", score);
```

Errors can go elsewhere:

``` c
fprintf(stderr, "Invalid score\n");
```

Files give us another destination:

``` c
fprintf(fp, "Score: %d\n", score);
```

The stream changes. The formatting system does not.

------------------------------------------------------------------------

# Why `stderr` Exists

Suppose a program's normal output is redirected:

``` bash
./analyze > results.txt
```

`stdout` goes into `results.txt`.

But `stderr` still appears in the terminal.

That lets us separate:

``` text
program results -> stdout
diagnostics     -> stderr
```

This becomes especially useful when programs are composed with shell
tools.

------------------------------------------------------------------------

# Better Error Messages

C exposes additional information through `errno`.

``` c
#include <errno.h>
#include <string.h>

FILE *fp = fopen("missing.txt", "r");

if (fp == NULL) {
    fprintf(stderr, "Error: %s\n",
            strerror(errno));
    return 1;
}
```

A simpler alternative for many system/library failures is:

``` c
perror("missing.txt");
```

------------------------------------------------------------------------

# End-of-File vs. Error

``` c
int ch;

while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
}

if (ferror(fp)) {
    fprintf(stderr, "Read error\n");
}
```

`EOF` tells us that the read operation could not produce another
character.

Afterward:

-   `feof(fp)` checks whether end-of-file was reached
-   `ferror(fp)` checks whether an I/O error occurred
-   `clearerr(fp)` clears those indicators

------------------------------------------------------------------------

# Reading Structured Data

Suppose `grades.txt` contains:

``` text
Alice 85
Bob 92
Charlie 78
```

We can parse it:

``` c
char name[50];
int grade;

while (fscanf(fp, "%49s %d", name, &grade) == 2) {
    printf("%s: %d\n", name, grade);
}
```

Again, the return value tells us whether the expected data was actually
read.

------------------------------------------------------------------------

# Mini Practice: Grade Summary

Given `grades.txt`, write a program that:

1.  opens the file
2.  reads `name score` pairs
3.  counts the records
4.  computes the average
5.  finds the maximum score
6.  reports malformed input or file errors
7.  closes the file

Then write the summary to `summary.txt`.

The interesting part is not the arithmetic --- it is the I/O discipline.

------------------------------------------------------------------------

# Environment Variables

The shell maintains named values called environment variables.

``` bash
echo "$PATH"
echo "$HOME"
echo "$USER"

export COURSE="CS1380"
env
```

Common examples:

``` text
PATH
HOME
USER
SHELL
PWD
```

Programs inherit environment information when they are launched.

------------------------------------------------------------------------

# Environment Variables in C

``` c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *home = getenv("HOME");

    if (home != NULL) {
        printf("HOME = %s\n", home);
    }

    return 0;
}
```

`getenv` returns the variable's value or `NULL` if it does not exist.

On POSIX systems, `setenv` and `unsetenv` can modify a process's
environment.

------------------------------------------------------------------------

# Why Environment Variables Matter

Environment variables let configuration exist **outside the source
code**.

Instead of:

``` c
char *path = "/home/tim/data";
```

a program can ask its environment:

``` c
char *path = getenv("DATA_PATH");
```

This is useful for:

-   configuration
-   executable lookup through `PATH`
-   user-specific paths
-   secrets and deployment settings

The program and its environment cooperate.

------------------------------------------------------------------------

# Shell Job Control

A shell can manage multiple processes.

``` bash
sleep 100 &
jobs
```

The `&` starts the command in the background.

Bring it forward:

``` bash
fg %1
```

Suspend a foreground job with:

``` text
Ctrl-Z
```

Then resume it in the background:

``` bash
bg %1
```

Terminate it:

``` bash
kill %1
```

------------------------------------------------------------------------

# Foreground vs. Background

A **foreground** job owns the terminal interaction.

``` text
shell -> program
         ^ keyboard
```

A **background** job runs while the shell accepts more commands.

``` text
program running
       +
shell ready for another command
```

Job control is the shell coordinating processes attached to the same
terminal.

------------------------------------------------------------------------

# Shell + C

Shell tools and C programs do not compete with each other.

They compose.

``` bash
for file in *.txt; do
    lines=$(wc -l < "$file")
    echo "$file: $lines lines"
done
```

The shell is excellent at coordinating files and programs.

C is excellent when the processing itself becomes more structured or
complex.

------------------------------------------------------------------------

# Hands-On: File I/O

Create `students.txt`:

``` text
Alice 85
Bob 92
Charlie 78
```

Write a C program that:

1.  opens the file
2.  computes average, minimum, and maximum
3.  handles a missing file
4.  handles malformed data
5.  writes the results to `summary.txt`

Then inspect the result from the shell.

------------------------------------------------------------------------

# Week 5 Recap

This week connected console I/O, files, and the shell.

``` text
stdin / stdout / stderr
          |
          v
       streams
          |
          v
       FILE *
```

Core habits:

-   check input and I/O return values
-   bound string input
-   understand what remains in the input stream
-   choose file modes carefully
-   send diagnostics to `stderr`
-   always close files

------------------------------------------------------------------------

# Next: Functions and Git

Next up:

-   function definitions and calls
-   parameters and return values
-   scope
-   breaking programs into reusable pieces
-   version control with Git

Questions?
