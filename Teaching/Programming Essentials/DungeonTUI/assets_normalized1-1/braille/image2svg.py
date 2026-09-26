#!/usr/bin/env python3

import sys
from pathlib import Path
from xml.sax.saxutils import escape


# Geometry of ONE Braille character.
#
# A Braille character is:
#
#   1 4
#   2 5
#   3 6
#   7 8
#
DOT_X = 4.0
DOT_Y = 4.0

CELL_WIDTH = 10.0
CELL_HEIGHT = 20.0

DOT_RADIUS = 1.5

FOREGROUND = "white"


# Braille dot number -> position within character cell.
DOT_POSITIONS = {
    1: (DOT_X, DOT_Y),
    2: (DOT_X, DOT_Y * 2),
    3: (DOT_X, DOT_Y * 3),
    4: (DOT_X * 2, DOT_Y),
    5: (DOT_X * 2, DOT_Y * 2),
    6: (DOT_X * 2, DOT_Y * 3),
    7: (DOT_X, DOT_Y * 4),
    8: (DOT_X * 2, DOT_Y * 4),
}


def braille_bits(char):
    """Return the 8-bit Braille pattern encoded by char."""

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

    print(f"Grid: {columns} x {rows} Braille characters")
    print(f"Logical dots: {columns * 2} x {rows * 4}")
    print(f"SVG size: {width:g} x {height:g}")

    svg = []

    svg.append(
        f'<svg xmlns="http://www.w3.org/2000/svg" '
        f'width="{width:g}" '
        f'height="{height:g}" '
        f'viewBox="0 0 {width:g} {height:g}">'
    )

    # Everything inherits the foreground color.
    svg.append(f'<g fill="{escape(FOREGROUND)}">')

    for row, line in enumerate(lines):
        for column, char in enumerate(line):

            bits = braille_bits(char)

            # Ignore anything that isn't Braille.
            if bits is None:
                continue

            cell_x = column * CELL_WIDTH
            cell_y = row * CELL_HEIGHT

            for dot in range(1, 9):

                # Braille dot N corresponds to bit N-1.
                if bits & (1 << (dot - 1)):

                    dx, dy = DOT_POSITIONS[dot]

                    cx = cell_x + dx
                    cy = cell_y + dy

                    svg.append(
                        f'<circle '
                        f'cx="{cx:g}" '
                        f'cy="{cy:g}" '
                        f'r="{DOT_RADIUS:g}"/>'
                    )

    svg.append("</g>")
    svg.append("</svg>")

    output_path.write_text(
        "\n".join(svg),
        encoding="utf-8",
    )


def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} INPUT.txt OUTPUT.svg")
        sys.exit(1)

    render(
        Path(sys.argv[1]),
        Path(sys.argv[2]),
    )


if __name__ == "__main__":
    main()
