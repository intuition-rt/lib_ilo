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


void Ilo::set_led_anim(String anim, uint repeat) {
  char *builded_trame = build_trame(
      "set_led_mode", {
        { "mode", anim.c_str() },
        { "nb_loop", String(repeat).c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}


void Ilo::set_led_single(String type, int id, uint8_t r, uint8_t g, uint8_t b, uint8_t brightness) {
  if (type != "circle" && type != "center")
    return printf("Type need to be 'circle' or 'center'\n"), (void)(0);

  char *builded_trame = build_trame(
      "set_led_mode", {
        { "type", String(type == "center" ? "1" : "0").c_str() },
        { "id", String(id).c_str() },
        { "red", String(r).c_str() },
        { "green", String(g).c_str() },
        { "blue", String(b).c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}
