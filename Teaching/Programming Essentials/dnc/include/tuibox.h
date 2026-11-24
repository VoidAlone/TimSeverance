/*
 * tuibox.h: simple tui library
 */

#ifndef TUIBOX_H
#define TUIBOX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>

/** BEGIN vec.h **/

/** 
 * Copyright (c) 2014 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See LICENSE for details.
 */

#ifndef VEC_H
#define VEC_H

#include <stdlib.h>
#include <string.h>

/** @brief Version string for the embedded dynamic-vector implementation. */
#define VEC_VERSION "0.2.1"


#define vec_unpack_(v)\
  (char**)&(v)->data, &(v)->length, &(v)->capacity, sizeof(*(v)->data)


/**
 * @brief Declares an anonymous dynamic-vector type for elements of type @p T.
 *
 * The resulting struct owns its @c data allocation. Initialize it with
 * vec_init() before use and release it with vec_deinit().
 *
 * @param T Element type stored by the vector.
 */
#define vec_t(T)\
  struct { T *data; int length, capacity; }


/**
 * @brief Initializes a vector to an empty state.
 *
 * This does not release existing storage; use it only for fresh or already
 * deinitialized vectors.
 *
 * @param v Pointer to the vector object.
 */
#define vec_init(v)\
  memset((v), 0, sizeof(*(v)))


/**
 * @brief Releases a vector's element storage and resets it to empty.
 *
 * This releases only the backing array, not resources owned by individual
 * elements.
 *
 * @param v Pointer to an initialized vector.
 * @see vec_init()
 */
#define vec_deinit(v)\
  ( free((v)->data),\
    vec_init(v) ) 


/**
 * @brief Appends one element to a vector.
 *
 * @param v Pointer to the vector.
 * @param val Element value to append.
 * @return 0. Allocation failure is not reliably propagated by this macro.
 */
#define vec_push(v, val)\
  ( vec_expand_(vec_unpack_(v)) ? -1 :\
    ((v)->data[(v)->length++] = (val), 0), 0 )


/**
 * @brief Removes and returns the final element of a nonempty vector.
 *
 * @param v Pointer to the vector.
 * @return The removed element.
 */
#define vec_pop(v)\
  (v)->data[--(v)->length]


/**
 * @brief Removes a contiguous range while preserving subsequent order.
 *
 * @param v Pointer to the vector.
 * @param start Index of the first element to remove.
 * @param count Number of elements to remove.
 */
#define vec_splice(v, start, count)\
  ( vec_splice_(vec_unpack_(v), start, count),\
    (v)->length -= (count) )


/**
 * @brief Removes a range by replacing it with elements from the vector end.
 *
 * This is more efficient than vec_splice() but does not preserve element
 * order.
 *
 * @param v Pointer to the vector.
 * @param start Index of the first element to remove.
 * @param count Number of elements to remove.
 */
#define vec_swapsplice(v, start, count)\
  ( vec_swapsplice_(vec_unpack_(v), start, count),\
    (v)->length -= (count) )


/**
 * @brief Inserts an element at an index, shifting later elements right.
 *
 * @param v Pointer to the vector.
 * @param idx Insertion index from 0 through the current length.
 * @param val Element value to insert.
 * @return 0. Allocation failure is not reliably propagated by this macro.
 */
#define vec_insert(v, idx, val)\
  ( vec_insert_(vec_unpack_(v), idx) ? -1 :\
    ((v)->data[idx] = (val), 0), (v)->length++, 0 )
    

/**
 * @brief Sorts vector elements using a qsort-compatible comparator.
 *
 * @param v Pointer to the vector.
 * @param fn Comparison function passed to qsort().
 */
#define vec_sort(v, fn)\
  qsort((v)->data, (v)->length, sizeof(*(v)->data), fn)


/**
 * @brief Exchanges two vector elements.
 *
 * @param v Pointer to the vector.
 * @param idx1 Index of the first element.
 * @param idx2 Index of the second element.
 */
#define vec_swap(v, idx1, idx2)\
  vec_swap_(vec_unpack_(v), idx1, idx2)


/**
 * @brief Shortens a vector without releasing its storage.
 *
 * @param v Pointer to the vector.
 * @param len Maximum number of elements to retain.
 */
#define vec_truncate(v, len)\
  ((v)->length = (len) < (v)->length ? (len) : (v)->length)


