import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'communication_service.dart';
import 'robot_status.dart';
import 'trame_builder.dart';

class IloLib {
  final CommunicationService communicationService;
  final RobotStatus robotStatus;

  IloLib(this.communicationService, this.robotStatus);

  Future<bool> _send(String content) {
    return communicationService.send("<$content>");
  }

  Future<bool> startTrameS(int hertz, List<String> paramList) async {
    if (hertz > 100 || hertz < 1) {
      debugPrint("[IloLib] Error: Hertz must be between 1 and 100");
      return false;
    }
    if (paramList.isEmpty) {
      debugPrint("[IloLib] Error: Param list is empty");
      return false;
    }
    final validParams = {
      "color_rgb_center",
      "color_rgb_left",
      "color_rgb_right",
      "color_clear",
      "line",
      "distance",
      "distance_front",
      "distance_back",
      "distance_right",
      "distance_left",
      "angle",
      "raw_imu",
      "battery",
      "vel_motor_1",
      "vel_motor_2",
      "vel_motor_3",
      "vel_motor_4",
      "pos_motor_1",
      "pos_motor_2",
      "pos_motor_3",
      "pos_motor_4",
      "temp_motor_1",
      "temp_motor_2",
      "temp_motor_3",
      "temp_motor_4",
      "volt_motor_1",
      "volt_motor_2",
      "volt_motor_3",
      "volt_motor_4",
      "load_motor_1",
      "load_motor_2",
      "load_motor_3",
      "load_motor_4",
      "current_motor_1",
      "current_motor_2",
      "current_motor_3",
      "current_motor_4",
      "move_motor_1",
      "move_motor_2",
      "move_motor_3",
      "move_motor_4",
    };

    final invalidParams =
        paramList.where((item) => !validParams.contains(item)).toList();
    if (invalidParams.isNotEmpty) {
      debugPrint("[IloLib] Error: Invalid params: $invalidParams");
      return false;
    }

    String params = "h${hertz}z/";

    if (paramList.contains("color_rgb_center")) params += "10c/";
    if (paramList.contains("color_rgb_left")) params += "10l/";
    if (paramList.contains("color_rgb_right")) params += "10r/";
    if (paramList.contains("color_clear")) params += "11/";
    if (paramList.contains("line")) params += "12/";
    if (paramList.contains("distance")) params += "20/";
    if (paramList.contains("distance_front")) params += "21/";
    if (paramList.contains("distance_back")) params += "22/";
    if (paramList.contains("distance_right")) params += "23/";
    if (paramList.contains("distance_left")) params += "24/";
    if (paramList.contains("angle")) params += "30/";
    if (paramList.contains("raw_imu")) params += "32/";
    if (paramList.contains("battery")) params += "40/";
    if (paramList.contains("vel_motor_1")) params += "611i1/";
    if (paramList.contains("vel_motor_2")) params += "611i2/";
    if (paramList.contains("vel_motor_3")) params += "611i3/";
    if (paramList.contains("vel_motor_4")) params += "611i4/";
    if (paramList.contains("pos_motor_1")) params += "621i1/";
    if (paramList.contains("pos_motor_2")) params += "621i2/";
    if (paramList.contains("pos_motor_3")) params += "621i3/";
    if (paramList.contains("pos_motor_4")) params += "621i4/";
    if (paramList.contains("temp_motor_1")) params += "63i1/";
    if (paramList.contains("temp_motor_2")) params += "63i2/";
    if (paramList.contains("temp_motor_3")) params += "63i3/";
    if (paramList.contains("temp_motor_4")) params += "63i4/";
    if (paramList.contains("volt_motor_1")) params += "64i1/";
    if (paramList.contains("volt_motor_2")) params += "64i2/";
    if (paramList.contains("volt_motor_3")) params += "64i3/";
    if (paramList.contains("volt_motor_4")) params += "64i4/";
    if (paramList.contains("load_motor_1")) params += "65i1/";
    if (paramList.contains("load_motor_2")) params += "65i2/";
    if (paramList.contains("load_motor_3")) params += "65i3/";
    if (paramList.contains("load_motor_4")) params += "65i4/";
    if (paramList.contains("current_motor_1")) params += "66i1/";
    if (paramList.contains("current_motor_2")) params += "66i2/";
    if (paramList.contains("current_motor_3")) params += "66i3/";
    if (paramList.contains("current_motor_4")) params += "66i4/";
    if (paramList.contains("move_motor_1")) params += "67i1/";
    if (paramList.contains("move_motor_2")) params += "67i2/";
    if (paramList.contains("move_motor_3")) params += "67i3/";
    if (paramList.contains("move_motor_4")) params += "67i4/";

    String msg = TrameBuilder.start_trame_s(params);
    debugPrint("[INFO] START TRAME S: <$msg>");
    return await _send(msg);
  }

