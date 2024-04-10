#!/usr/bin/env python3
from typing import Dict
import os


LAYOUTS: Dict[str, str] = {
    '01': "base",
    '02': "cole",
    '03': "work",
    '04': "game",
    '05': "36-base",
    '06': "36-navi",
    '07': "36-mouse",
    '08': "36-media",
    '09': "36-numeric",
    '10': "36-symbols",
    '11': "36-functions",
    '12': "36-buttons",
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
    PARSE_DOC = fr"cat onjin/available_layers.h |grep '\*\*\*{nr}\*'|sed -e 's/\*\*{nr}\*//' > /tmp/{txt_filename}"
    GENERATE_IMG = fr"""pango-view --margin "{MARGIN}" --font {FONT} --background={BACKGROUND} --foreground={FOREGROUND} --width {WIDTH} --height {HEIGHT} /tmp/{txt_filename} -qo {img_filename}"""

    print(f"Generating {txt_filename}")
    os.system(PARSE_DOC)
    print(f"Generating {img_filename}")
    os.system(GENERATE_IMG)