/**
 * @brief Removes all elements without releasing vector storage.
 *
 * @param v Pointer to the vector.
 */
#define vec_clear(v)\
  ((v)->length = 0)


/**
 * @brief Returns the first element of a nonempty vector.
 *
 * @param v Pointer to the vector.
 * @return The first element.
 */
#define vec_first(v)\
  (v)->data[0]


/**
 * @brief Returns the last element of a nonempty vector.
 *
 * @param v Pointer to the vector.
 * @return The last element.
 */
#define vec_last(v)\
  (v)->data[(v)->length - 1]


/**
 * @brief Ensures capacity for at least a requested number of elements.
 *
 * @param v Pointer to the vector.
 * @param n Minimum element capacity.
 * @return 0 on success or -1 if allocation fails.
 */
#define vec_reserve(v, n)\
  vec_reserve_(vec_unpack_(v), n)

 
/**
 * @brief Shrinks a vector allocation to its current length.
 *
 * @param v Pointer to the vector.
 * @return 0 on success or -1 if shrinking allocation fails.
 */
#define vec_compact(v)\
  vec_compact_(vec_unpack_(v))


/**
 * @brief Appends elements from a contiguous array.
 *
 * @param v Pointer to the vector.
 * @param arr Source array of elements.
 * @param count Number of source elements to append.
 */
#define vec_pusharr(v, arr, count)\
  do {\
    int i__, n__ = (count);\
    if (vec_reserve_po2_(vec_unpack_(v), (v)->length + n__) != 0) break;\
    for (i__ = 0; i__ < n__; i__++) {\
      (v)->data[(v)->length++] = (arr)[i__];\
    }\
  } while (0)


/**
 * @brief Appends every element of one vector to another.
 *
 * @param v Destination vector.
 * @param v2 Source vector.
 */
#define vec_extend(v, v2)\
  vec_pusharr((v), (v2)->data, (v2)->length)


/**
 * @brief Finds the first element equal to a value.
 *
 * @param v Pointer to the vector.
 * @param val Value compared with @c ==.
 * @param idx Output variable set to the matching index or -1.
 */
#define vec_find(v, val, idx)\
  do {\
    for ((idx) = 0; (idx) < (v)->length; (idx)++) {\
      if ((v)->data[(idx)] == (val)) break;\
    }\
    if ((idx) == (v)->length) (idx) = -1;\
  } while (0)


/**
 * @brief Removes the first element equal to a value.
 *
 * @param v Pointer to the vector.
 * @param val Value compared with @c ==.
 */
#define vec_remove(v, val)\
  do {\
    int idx__;\
    vec_find(v, val, idx__);\
    if (idx__ != -1) vec_splice(v, idx__, 1);\
  } while (0)


/**
 * @brief Reverses the order of all vector elements in place.
 *
 * @param v Pointer to the vector.
 */
#define vec_reverse(v)\
  do {\
    int i__ = (v)->length / 2;\
    while (i__--) {\
      vec_swap((v), i__, (v)->length - (i__ + 1));\
    }\
  } while (0)


/**
 * @brief Iterates vector elements from first to last.
 *
 * @param v Pointer to the vector.
 * @param var Variable assigned each element value.
 * @param iter Integer loop-index variable.
 */
#define vec_foreach(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
        (iter) < (v)->length && (((var) = (v)->data[(iter)]), 1);\
        ++(iter))


/**
 * @brief Iterates vector elements from last to first.
 *
 * @param v Pointer to the vector.
 * @param var Variable assigned each element value.
 * @param iter Integer loop-index variable.
 */
#define vec_foreach_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
        (iter) >= 0 && (((var) = (v)->data[(iter)]), 1);\
        --(iter))


/**
 * @brief Iterates pointers to vector elements from first to last.
 *
 * @param v Pointer to the vector.
 * @param var Pointer variable assigned each element address.
 * @param iter Integer loop-index variable.
 */
#define vec_foreach_ptr(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = 0;\
        (iter) < (v)->length && (((var) = &(v)->data[(iter)]), 1);\
        ++(iter))


/**
 * @brief Iterates pointers to vector elements from last to first.
 *
 * @param v Pointer to the vector.
 * @param var Pointer variable assigned each element address.
 * @param iter Integer loop-index variable.
 */
#define vec_foreach_ptr_rev(v, var, iter)\
  if  ( (v)->length > 0 )\
  for ( (iter) = (v)->length - 1;\
        (iter) >= 0 && (((var) = &(v)->data[(iter)]), 1);\
        --(iter))



