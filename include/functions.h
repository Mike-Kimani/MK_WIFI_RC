#include <Arduino.h>
#include <defs.h>
#include <ESP32Servo.h>

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
int throttle;
int basetime = 0;
int motor_time = 0;

//Accelerator and decelerator
int button_state = 0;
int button2_state = 0;




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

    //Read accelerator and brake status
    button_state = digitalRead(button);
    button2_state = digitalRead(button2);
    
    while (motor_time<=6000)
    {
        //Accelerating
        if (button_state == 1 && button2_state ==0)
        {
            ton = millis();
            motor_time = ton - basetime;
            period = period + 4;
            period = constrain(period, 0, 5025);
            return period;
        }
        //Should be Coasting but we losing some speed
        //Consider changing to pure coasting
        else if(button_state == 0 && button2_state ==0)
        {
            period = period - 2;
            period = constrain(period, 0, 5025);
            basetime = 0;
            return period;
        }
        //Rapid deceleration
        else if(button_state == 0 && button2_state == 1)
        {
            period = period - 30;
            period = constrain(period, 0, 5025);
            basetime = 0;
            return period;
        }
        //Both buttons pressed speed maintained
        else
        {
            period = period;
            basetime = 0;
            return period;
        }        

    }

    //Back to accelerating time. Losing time consider also increasing speed here
    if(button_state == 1 && button2_state == 0) 
    {
        period = period;
        period = constrain(period, 0, 5025);
        motor_time = 0;
        basetime = 0;
        return period;
    }

    //Coasting. Losing the slightest of speeds
    else if(button_state == 0 && button2_state == 0)
    {
        period = period - 2;
        motor_time = 0;
        period = constrain(period, 0, 5025);
        basetime = 0;
        return period;
    }

    //Hard braking
    else if(button_state == 0 && button2_state ==1)
    {
        period = period - 40;
        period = constrain(period, 0, 5025);
        motor_time = 0;
        basetime = 0;
        return period;
    }
    //Both buttons pressed back to coasting
    else
    {
        period = period;
        motor_time = 0;
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