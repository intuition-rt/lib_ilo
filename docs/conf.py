import os
import sys

# Allow `import ilo_primitives` if needed
sys.path.insert(0, os.path.abspath('../artefacts/primitives/python'))

project = "Ilo Libs"
copyright = author = "Intuition-rt"

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.extlinks",
    "sphinx.ext.napoleon",
    "sphinx.ext.viewcode",
]

templates_path = ["_templates"]
html_static_path = ["_static"]

html_title = project
html_theme = "furo"
html_logo = "_static/ilo.png"
html_favicon = "_static/favicon.png"
