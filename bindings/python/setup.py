import os
from typing import Iterator

from setuptools import Extension, setup


def find_sources(basepath: str) -> Iterator[str]:
    files = (
        (current_dir, file)
        for current_dir, _, files in os.walk(basepath, followlinks=True)
        for file in files
    )

    for current_dir, file in files:
        *_, ext = os.path.splitext(file)
        if ext != f"{os.path.extsep}c":
            continue

        fullpath = os.path.join(current_dir, file)
        print(f"Registering ${fullpath} to sources")
        yield fullpath


ilo_binding = Extension(
    "ilo_binding",
    sources=list(find_sources("ilo_binding")),
    include_dirs=["ilo_binding"],
    language="c",
)

if __name__ == "__main__":
    setup(ext_modules=[ilo_binding])