int vec_expand_(char **data, int *length, int *capacity, int memsz);
int vec_reserve_(char **data, int *length, int *capacity, int memsz, int n);
int vec_reserve_po2_(char **data, int *length, int *capacity, int memsz,
                     int n);
int vec_compact_(char **data, int *length, int *capacity, int memsz);
int vec_insert_(char **data, int *length, int *capacity, int memsz,
                int idx);
void vec_splice_(char **data, int *length, int *capacity, int memsz,
                 int start, int count);
void vec_swapsplice_(char **data, int *length, int *capacity, int memsz,
                     int start, int count);
void vec_swap_(char **data, int *length, int *capacity, int memsz,
               int idx1, int idx2);


/** @brief Dynamic vector whose elements are @c void pointers. */
typedef vec_t(void*) vec_void_t;
/** @brief Dynamic vector whose elements are C string pointers. */
typedef vec_t(char*) vec_str_t;
/** @brief Dynamic vector whose elements are integers. */
typedef vec_t(int) vec_int_t;
/** @brief Dynamic vector whose elements are characters. */
typedef vec_t(char) vec_char_t;
/** @brief Dynamic vector whose elements are single-precision values. */
typedef vec_t(float) vec_float_t;
/** @brief Dynamic vector whose elements are double-precision values. */
typedef vec_t(double) vec_double_t;

int vec_expand_(char **data, int *length, int *capacity, int memsz) {
  if (*length + 1 > *capacity) {
    void *ptr;
    int n = (*capacity == 0) ? 1 : *capacity << 1;
    ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *data = ptr;
    *capacity = n;
  }
  return 0;
}


int vec_reserve_(char **data, int *length, int *capacity, int memsz, int n) {
  (void) length;
  if (n > *capacity) {
    void *ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *data = ptr;
    *capacity = n;
  }
  return 0;
}


int vec_reserve_po2_(
  char **data, int *length, int *capacity, int memsz, int n
) {
  int n2 = 1;
  if (n == 0) return 0;
  while (n2 < n) n2 <<= 1;
  return vec_reserve_(data, length, capacity, memsz, n2);
}


int vec_compact_(char **data, int *length, int *capacity, int memsz) {
  if (*length == 0) {
    free(*data);
    *data = NULL;
    *capacity = 0;
    return 0;
  } else {
    void *ptr;
    int n = *length;
    ptr = realloc(*data, n * memsz);
    if (ptr == NULL) return -1;
    *capacity = n;
    *data = ptr;
  }
  return 0;
}


int vec_insert_(char **data, int *length, int *capacity, int memsz,
                 int idx
) {
  int err = vec_expand_(data, length, capacity, memsz);
  if (err) return err;
  memmove(*data + (idx + 1) * memsz,
          *data + idx * memsz,
          (*length - idx) * memsz);
  return 0;
}


void vec_splice_(char **data, int *length, int *capacity, int memsz,
                 int start, int count
) {
  (void) capacity;
  memmove(*data + start * memsz,
          *data + (start + count) * memsz,
          (*length - start - count) * memsz);
}


void vec_swapsplice_(char **data, int *length, int *capacity, int memsz,
                     int start, int count
) {
  (void) capacity;
  memmove(*data + start * memsz,
          *data + (*length - count) * memsz,
          count * memsz);
}


void vec_swap_(char **data, int *length, int *capacity, int memsz,
               int idx1, int idx2 
) {
  unsigned char *a, *b, tmp;
  int count;
  (void) length;
  (void) capacity;
  if (idx1 == idx2) return;
  a = (unsigned char*) *data + idx1 * memsz;
  b = (unsigned char*) *data + idx2 * memsz;
  count = memsz;
  while (count--) {
    tmp = *a;
    *a = *b;
    *b = tmp;
    a++, b++;
  }
}

#endif

/** END vec.h **/

/*
 * PREPROCESSOR
 */
/** @brief Initial byte capacity allocated for each box's rendered-text cache. */
#define MAXCACHESIZE 65535

#define CURSOR_Y(b) (b->y+(n+1)+(u->canscroll ? u->scroll : 0))

#define box_contains(x, y, b) (x >= b->x && x <= b->x + b->w && y >= b->y && y <= b->y + b->h)

/**
 * @brief Changes the active screen and requests a complete redraw.
 *
 * @param s Screen identifier to make active.
 * @param u Pointer to initialized UI state.
 * @see ui_draw()
 */
