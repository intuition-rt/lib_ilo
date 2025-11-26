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

void Ilo::flat_movement(uint angle, uint distance) {
  if (angle > 360)
    return printf(LOG_PREFIX LOG_ERROR " Angle need to be between 0 and 360\n"), (void)(0);

  int indice_x, indice_y;

  if (angle >= 0 || angle < 90) {
    indice_x = 1;
    indice_y = 1;
  } else if (angle >= 90 || angle < 180) {
    indice_x = 0;
    indice_y = 1;
  } else if (angle >= 180 || angle < 270) {
    indice_x = 0;
    indice_y = 0;
  } else if (angle >= 270 || angle <= 360) {
    indice_x = 1;
    indice_y = 0;
  }

  int radian = angle * M_PI / 180;
  int distance_x = abs(int(cos(radian) * distance));
  int distance_y = abs(int(sin(radian) * distance));
  
  String params = "vpx" + String(indice_x) + String(distance_x) +
    "y" + String(indice_y) + String(distance_y) + "r"; 

  char *builded_trame = build_trame(
      "run_command_motor", {
        { "params", params.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

void Ilo::step(String direction, float step, bool finish_state, bool display_led) {
  if (direction == "front" || direction == "back" || direction == "right" || direction == "left") {
    if (step > 100 || step < 0.01)
      return printf(LOG_PREFIX LOG_ERROR " Step must be between 100 and 0.01\n"), (void)(0);

    if (!step)
      step = 1;
    step *= 100;
  } else if (direction == "rot_clock" || direction == "rot_trigo") {
    if (step < 0.01)
      return printf(LOG_PREFIX LOG_ERROR " Step must be higher than 0.01\n"), (void)(0);

    if (!step)
      step = 1;
    step *= 90;
  } else
    return printf(LOG_PREFIX LOG_ERROR " Unknown direction\n"), (void)(0);

  String params;
  if (direction == "front" || direction == "back")
    params = "60vpx" + String(direction == "front" ? "1" : "0") + String(int(step)) + "r";
  else if (direction == "left" || direction == "right")
    params = "60vpxy" + String(direction == "left" ? "1" : "0") + String(int(step))+ "r";
  else if (direction == "rot_trigo" || direction == "rot_clock")
    params = "60vpxyr" + String(direction == "rot_trigo" ? "1" : "0") + String(int(step))+ "r";
  params += String(display_led ? "t" : "f");

  char *builded_trame = build_trame(
      "run_command_motor", {
        { "params", params.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

void Ilo::stop() {
  char *builded_trame = build_trame("safety_stop", {});

  this->_sendMsg(String(builded_trame));
}

void Ilo::pause(uint duration) {
  String params = "vp" + String(duration*1000) + "yxr";

  char *builded_trame = build_trame(
      "run_command_motor", {
        { "params", params.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}


void Ilo::rotation(int angle, bool display_led) {
  String params = "vpyxr" + String(angle ? "1" : "0") + String(abs(angle));

  char *builded_trame = build_trame(
      "run_command_motor", {
        { "params", params.c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}

void Ilo::set_pid(uint kp, uint ki, uint kd) {
  if (kp > 10 || ki > 10 || kd > 10)
    return printf(LOG_PREFIX LOG_ERROR " Values need to be between 0 and 10\n"), (void)(0);

  kp *= 100;
  ki *= 100;
  kd *= 100;

  
  char *builded_trame = build_trame(
      "set_pid", {
        { "Kp", String(kp).c_str() },
        { "Ki", String(ki).c_str() },
        { "Kd", String(kd).c_str() },
      }
  );

  this->_sendMsg(String(builded_trame));
}
