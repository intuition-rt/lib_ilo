#include <Arduino.h>

#include "common.hpp"
#include "../include/ilo.hpp"

Ilo::Ilo() {
  Serial2.begin(SERIAL_BAUD, SERIAL_CONFIG, SERIAL_RX_PIN, SERIAL_TX_PIN);
}

void Ilo::_sendMsg(String msg) {
  printf("[%s]\n", msg.c_str());
  Serial2.print(String(msg));
}

void Ilo::handshakeIlo() {
  char *p = build_trame(
      "handshake_ilo", {}
  );

  this->_sendMsg(String(p));
}

void Ilo::getWifiCredentials() {
  char *p = build_trame(
      "get_wifi_credentials", {}
  );

  this->_sendMsg(String(p));
}

void Ilo::setWifiCredentials(String ssid, String password) {
  char *p = build_trame(
      "set_wifi_credentials", {
        { "ssid", ssid.c_str() },
        { "password", password.c_str() },
      }
  );

  this->_sendMsg(String(p));
}
