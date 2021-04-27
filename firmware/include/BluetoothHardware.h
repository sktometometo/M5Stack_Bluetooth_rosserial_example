#ifndef ROS_ARDUINO_BLUETOOTH_HARDWARE_H_
#define ROS_ARDUINO_BLUETOOTH_HARDWARE_H_

#include <Arduino.h>
#include "BluetoothSerial.h"

class BluetoothHardware {
public:
  BluetoothHardware()
  {
  }

  void init()
  {
    bluetooth_serial.begin("ESP32ROS");
  }

  void init(char *name)
  {
    bluetooth_serial.begin(name);
  }

  int read(){
    return bluetooth_serial.read();
  }

  void write(const uint8_t* data, int length)
  {
    bluetooth_serial.write(data, length);
  }

  unsigned long time()
  {
    return millis();
  }

protected:
  BluetoothSerial bluetooth_serial;
};

#endif
