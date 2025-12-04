import 'dart:async';
import 'dart:io';
import 'package:flutter/foundation.dart';
import 'package:flutter_blue_plus/flutter_blue_plus.dart';
import 'package:web_socket_channel/web_socket_channel.dart';

import 'msg_parser.dart';
import 'robot_status.dart';

class CommunicationService {
  final RobotStatus robotStatus;
  late final MsgParser msgParser;

  CommunicationService(this.robotStatus) {
    msgParser = MsgParser(robotStatus);
  }

  WebSocket? robotSocket;
  WebSocketChannel? _apiWebSocketChannel;
  StreamSubscription? _apiWebSocketSubscription;
  
  BluetoothDevice? bluetoothDevice;
  BluetoothCharacteristic? bluetoothCharacteristic;
  StreamSubscription? bluetoothSubscription;

  bool isConnected = false;
  bool useBluetooth = false;
  bool useSerial = false; // Serial not fully implemented in this binding yet

  // Stream for raw messages if needed by external consumers
  final StreamController<String> _messageController =
      StreamController<String>.broadcast();
  Stream<String> get messageStream => _messageController.stream;

  Future<bool> connectSocket(String ip, int port) async {
    try {
      debugPrint("[CommunicationService] Connecting to socket $ip:$port...");
      robotSocket = await WebSocket.connect('ws://$ip:$port');
      robotSocket!.listen(
        (data) {
          String message = data.toString();
          _handleMessage(message);
        },
        onDone: () {
          debugPrint("[CommunicationService] Socket closed");
          isConnected = false;
          robotStatus.setConnected(false);
        },
        onError: (error) {
          debugPrint("[CommunicationService] Socket error: $error");
          isConnected = false;
        },
      );
      isConnected = true;
      debugPrint("[CommunicationService] Socket connected");
      return true;
    } catch (e) {
      debugPrint("[CommunicationService] Socket connection failed: $e");
      return false;
    }
  }

  Future<bool> connectBluetooth(BluetoothDevice device) async {
    try {
      debugPrint("[CommunicationService] Connecting to Bluetooth device ${device.platformName}...");
      await device.connect();
      bluetoothDevice = device;
      
      // Discover services
      List<BluetoothService> services = await device.discoverServices();
      for (var service in services) {
        // Look for specific service/characteristic if known, or just iterate
        // Based on original code: service starts with 5f, char notify & read
        if (service.uuid.toString().startsWith("5f")) {
           for (var char in service.characteristics) {
             if (char.properties.notify && char.properties.read) {
               bluetoothCharacteristic = char;
               await char.setNotifyValue(true);
               bluetoothSubscription = char.lastValueStream.listen((value) {
                 String message = String.fromCharCodes(value);
                 _handleMessage(message);
               });
               debugPrint("[CommunicationService] Bluetooth connected and listening");
               isConnected = true;
               useBluetooth = true;
               return true;
             }
           }
        }
      }
      debugPrint("[CommunicationService] No suitable characteristic found");
      return false;
    } catch (e) {
      debugPrint("[CommunicationService] Bluetooth connection failed: $e");
      return false;
    }
  }

  void disconnect() {
    robotSocket?.close();
    _apiWebSocketChannel?.sink.close();
    bluetoothSubscription?.cancel();
    bluetoothDevice?.disconnect();
    isConnected = false;
    useBluetooth = false;
  }

  void _handleMessage(String message) {
    // debugPrint("[CommunicationService] Received: $message");
    _messageController.add(message);
    msgParser.parse(message);
  }

  Future<bool> send(String message, {bool debug = true}) async {
    if (debug) {
      // debugPrint("[CommunicationService] Sending: $message");
    }

    try {
      if (useBluetooth && bluetoothCharacteristic != null) {
        // Split message if too long? Bluetooth MTU is usually small.
        // Original code didn't seem to split explicitly but maybe flutter_blue_plus handles it or messages are short.
        await bluetoothCharacteristic!.write(message.codeUnits, withoutResponse: true); // or false
        return true;
      } else if (robotSocket != null && robotSocket!.readyState == WebSocket.open) {
        robotSocket!.add(message);
        return true;
      } else if (_apiWebSocketChannel != null) {
         _apiWebSocketChannel!.sink.add(message); // Simplified API send
         return true;
      }
    } catch (e) {
      debugPrint("[CommunicationService] Send failed: $e");
    }
    return false;
  }
}
