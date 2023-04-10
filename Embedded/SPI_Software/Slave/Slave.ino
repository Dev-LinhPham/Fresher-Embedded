/*
  File: Slave.ino
  Author: Linh Pham
  Date: 10/04/2023
  Description: Chương trình mô phỏng quá trình Truyền Nhận Data của Slave
*/
#define SCK  3   // chân SCK
#define MOSI 4   // Chân MOSI
#define SS   2   // Chân SS
#define MISO 5   // chân MISO

bool stateSlave = 1;
uint8_t dataReceived = 0x00;
uint8_t sizeDataReceived = 0;
uint8_t dataTransmited = 0x00;
uint8_t sizeDataTransmited = 0;

void spiSoftTransmit();// chương trình gửi 1 byte
void spiSoftReceived();// chương trình nhận về 1 byte
void spiSoftSlave();// chương trình ngắt khi có xung SCK

/*
*  Function: setup
*  Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
*  Input:
*    void
*  Output:
*   return: None
*/
void setup()
{
  Serial.begin(115200);
  pinMode(SCK, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(SS, INPUT);
  pinMode(MISO, OUTPUT);
  attachInterrupt(1, spiSoftSlave, RISING); // gọi hàm tatled liên tục khi còn nhấn nút
}

/*
*  Function: loop
*  Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
*  Input:
*    void
*  Output:
*   return: None
*/
void loop()
{
  if (digitalRead(SS) == HIGH) {
    if (sizeDataReceived == 8) {
      Serial.print("Data Received from Master: ");
      Serial.println((char)dataReceived);
      dataReceived = 0x00;
      sizeDataReceived = 0;
      stateSlave = 0;
      dataTransmited = 88;
    }
    else
    {
      dataReceived = 0x00;
      sizeDataReceived = 0;
    }
    if (sizeDataTransmited == 8) {
      dataTransmited = 88;
      sizeDataTransmited = 0;
      stateSlave = 1;
      Serial.println("Transmited Data");
    }
    else
    {
      sizeDataTransmited = 0;
    }
  }
}

/*
*  Function: spiSoftSlave
*  Description: Hàm ngắt khi xung SCK của Master phát ra
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftSlave()
{
  if (digitalRead(SS) == HIGH) return;
  if (stateSlave) 
  {
    spiSoftReceived();
  }
  else
  {
    spiSoftTransmit();
  }
}

/*
*  Function: spiSoftReceived
*  Description: Hàm nhận Data từ Master -> Slave
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftReceived()
{
  dataReceived = dataReceived << 1; // dịch dữ liệu lên 1 bit
  dataReceived = dataReceived | digitalRead(MOSI);    //đọc chân MOSI
  delay(2);
  sizeDataReceived++;
}

/*
*  Function: spiSoftTransmit
*  Description: Hàm truyền Data từ Slave -> Master
* Input:
*   No input
*  Output:
*   return : None
*/
void spiSoftTransmit()
{
  uint8_t x = 0;
  x = dataTransmited & 0x80; // đưa bit cần truyền lên chân MOSI
  if (x > 0)
    digitalWrite(MISO, HIGH);
  else
    digitalWrite(MISO, LOW);
  dataTransmited = dataTransmited << 1; // dịch dữ liệu cần gửi lên 1 bits
  sizeDataTransmited++;
}