#define ui_screen(s, u) u->screen = s;u->force = 1

/**
 * @brief Calculates a horizontal coordinate that centers a width in the UI.
 *
 * @param w Width in terminal cells.
 * @param u Pointer to initialized UI state.
 * @return The calculated terminal-column coordinate.
 */
#define ui_center_x(w, u) (((u)->ws.ws_col - w) / 2)
/**
 * @brief Calculates a vertical coordinate that centers a height in the UI.
 *
 * @param h Height in terminal cells.
 * @param u Pointer to initialized UI state.
 * @return The calculated terminal-row coordinate.
 */
#define ui_center_y(h, u) (((u)->ws.ws_row - h) / 2)

/** @brief Special @c x value that centers a box horizontally when added. */
#define UI_CENTER_X -1
/** @brief Special @c y value that centers a box vertically when added. */
#define UI_CENTER_Y -1

/* The argument isn't actually necessary here, but it helps with design consistency */
/**
 * @brief Repeatedly reads terminal input from standard input.
 *
 * Use as @c ui_loop(ui) @c { ... }. The loop body can call ui_update() once
 * for each input buffer read. The @p u argument is not evaluated.
 *
 * @param u UI object, retained only for call-site consistency.
 * @see ui_update()
 */
#define ui_loop(u) char buf[64];int n;while((n=read(STDIN_FILENO, buf, sizeof(buf))) > 0)

/**
 * @brief Dispatches input read by the enclosing ui_loop().
 *
 * This macro requires the @c buf and @c n variables supplied by ui_loop().
 *
 * @param u Pointer to initialized UI state.
 * @see ui_loop()
 */
#define ui_update(u) _ui_update(buf, n, u)

/**
 * @brief Retrieves a registered box by its numeric identifier.
 *
 * Valid IDs are returned by ui_add() or ui_text(); this macro performs no
 * bounds checking.
 *
 * @param id Box identifier.
 * @param u Pointer to initialized UI state.
 * @return Pointer to the registered box.
 */
#define ui_get(id, u) ((u)->b.data[id])

#define COORDINATE_DECODE() \
  tok = strtok(NULL, ";"); \
  x = atoi(tok); \
  tok = strtok(NULL, ";"); \
  y = strtol(tok, NULL, 10) - (u->canscroll ? u->scroll : 0)

#define CLICK_COMPARATOR(x, y, tmp) \
  (u->click == tmp || \
   (box_contains(x, y, tmp) && u->click == NULL))

#define HOVER_COMPARATOR(x, y, tmp) \
  (box_contains(x, y, tmp))

#define LOOP_AND_EXECUTE(f, c) \
  do { \
    vec_foreach(&(u->b), tmp, ind){ \
      if(tmp->screen == u->screen && \
         f != NULL && \
         (c ? CLICK_COMPARATOR(x, y, tmp) : HOVER_COMPARATOR(x, y, tmp)) \
      ){ \
        f(tmp, x, y, u->mouse); \
        if(c){ \
          u->click = tmp; \
        } \
      } \
    } \
  } while(0)

/*
 * TYPES
 */
/**
 * @brief Generic callback pointer used by the UI registration functions.
 *
 * ui_add() expects effective draw and mouse-handler signatures described in
 * its documentation, while ui_key() handlers take no arguments.
 */
typedef void (*func)();

/**
 * @brief Registered rectangular UI element and its callback context.
 *
 * Instances are allocated and owned by a ui_t after ui_add() or ui_text().
 * Draw and mouse callbacks receive this object and may use @c data1 and
 * @c data2 as application-defined context.
 */
typedef struct ui_box_t {
  /** Numeric identifier assigned when the box is registered. */
  int id;
  /** Top-left position in terminal coordinates. */
  int x, y;
  /** Declared box dimensions in terminal cells. */
  int w, h;
  /** Screen identifier captured when the box is registered. */
  int screen;
  /** Library-owned cached rendering of the box. */
  char *cache;
  /** Optional application-owned byte used to detect redraws. */
  char *watch;
  /** Last watched byte value used for rendering. */
  char last;
  /** Rendering callback, effectively @c void(ui_box_t *, char *). */
  func draw;
  /** Click callback, effectively @c void(ui_box_t *, int, int, int). */
  func onclick;
  /** Hover callback, effectively @c void(ui_box_t *, int, int, int). */
  func onhover;
  /** First application-defined callback context pointer. */
  void *data1;
  /** Second application-defined callback context pointer. */
  void *data2;
} ui_box_t;

