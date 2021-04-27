#include <M5Stack.h>
#include <ros/node_handle.h>
#include <BluetoothHardware.h>
#include <std_msgs/String.h>

ros::NodeHandle_<BluetoothHardware> nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  M5.begin();
  M5.Lcd.begin();
  nh.initNode();
  nh.advertise(chatter);

  M5.Lcd.print("M5Stack rosserial with bluetooth\n");

  while (not nh.connected()) {
      nh.spinOnce();
      delay(100);
  }
  M5.Lcd.print("Bluetooth connected.");
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
