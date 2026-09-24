---
title: "CS 1380 — Week 1"
sub_title: "Introduction to C23 and the Development Environment"
authors: ["Dr. George Rudolph", "Adapted by Tim Severance & ChatGPT"]
# editor: "Tim Severance & ChatGPT"
# note: "Adapted to MD for Terminal Presentation"
options:
  end_slide_shorthand: true
---

<!-- grid -->
# CS 1380
## Modern Programming Essentials

### Week 1
Introduction to C23 and the Development Environment

- Thursday, August 20, 2026
- Textbook: Chapter 1 — Introduction to C23
- MIT Missing Semester: Course Overview + The Shell

---

# Week 1 Schedule

**Short week:** only one 1h15m meeting.

- Course intro, policies, C23 overview, dev environment 
- Compilation, Hello World, shell fundamentals 

After Thursday, editors, scripting, and workflow practice continue in Week 2 and homework.

---

# What You'll Learn

- Programming fundamentals in **C23**
- Development tools and command-line skills
- Problem solving through programming
- Modern development practices

---

# Course Structure

- Approx. **9 hours** of academic engagement per week
- 3 × 50-minute sessions per week
  - except this short first week
- Weekly homework
  - ~6 hours expected
- Hands-on programming throughout
- Real-world applications

---

# Learning Outcomes

By the end of the course, you should be able to:

1. Use command-line programming and file operations
2. Write, compile, and debug programs with modern tools
3. Implement basic data structures and algorithms
4. Use functions, arrays, and pointers effectively
5. Apply programming concepts to real-world problems
6. Use development tools, version control, and debugging tools

---

# Assessment

| Component | Weight | Due |
|---|---:|---|
| Homework | **55%** | Weekly |
| Final Exam | **20%** | Week 17 |
| Midterm 1 | 10% | Week 8 |
| Midterm 2 | 10% | Week 13 |
| Participation | 5% | Ongoing |
| SRI Submission | +2% | Extra credit |

**To pass:** Final Exam ≥ 70% **and** Homework ≥ 70%.

---

# Materials & Tools

- **Textbook:** *Mastering C23* — Ayman Alheraki
- **Compilers:** GCC / Clang (the goat)
- **Builds:** Make
- **Version control:** Git
- **Debugger:** GDB / Clangd
- **Environment:** Linux / Unix
- **Reference:** Linux man pages + C23 documentation
- **MIT Missing Semester:** https://missing.csail.mit.edu/

---

# Windows Setup

This course assumes a **Linux/Unix command line**.

If you're on Windows:

- **WSL2** — recommended
  - Ubuntu inside Windows
  - Fast and easiest for CLI work
- **MSYS2**
  - Unix translation layer for windows
  - Decent option for closer integration to windows development
- **Multipass**
  - Quick Ubuntu VM
- **Docker Desktop**
  - Ubuntu container for CLI + builds
  - Good if you already use Docker

### Goal by End of Week

```sh
gcc --version
git --version
make --version
```

---

# AI Usage Policy

## Allowed

- Load `Agents.md` at the start of each AI session
- Ask AI to explain concepts
- Ask AI to guide your learning

## Not Allowed

- Having AI write homework code for you
- Submitting code you cannot explain
- Submitting code you did not write yourself

**You must understand every line you submit.**

---

# Think — Pair — Share

### What programming languages do you know?

### Where might C23 be used?

1. **Think** — 1 minute
2. **Pair** — 2 minutes
3. **Share** — 2 minutes

---

# Session 1
## Course Introduction & C23 Basics

**Thursday, August 20 — 1h15m**

1. Course introduction
2. C23 programming language — 15 min
3. Development environment overview — 10 min

---

# What is C23?

- Latest C standard
- Backward compatible with C17 / C11 / C99
- Performance-focused
- Direct control over memory and hardware details
- Modern tooling and language improvements

### Common domains

- OS kernels
- Embedded systems / IoT
- Drivers
- Firmware

---

# Why Learn C?

C gives you a much clearer view of what the computer is actually doing.

It provides a foundation for:

- Understanding memory
- Understanding compilation
- Understanding how programs interact with hardware
- Systems programming
- Advanced CS courses

---

# Development Environment

| Tool | Role |
|---|---|
| GCC / Clang | Compile C23 source |
| Make | Automate builds |
| Git / GitHub | Version control |
| GDB / Clangd | Debug programs |
| Editor | Nano, NeoVim, or VS Code |

**Linux/Unix CLI:** navigation, files, and permissions.

---

# Session 2
## Compilation & Shell Basics

**Friday, August 21 — 50 minutes**

1. Compilation + Hello World — 20 min
2. Shell fundamentals — 25 min
3. Homework preview — 5 min

---

# Compilation Pipeline

```text
hello.c
   │
   ▼
Preprocessor
#include, #define
   │
   ▼
Compiler
C → assembly
   │
   ▼
Assembler
assembly → hello.o
   │
   ▼
Linker
objects + libraries
   │
   ▼
Executable
```

---

# GCC Does It All

```sh
gcc -Wall -Wextra -std=c23 -g -o hello hello.c
```

Behind that command:

1. **Preprocessor** — handles `#include`, `#define`
2. **Compiler** — C → assembly
3. **Assembler** — assembly → object file (`.o`)
4. **Linker** — objects + libraries → executable

---

# Your First C23 Program

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

### Live Demo

Create → compile → run → inspect warnings.

```sh
gcc -Wall -Wextra -std=c23 -o hello hello.c
./hello
```

---

# Useful GCC Flags

| Flag | Purpose |
|---|---|
| `-Wall -Wextra` | Enable warnings |
| `-std=c23` | Use C23 |
| `-g` | Debug symbols for GDB |
| `-O2` | Optimized build |

### Habit

**Compile with warnings enabled every time.**

---

# Shell: Navigation & Files

```sh
<prog> --help / -h  # get help for a program
man <prog>          # Read the full manual for a program
pwd                 # where am I?
ls -la              # list files
cd path             # change directory
mkdir name          # create directory
cp a b              # copy
mv a b              # move / rename
rm file             # delete — careful! (-rf will force delete recursively with no return)
touch file          # create empty file
```

---

# File Permissions

Example:

```text
-rw-r--r-- 1 user group 1024 Aug 19 10:00 file.txt
```

Think in three groups:

```text
owner | group | others
 rwx  |  rwx  |  rwx
```

- `r` — read
- `w` — write
- `x` — execute

**Directories need `x` permission to enter.**

---

# Hands-On: Shell Practice

Try together:

```sh
pwd
```

1. `cd` into your home or project folder
2. Create a lab directory:

```sh
mkdir cs1380-lab
cd cs1380-lab
```

3. Create a file and inspect it:

```sh
touch notes.txt
ls -l
```

4. Practice `cp` and `mv`

---

# Homework Preview

### Homework 1
**Environment Setup & First Program**

Due: **Friday, August 21, 2026**

- Verify toolchain
- Write and compile a first program

### Homework 2
**Shell & Text Editor Practice**

Due: **Monday, August 24, 2026**

- Shell navigation
- Basic editor practice

Submit via Canvas.

**Late policy:** 10% per business day.

---

# Next Class — Week 2

## Basic Syntax & Program Structure

- Textbook Chapter 2 — Fundamentals, Part 1
- MIT Missing Semester — Shell Tools & Scripting
- Nano / Vim
- Workflow
- More shell practice

### Questions?
