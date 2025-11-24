#include "../include/ilo.hpp"


extern "C" {
#include "core/trame.h"
}

#undef build_trame
#define build_trame(name, ...) \
  ({ \
    trame_param tmp_params[] = __VA_ARGS__; \
    exposed_build_trame(name, countof(tmp_params), tmp_params); \
  })

void Ilo::setWifiCredentials(String ssid, String password) {
  char *p = build_trame(
        "set_wifi_credentials", {
            { "ssid", ssid.c_str() },
            { "password", password.c_str() },
        }
   );

  printf("[%s]\n", p);
}
