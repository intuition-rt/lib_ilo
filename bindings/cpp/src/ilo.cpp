#include <Arduino.h>

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


Ilo::Ilo() {
  Serial2.begin(SERIAL_BAUD, SERIAL_CONFIG, SERIAL_RX_PIN, SERIAL_TX_PIN);
}

void Ilo::handshakeIlo() {
  char *p = build_trame(
      "handshake_ilo", {}
  );

  Serial2.println(String(p));
}

void Ilo::getWifiCredentials() {
  char *p = build_trame(
      "get_wifi_credentials", {}
  );

  Serial2.println(String(p));
}

void Ilo::setWifiCredentials(String ssid, String password) {
  char *p = build_trame(
      "set_wifi_credentials", {
        { "ssid", ssid.c_str() },
        { "password", password.c_str() },
      }
  );

  printf("[%s]\n", p);
  Serial2.print(String(p));
}
