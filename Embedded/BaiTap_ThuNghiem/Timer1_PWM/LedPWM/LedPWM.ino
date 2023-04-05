#include <TimerOne.h>

/* Sử dụng Timer1 để băm xung PWM điều khiển độ sáng đèn Led*/

const int ledPin = 10;

void setup(void)
{
  Timer1.initialize(25000);  // 50000us = 0.05s
  Serial.begin(9600);
}

void loop(void)
{
  // slowly increase the PWM led
  
  for (int dutyCycle = 0; dutyCycle < 1023; dutyCycle++) {
    Serial.print("PWM Led, Duty Cycle = ");
    Serial.println(dutyCycle);
    Timer1.pwm(ledPin, dutyCycle);
    delay(100);
  }
}
