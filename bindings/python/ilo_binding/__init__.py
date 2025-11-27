from ilo_binding_ext import build_trame, get_trames
from functools import wraps
import re


def __create_func(name: str, fmt: str):
    matches = {
        name: {"i": "int", "s": "str"}[t]
        for t, name in re.findall(r"\[(\w):([^\]]+)\]", fmt)
    }

    params_repr = ', '.join(
        f"{name}: {type_}"
        for name, type_ in matches.items()
    )

    namespace = {}
    exec(f"def {name}({params_repr}) -> str: ...", namespace)

    @wraps(namespace[name])
    def wrapped(**kwargs):
        if len(kwargs) != len(matches):
            raise TypeError("Invalid number of arguments.")

        for k, v in kwargs.items():
            p = matches.get(k)
            if p is None:
                continue

            if type(v).__name__ != p:
                raise TypeError(
                    f"Expected `{p}` for parameter {k}, but got `{type(v).__name__}`"
                )

        return build_trame(
            name,
            tuple((n, f"{f}") for n, f in kwargs.items())
        )

    return wrapped

locals().update(**{
   name: __create_func(name, fmt)
   for name, fmt in get_trames()
})
