---
title: "CS 1380 — Week 14: Advanced Topics and Optimization"
sub_title: "Modern C23 • Performance • Threads • Professional Practice"
author: "CS 1380 — Modern Programming Essentials"
theme:
  name: dark
---

# Week 14: Advanced Topics and Optimization

**Two 75-minute sessions**

- Day 1: Advanced C23 and performance
- Day 2: Multithreading, testing, and workflow

---

# Learning Objectives

- Use `_Generic`, compile-time assertions, and `typeof` appropriately
- Explain algorithmic and memory-access performance
- Compare debug, optimized, and profiling builds
- Create and join POSIX threads
- Recognize data races and protect shared state with mutexes
- Organize, document, and test C programs

---

# Day 1 — C23 and Performance

**75 minutes**

1. Modern C features and preprocessor — 30 min
2. Algorithms, memory, and compiler optimization — 25 min
3. Hands-on exercises and discussion — 20 min

---

# `_Generic`: Compile-Time Type Selection

Select an expression based on its type.

```c
#include <stdio.h>

#define print_val(x) _Generic((x), \
    int: print_int,                 \
    double: print_double,           \
    char *: print_string,           \
    const char *: print_string      \
)(x)

void print_int(int x) { printf("%d\n", x); }
void print_double(double x) { printf("%.2f\n", x); }
void print_string(const char *x) { printf("%s\n", x); }
```

- Type selection happens at compile time
- Unlike a runtime `switch`, the selection depends on a *type*
- Useful for type-aware interfaces and macros

---

# `_Generic` in Action

```c
int main(void) {
    print_val(42);
    print_val(3.14);
    print_val("hello");
}
```

**Discussion:** What happens if we pass a `float` or `long`?

- Only listed types are supported here
- A `default:` association can provide a fallback
- `print_val(x)` evaluates `x` once in this implementation

---

# Preprocessor: Stringification and Logging

```c
#include <stdio.h>

#define LOG(level, ...) do {                       \
    fprintf(stderr, "[%s] ", #level);              \
    fprintf(stderr, __VA_ARGS__);                  \
    fputc('\n', stderr);                           \
} while (0)

LOG(INFO, "loaded %d records", 42);
```

- `#level` converts a macro argument into a string
- `##` pastes tokens together to form a new token
- Variadic macros accept a variable number of arguments

---

# Conditional Compilation

```c
#ifdef DEBUG
    #define DBG(msg) fprintf(stderr, "DBG: %s\n", msg)
#else
    #define DBG(msg) ((void)0)
#endif
```

```bash
cc -std=c23 -DDEBUG main.c -o app_debug
cc -std=c23 main.c -o app
```

- `#ifdef` / `#ifndef` enable conditional compilation
- Include guards prevent duplicate header declarations
- `-DDEBUG` defines a macro at compile time

---

# Compile-Time Assertions and `typeof`

```c
static_assert(sizeof(int) >= 4,
              "int must be at least 32 bits");

#define SWAP(a, b) do {  \
    typeof(a) tmp = (a); \
    (a) = (b);           \
    (b) = tmp;           \
} while (0)
```

- `static_assert` catches violated assumptions at compile time
- `typeof` (standardized in C23) obtains a type from an expression
- `SWAP` assumes compatible, modifiable operands; it is not universally safe

---

# Modern C Habits

- Use `const` for read-only access
- Use `size_t` for object sizes and array indices
- Initialize variables and check function results
- Prefer bounded formatting with `snprintf` over `sprintf`
- Avoid `gets` and unbounded copies; check destination capacity
- Compile with `-std=c23 -Wall -Wextra -Wpedantic`
- Treat warnings as problems worth investigating

---

# Performance: Start with the Algorithm

```c
#include <stddef.h>

long long sum(const int *a, size_t n) {
    long long total = 0;
    for (size_t i = 0; i < n; ++i) {
        total += a[i];
    }
    return total;
}
```

- This loop takes **O(n)** time
- Algorithm choice usually matters more than micro-optimizations
- Avoid redundant computation inside loops
- Assumes the accumulated sum fits in `long long`

---

# Memory Access and Cache Locality

- Contiguous arrays make sequential access efficient
- Jumping around memory can cause more cache misses
- Data layout and iteration order matter

**Question:** In a row-major 2D C array, which loop order walks adjacent elements?

```c
for (size_t row = 0; row < rows; ++row)
    for (size_t col = 0; col < cols; ++col)
        use(a[row][col]);
```

---

# Compiler Optimization Flags

```bash
# Easier to debug
cc -std=c23 -O0 -g -o app_debug main.c

# Optimized build
cc -std=c23 -O2 -o app_fast main.c

# GCC/gprof instrumentation
gcc -std=c23 -O2 -pg -o app_profile main.c
```

| Flag | Purpose |
| --- | --- |
| `-O0` | Minimal optimization |
| `-O2` | Common performance optimizations |
| `-g` | Debug information |
| `-pg` | Profiling instrumentation (GCC/gprof) |

---

# Measure Before Optimizing

```bash
/usr/bin/time ./app_debug
/usr/bin/time ./app_fast

# With GCC's -pg build:
./app_profile
gprof ./app_profile gmon.out
```

- Run multiple times; compare equivalent workloads
- Watch out for very short runs and noisy measurements
- Profile to locate bottlenecks instead of guessing
- Correctness still matters more than speed

---

# Day 1 — Hands-On (20 min)

