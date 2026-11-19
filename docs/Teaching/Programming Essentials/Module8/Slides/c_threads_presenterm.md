---
title: "Multithreading in C23"
sub_title: "Threads, races, mutexes, and atomics"
author: "CS 1380 — Modern Programming Essentials"
theme:
  name: dark
---

# Multithreading in C

- **Concurrency:** multiple tasks make progress over overlapping time.
- **Parallelism:** tasks execute simultaneously on multiple cores.
- Threads share a process's address space, but each has its own stack.
- C11 introduced `<threads.h>`; C23 retains it.

---

# C vs. C++: Same ideas, less machinery

| C (`<threads.h>`) | C++ | Role |
|---|---|---|
| `thrd_t` | `std::thread` | Thread handle |
| `thrd_create` | `std::thread(...)` | Start |
| `thrd_join` | `.join()` | Wait |
| `mtx_t` | `std::mutex` | Lock |
| `atomic_int` | `std::atomic<int>` | Atomic value |

- C thread entry point: `int worker(void *arg)`.
- No RAII: explicitly initialize, lock/unlock, and destroy resources.

---

# First thread: start and join

```c
#include <stdio.h>
#include <threads.h>

//multithreaded function
int worker(void *arg) {
    int id = *(int *)arg;
    printf("Hello from worker %d\n", id);
    return 0;
}

int main(void) {
    thrd_t thread;
    int id = 1;
    //c vs cpp jobs
    if (thrd_create(&thread, worker, &id) != thrd_success)
        return 1;
    int result;
    thrd_join(thread, &result);
}
```

`&id` must remain valid until the worker is done. `join` waits for completion.

---

# The race: two threads, one counter

```c
#include <stdio.h>
#include <threads.h>

#define ITERATIONS 1000000
int counter = 0;

int increment(void *unused) {
    (void)unused;
    for (int i = 0; i < ITERATIONS; ++i)
        counter++; // DATA RACE: undefined behavior!
    return 0;
}

int main(void) {
    thrd_t a, b;
    if (thrd_create(&a, increment, NULL) != thrd_success)
        return 1;
    if (thrd_create(&b, increment, NULL) != thrd_success) {
        thrd_join(a, NULL);
        return 1;
    }
    thrd_join(a, NULL);
    thrd_join(b, NULL);
    printf("Expected: %d; actual: %d\n", 2 * ITERATIONS, counter);
}
```

**Do not rely on a particular wrong result.** A C data race is *undefined behavior*, not merely a lost update.

---

# Why `counter++` isn't safe

Conceptually, incrementing involves:

1. Read the old value.
2. Add one.
3. Write the new value.

Two threads can read the same old value and both write the same new value.

```text
          Thread A           Thread B
          read 10            read 10
          add 1              add 1
          write 11           write 11

          Two increments, but counter = 11
```

- Thread scheduling is nondeterministic.
- `volatile` does **not** fix synchronization or atomicity.

---

# Fix 1: mutex (mutual exclusion)

```c
#include <threads.h>

int counter = 0;
mtx_t lock;

int increment(void *unused) {
    (void)unused;
    for (int i = 0; i < ITERATIONS; ++i) {
        mtx_lock(&lock);
        counter++;
        mtx_unlock(&lock);
    }
    return 0;
}
```

In `main`, before creating workers:

```c
if (mtx_init(&lock, mtx_plain) != thrd_success)
    return 1;
// Create both threads; join both threads.
mtx_destroy(&lock);
```

Only one thread may hold this mutex at a time. **All** accesses to protected shared state must follow the same locking discipline.

---

# Fix 2: atomic integer

```c
#include <stdatomic.h>
#include <threads.h>

#define ITERATIONS 1000000
atomic_int counter = 0;

int increment(void *unused) {
    (void)unused;
    for (int i = 0; i < ITERATIONS; ++i)
        atomic_fetch_add(&counter, 1);
    return 0;
}
```

- `atomic_fetch_add` performs an indivisible read-modify-write.
- `atomic_load(&counter)` safely reads the result.
- Default atomic operations use sequentially consistent ordering.
- Atomics are excellent for simple counters; a mutex is easier for protecting *multiple related fields*.

---

# Build, test, and discuss

```sh
cc -std=c23 -Wall -Wextra -pthread race.c -o race
./race
```

If your compiler uses the older spelling, use `-std=c2x`.

**Class experiment:**

1. Run the unsafe version repeatedly. Does the output change?
2. Replace `int counter` with `atomic_int` and use `atomic_fetch_add`.
3. Compare with a mutex-protected counter.
4. Why isn't `volatile int counter` sufficient?

**Takeaway:** Threads share memory; shared mutable state requires synchronization. `join` waits for completion, but does not make concurrent increments safe.
