
#include <Arduino.h>

#include "common.hpp"
#include "../include/ilo.hpp"

void Ilo::reset_angle() {
  char *builded_trame = build_trame(
      "reset_angle", {}
  );

  this->_sendMsg(String(builded_trame));
}
