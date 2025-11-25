#pragma once

#define LOG_PREFIX "[ILO]"
#define LOG_DEBUG "[DEBUG]"
#define LOG_INFO "[INFO]"
#define LOG_WARN "[WARN]"
#define LOG_ERROR "[ERROR]"
#define LOG_FATAL "[FATAL]"

extern "C" {
  #include "core/trame.h"
}

#undef build_trame
#define build_trame(name, ...) \
  ({ \
    trame_param tmp_params[] = __VA_ARGS__; \
    exposed_build_trame(name, countof(tmp_params), tmp_params); \
  })