/** @brief Registered input-prefix handler owned by a ui_t. */
typedef struct ui_evt_t {
  /** Input prefix matched against a buffer read from standard input. */
  char *c;
  /** No-argument function invoked when the prefix matches. */
  func f;
} ui_evt_t;

/** @brief Dynamic vector of pointers to registered UI boxes. */
typedef vec_t(ui_box_t*) vec_box_t;
/** @brief Dynamic vector of pointers to registered key-event handlers. */
typedef vec_t(ui_evt_t*) vec_evt_t;

/**
 * @brief Mutable state for one terminal UI session.
 *
 * Initialize this object with ui_new() before using it and release it with
 * ui_free() before it goes out of scope. Its fields are exposed, but the
 * library manages their normal lifecycle.
 */
typedef struct ui_t {
  /** Terminal attributes captured by ui_new() for later restoration. */
  struct termios tio;
  /** Terminal dimensions captured when the UI is initialized; not refreshed on resize. */
  struct winsize ws;
  /** Registered boxes owned by this UI. */
  vec_box_t b;
  /** Registered key handlers owned by this UI. */
  vec_evt_t e;
  /** Box currently receiving a mouse click drag, if any. */
  ui_box_t *click;
  /** Nonzero while the last processed mouse event reports a pressed button. */
  int mouse;
  /** Current active screen identifier. */
  int screen;
  /** Vertical offset applied while scroll handling is enabled. */
  int scroll;
  /** Nonzero to process mouse-wheel events as scrolling. */
  int canscroll;
  /** Identifier assigned to the next registered box. */
  int id;
  /** Nonzero to refresh box renderings on the next draw. */
  int force;
} ui_t;

/* =========================== */

/**
 * @brief Initializes a terminal UI session.
 *
 * Captures terminal settings and dimensions, disables canonical input and
 * echo, enters the alternate screen, enables mouse reporting, and initializes
 * the UI's box and key-handler collections. Call ui_free() to restore the
 * terminal and release registered objects.
 *
 * @param s Initial active screen identifier.
 * @param u Storage for the UI state.
 * @see ui_free()
 */
void ui_new(int s, ui_t *u){
  struct termios raw;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &(u->ws));

  tcgetattr(STDIN_FILENO, &(u->tio));
  raw = u->tio;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

  vec_init(&(u->b));
  vec_init(&(u->e));

  u->click = NULL;

  printf("\x1b[?1049h\x1b[0m\x1b[2J\x1b[?1003h\x1b[?1015h\x1b[?1006h\x1b[?25l");

  u->mouse = 0;

  u->screen = s;
  u->scroll = 0;
  u->canscroll = 1;
  
  u->id = 0;

  u->force = 0;
}

/**
 * @brief Releases a UI session and restores terminal state.
 *
 * Frees boxes, their rendered-text caches, and registered key handlers.
 * Application-owned @c watch, @c data1, @c data2, and key-sequence pointers
 * are not freed. This function also leaves the alternate screen and disables
 * the mouse-reporting modes enabled by ui_new().
 *
 * @param u Pointer to an initialized UI state.
 * @see ui_new()
 */
void ui_free(ui_t *u){
  ui_box_t *val;
  ui_evt_t *evt;
  int i;
  char *term;

  printf("\x1b[0m\x1b[2J\x1b[?1049l\x1b[?1003l\x1b[?1015l\x1b[?1006l\x1b[?25h");
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &(u->tio));

  vec_foreach(&(u->b), val, i){
    free(val->cache);
    free(val);
  }
  vec_deinit(&(u->b));

  vec_foreach(&(u->e), evt, i){
    free(evt);
  }
  vec_deinit(&(u->e));

  term = getenv("TERM");
  if(strncmp(term, "screen", 6) == 0 ||
     strncmp(term, "tmux", 4) == 0){
    printf("Note: Terminal multiplexer detected.\n  For best performance (i.e. reduced flickering), running natively inside\n  a GPU-accelerated terminal such as alacritty or kitty is recommended.\n");
  }
}