1. Write a `_Generic` macro that handles `int`, `double`, and `float`.
2. Add a `static_assert` for a compile-time assumption.
3. Add debug-only logging with `#ifdef DEBUG`.
4. Build the same program with `-O0` and `-O2`, then compare runtime.

**Wrap-up:** What did the compiler do for us, and what did we have to measure?

---

# Day 2 — Threads and Professional Practice

**75 minutes**

1. POSIX threads and shared memory — 25 min
2. Race conditions and mutexes — 20 min
3. Project organization, testing, and defensive C — 20 min
4. MIT Missing Semester Q&A — 10 min

---

# Concurrency vs. Parallelism

- **Thread:** unit of execution sharing a process's address space
- **Concurrency:** tasks can make progress over overlapping periods
- **Parallelism:** tasks execute simultaneously on separate cores
- **pthreads:** common POSIX threading API

```c
#include <pthread.h>
```

```bash
cc -std=c23 -pthread threads.c -o threads
```

---

# Creating and Joining a Thread

```c
#include <pthread.h>
#include <stdio.h>

void *worker(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d running\n", id);
    return NULL;
}

int main(void) {
    pthread_t thread;
    int id = 1;
    if (pthread_create(&thread, NULL, worker, &id) != 0)
        return 1;
    if (pthread_join(thread, NULL) != 0)
        return 1;
}
```

- `pthread_create` starts a thread
- `pthread_join` waits for completion
- The `id` variable remains alive until the thread finishes

---

# Shared Memory and Data Races

```c
static int counter = 0;

void *increment(void *arg) {
    (void)arg;
    for (int i = 0; i < 1000000; ++i)
        counter++;
    return NULL;
}
```

**If two threads execute this concurrently, what is the final count?**

- `counter++` is a read-modify-write operation, not automatically atomic
- Unsynchronized concurrent writes cause a **data race**
- In C, a data race is **undefined behavior**; don't rely on a particular result

---

# Mutexes Protect Critical Sections

```c
static int counter = 0;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *arg) {
    (void)arg;
    for (int i = 0; i < 1000000; ++i) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
```

- Only one thread can hold the mutex at a time
- Protect *every* conflicting access to the shared value
- Mutexes prevent this race, but locking has overhead

---

# Threading Exercise

1. Create two threads that each increment a shared counter one million times.
2. Join both threads before reading the result.
3. Identify the data race in the unsynchronized version.
4. Add a mutex and verify the final count is 2,000,000.
5. Compare runtimes; discuss why synchronization costs time.

**Optional:** Run the unsafe version with ThreadSanitizer (`-fsanitize=thread`) if supported by your toolchain.

---

# Organizing a C Project

```text
project/
├── src/          # .c implementations
├── include/      # .h interfaces
├── tests/        # test programs
├── Makefile      # reproducible builds
└── README.md     # usage and documentation
```

- Separate public interfaces from implementations
- Use include guards in headers
- Make builds repeatable with a build script or Makefile
- Keep modules focused and dependencies explicit

---

# Documentation and Testing

```c
/**
 * Compute the mean of an integer array.
 * @param arr Non-NULL pointer to n integers.
 * @param n Number of elements; must be greater than zero.
 * @return Arithmetic mean, or -1.0 on invalid input.
 */
double average(const int *arr, size_t n);
```

- Unit tests exercise individual functions
- Integration tests exercise complete workflows
- Test normal cases and edge cases: `NULL`, zero length, boundaries, overflow
- Document preconditions and failure behavior clearly

---

# Defensive C Checklist

- [ ] Validate inputs and array bounds
- [ ] Check pointers before dereferencing when `NULL` is possible
- [ ] Check `malloc`, `fopen`, and other failure-prone calls
- [ ] Release owned resources on every exit path
- [ ] Avoid unsafe or unbounded string operations
- [ ] Check thread and synchronization API results
- [ ] Test error paths, not only successful ones

---

# Professional Workflow — Mini Exercise

Take a single-file C program and:

1. Split the interface into `.h` and implementation into `.c`.
2. Add a `Makefile` with `all`, `test`, and `clean` targets.
3. Write one test for a normal case and one edge case.
4. Add a documentation comment to a public function.

**Goal:** A classmate should be able to clone, build, and test it.

---

# MIT Missing Semester — Open Q&A

Possible topics:

- Git branches, pull requests, and `.gitignore`
- GDB watchpoints and conditional breakpoints
- Make vs. CMake
- Shell scripts for compile-test cycles
- Writing a useful README and documenting code

**What part of your development workflow still feels unnecessarily difficult?**

---

# Week 14 Review

- `_Generic`, `typeof`, and `static_assert` extend what we can express at compile time
- Good algorithms and memory access patterns matter for performance
- `-O2` optimizes; profiling tells us *where* time goes
- Threads share memory, so unsynchronized access can be dangerous
- Mutexes protect critical sections
- Tests, documentation, and repeatable builds make programs maintainable

---

# Homework and Next Week

**Original Week 14 assignments:**

- HW27: generic selections, profiling, threads, and mutexes — originally due Nov 18
- HW28: optimization, thread-safe counter, profiling, and development practices — originally due Nov 20

**Week 15:** comprehensive review, integrated programming challenges, and final preparation.

*Confirm assignment deadlines in the course LMS; dates above are from the source deck.*

---

# Questions?

- What remains unclear?
- What would be useful to demonstrate live?
- Which topics should we revisit before the final?
