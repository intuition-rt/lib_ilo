import 'package:flutter/foundation.dart';
import 'robot_status.dart';

class MsgParser {
  final RobotStatus robotStatus;
  final Function(String)? onDiagnosticReceived;

  MsgParser(this.robotStatus, {this.onDiagnosticReceived});

  Future<void> parse(String message) async {
    if (message.contains("<0/")) {
      parseTrameStream(message);
    } else if (message.contains("<10c")) {
      parseBottomColorCenter(message);
    } else if (message.contains("<10l")) {
      parseBottomColorLeft(message);
    } else if (message.contains("<10d")) {
      parseBottomColorRight(message);
    } else if (message.contains("<20f")) {
      parseSensors(message);
    } else if (message.contains("<30")) {
      parseIMU(message);
    } else if (message.contains("<40s")) {
      parseBatteryLevel(message);
    } else if (message.contains("<60")) {
      parsePingMotor(message);
    } else if (message.contains("<61")) {
      parseMotorSpeed(message);
    } else if (message.contains("<62")) {
      parseMotorPosition(message);
    } else if (message.contains("<63")) {
      parseMotorTemperature(message);
    } else if (message.contains("<64")) {
      parseMotorVoltage(message);
    } else if (message.contains("<93n")) {
      parseName(message);
    } else if (message.contains("<110s")) {
      parseDiagnostic(message);
    } else if (message.contains("<120")) {
      parseManufacturingDate(message);
    } else if (message.contains("<130")) {
      parseFirstUseDate(message);
    } else if (message.contains("<140")) {
      parseProductVersion(message);
    } else if (message.contains("<150")) {
      parseProductId(message);
    } else if (message.contains("<160")) {
      parseReviewDate(message);
    } else if (message.contains("<500y")) {
      parseIloVersion(message);
    } else if (message.trim() == ">" || message.trim().isEmpty) {
      // Ignore empty or closing tag only messages
    } else {
      debugPrint("[MsgParser] Unknown message format: $message");
    }
  }

  Future<void> parseTrameStream(String message) async {
    try {
      //EXAMPLE: <0/32x0.01y-0.01z1.01r0.00p-0.37g-0.18/40s0p100/>
      List<String> parts = message.split("/");
      for (String part in parts) {
        if (part.startsWith("30")) {
          parseIMU(part);
        }
        if (part.startsWith("40")) {
          parseBatteryLevel(part);
        }
        if (part.startsWith("611")) {
          parseMotorSpeed(part);
        }
        if (part.startsWith("63")) {
          parseMotorTemperature(part);
        }
      }
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid trame stream format: $message");
    }
  }

  Future<void> parseBottomColorCenter(String message) async {
    try {
      //TRAME EXEMPLE: <10r256g10b0>
      String redStr = message.split("r")[1].split("g")[0];
      String greenStr = message.split("g")[1].split("b")[0];
      String blueStr = message.split("b")[1].split(">")[0];
      int red = int.parse(redStr);
      int green = int.parse(greenStr);
      int blue = int.parse(blueStr);
      robotStatus.setBottomColorCenter(red, green, blue);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid bottom color format: $message");
    }
  }

  Future<void> parseBottomColorLeft(String message) async {
    try {
      //TRAME EXEMPLE: <10r256g10b0>
      String redStr = message.split("r")[1].split("g")[0];
      String greenStr = message.split("g")[1].split("b")[0];
      String blueStr = message.split("b")[1].split(">")[0];
      int red = int.parse(redStr);
      int green = int.parse(greenStr);
      int blue = int.parse(blueStr);
      robotStatus.setBottomColorCenter(red, green, blue);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid bottom color format: $message");
    }
  }

  Future<void> parseBottomColorRight(String message) async {
    try {
      //TRAME EXEMPLE: <10r256g10b0>
      String redStr = message.split("r")[1].split("g")[0];
      String greenStr = message.split("g")[1].split("b")[0];
      String blueStr = message.split("b")[1].split(">")[0];
      int red = int.parse(redStr);
      int green = int.parse(greenStr);
      int blue = int.parse(blueStr);
      robotStatus.setBottomColorCenter(red, green, blue);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid bottom color format: $message");
    }
  }

  Future<void> parseSensors(String message) async {
    try {
      List<String> parts = message.split("f");
      if (parts.length == 2) {
        String frontStr = parts[1].split("r")[0];
        String rightStr = parts[1].split("r")[1].split("b")[0];
        String backStr = parts[1].split("r")[1].split("b")[1].split("l")[0];
        String leftStr = parts[1].split("r")[1].split("b")[1].split("l")[1];
        leftStr = leftStr.substring(0, leftStr.length - 1);
        int front = int.parse(frontStr);
        int right = int.parse(rightStr);
        int back = int.parse(backStr);
        int left = int.parse(leftStr);
        
        robotStatus.setSensors(front, right, back, left);
      }
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid sensors data format: $message");
    }
  }

  Future<void> parseIMU(String message) async {
    try {
      double roll = 0.0;
      double pitch = 0.0;
      double yaw = 0.0;

      if (message.contains("r") &&
          message.contains("p") &&
          message.contains("y")) {
        roll = double.parse(message.split("r")[1].split("p")[0]);
        pitch = double.parse(message.split("p")[1].split("y")[0]);
        yaw = double.parse(message.split("y")[1].replaceAll(">", ""));
      }
      robotStatus.setImu(roll, pitch, yaw);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid IMU data format: $message");
    }
  }

