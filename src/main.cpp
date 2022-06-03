#include <Arduino.h>
#include <functions.h>
#include <webserver.h>
//pinMode(2, OUTPUT);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
pinMode(blueonboard, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(ena, OUTPUT);
//Check if line 14 below is necessary
//pinMode(servopin, OUTPUT);
// pinMode(accelerator, INPUT_PULLDOWN);
// pinMode(decelerator, INPUT_PULLDOWN);
// pinMode(rightsteer, INPUT_PULLDOWN);
// pinMode(leftsteer, INPUT_PULLDOWN);
// pinMode(centresteer, INPUT_PULLDOWN);


steeringservo.attach(servopin);


wificonnect();
clientinput();

}

void loop() {
  //put your main code here, to run repeatedly:
  //indicate(blueonboard);
  driveforward();
  throttletime();
  steer();
  Serial.println(accelerator_state);
  timedacceleration();
  hardbrake();
}

