#include <Arduino.h>

#include "common.hpp"
#include "../include/ilo.hpp"

void Ilo::set_led_captor(uint8_t brightness) {
  char *builded_trame = build_trame(
      "set_led_captor", {
        { "brightness", String(brightness).c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

void Ilo::set_led_color(uint8_t r, uint8_t g, uint8_t b) {
  char *builded_trame = build_trame(
      "set_led_color", {
        { "red", String(r).c_str() },
        { "green", String(g).c_str() },
        { "blue", String(b).c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

void Ilo::set_led_shape(String shape) {
  char *builded_trame = build_trame(
      "set_led_shape", {
        { "shape", shape.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}