/**
 * @brief Registers a rectangular element with rendering and mouse callbacks.
 *
 * The draw callback is called immediately to initialize the box cache and
 * subsequently when the box is drawn, unless a non-NULL watched byte has not
 * changed. It must write NUL-terminated text to @c out; newline-separated
 * lines are rendered on successive terminal rows. Mouse callbacks may be
 * NULL. Their effective signatures are @c void(ui_box_t *, int, int, int),
 * where the integer arguments are mouse x, mouse y, and button state.
 *
 * Although @p screen is accepted, this implementation assigns the box to the
 * UI's current screen. Use ui_screen() before registration to select it.
 * The caller retains ownership of @p watch, @p data1, and @p data2, which must
 * remain valid for as long as callbacks or redraw checks need them.
 *
 * @param x Left terminal coordinate, or UI_CENTER_X to center horizontally.
 * @param y Top terminal coordinate, or UI_CENTER_Y to center vertically.
 * @param w Declared box width in terminal cells.
 * @param h Declared box height in terminal cells.
 * @param screen Accepted screen identifier; current UI screen is used instead.
 * @param watch Optional byte whose change triggers a fresh rendering.
 * @param initial Initial value for the watched byte.
 * @param draw Required callback, effectively @c void(ui_box_t *, char *).
 * @param onclick Optional mouse-click callback.
 * @param onhover Optional mouse-hover callback.
 * @param data1 First application-defined pointer exposed through the box.
 * @param data2 Second application-defined pointer exposed through the box.
 * @param u Pointer to initialized UI state.
 * @return The assigned box identifier.
 * @see ui_text()
 * @see ui_get
 */
int ui_add(
  int x, int y, int w, int h, int screen,
  char *watch, char initial,
  func draw, func onclick, func onhover,
  void *data1, void *data2,
  ui_t *u
){
  ui_box_t *b = malloc(sizeof(ui_box_t));

  b->id = u->id++;

  b->x = (x == UI_CENTER_X ? ui_center_x(w, u) : x);
  b->y = (y == UI_CENTER_Y ? ui_center_y(h, u) : y);
  b->w = w;
  b->h = h;

  b->screen = u->screen;

  b->watch = watch;
  b->last = initial;

  b->draw = draw;
  b->onclick = onclick;
  b->onhover = onhover;

  b->data1 = data1;
  b->data2 = data2;

  b->cache = malloc(MAXCACHESIZE);
  draw(b, b->cache);
  b->cache = realloc(b->cache, strlen(b->cache) * 2);

  vec_push(&(u->b), b);

  return b->id;
}

/**
 * @brief Registers a handler for an input byte prefix.
 *
 * When a buffer processed by ui_update() begins with @p c, the no-argument
 * handler is invoked. The sequence pointer is retained, not copied, and must
 * remain valid until ui_free() or ui_clear().
 *
 * @param c Input prefix to match.
 * @param f No-argument callback to invoke on a match.
 * @param u Pointer to initialized UI state.
 * @see ui_update
 */
void ui_key(char *c, func f, ui_t *u){
  ui_evt_t *e = malloc(sizeof(ui_evt_t));
  e->c = c;
  e->f = f;

  vec_push(&(u->e), e);
}

/**
 * @brief Removes all registered boxes and key handlers, then reinitializes.
 *
 * The current screen identifier is retained. This performs the same terminal
 * teardown and setup effects as ui_free() followed by ui_new().
 *
 * @param u Pointer to initialized UI state.
 * @see ui_free()
 * @see ui_new()
 */
void ui_clear(ui_t *u){
  int tmp = u->screen;

  ui_free(u);
  ui_new(tmp, u);
}

/**
 * @brief Draws one box when it belongs to the active screen.
 *
 * A box with no watched byte is rendered on every call. Otherwise its cached
 * rendering is reused until the watched byte differs from its @c last field,
 * unless the UI has a pending forced redraw. Output lines are placed at
 * the box's x coordinate and are skipped when their cursor position is outside
 * the recorded terminal bounds.
 *
 * @param tmp Registered box to draw.
 * @param flush Nonzero to flush standard output after drawing.
 * @param u Pointer to initialized UI state.
 * @see ui_draw()
 * @see ui_redraw()
 */
