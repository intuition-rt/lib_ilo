import 'package:flutter/foundation.dart';

enum RobotStatusSensor {
  SENSOR_FRONT,
  SENSOR_BACK,
  SENSOR_LEFT,
  SENSOR_RIGHT,
}

class RobotStatus extends ChangeNotifier {
  static const double LOW_BATTERY_THRESHOLD = 15;
  static const double CRITICAL_BATTERY_THRESHOLD = 5;

  bool get isLowBattery =>
      _batteryLevel != null && _batteryLevel! < LOW_BATTERY_THRESHOLD;
  bool get isCriticalBattery =>
      _batteryLevel != null && _batteryLevel! < CRITICAL_BATTERY_THRESHOLD;
  int? _batteryLevel;
  bool? _batteryCharging;
  double? _batteryVoltage;
  bool _connected = false;
  String? _error;
  final Set<RobotStatusSensor> _obstacles = {};

  String? name;
  String? version;

  /*
      INFOS COMPLEMENTAIRES
  */

  String? productVersion;
  String? productId;
  String? manufacturingDate;
  String? firstUseDate;
  String? reviewDate;

  void setProductVersion(String version) {
    productVersion = version;
    notifyListeners();
  }

  void setProductId(String id) {
    productId = id;
    notifyListeners();
  }

  void setManufacturingDate(String date) {
    manufacturingDate = date;
    notifyListeners();
  }

  void setFirstUseDate(String date) {
    firstUseDate = date;
    notifyListeners();
  }

  void setReviewDate(String date) {
    reviewDate = date;
    notifyListeners();
  }

  double? imuRoll;
  double? imuPitch;
  double? imuYaw;

  int? sensorFront = 0;
  int? sensorBack = 0;
  int? sensorLeft = 0;
  int? sensorRight = 0;

  bool captorsLight = false;

  int? get batteryLevel => _batteryLevel;

  bool get isBatteryCharging => _batteryCharging == true;
  bool get isConnected => _connected;
  bool get hasError => _error != null;
  bool get hasLeftObstacle =>
      _obstacles.contains(RobotStatusSensor.SENSOR_LEFT);
  bool get hasRightObstacle =>
      _obstacles.contains(RobotStatusSensor.SENSOR_RIGHT);
  bool get hasFrontObstacle =>
      _obstacles.contains(RobotStatusSensor.SENSOR_FRONT);
  bool get hasBackObstacle =>
      _obstacles.contains(RobotStatusSensor.SENSOR_BACK);

  final Map<RobotStatusSensor, int> _obstacleDistances = {
    RobotStatusSensor.SENSOR_FRONT: 0,
    RobotStatusSensor.SENSOR_BACK: 0,
    RobotStatusSensor.SENSOR_LEFT: 0,
    RobotStatusSensor.SENSOR_RIGHT: 0,
  };

  List<Map<String, dynamic>> motors = [
    {
      'motor': 1,
      'status': true,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 2,
      'status': true,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 3,
      'status': true,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false,
    },
    {
      'motor': 4,
      'status': true,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 5,
      'status': false,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 6,
      'status': false,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 7,
      'status': false,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
    {
      'motor': 8,
      'status': false,
      'speed': 0,
      'position': 0,
      'temperature': 0,
      'voltage': 0,
      'torque': false,
      'current': 0,
      'isMoving': false
    },
  ];

  String? diagnostic;

  void setSensors(int front, int right, int back, int left) {
    sensorFront = front;
    sensorRight = right;
    sensorBack = back;
    sensorLeft = left;
    notifyListeners();
  }

  void setName(String newName) {
    name = newName;
    notifyListeners();
  }

  void setVersion(String newVersion) {
    version = newVersion;
    notifyListeners();
  }

  void setDiagnostic(String newDiagnostic) {
    diagnostic = newDiagnostic;
    notifyListeners();
  }

  void setConnected(bool connected) {
    _connected = connected;
    notifyListeners();
  }

  // Methods to update state (extracted from MsgParser usage)
  void setBottomColorCenter(int r, int g, int b) {
    // TODO: Implement storage for color if needed
    notifyListeners();
  }

  void setImu(double roll, double pitch, double yaw) {
    imuRoll = roll;
    imuPitch = pitch;
    imuYaw = yaw;
    notifyListeners();
  }

  void setMotorInfo(String key, int motorId, dynamic value) {
    if (motorId >= 1 && motorId <= motors.length) {
      motors[motorId - 1][key] = value;
      notifyListeners();
    }
  }
}
