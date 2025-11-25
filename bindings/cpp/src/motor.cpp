#include <Arduino.h>
#include <cmath>

#include "common.hpp"
#include "../include/ilo.hpp"

void Ilo::move(String direction, uint speed, uint acc) {
  if (speed > 100)
    return printf(LOG_PREFIX LOG_ERROR " Speed must be include between 0 and 100\n"), (void)(0);
  if (!acc || acc > 100)
    return printf(LOG_PREFIX LOG_ERROR " Acceleration must be include between 0 and 100\n"), (void)(0);

  acc *= 2;

  std::array<int, 3> pos_cmd;

  if (direction == "front")
    pos_cmd = {int(speed*1.27)+128, 128, 128};
  else if (direction == "back")
    pos_cmd = {int(-(speed*1.27))+128, 128, 128};
  else if (direction == "right")
    pos_cmd = {128, int(speed*1.27)+128, 128};
  else if (direction == "left")
    pos_cmd = {128, int(-(speed*1.27))+128, 128};
  else if (direction == "rot_trigo")
    pos_cmd = {128, 128, int(-(speed*1.27))+128};
  else if (direction == "rot_clock")
    pos_cmd = {128, 128, int(speed*1.27)+128};
  else
    return printf(LOG_PREFIX LOG_ERROR " Direction must be 'front', 'back', 'right', 'left', "
      "'rot_trigo', 'rot_clock'\n"), (void)(0);

  std::array<String, 3> pos_cmd_str;

  for (size_t i = 0; i < pos_cmd.size(); i++) {
    if (pos_cmd[i] >= 100)
      pos_cmd_str[i] = String(pos_cmd[i]);
    else if (pos_cmd[i] < 100 && pos_cmd[i] >= 10)
      pos_cmd_str[i] = "0" + String(pos_cmd[i]);
    else if (pos_cmd[i] < 10 && pos_cmd[i] >= 1)
      pos_cmd_str[i] = "00" + String(pos_cmd[i]);
    else
      pos_cmd_str[i] = "000";
  }

  String params = String(acc) + "v" + pos_cmd_str[0] + pos_cmd_str[1] + pos_cmd_str[2] + "pxyr";

  char *builded_trame = build_trame(
      "run_command_motor", {
        { "params", params.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