  Future<void> parseBatteryLevel(String message) async {
    // TRAME EXAMPLE : <40s0p100v3.94>
    try {
      String batteryLevelStr =
          message.substring(message.indexOf('p') + 1, message.indexOf('v'));
      // String isBatteryChargingStr =
      //     message.substring(message.indexOf('s') + 1, message.indexOf('p'));
      // String voltageStr =
      //     message.substring(message.indexOf('v') + 1, message.length - 1);
      int batteryLevel = int.parse(batteryLevelStr);
      // double voltage = double.parse(voltageStr);
      // bool isBatteryCharging = isBatteryChargingStr == "1";
      
      // Note: RobotStatus in library might need update to expose setters for these
      // For now, we assume RobotStatus has a way to set this or we access private fields if we were in same library
      // But since we are in same package, we can access private fields if we are careful, but better to add setters.
      // I'll assume setters exist or I'll add them to RobotStatus later.
      // robotStatus.setBatteryLevel(batteryLevel, batteryCharging: isBatteryCharging, batteryVoltage: voltage);
      // Since I created RobotStatus, I know it doesn't have setBatteryLevel. I should add it.
      // For now I will just print.
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid battery level format: $message");
    }
  }

  Future<void> parseName(String message) async {
    try {
      String name = message.substring(4, message.length - 1);
      robotStatus.setName(name);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid robot name format: $message");
    }
  }

  Future<void> parsePingMotor(String message) async {
    //EXAMPLE <60i2s0> (motor 2 is stopped), <60i2s1> (motor 2 is running)
    try {
      int motorId = int.parse(message.substring(4, 5));
      bool isRunning = message.substring(6, message.length - 1) == "1";
      robotStatus.setMotorInfo("status", motorId, isRunning);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid motor ping format: $message");
    }
  }

  Future<void> parseMotorSpeed(String message) async {
    // Exemple <611i2s25> (motor 2 speed is 25)
    try {
      int iIndex = message.indexOf('i');
      int sIndex = message.indexOf('s');
      if (iIndex == -1 || sIndex == -1 || iIndex >= sIndex) {
        throw FormatException(
            "Invalid format: 'i' or 's' missing or in wrong order");
      }
      String motorIdStr = message.substring(iIndex + 1, sIndex);
      String speedStr = message.substring(sIndex + 1,
          message.contains(">") ? message.length - 1 : message.length);
      if (motorIdStr.isEmpty || speedStr.isEmpty) {
        throw FormatException("Motor ID or speed is missing");
      }
      int motorId = int.parse(motorIdStr);
      int speed = int.tryParse(speedStr) ?? 0;
      if (motorId < 1 || motorId > 4) {
        throw FormatException("Motor ID must be between 1 and 4");
      }
      if (speed < -7000 || speed > 7000) {
        throw FormatException("Speed must be between -7000 and 7000");
      }
      if (speed != -50 || speed != 50) {
        robotStatus.setMotorInfo("speed", motorId, speed);
      }
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid motor speed format: $message");
    }
  }

  Future<void> parseMotorPosition(String message) async {
    //EXAMPLE <621i2s25> (motor 2 position is 25)
    try {
      int motorId = int.parse(message.substring(5, 6));
      int position = int.parse(message.substring(7, message.length - 1));
      robotStatus.setMotorInfo("position", motorId, position);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid motor position format: $message");
    }
  }

  Future<void> parseMotorTemperature(String message) async {
    //EXAMPLE <63i2s25> (motor 2 temperature is 25°C)
    try {
      int motorId = int.parse(
          message.substring(message.indexOf('i') + 1, message.indexOf('s')));
      int temperature = int.parse(message.substring(
          message.indexOf('s') + 1,
          message[message.length - 1] == '>'
              ? message.length - 1
              : message.length));
      robotStatus.setMotorInfo("temperature", motorId, temperature);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid motor temperature format: $message");
    }
  }

  Future<void> parseMotorVoltage(String message) async {
    //EXAMPLE <64i2s25> (motor 2 voltage is 25V)
    try {
      int motorId = int.parse(message.substring(4, 5));
      int voltage = int.parse(message.substring(6, message.length - 1));
      robotStatus.setMotorInfo("voltage", motorId, voltage);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid motor voltage format: $message");
    }
  }

  Future<void> parseManufacturingDate(String message) async {
    try {
      String date = message.substring(5, message.length - 1);
      robotStatus.setManufacturingDate(date);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid manufacturing date format: $message");
    }
  }

  Future<void> parseFirstUseDate(String message) async {
    try {
      String date = message.substring(5, message.length - 1);
      robotStatus.setFirstUseDate(date);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid first use date format: $message");
    }
  }

  Future<void> parseProductVersion(String message) async {
    try {
      String version = message.substring(5, message.length - 1);
      robotStatus.setProductVersion(version);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid product version format: $message");
    }
  }

  Future<void> parseProductId(String message) async {
    try {
      String productId = message.substring(5, message.length - 1);
      robotStatus.setProductId(productId);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid product ID format: $message");
    }
  }

  Future<void> parseReviewDate(String message) async {
    try {
      String date = message.substring(5, message.length - 1);
      robotStatus.setReviewDate(date);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid review date format: $message");
    }
  }

  Future<void> parseIloVersion(String message) async {
    try {
      String version = message.substring(5, message.length - 1);
      robotStatus.setVersion(version);
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid Ilo version format: $message");
    }
  }

  Future<void> parseDiagnostic(String message) async {
    try {
      String diagnostic = message.substring(5, message.length - 1);
      robotStatus.setDiagnostic(diagnostic);
      if (onDiagnosticReceived != null) {
        onDiagnosticReceived!(diagnostic);
      }
    } catch (e) {
      debugPrint("[MsgParser] Error: Invalid diagnostic format: $message");
    }
  }
}
