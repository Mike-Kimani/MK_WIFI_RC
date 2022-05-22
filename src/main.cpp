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
}

void loop() {
  // put your main code here, to run repeatedly:
indicate(blueonboard);
}