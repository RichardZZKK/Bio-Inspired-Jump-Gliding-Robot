#include <ArduinoBLE.h>
#include "Arduino_BMI270_BMM150.h"
#include <Wire.h>
#include <Servo.h>
#include "include.h"
#include "SerialServo.h"

Servo servo1;
Servo servo2;

// BLE characteristics
BLEService sensorService("180F");
BLEByteCharacteristic servoCommandCharacteristic("2A19", BLEWrite);
BLECharacteristic imuDataCharacteristic("2A58", BLENotify, 36);

unsigned long previousMillis = 0;
const long interval = 50;
const int motorPin = 3;     // D3 pin controls the MOSFET gate for the 6V motor
const int clutchPin = 4;    // D4 pin controls the MOSFET gate for the 24V electromagnetic clutch

void setup() {
  Serial1.begin(115200);
  Wire.begin();
  servo1.attach(9);   // D9 pin controls a potential future servo motor
  servo2.attach(10);  // D10 pin controls a potential future servo motor

  // Initialize clutch and motor
  pinMode(motorPin, OUTPUT);
  pinMode(clutchPin, OUTPUT);
   digitalWrite(clutchPin, LOW);
   digitalWrite(motorPin, LOW);

  // Initialize Bluetooth
  if (!BLE.begin()) {
    while (1);
  }
  BLE.setLocalName("Nano33BLE_IMU");
  BLE.setAdvertisedService(sensorService);
  sensorService.addCharacteristic(servoCommandCharacteristic);
  sensorService.addCharacteristic(imuDataCharacteristic);
  BLE.addService(sensorService);
  BLE.advertise();

  // Initialize potential future IMU usage
  if (!IMU.begin()) {
    while (1);
  }
}
  // Function to send IMU data (potential future use)
void sendIMUData() {
  float ax, ay, az, gx, gy, gz, mx, my, mz;

  if (IMU.accelerationAvailable()) IMU.readAcceleration(ax, ay, az);
  if (IMU.gyroscopeAvailable()) IMU.readGyroscope(gx, gy, gz);
  if (IMU.magneticFieldAvailable()) IMU.readMagneticField(mx, my, mz);

  byte imuData[36];
  memcpy(&imuData[0], &ax, 4);
  memcpy(&imuData[4], &ay, 4);
  memcpy(&imuData[8], &az, 4);
  memcpy(&imuData[12], &gx, 4);
  memcpy(&imuData[16], &gy, 4);
  memcpy(&imuData[20], &gz, 4);
  memcpy(&imuData[24], &mx, 4);
  memcpy(&imuData[28], &my, 4);
  memcpy(&imuData[32], &mz, 4);

  imuDataCharacteristic.writeValue(imuData, 36);
}
void loop() {
  BLEDevice central = BLE.central();

  if (central) {
    while (central.connected()) {
      if (servoCommandCharacteristic.written()) {
        byte command = servoCommandCharacteristic.value();
        // When input '1', send automatic pull and release commands
       if (command == 1) {
          // Pull rope
         digitalWrite(motorPin, HIGH);   // Start motor rotation
         digitalWrite(clutchPin, HIGH);  // Power clutch to prepare for pulling
          delay(5000);                   // Run motor for a few seconds
          // Release rope 
          digitalWrite(motorPin, LOW);  // Cut power to motor
          digitalWrite(clutchPin, HIGH);  // Cut power to clutch to release
        }

        // When input '2', for timing tests, start motor and clutch
        else if (command == 2) {
        // Pull rope 
         digitalWrite(motorPin, HIGH);  // Start motor rotation
         digitalWrite(clutchPin, HIGH); // Power clutch to prepare for pullin
        } 

        // When input '3', currently unused; may control gliding in future
        else if (command == 3) {
          LobotSerialServoMove(Serial1, 1, 400, 800);
          LobotSerialServoMove(Serial1, 2, 400, 800);
        }  
        
        // When input '4', currently unused; may control gliding in future
        else if (command == 4) {
          LobotSerialServoMove(Serial1, 1, 800, 400);
          LobotSerialServoMove(Serial1, 2, 800, 400);
        }
      }  
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        sendIMUData();
      }
    }
  }
}
