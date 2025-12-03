#pragma once

#include <Arduino.h>
#include <vector>

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
    void set_debug_state(bool debug);

    // WiFi
    void setWifiCredentials(String ssid, String password);
    void getWifiCredentials();

    // motors
    void move(String direction, uint speed, uint acc);
    void flat_movement(uint angle, uint distance);
    void step(String direction, float step = 1, bool finish_state = false, bool display_led = false);
    void stop();
    void pause(uint duration = 1);
    void rotation(int angle, bool display_led=false);
    void set_pid(uint kp, uint ki, uint kd);
    void list_order(std::vector<String> list);

    // led
    void set_led_captor(uint8_t brightness=200);
    void set_led_color(uint8_t r, uint8_t g, uint8_t b);
    void set_led_shape(String shape);
    void set_led_anim(String anim, uint repeat=1);
    void set_led_single(String type, int id, uint8_t r, uint8_t g, uint8_t b, uint8_t brightness=100);

    // sensors
    void reset_angle();
};
