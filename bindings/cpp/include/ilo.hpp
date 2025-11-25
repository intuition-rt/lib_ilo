#pragma once

#include <Arduino.h>

#define SERIAL_RX_PIN 17
#define SERIAL_TX_PIN 16
#define SERIAL_BAUD 115200
#define SERIAL_CONFIG SERIAL_8N1

class Ilo {
  public:
    Ilo();

    void handshakeIlo();
    void setWifiCredentials(String ssid, String password);
    void getWifiCredentials();
};
