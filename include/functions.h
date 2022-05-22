#include <Arduino.h>
#include <defs.h>

void indicate(int indicator)
{
    digitalWrite(indicator, HIGH);
    delay(100);
    digitalWrite(indicator, LOW);
    delay(100);
}

void driveforward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void drivereverse()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);    
}

void drivemotor(int avalue)
{
    analogWrite(ena, avalue);
}