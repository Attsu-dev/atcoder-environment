import re
import sys

CANDIDATES = [
    "ll",
    "ull",
    "VLL",
    "VVLL",
    "VVVLL",
    "VD",
    "VS",
    "VB",
    "VVB",
    "PLL",
    "VPLL",
    "VVPLL",
    "rep",
    "rrep",
    "FOR",
    "all",
    "rall",
    "INF",
    "dx",
    "dy",
    "print",
    "printv",
    "printvv",
    "YesNo",
    "chmax",
    "chmin",
]


def clean(code: str) -> str:
    lines = [
        line
        for line in code.splitlines()
        if not re.match(r"^\s*(?:#\s*line\b|//\s*clang-format\b)", line)
    ]
    code = "\n".join(lines) + "\n"

    while True:
        unused = [
            name for name in CANDIDATES if len(re.findall(rf"\b{name}\b", code)) == 1
        ]

        if not unused:
            return code

        pattern = r"\b(?:" + "|".join(unused) + r")\b"
        lines = [line for line in code.splitlines() if not re.search(pattern, line)]
        code = "\n".join(lines) + "\n"


sys.stdout.write(clean(sys.stdin.read()))