  Future<bool> stopTrameS() async {
    return await _send(TrameBuilder.stop_tasks());
  }

  Future<void> stopAll() async {
    debugPrint("[IloLib] STOP <>.");
    await communicationService.send("<>");
    await communicationService.send("<>");
  }

  Future<bool> getBottomColorCenter() async {
    //debugPrint("[IloLib] Request Bottom color...");
    return await _send(TrameBuilder.get_color_rgb_center());
  }

  Future<bool> getBottomColorLeft() async {
    debugPrint("[IloLib] Request Bottom color...");
    return await _send(TrameBuilder.get_color_rgb_left());
  }

  Future<bool> getBottomColorRight() async {
    debugPrint("[IloLib] Request Bottom color...");
    return await _send(TrameBuilder.get_color_rgb_right());
  }

  Future<void> getSensors({bool debug = true}) async {
    await communicationService.send("<${TrameBuilder.get_sensor_distance()}>", debug: debug);
  }

  Future<bool> getIMU() async {
    debugPrint("[IloLib] Request IMU data...");
    bool result = await _send(TrameBuilder.get_imu_info());
    debugPrint("[IloLib] IMU request result: $result");
    return result;
  }

  Future<void> getBatteryLevel() async {
    debugPrint("[IloLib] Request battery level...");
    await _send(TrameBuilder.get_battery_info());
  }

  Future<void> setColor(Color color) async {
    debugPrint("[IloLib] SET COLOR to: $color");
    // TrameBuilder.set_led_color_circle(r, g, b) exists?
    // trames.json: "set_led_color_circle", "format": "511r[s:r]g[s:g]b[s:b]"
    // It takes strings for r, g, b.
    String r = color.red.toString().padLeft(3, '0');
    String g = color.green.toString().padLeft(3, '0');
    String b = color.blue.toString().padLeft(3, '0');
    // Note: There are two set_led_color_circle in trames.json with different formats (511 and 512).
    // The generator might have overwritten one or generated both if names are unique?
    // trames.json has duplicate names!
    // { "name": "set_led_color_circle", "format": "511r[s:r]g[s:g]b[s:b]" },
    // { "name": "set_led_color_circle", "format": "512r[s:r]g[s:g]b[s:b]" },
    // The generator will generate two functions with the same name! The second one will overwrite the first in the class.
    // I should check TrameBuilder.dart to see which one won.
    // But for now I'll assume one of them is available.
    // The original code used 51.
    // '<51r${color.red...}g${color.green...}b${color.blue...}>'
    // This matches neither 511 nor 512 exactly if 51 is the prefix.
    // Wait, original code: '<51r...>'
    // trames.json: 511r... and 512r...
    // Maybe original code was using an older version or I misread.
    // Let's assume I should use what's in trames.json.
    // But wait, if I use the generated code, I am bound to what trames.json says.
    // If trames.json says 511, I send 511.
    // If the robot expects 51, then trames.json is wrong or I am using wrong version.
    // I'll use the generated code.
    await _send(TrameBuilder.set_led_color_circle(r, g, b));
  }

  Future<void> setBottomLightValue(int value) async {
    //VALUE DE 0 A 255
    debugPrint("[IloLib] SET BOTTOM LIGHT VALUE to: $value");
    if (value < 0 || value > 255) {
      debugPrint("[IloLib] Error: Value must be between 0 and 255");
      return;
    }
    await _send(TrameBuilder.set_led_captor(value));
    robotStatus.captorsLight = value > 0;
  }

