/*
* File: Timer_BlinkLed.c
* Author: Linh Pham
* Date: 05/04/2023
* Description: Sử dụng ngắt Timer để BlinkLed
*/
#include <TimerOne.h>

byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};// Mảng các chân sử dụng
byte sizeLedPin;
int stateLed = LOW;

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
  Timer1.initialize(150000); //Khởi động ngắt, thời gian đặt cho nó là 150000us=0.15s.
  Timer1.attachInterrupt(blinkLED); //Khi xảy ra ngắt chương trình sẽ gọi hàm blinkLED().
  Serial.begin(9600);
  sizeLedPin = sizeof(ledPin);
  for (int i = 0; i < sizeLedPin; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], stateLed);
  }
}

/*
* Function: blinkLED
* Description: Hàm nhấp nháy Led khi ngắt Timer xảy ra
* Input:
*   void
* Output:
*   return: None
*/
void blinkLED(void)
{
  stateLed = !stateLed;
  for (int j = 0; j < sizeLedPin; j++) {
    digitalWrite(ledPin[j], stateLed);
  }
  delay(50);
}

/*
* Function: loop
* Description: Hàm nhấp nháy Led khi ngắt Timer xảy ra
* Input:
*   void
* Output:
*   return: None
*/
void loop(void)
{
  delay(100);
  Serial.println("State: " + String(stateLed));
}
