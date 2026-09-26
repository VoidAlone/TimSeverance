#!/usr/bin/env python3

import sys
from pathlib import Path


# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

# Position of each Braille pixel within a character cell.
PIXEL_X = 4.0
PIXEL_Y = 4.0

# Size of one Braille character cell.
CELL_WIDTH = 10.0
CELL_HEIGHT = 20.0

# Size of each square pixel.
PIXEL_SIZE = 3.0

FOREGROUND = "white"


# Braille layout:
#
#   1 4
#   2 5
#   3 6
#   7 8
#
PIXEL_POSITIONS = {
    1: (PIXEL_X,     PIXEL_Y),
    2: (PIXEL_X,     PIXEL_Y * 2),
    3: (PIXEL_X,     PIXEL_Y * 3),
    4: (PIXEL_X * 2, PIXEL_Y),
    5: (PIXEL_X * 2, PIXEL_Y * 2),
    6: (PIXEL_X * 2, PIXEL_Y * 3),
    7: (PIXEL_X,     PIXEL_Y * 4),
    8: (PIXEL_X * 2, PIXEL_Y * 4),
}


def braille_bits(char):
    """Return the 8-bit pattern encoded by a Unicode Braille character."""

    codepoint = ord(char)

    if 0x2800 <= codepoint <= 0x28FF:
        return codepoint - 0x2800

    return None


def render(input_path: Path, output_path: Path):
    text = input_path.read_text(encoding="utf-8")
    lines = text.splitlines()

    if not lines:
        raise ValueError("Input file is empty.")

    columns = max(len(line) for line in lines)
    rows = len(lines)

    width = columns * CELL_WIDTH
    height = rows * CELL_HEIGHT

    print(f"Grid:         {columns} x {rows} Braille characters")
    print(f"Logical:      {columns * 2} x {rows * 4} pixels")
    print(f"SVG canvas:   {width:g} x {height:g}")

    svg = [
        (
            f'<svg xmlns="http://www.w3.org/2000/svg" '
            f'width="{width:g}" '
            f'height="{height:g}" '
            f'viewBox="0 0 {width:g} {height:g}">'
        ),
        f'<g fill="{FOREGROUND}">'
    ]

    half_pixel = PIXEL_SIZE / 2

    for row, line in enumerate(lines):
        for column, char in enumerate(line):

            bits = braille_bits(char)

            if bits is None:
                continue

            cell_x = column * CELL_WIDTH
            cell_y = row * CELL_HEIGHT

            for dot in range(1, 9):

                if not bits & (1 << (dot - 1)):
                    continue

                dx, dy = PIXEL_POSITIONS[dot]

                # dx/dy represent the center of the pixel.
                x = cell_x + dx - half_pixel
                y = cell_y + dy - half_pixel

                svg.append(
                    f'<rect '
                    f'x="{x:g}" '
                    f'y="{y:g}" '
                    f'width="{PIXEL_SIZE:g}" '
                    f'height="{PIXEL_SIZE:g}"/>'
                )

    svg.extend([
        "</g>",
        "</svg>"
    ])

    output_path.write_text(
        "\n".join(svg),
        encoding="utf-8"
    )

    print(f"Wrote: {output_path}")


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} INPUT.txt OUTPUT.svg")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    render(input_path, output_path)


if __name__ == "__main__":
    main()
