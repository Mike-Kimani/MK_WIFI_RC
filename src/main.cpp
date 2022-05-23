#include <Arduino.h>
#include <functions.h>
#include <defs.h>

//pinMode(2, OUTPUT);

void setup() {
  // put your setup code here, to run once:
pinMode(blueonboard, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(ena, OUTPUT);
pinMode(button, INPUT_PULLDOWN);
pinMode(button2, INPUT_PULLDOWN);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //indicate(blueonboard);
  driveforward();
  throttletime();
  Serial.println(period);
  timedacceleration();
}