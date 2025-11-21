#ifndef TRAME_H
  #define TRAME_H

typedef struct {
  char const *name;
  char const *format;
} trame;

typedef struct {
  char const *name;
  char const *value;
} trame_param;

typedef unsigned int uint;

#define TRAME_CHAR_START '<'
#define TRAME_CHAR_END '>'

#define TRAME_BUILDER_CHAR_PARAM_START '['
#define TRAME_BUILDER_CHAR_PARAM_END ']'

#define countof(arr) (sizeof (arr) / sizeof *(arr))

char *exposed_build_trame(
    char const *name,
    unsigned int nb_params,
    trame_param *params);


#define build_simple_trame(name) \
    exposed_build_trame(name, 0, NULL)

#define build_trame(name, ...) \
    exposed_build_trame( \
        name, \
        countof(((trame_param[])__VA_ARGS__)), \
        ((trame_param[])__VA_ARGS__) \
    )

#endif
