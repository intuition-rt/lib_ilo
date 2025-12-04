# Lib Ilo

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/intuition-rt/library/ilo.svg)](https://registry.platformio.org/libraries/intuition-rt/ilo)

Ce projet contiens les différentes libraries nécessaire au bon fonctionnement de la communication avec ilo.

Afin de simplifier le dévelopement, tout la partie communication est génération à partir d'une unique source de vérité. Cela permet d'assure que les different bindings sont synchronisé et utilise les mêmes trames.

## Layout

```c
artefacts/          # contenu généré automatiquement
├── primitives/     # abstraction simple des trames en fonctions
│   └── {cpp,python,flutter}/
└── trames.json
bindings/           # wrapper au dessus des primitives
└── {cpp/python/flutter}/
core/               # source de vérité des des données
generators/
   └── generate_primitives.py
```
