#ifndef TRAME_H
  #define TRAME_H

  #include <stddef.h>

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
#define TRAME_BUILDER_CHAR_PARAM_SEP ':'
#define TRAME_BUILDER_CHAR_PARAM_END ']'

#define countof(arr) (sizeof (arr) / sizeof *(arr))

#define cat(x) #x
#define xcat(x) cat(x)

char *exposed_build_trame(
    char const *name,
    unsigned int nb_params,
    trame_param *params);

#define build_simple_trame(name) exposed_build_trame(name, 0, NULL)

#define NARG(...) NARG_(__VA_ARGS__,RSEQ_N())
#define NARG_(...) ARG_N(__VA_ARGS__)

#define ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define RSEQ_N() 10,9,8,7,6,5,4,3,2,1,0

#define stringify_trame_param(p) \
    _Generic(p,                \
      int: stringify_trame_param_int, \
      char *: stringify_trame_param_s \
    )(p)

char *stringify_trame_param_int(int value);
char *stringify_trame_param_s(char *value);

extern const trame TRAMES[];
extern const size_t TRAME_COUNT;

#define PARAM(v) (trame_param){ #v, stringify_trame_param(v) }
#define EXPAND(...) __VA_ARGS__

#define FE_1(WHAT, X) WHAT(X)
#define FE_2(WHAT, X, ...) WHAT(X), FE_1(WHAT, __VA_ARGS__)
#define FE_3(WHAT, X, ...) WHAT(X), FE_2(WHAT, __VA_ARGS__)
#define FE_4(WHAT, X, ...) WHAT(X), FE_3(WHAT, __VA_ARGS__)
#define FE_5(WHAT, X, ...) WHAT(X), FE_4(WHAT, __VA_ARGS__)
#define FE_6(WHAT, X, ...) WHAT(X), FE_5(WHAT, __VA_ARGS__)
#define FE_7(WHAT, X, ...) WHAT(X), FE_6(WHAT, __VA_ARGS__)
#define FE_8(WHAT, X, ...) WHAT(X), FE_7(WHAT, __VA_ARGS__)

#define CONCAT(a, b) CONCAT_(a, b)
#define CONCAT_(a, b) a##b
#define FOR_EACH(WHAT, ...) \
    CONCAT(FE_, NARG(__VA_ARGS__))(WHAT, __VA_ARGS__)

#define build_trame(name, ...) \
    exposed_build_trame( \
        name, \
        NARG(__VA_ARGS__), \
        (trame_param[]){ FOR_EACH(PARAM, __VA_ARGS__) } \
    )

#endif
