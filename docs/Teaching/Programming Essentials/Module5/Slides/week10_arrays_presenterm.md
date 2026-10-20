---
title: "CS 1380 — Week 10: Arrays"
sub_title: "Two lectures | Arrays, operations, and debugging"
author: "CS 1380"
theme:
  name: dark
options:
  end_slide_shorthand: true
---

# Week 10 — Arrays and Array Manipulation

**Two-day lecture plan**

- Day 1: Fundamentals and memory layout
- Day 2: Operations, safety, and debugging

---

# Day 1 — Arrays and Memory

**50 minutes**

1. What arrays are; declaration and indexing (15 min)
2. `sizeof`, pointers, and memory layout (15 min)
3. 2D arrays and hands-on exercise (20 min)

---

# Why arrays?

We already know how to store one score:

```c
int score = 95;
```

What if we need **30 scores**?

```c
int scores[30];
```

One variable name, many elements of the **same type**.

---

# Declaring and initializing

```c
int a[5];                    // uninitialized local array
int b[5] = {1, 2, 3, 4, 5}; // fully initialized
int c[] = {10, 20, 30};     // size inferred
int d[5] = {1, 2};          // remaining elements are 0
int e[5] = {0};             // all elements are 0
```

- A local array without an initializer contains indeterminate values.
- Arrays have a fixed extent once created.
- For dynamically chosen heap capacity, recall `malloc`.

---

# Indexing starts at zero

```c
int hp[5] = {10, 20, 30, 40, 50};

printf("First: %d\n", hp[0]);
printf("Last:  %d\n", hp[4]);

hp[2] = 300;
```

Valid indices for an array of 5 elements: **0 through 4**.

`hp[5]` is out of bounds: **undefined behavior**.

---

# Walking through an array

```c
int hp[] = {10, 20, 30, 40, 50};

for (int i = 0; i < 5; i++) {
    printf("hp[%d] = %d\n", i, hp[i]);
}
```

**Ask:** Why is the condition `i < 5` rather than `i <= 5`?

---

# How many elements?

```c
int scores[] = {95, 80, 75, 100};

size_t count = sizeof(scores) / sizeof(scores[0]);
printf("%zu elements\n", count);
```

- `sizeof(scores)` measures the whole array **in bytes**.
- `sizeof(scores[0])` measures one element **in bytes**.
- Dividing gives the element count.

**Important:** This works where `scores` is an actual array, not an array parameter that has become a pointer.

---

# Arrays live in contiguous memory

```c
int values[] = {10, 20, 30, 40, 50};

for (size_t i = 0; i < 5; i++) {
    printf("%zu: %d at %p\n",
           i, values[i], (void *)&values[i]);
}
```

Each element follows the previous element in memory.

**Connect to pointers:** `&values[i + 1]` advances by one `int`.

---

# Arrays and pointers: related, not identical

```c
int values[] = {10, 20, 30};
int *p = values;

printf("%d\n", values[1]);
printf("%d\n", *(p + 1));
```

Both access the second element.

- An array is **not** a pointer variable.
- In most expressions, an array expression converts to a pointer to its first element.
- `sizeof(values)` and `sizeof(p)` mean different things.

---

# Passing arrays to functions

```c
void print_scores(const int scores[], size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%d\n", scores[i]);
    }
}
```

```c
int scores[] = {90, 85, 100};
size_t count = sizeof(scores) / sizeof(scores[0]);
print_scores(scores, count);
```

The function **must receive the length separately**.

---

# Checking bounds

```c
bool valid_index(size_t size, size_t index) {
    return index < size;
}
```

```c
if (valid_index(count, requested_index)) {
    printf("%d\n", scores[requested_index]);
} else {
    fprintf(stderr, "Invalid index\n");
}
```

Validate signed user input **before** converting it to `size_t`.

---

# Two-dimensional arrays

```c
int grid[3][4] = {
    { 1,  2,  3,  4},
    { 5,  6,  7,  8},
    { 9, 10, 11, 12}
};

printf("%d\n", grid[2][3]); // 12
```

Think **rows and columns**: `grid[row][column]`.

C stores this 2D array contiguously, **row by row**.

---

# Nested loops over a grid

```c
for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 4; col++) {
        printf("%3d ", grid[row][col]);
    }
    printf("\n");
}
```

**Ask:** Which loop should advance to print one complete row?

---

# Day 1 — Live coding (15–20 min)

**Exercise A: Scoreboard**

- Declare five integer scores.
- Compute and print their sum and average.
- Use `sizeof` to calculate the count.

**Exercise B: Mini-map**

- Declare a `3 x 3` integer grid initialized to zero.
- Set the diagonal elements to `1`.
- Print the grid using nested loops.

---

# Day 1 — Review

- Arrays hold fixed numbers of same-type elements.
- Indices range from `0` to `count - 1`.
- Elements are contiguous in memory.
- `sizeof(array) / sizeof(array[0])` works on actual arrays.
- Multidimensional arrays use multiple indices and nested loops.

