# M5Stack Bluetooth rosserial example

This is a simple rosserial example on bluetooth SPP with M5Stack
You can use this example for other ESP32 board with slight changes.

## How to build

This repo is tested with Ubuntu 18.04 + ROS Melodic + M5Stack Fire, and the project is for PlatformIO.

- M5Stack
- rosserial
- platformio

```bash
pip install platformio
```

and if you want to use other board. please configure the project like

```bash
cd firmware
pio init -b m5stick-c
```

After that, please generate ros_lib

```bash
cd <this repo>/firmware/lib
rosrun rosserial_arduino make_libraries.py
```

And you can now build the project and burn it to your board.

```bash
pio run -t upload --upload-port <serial port to your board>
```

## How to run

Before actually use it, please pair and connect your device to PC.

```bash
bluetoothctl
scan on # check your device is visible and
scan off
pair <MAC Address of your device>
trust <MAC Address of your device>
connect <MAC Address of your device>
info <MAC Address of your device>
```

and bind bluetooth spp

```bash
sudo rfcomm bind 1 <MAC Address of your device>
sudo stty -F /dev/rfcomm1 57600 cs8
```

then you can now run rosserial

```bash
roscore
```

```bash
rosrun rosserial_python serial_node.py _port:=/dev/rfcomm1 _baud:=57600
```