void ui_draw_one(ui_box_t *tmp, int flush, ui_t *u){
  char *buf, *tok;
  int n = -1;

  if(tmp->screen != u->screen) return;
  
  buf = calloc(1, strlen(tmp->cache) * 2);
  if(u->force ||
     tmp->watch == NULL ||
     *(tmp->watch) != tmp->last
  ){
    tmp->draw(tmp, buf);
    if(tmp->watch != NULL) tmp->last = *(tmp->watch);
    strcpy(tmp->cache, buf);
  } else {
    /* buf is allocated proportionally to tmp->cache, so strcpy is safe */
    strcpy(buf, tmp->cache);
  }
  tok = strtok(buf, "\n");
  while(tok != NULL){
    if(tmp->x > 0 &&
       tmp->x < u->ws.ws_col &&
       CURSOR_Y(tmp) > 0 &&
       CURSOR_Y(tmp) < u->ws.ws_row){
      printf("\x1b[%i;%iH%s", CURSOR_Y(tmp), tmp->x, tok);
      n++;
    }
    tok = strtok(NULL, "\n");
  }
  free(buf);

  if(flush) fflush(stdout);
}

/**
 * @brief Clears the terminal and draws every box on the active screen.
 *
 * This flushes standard output and clears the pending forced-redraw flag after
 * drawing. Boxes are rendered or served from cache according to ui_draw_one().
 *
 * @param u Pointer to initialized UI state.
 * @see ui_redraw()
 * @see ui_screen
 */
void ui_draw(ui_t *u){
  ui_box_t *tmp;
  int i;

  printf("\x1b[0m\x1b[2J");

  vec_foreach(&(u->b), tmp, i){
    ui_draw_one(tmp, 0, u);
  }
  fflush(stdout);
  u->force = 0;
}

/**
 * @brief Forces all visible boxes to refresh their cached rendering.
 *
 * Sets the redraw flag and immediately calls ui_draw().
 *
 * @param u Pointer to initialized UI state.
 * @see ui_draw()
 */
void ui_redraw(ui_t *u){
  u->force = 1;
  ui_draw(u);
}

/* Internal implementation for ui_update(). */
void _ui_update(char *c, int n, ui_t *u){
  ui_box_t *tmp;
  ui_evt_t *evt;
  int ind, x, y;
  char cpy[n], *tok;

  if(n >= 4 &&
     c[0] == '\x1b' &&
     c[1] == '[' &&
     c[2] == '<'){
    strncpy(cpy, c, n);
    tok = strtok(cpy+3, ";");
    
    switch(tok[0]){
      case '0':
        u->mouse = (strchr(c, 'm') == NULL);
        COORDINATE_DECODE();
        LOOP_AND_EXECUTE(tmp->onclick, 1);
        if(!u->mouse){
          u->click = NULL;
        }
        break;
      case '3':
        u->mouse = (strcmp(tok, "32") == 0);
        COORDINATE_DECODE();
        LOOP_AND_EXECUTE(tmp->onhover, u->mouse);
        break;
      case '6':
        if(u->canscroll){
          u->scroll += (4 * (tok[1] == '4')) - 2;
          printf("\x1b[0m\x1b[2J");
          ui_draw(u);
        }
        break;
    }
  }

  vec_foreach(&(u->e), evt, ind){
    if(strncmp(c, evt->c, strlen(evt->c)) == 0) evt->f();
  }
}

/*
 * HELPERS
 */
void _ui_text(ui_box_t *b, char *out){
  sprintf(out, "%s", (char*)b->data1);
}

/**
 * @brief Registers a one-line box that displays a C string.
 *
 * This convenience wrapper uses the string length as the box width and stores
 * @p str as the box's first application-data pointer. The string is not
 * copied, so it must remain valid while the box exists. The click and hover
 * callbacks follow the mouse-handler convention described by ui_add().
 *
 * As with ui_add(), the @p screen argument is accepted but the current UI
 * screen is captured for the box.
 *
 * @param x Left terminal coordinate, or UI_CENTER_X to center horizontally.
 * @param y Top terminal coordinate, or UI_CENTER_Y to center vertically.
 * @param str NUL-terminated text to display.
 * @param screen Accepted screen identifier; current UI screen is used instead.
 * @param click Optional mouse-click callback.
 * @param hover Optional mouse-hover callback.
 * @param u Pointer to initialized UI state.
 * @return The assigned box identifier.
 * @see ui_add()
 */
int ui_text(
  int x, int y, char *str,
  int screen,
  func click, func hover,
  ui_t *u
){
  return ui_add(
    x, y,
    strlen(str), 1,
    screen,
    NULL, 0,
    _ui_text,
    click,
    hover,
    str,
    NULL,
    u
  );
}

#endif
