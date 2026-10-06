#!/usr/bin/env python3

import sys
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont


# ---- Configuration ----------------------------------------------------------

FONT_PATH = "/usr/share/fonts/truetype/DejaVuSans.ttf"
FONT_SIZE = 16

FOREGROUND = (255, 255, 255, 255)
BACKGROUND = (0, 0, 0, 0)

# Correct the aspect ratio of the rendered Braille art.
SCALE_X = 1
SCALE_Y = 1.5


# ---- Renderer ---------------------------------------------------------------

def render(input_path: Path, output_path: Path):
    text = input_path.read_text(encoding="utf-8")
    lines = text.splitlines()

    if not lines:
        raise ValueError("Input file is empty.")

    font = ImageFont.truetype(FONT_PATH, FONT_SIZE)

    # Determine character-cell dimensions.
    cell_width = round(font.getlength("M"))

    ascent, descent = font.getmetrics()
    cell_height = ascent + descent

    columns = max(len(line) for line in lines)
    rows = len(lines)

    width = columns * cell_width
    height = rows * cell_height

    print(f"Grid:   {columns} x {rows} characters")
    print(f"Cell:   {cell_width} x {cell_height} pixels")
    print(f"Render: {width} x {height} pixels")

    image = Image.new(
        "RGBA",
        (width, height),
        BACKGROUND,
    )

    draw = ImageDraw.Draw(image)

    # Render every Unicode codepoint into its own fixed cell.
    for y, line in enumerate(lines):
        for x, char in enumerate(line):
            draw.text(
                (x * cell_width, y * cell_height),
                char,
                font=font,
                fill=FOREGROUND,
            )

    # Correct the terminal/Braille aspect ratio.
    if SCALE_X != 1 or SCALE_Y != 1:
        image = image.resize(
            (
                image.width * SCALE_X,
                image.height * SCALE_Y,
            ),
            resample=Image.Resampling.NEAREST,
        )

    print(f"Output: {image.width} x {image.height} pixels")

    image.save(output_path)


# ---- CLI --------------------------------------------------------------------

def main():
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} INPUT.txt OUTPUT.png")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])

    render(input_path, output_path)


if __name__ == "__main__":
    main()
