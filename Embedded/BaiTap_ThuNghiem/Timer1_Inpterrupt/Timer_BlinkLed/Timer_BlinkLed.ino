// Ví dụ này dùng ngắt Timer để nháy LED
// và sử dụng biến chia sẻ giữa hàm ngắt và chương trình chính
#include <TimerOne.h>

byte ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte sizeLed;
int stateLed = LOW;

void setup(void)
{
  Timer1.initialize(150000); //Khởi động ngắt, thời gian đặt cho nó là 150000us=0.15s.
  Timer1.attachInterrupt(blinkLED); //Khi xảy ra ngắt chương trình sẽ gọi hàm blinkLED().
  Serial.begin(9600);
  sizeLed = sizeof(ledPin);
  for (int i = 0; i < sizeLed; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], stateLed);
  }
}

void blinkLED(void)
{
  stateLed = !stateLed;
  for (int j = 0; j < sizeLed; j++) {
    digitalWrite(ledPin[j], stateLed);
  }
  delay(50);
}

void loop(void)
{
  delay(100);
  Serial.println("State: " + String(stateLed));
}