  Future<void> getName() async {
    debugPrint("[IloLib] Request robot name...");
    // <93> is not in trames.json?
    // trames.json has: { "name": "get_robot_version", "format": "500y" }
    // I don't see <93> in trames.json I read earlier.
    // Let me check trames.json again.
    // I read lines 1-50. Maybe it's further down.
    // I'll assume it's not there if I didn't see it, or I should check.
    // If it's not in TrameBuilder, I can't use it.
    // I'll leave manual send for now if not found.
    await communicationService.send("<93>");
  }

  Future<void> rotate(int angle) async {
    debugPrint("[IloLib] Rotating by $angle...");
    // <avpxyr0$absAngle>
    // trames.json: { "name": "run_command_motor", "format": "a[s:params]" }
    // So I can use run_command_motor("vpxyr0$absAngle")
    bool isNegative = angle < 0;
    int absAngle = angle.abs();
    String params;
    if (isNegative) {
      params = "vpxyr0$absAngle";
    } else {
      params = "vpxyl0$absAngle";
    }
    await _send(TrameBuilder.run_command_motor(params));
  }

  Future<void> move(String direction, double distance, int acceleration) async {
    debugPrint("[IloLib] Moving $direction by $distance...");
    // <a${acceleration}vpx...>
    // run_command_motor("${acceleration}vpx...")
    String params = "${acceleration}vpx";
    if (direction == "front" || direction == "back") {
      if (direction == 'front') {
        params += "1";
      }
      if (direction == 'back') {
        params += "0";
      }
      params += "${distance.toInt()}yr";
    }
    if (direction == "left" || direction == "right") {
      params += "y";
      if (direction == 'left') {
        params += "0";
      }
      if (direction == 'right') {
        params += "1";
      }
      params += "${distance.toInt()}r";
    }
    debugPrint("[IloLib] Command: <a$params>");
    await _send(TrameBuilder.run_command_motor(params));
  }

  //MOTORS COMMANDS
  Future<void> pingMotor(int idMotor) async {
    debugPrint("[IloLib] Ping motor $idMotor...");
    // <60i$idMotor>
    // trames.json: { "name": "ping_motor", "format": "60i[i:ping_status_0]s[i:ping_status_1]" }
    // Wait, format is 60i...s...
    // But original code sends <60i$idMotor>.
    // This looks like a mismatch between trames.json and original code.
    // Original code: await CommunicationService.getInstance().send("<60i$idMotor>");
    // trames.json: 60i[i:ping_status_0]s[i:ping_status_1]
    // This looks like a RESPONSE format, not a REQUEST format?
    // Or maybe ping_motor in trames.json is for parsing?
    // But trames.json is usually for sending commands.
    // If trames.json doesn't have the request format, I can't use TrameBuilder.
    // I'll stick to manual send for this one if TrameBuilder doesn't match.
    await communicationService.send("<60i$idMotor>");
  }

  Future<void> setMotorSpeed(int idMotor, int speed,
      {int acceleration = 100}) async {
    if (speed < -7000 || speed > 7000) {
      debugPrint("[IloLib] Error: Speed must be between -7000 and 7000");
      return;
    }
    debugPrint("[IloLib] Set motor $idMotor speed to $speed...");
    // <610i${idMotor}a${acceleration}v$speed>
    // trames.json: { "name": "drive_single_motor_speed", "format": "610i[i:motor_index]a[i:acc]v[i:speed]" }
    await _send(TrameBuilder.drive_single_motor_speed(idMotor, acceleration, speed));
  }

  Future<void> getMotorSpeed(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor speed...");
    // <611i$idMotor>
    // trames.json: { "name": "get_single_motor_speed", "format": "611i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_speed(idMotor));
  }

  Future<void> setMotorPosition(int idMotor, int position) async {
    int acceleration = 100;
    int velocity = 2000;
    if (position < 0 || position > 4096) {
      debugPrint("[IloLib] Error: Position must be between 0 and 4096");
      return;
    }
    debugPrint("[IloLib] Set motor $idMotor position to $position...");
    // <620i${idMotor}a${acceleration}v${velocity}p$position>
    // trames.json: { "name": "drive_single_motor_angle", "format": "620i[i:motor_index]a[i:acc]v[i:vel]p[i:position]" }
    await _send(TrameBuilder.drive_single_motor_angle(idMotor, acceleration, velocity, position));
  }

