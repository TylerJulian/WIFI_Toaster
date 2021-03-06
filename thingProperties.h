// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "d3d18253-e46e-498a-8dfe-235c1163ae1a";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onMotorContorllerChange();
void onMyLEDChange();
void onOpenDoorChange();

float ultrasonic;
int motorContorller;
bool isBread;
bool myLED;
bool openDoor;
bool startToast

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(ultrasonic, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(motorContorller, READWRITE, ON_CHANGE, onMotorContorllerChange);
  ArduinoCloud.addProperty(isBread, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(myLED, READWRITE, ON_CHANGE, onMyLEDChange);
  ArduinoCloud.addProperty(openDoor, READWRITE, ON_CHANGE, onOpenDoorChange);
  ArduinoCloud.addProperty(startToast, READWRITE, ON_CHANGE, onStartToastChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
