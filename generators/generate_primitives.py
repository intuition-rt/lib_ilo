import json
from pathlib import Path
from jinja2 import Environment, FileSystemLoader

ROOT_DIR = Path(__file__).parent.resolve()

TRAMES_JSON = ROOT_DIR.parent / "artefacts" / "trames.json"
TEMPLATES_DIR = ROOT_DIR / "templates"
OUTPUT_DIR = ROOT_DIR.parent / "artefacts"


def main():
    with TRAMES_JSON.open() as f:
        trames_list= json.load(f)

    env = Environment(
        loader=FileSystemLoader(TEMPLATES_DIR),
        trim_blocks=True,
        lstrip_blocks=True,
    )

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
            trames=trames_list,
            lang=lang_dir.name
        )

        out_path.write_text(rendered)
        print(f"[+] Generated {out_path.relative_to(ROOT_DIR.parent)}")


if __name__ == "__main__":
    main()