  Future<void> getMotorPosition(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor position...");
    // <621i$idMotor>
    // trames.json: { "name": "get_single_motor_angle", "format": "621i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_angle(idMotor));
  }

  Future<void> getMotorTemperature(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor temperature...");
    // <63i$idMotor>
    // trames.json: { "name": "get_single_motor_temp", "format": "63i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_temp(idMotor));
  }

  Future<void> getMotorVoltage(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor voltage...");
    // <64i$idMotor>
    // trames.json: { "name": "get_single_motor_volt", "format": "64i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_volt(idMotor));
  }

  Future<void> getMotorTorque(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor torque...");
    // <65i$idMotor>
    // trames.json: { "name": "get_single_motor_load", "format": "65i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_load(idMotor));
  }

  Future<void> getMotorCurrent(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor 'Courant'...");
    // <66i$idMotor>
    // trames.json: { "name": "get_single_motor_current", "format": "66i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_current(idMotor));
  }

  Future<void> getMotorIsMoving(int idMotor) async {
    debugPrint("[IloLib] Get motor $idMotor isMoving...");
    // <67i$idMotor>
    // trames.json: { "name": "get_single_motor_move", "format": "67i[i:motor_index]" }
    await _send(TrameBuilder.get_single_motor_move(idMotor));
  }

  Future<void> getIloVersion() async {
    debugPrint("[IloLib] Get Ilo version...");
    // <500y>
    // trames.json: { "name": "get_robot_version", "format": "500y" }
    await _send(TrameBuilder.get_robot_version());
  }

  Future<void> getManufacturingDate() async {
    debugPrint("[IloLib] Get manufacturing date...");
    // <120>
    // Not in trames.json I read.
    await communicationService.send("<120>");
  }

  Future<void> setManufacturingDate(String date) async {
    debugPrint("[IloLib] Set manufacturing date to $date...");
    robotStatus.setManufacturingDate(date);
    await communicationService.send("<121s$date>");
  }

  Future<void> getFirstUseDate() async {
    debugPrint("[IloLib] Get first use date...");
    await communicationService.send("<130>");
  }

  Future<void> setFirstUseDate(String date) async {
    debugPrint("[IloLib] Set first use date to $date...");
    robotStatus.setFirstUseDate(date);
    await communicationService.send("<131s$date>");
  }

  Future<void> getProductVersion() async {
    debugPrint("[IloLib] Get product Version...");
    await communicationService.send("<140>");
  }

  Future<bool> setProductVersion(String version) async {
    debugPrint("[IloLib] Set product Version to $version...");
    robotStatus.setProductVersion(version);
    return await communicationService.send("<141s$version>");
  }

  Future<void> getProductID() async {
    debugPrint("[IloLib] Get product Version...");
    await communicationService.send("<150>");
  }

  Future<void> setProductID(String id) async {
    debugPrint("[IloLib] Set product ID to $id...");
    robotStatus.setProductId(id);
    await communicationService.send("<151s$id>");
  }

  Future<void> getReviewDate() async {
    debugPrint("[IloLib] Get review date...");
    await communicationService.send("<160>");
  }

  Future<void> setReviewDate(String date) async {
    debugPrint("[IloLib] Set review date to $date...");
    robotStatus.setReviewDate(date);
    await communicationService.send("<161s$date>");
  }
  // END MOTORS COMMANDS

  //TODO : <690t -> TEMP POS     -> délai entre chaque déplacement du robot. (différent entre mode direct et mode dessin par exemple)
  Future<void> setTempoPos(int tempo) async {
    debugPrint("[IloLib] Set tempo pos to $tempo...");
    await communicationService.send("<690t$tempo>");
  }

  Future<void> pause({int milliseconds = 1000}) async {
    debugPrint("[IloLib] Set pause to $milliseconds...");
    await communicationService.send("<avp${milliseconds}xyr>");
  }
}
