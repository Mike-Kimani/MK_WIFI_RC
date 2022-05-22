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


int ton, period;
int oldtime =0;
int throttle;
int basetime = 0;


int throttletime()
{
    if(basetime == 0)
    {
        basetime == millis();
    }
    if(period<=5000)
    {
        ton = millis();
        period = ton - basetime;
        return period;
    }

    else
    {
        period = period;
        basetime = 0;
        return period;
    }
}

void timedacceleration()
{
    throttle = map(period, 0,5150,0,255);
    drivemotor(throttle);
}