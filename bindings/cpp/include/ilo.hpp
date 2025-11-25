#pragma once

#include <Arduino.h>

#define SERIAL_RX_PIN 17
#define SERIAL_TX_PIN 16
#define SERIAL_BAUD 115200
#define SERIAL_CONFIG SERIAL_8N1

class Ilo {
  void _sendMsg(String msg);

  public:
    Ilo();

    // others
    void handshakeIlo();

    // WiFi
    void setWifiCredentials(String ssid, String password);
    void getWifiCredentials();

    // motors
    void move(String direction, uint speed, uint acc);
    void flat_movement(uint angle, uint distance);
};
