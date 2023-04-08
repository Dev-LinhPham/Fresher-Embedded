/*
* File: LedPWM.c
* Author: Linh Pham
* Date: 05/04/2023
* Description: Sử dụng Timer1 để băm xung PWM điều khiển độ sáng đèn Led
*/
#include <TimerOne.h>

const int ledPin = 10;

/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
* Input:
*   void
* Output:
*   return: None
*/
void setup(void)
{
  Timer1.initialize(25000);  // 50000us = 0.05s
  Serial.begin(9600);
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* Input:
*   void
* Output:
*   return: None
*/
void loop(void)
{
  // slowly increase the PWM led
  
  for (int dutyCycle = 0; dutyCycle < 1023; dutyCycle++) {
    Serial.print("PWM Led, Duty Cycle = ");
    Serial.println(dutyCycle);
    Timer1.pwm(ledPin, dutyCycle);// Băm xung PWM 
    delay(100);
  }
}
