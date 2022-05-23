#include <Arduino.h>
#include <defs.h>

//BLinking function
void indicate(int indicator)
{
    digitalWrite(indicator, HIGH);
    delay(100);
    digitalWrite(indicator, LOW);
    delay(100);
}

//Forward direction
void driveforward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

//Reverse direction
void drivereverse()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

//PWM to motor
void drivemotor(int avalue)
{
    analogWrite(ena, avalue);
}

//Time variables
int ton;
int period = 0;
int oldtime = 0;
int throttle;
int basetime = 0;

int button_state = 0;
int button2_state = 0;

int check_motor =0;


//Time to throttle motor
int throttletime()
{
    if (basetime == 0)
    {
        basetime = millis();
    }

    else
    {
    }

    button_state = digitalRead(button);
    button2_state = digitalRead(button2);
    

    while (period<=5000)
    {
        if (button_state == 1)
        {
            ton = millis();
            period = ton - basetime;

            return period;
        }

        else
        {
            period = period - 10;
            basetime = 0;
            return period;
        }
    }

    if(button_state == 1) 
    {
        period = period;
        basetime = 0;
        return period;
    }

    else
    {
        period = period - 10;
        basetime = 0;
        return period;
    }

}

//Accelerate/Decelerate motor
void timedacceleration()
{
    throttle = map(period, 0, 5150, 0, 255);
    drivemotor(throttle);
}