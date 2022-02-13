#include "toaster.h"
#include <Servo.h>


// init objects/modules
Servo trapdoor; // this servo controls the trapdoor.

//pin inits
int potpin = 0; // potentiometer pin for reading analog in.

//globals
int val;

void setup() {
  // put your setup code here, to run once:
  trapdoor.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1000, 2000);     // scale it to use it with the servo (value between 0 and 180)

  if (val > 90){ 
    trapdoor.writeMicroseconds(val); 
  }
  else{
    trapdoor.writeMicroseconds(val); 
  }
  Serial.println(val);
}
