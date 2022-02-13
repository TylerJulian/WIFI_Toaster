#include "arduino_secrets.h"
/*
  The following variables are automatically generated and updated when changes are made to the Thing

  float ultrasonic;
  int motorContorller;
  bool isBread;
  bool myLED;
*/

#include "thingProperties.h"
#include <Servo.h> 

int ledPin = 33;
int trigPin = 23;
int echoPin = 22;
int breadDistCalabration = 10;
int servoPin1 = 19;
int servoPin2 = 18;

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int toastDistance;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);



  // Cloud Connection stuff
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  //random error stuff
  // setDebugMessageLevel(1);
  // ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Displays the distance on the Serial Monitor
  servoPin1 = 1;
  servoPin2 = 0; 
  checkIfToast();

}

/*
  Since MyLED is READ_WRITE variable, onMyLEDChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMyLEDChange()  {
  // Add your code here to act upon MyLED change
  if (myLED) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

/*
  Since MotorContorller is READ_WRITE variable, onMotorContorllerChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMotorContorllerChange()  {
}

void checkIfToast() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  isBread = (distance <=  breadDistCalabration);
}
/*
  Since StartToast is READ_WRITE variable, onStartToastChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onStartToastChange()  {
  if(tartToast){
    servoPin1 = 0;
    delay(2000);
    servoPin2 = 1; 
  }
  // Add your code here to act upon StartToast change
}