**Next class:** searching, sorting, and tracking down array bugs.

---

# Day 2 — Operations and Debugging

**50 minutes**

1. Traversal and searching (15 min)
2. Sorting and bounds safety (15 min)
3. GDB walkthrough and debugging exercise (20 min)

---

# Three ways to traverse

```c
int arr[] = {10, 20, 30, 40, 50};
size_t n = sizeof(arr) / sizeof(arr[0]);

for (size_t i = 0; i < n; i++)
    printf("%d ", arr[i]);

for (size_t i = n; i > 0; i--)
    printf("%d ", arr[i - 1]);

for (int *p = arr; p < arr + n; p++)
    printf("%d ", *p);
```

Forward, backward, and pointer-based traversal.

---

# Linear search

```c
int linear_search(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}
```

- Works on **unsorted** arrays.
- Returns the first matching index, or `-1`.
- Worst case: inspect every element — **O(n)**.

---

# Counting occurrences

```c
int count_value(const int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            count++;
    }
    return count;
}
```

**Try:** How many `2`s occur in `{5, 2, 8, 2, 1}`?

Why can't we return as soon as we find the first match?

---

# Binary search — sorted input only

```c
int binary_search(const int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

Eliminate half the search space each step: **O(log n)**.

---

# Comparing search methods

| Method | Input requirement | Worst-case time |
|---|---|---|
| Linear search | Any array | O(n) |
| Binary search | Sorted array | O(log n) |

**Ask:** Is binary search useful if we first need to sort a tiny array for just one lookup?

---

# Bubble sort: compare neighbors

```c
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
```

Easy to trace; worst-case **O(n²)**.

---

# Walk through one pass

Start with:

```text
5  2  8  2  1
```

Compare neighbors and swap whenever left > right:

```text
2  5  8  2  1
2  5  8  2  1
2  5  2  8  1
2  5  2  1  8
```

The largest element has moved to the end.

---

# Other useful array operations

```c
int sum_array(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}
```

Finding min/max is also one pass: initialize from `arr[0]`, then compare each remaining element.

**Precondition:** The array must have at least one element before reading `arr[0]`.

---

# Array safety

```c
void safe_set(int arr[], int size, int index, int value) {
    if (index < 0 || index >= size) {
        fprintf(stderr, "Invalid index: %d\n", index);
        return;
    }
    arr[index] = value;
}
```

- Never trust unchecked indices.
- Pass array lengths to functions.
- Arrays do not automatically grow.
- Out-of-bounds access is undefined behavior, not a guaranteed crash.

---

# Compile for debugging

```bash
gcc -std=c23 -Wall -Wextra -g -O0 -o program program.c
gdb ./program
```

- `-g`: include debugging information.
- `-O0`: avoid optimization during introductory debugging.
- `-Wall -Wextra`: enable useful warnings.

---

# GDB — first commands

```text
(gdb) break main
(gdb) run
(gdb) next
(gdb) step
(gdb) print i
(gdb) print arr[3]
(gdb) continue
(gdb) backtrace
```

`next` steps **over** calls; `step` steps **into** calls.

---

# GDB — inspecting arrays

```text
(gdb) print arr
(gdb) print *arr@5
(gdb) x/5dw arr
(gdb) watch arr[0]
```

- `*arr@5`: display five elements starting at `arr`.
- `x/5dw arr`: examine five decimal words of memory.
- `watch`: stop when a watched value changes.

**Caution:** Only inspect memory known to be valid.

---

# Debugging challenge

```c
#include <stdio.h>

int main(void) {
    int arr[] = {4, 8, 15, 16, 23};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <= size; i++) {
        printf("%d\n", arr[i]);
    }
}
```

**Find the bug before running it.**

---

# Debugging challenge — walkthrough

1. Compile with `-g -O0`.
2. Set a breakpoint on the loop.
3. Inspect `i`, `size`, and valid elements.
4. Step until `i == size`.
5. Explain why `arr[size]` is invalid.
6. Fix the loop condition and run again.

**Bonus:** Try `-fsanitize=address,undefined` when compiling.

---

# Memory debugging beyond GDB

```bash
valgrind --leak-check=full ./program
```

- GDB: follow control flow and inspect program state.
- Valgrind: detect many invalid memory accesses and leaks.
- AddressSanitizer: catch many memory errors during instrumented runs.

Especially useful when revisiting dynamically allocated arrays from last week.

---

# Day 2 — Hands-on (remaining time)

Given `{5, 2, 8, 2, 1}`:

1. Linear-search for `8`.
2. Count occurrences of `2`.
3. Sort using bubble sort.
4. Binary-search the sorted array for `8`.
5. Add an invalid-index test and confirm the guard catches it.

---

# Week 10 — Review

- Index from `0` to `size - 1`.
- Linear search: **O(n)**.
- Binary search: **O(log n)**, requires sorted input.
- Bubble sort: **O(n²)**.
- Guard all potentially invalid indices.
- Debug with `-g`, breakpoints, and array inspection.

**Coming next:** Strings and string functions.
