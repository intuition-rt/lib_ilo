import json
import re

from pathlib import Path
from typing import TypedDict, List, Dict

from jinja2 import Environment, FileSystemLoader

ROOT_DIR = Path(__file__).parent.resolve()

TRAMES_JSON = ROOT_DIR.parent / "artefacts" / "trames.json"
TEMPLATES_DIR = ROOT_DIR / "templates"
OUTPUT_DIR = ROOT_DIR.parent / "artefacts"


class TrameParam(TypedDict):
    name: str
    type: str


class Trame(TypedDict):
    name: str
    trame_parts: List[str]
    parameters: List[TrameParam]
    doc: str


PARAM_TYPE_MAP = {
    "b": "boolean",
    "i": "integer",
    "s": "string",
    "f": "float",
}


def rework_trame(trame: Dict[str, str]) -> Trame:
    """
    Transform a trame with "format" into structured trame-parts and parameters.
    Example:
      { "name": "move_motor", "format": "20ma[i:angle]s[i:speed]" }
    -->
      { "name": "move_motor",
        "trame_parts": ["20ma", "s"],
        "parameters": [
            {"name": "angle", "type": "integer"},
            {"name": "speed", "type": "integer"}
        ]
      }
    """
    fmt = trame["format"]

    parts = re.split(r"\[[ifs]:[^\]]+\]", fmt)
    parts = [p for p in parts if p]  # remove empty strings

    param_matches = re.findall(r"\[([ifs]):([^\]]+)\]", fmt)
    parameters: List[TrameParam] = [
        {"name": name, "type": PARAM_TYPE_MAP.get(t, "unknown")}
        for t, name in param_matches
    ]

    return Trame(
        name=trame["name"],
        trame_parts=parts,
        parameters=parameters,
        doc=trame.get("doc", ""),
    )


def escape_fstring_literal(s: str) -> str:
    return s.replace("{", "{{").replace("}", "}}")


def format_trame(trame: Trame):
    parts = []

    for part, param in zip(trame["trame_parts"], trame["parameters"]):
        parts.append(f'{part}[{param["name"]}]')

    if len(trame["trame_parts"]) > len(trame["parameters"]):
        parts.append(trame["trame_parts"][-1])


    return '``<' + "".join(parts) + '>``'


def main():
    with TRAMES_JSON.open() as f:
        trames_formats = json.load(f)
        trames = [rework_trame(trame) for trame in trames_formats]

    env = Environment(
        loader=FileSystemLoader(TEMPLATES_DIR),
        trim_blocks=True,
        lstrip_blocks=True,
    )

    env.filters["escape_fstring"] = escape_fstring_literal
    env.filters["format_trame"] = format_trame

    jinja_templates_per_langs = (
      (lang_dir, template_file)
      for lang_dir in TEMPLATES_DIR.iterdir()
      for template_file in lang_dir.glob("*.jinja")
      if lang_dir.is_dir()
    )

    for lang_dir, template_file in jinja_templates_per_langs:
        rel_path = template_file.relative_to(TEMPLATES_DIR)
        out_path = OUTPUT_DIR / rel_path.parent / template_file.stem
        out_path.parent.mkdir(parents=True, exist_ok=True)

        template = env.get_template(str(rel_path))
        rendered = template.render(
            trames=trames,
            trames_formats=trames_formats,
            lang=lang_dir.name
        )

        out_path.write_text(rendered)
        print(f"[+] Generated {out_path.relative_to(ROOT_DIR.parent)}")


if __name__ == "__main__":
    main()
