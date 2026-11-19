---
title: "CS 1380 — Macro Shenanigans"
sub_title: "Token substitution, sharp edges, and compile-time tricks"
author: "CS 1380 — Modern Programming Essentials"
theme:
  name: dark
---

# Macro Shenanigans

**C's preprocessor is not the C compiler.**

- Macros operate on *preprocessing tokens*
- Expansion happens before normal C type checking
- Powerful? Yes. Safe by default? Absolutely not.

---

# 1. Function-like macros

```c
#define SQUARE(x) ((x) * (x))

int result = SQUARE(5 + 3);
// ((5 + 3) * (5 + 3))
```

- `x` is a macro *parameter*, not a C variable
- `5 + 3` is the argument's token sequence
- The preprocessor substitutes tokens, then rescans

---

# 2. Parentheses matter

```c
#define BAD_SQUARE(x) x * x

int n = BAD_SQUARE(5 + 3);
// 5 + 3 * 5 + 3 == 23
```

```c
#define SQUARE(x) ((x) * (x))
// ((5 + 3) * (5 + 3)) == 64
```

**Rule:** Parenthesize parameter uses *and* the complete expression.

---

# 3. The repeated-evaluation trap

```c
#define SQUARE(x) ((x) * (x))

int i = 5;
int n = SQUARE(i++);
// ((i++) * (i++)) — undefined behavior!
```

- An argument can appear more than once after expansion
- Side effects can happen multiple times
- Prefer a real function when you can

```c
static inline int square(int x) { return x * x; }
```

---

# 4. `#` stringification

```c
#define STRINGIFY(x) #x

puts(STRINGIFY(hello world)); // "hello world"
```

`#` turns an argument's spelling into a string literal.

```c
#define VALUE 42
STRINGIFY(VALUE)  // "VALUE", not "42"
```

**Why?** Arguments adjacent to `#` aren't macro-expanded first.

---

# 5. Force expansion with indirection

```c
#define VALUE 42
#define STR_IMPL(x) #x
#define STR(x) STR_IMPL(x)

STR(VALUE) // "42"
```

- `STR` expands `VALUE` before forwarding it
- `STR_IMPL` stringifies the resulting `42`

**Discussion:** Why doesn't `STRINGIFY(VALUE)` do the same thing?

---

# 6. `##` token pasting

```c
#define FIELD(name) field_##name

int FIELD(count) = 10;
// int field_count = 10;
```

- Joins tokens into **one preprocessing token**
- Not runtime string concatenation
- The pasted result must be a valid preprocessing token

---

# 7. Multistatement macro disaster

```c
#define PRINT_BOTH(a, b) \
    printf("%d\n", a);   \
    printf("%d\n", b)

if (ready)
    PRINT_BOTH(1, 2);
```

The second `printf` is **outside** the `if`!

---

# 8. The `do { } while (0)` pattern

```c
#define PRINT_BOTH(a, b) do { \
    printf("%d\n", (a));      \
    printf("%d\n", (b));      \
} while (0)

if (ready)
    PRINT_BOTH(1, 2);
else
    puts("not ready");
```

Behaves as one statement; the caller supplies the semicolon.

**Still beware:** `a` and `b` may have side effects.

---

# 9. Macros have no C scope

```c
#define SIZE 100

struct Thing {
    int SIZE;
};
```

After preprocessing:

```c
struct Thing {
    int 100; // syntax error
};
```

- Definitions apply from their point of definition onward
- `#undef SIZE` stops later replacement
- Prefer distinctive macro names and narrow exposure

---

# 10. `_Generic` is a compiler feature

```c
#define cube_root(x) _Generic((x), \
    float: cbrtf,                  \
    long double: cbrtl,            \
    default: cbrt                  \
)(x)
```

- Macro expansion builds a C expression
- The **compiler** selects a function by type
- The controlling expression `(x)` is **not evaluated**
- The final `(x)` calls the selected function once

`_Generic` arrived in **C11**, not C23.

---

# 11. Peek behind the curtain

```bash
clang -std=c23 -E example.c
```

- `-E`: preprocess only; don't compile
- Inspect what the compiler actually receives
- For cleaner output, try `-E -P`

**Live demo:** Expand `BAD_SQUARE(5 + 3)` and `STR(VALUE)`.

---

# 12. Mini challenge

Predict the expansion or behavior:

```c
#define DOUBLE(x) ((x) + (x))
#define LABEL(x) #x
#define JOIN(a, b) a##b
#define ANSWER 42

DOUBLE(2 + 3)
LABEL(ANSWER)
JOIN(my, _var)
```

**Bonus:** What happens with `DOUBLE(i++)`?

---

# Takeaways

- Macros substitute **tokens**, not typed values
- Parenthesize expressions; avoid repeated side effects
- `#` stringifies; `##` pastes tokens
- Indirection changes when arguments expand
- Use `do { } while (0)` for statement macros
- Reach for `static inline` functions when macros aren't needed

**Rule of thumb:** If it can be a function, make it a function.
