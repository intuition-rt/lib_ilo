#ifndef TRAME_H
  #define TRAME_H

typedef struct {
  char const *name;
  char const *format;
} trame_t;

typedef struct {
  char const *name;
  char const *value;
} trame_param_t;

char *build_trame(char const *name, trame_param_t *params);

#endif
