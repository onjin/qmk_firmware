#!/usr/bin/env python3
from typing import Dict
import os


LAYOUTS: Dict[int, str] = {
    0: "base",
    1: "cole",
    2: "work",
    3: "game",
    4: "symb",
    5: "nump",
    6: "medi",
    7: "36-base",
    8: "36-navi",
    9: "36-mouse",
    10: "36-media",
    11: "36-numeric",
    12: "36-symbols",
    13: "36-functions",
    14: "36-buttons",
}

MARGIN: str = "400px 0px 0px 0px"
FONT: str = r"Fira\ Code\ 22"
BACKGROUND: str = "#1c1c1c"
FOREGROUND: str = "#5f875f"
WIDTH: int = 1920
HEIGHT: int = 1080


for nr, name in LAYOUTS.items():
    filename = f"ed_layout_{nr}_{name}"
    txt_filename = filename + ".txt"
    img_filename = filename + ".png"
    PARSE_DOC = fr"cat keymap.c |grep '\*\*\*{nr}'|sed -e 's/\*\*[0-9]\*//' > /tmp/{txt_filename}"
    GENERATE_IMG = fr"""pango-view --margin "{MARGIN}" --font {FONT} --background={BACKGROUND} --foreground={FOREGROUND} --width {WIDTH} --height {HEIGHT} /tmp/{txt_filename} -qo {img_filename}"""

    print(f"Generating {txt_filename}")
    os.system(PARSE_DOC)
    print(f"Generating {img_filename}")
    os.system(GENERATE_IMG)
