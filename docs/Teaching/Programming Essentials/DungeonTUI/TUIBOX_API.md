# TUIBox API Summary

`tuibox.h` is a single-header terminal UI library. Include it in one C source
file, create a `ui_t`, register UI boxes and input handlers, draw the UI, then
process terminal input in the provided loop.

## Basic lifecycle

```c
#include "tuibox.h"

ui_t ui;

int main(void) {
  ui_new(0, &ui);

  /* Register boxes and handlers here. */
  ui_draw(&ui);

  ui_loop(ui) {
    ui_update(&ui);
  }

  ui_free(&ui);
}
```

Call `ui_new(start_screen, ui)` before any other UI operation. It records the
terminal size, enables raw input and mouse reporting, switches to the terminal
alternate screen, and initializes the UI state.

Always call `ui_free(ui)` before exiting. It frees registered boxes and key
handlers, restores terminal settings, disables mouse reporting, and leaves the
alternate screen.

## Adding content

### `ui_add`

```c
int ui_add(int x, int y, int width, int height, int screen,
           char *watch, char initial,
           func draw, func onclick, func onhover,
           void *data1, void *data2, ui_t *ui);
```

Registers a rectangular box and returns its numeric ID. The library calls its
draw callback to build the text displayed by the box.

- `x`, `y`, `width`, and `height` describe the box in terminal cells.
- Use `UI_CENTER_X` or `UI_CENTER_Y` for the corresponding coordinate to
  center the box in the current terminal size.
- `screen` identifies the screen on which the box should appear.
- `watch` may point to a changing `char`; when its value differs from
  `initial`/the last drawn value, the box is rendered again. Pass `NULL` to
  render whenever the UI is drawn.
- `data1` and `data2` are application-owned pointers available through the
  `ui_box_t` received by callbacks.

The callback type is declared as `func` for compatibility, but callbacks used
by `ui_add` must match these effective call signatures:

```c
void draw(ui_box_t *box, char *out);
void onclick(ui_box_t *box, int x, int y, int mouse_down);
void onhover(ui_box_t *box, int x, int y, int mouse_down);
```

`draw` is required. Write the box contents to `out`; newline-separated text is
drawn on successive rows. `onclick` and `onhover` may be `NULL`. The `x` and
`y` callback arguments are the mouse coordinates; `mouse_down` is nonzero
while the mouse button is pressed.

### `ui_text`

```c
int ui_text(int x, int y, char *text, int screen,
            func click, func hover, ui_t *ui);
```

Registers a one-line text box. This is the simple alternative to `ui_add`; it
uses `strlen(text)` as its width and renders `text` directly. It returns the
box ID. The click and hover callbacks follow the same signatures as above.

The text pointer must remain valid while the box exists.

## Input

### `ui_key`

```c
void ui_key(char *sequence, func handler, ui_t *ui);
```

Registers a keyboard sequence and a no-argument handler:

```c
void handler(void);
```

When input begins with `sequence`, the handler runs. Use terminal input bytes,
for example `"q"` or an escape sequence.

### `ui_loop` and `ui_update`

```c
ui_loop(ui) {
  ui_update(&ui);
}
```

`ui_loop(ui)` is a macro that repeatedly reads from standard input. Inside its
body, call `ui_update(ui_pointer)` once per read to dispatch registered key
handlers and mouse click, hover, and scroll events. Do not call `_ui_update`
directly; it is the macro's implementation function.

## Drawing and screens

### `ui_draw` and `ui_redraw`

```c
void ui_draw(ui_t *ui);
void ui_redraw(ui_t *ui);
```

`ui_draw` clears the terminal and draws every box on the active screen. It
uses a box's cached output when its watched value has not changed. `ui_redraw`
forces every box to run its draw callback before drawing.

### `ui_screen`

```c
ui_screen(screen_id, ui_pointer);
```

Sets the active screen and marks the UI for a forced redraw on the next draw.
Use screen IDs to group boxes into separate views.

`ui_add` and `ui_text` accept a `screen` argument, but this version of the
header stores the current `ui->screen` when registering a box. Set the desired
screen with `ui_screen(...)` before adding its boxes.

### `ui_clear`

```c
void ui_clear(ui_t *ui);
```

Removes all boxes and key handlers, then reinitializes the UI on its current
screen. Register the new UI contents after calling it.

## Useful types

`ui_t` is the UI state object passed to every library call. `ui_box_t` is
passed to draw and mouse callbacks. Application code will normally use these
fields in a callback:

```c
box->data1   /* first application pointer supplied to ui_add */
box->data2   /* second application pointer supplied to ui_add */
box->x       /* box position */
box->y
box->w       /* box dimensions */
box->h
```

`ui_get(id, ui_pointer)` returns the registered `ui_box_t *` for a box ID
returned by `ui_add` or `ui_text`.
