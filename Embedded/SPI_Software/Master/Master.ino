/*
* File: Master.ino
* Author: Linh Pham
* Date: 10/04/2023
* Description: Chương trình mô phỏng quá trình Truyền Nhận Data của Master
*/
#define SCK  4   // chân SCK
#define MOSI 3   // Chân MOSI
#define SS   5   // Chân SS
#define MISO 2   // chân MISO

uint8_t dataFromSlave = 0x00;

void spiSoftInit();// chương trình khởi tạo SPI
void clockSignal();// chương trình tạo 1 xung clock
void spiSoftTransmitMaster(uint8_t mData);// chương trình gửi 1 byte
uint8_t spiSoftReceiveMaster();// chương trình nhận về 1 byte

/*
* Function: setup
* Description: Hàm chỉ chạy 1 lần duy nhất khi Arduino hoạt động
* Input:
*   void
* Output:
*   return: None
*/
void setup() {
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SS, OUTPUT);
  pinMode(MISO, INPUT);
  Serial.begin(115200);
  spiSoftInit();
}

/*
* Function: loop
* Description: Hàm chạy lặp đi lặp lại khi Arduino hoạt động
* Input:
*   void
* Output:
*   return: None
*/
void loop()
{
  for (char i = 'A'; i <= 'Z'; i++) {
    spiSoftTransmitMaster(i);
    Serial.print("Send Data to Slave: ");
    Serial.println(i);
    delay(500);
    dataFromSlave = spiSoftReceiveMaster();
    Serial.print("Data Received from Slave: ");
    Serial.println(dataFromSlave);
    delay(500);
  }
}

/*
* Function: spiSoftInit
* Description: Hàm khởi động giao thức SPI
* Input:
*   No Input
* Output:
*   return : None
*/
void spiSoftInit()
{
  digitalWrite(SCK, LOW);
  digitalWrite(MOSI, LOW);
  digitalWrite(SS, HIGH);
}

/*
* Function: clockSignal
* Description: Hàm tín hiệu xung Clock
* Input:
*   No Input
* Output:
*   return : None
*/
void clockSignal()
{
  digitalWrite(SCK, HIGH);
  asm volatile("nop"::);
  digitalWrite(SCK, LOW);
  asm volatile("nop"::);
}

/*
* Function: spiSoftTransmitMaster
* Description: Hàm gửi Data từ Master -> Slave
* Input:
*   mData - uint8_t
* Output:
*   return : None
*/
void spiSoftTransmitMaster(uint8_t mData)
{
  uint8_t i = 0, x = 0;
  digitalWrite(SS, LOW);
  for (i = 0; i < 8; i++) {
    x = mData & 0x80; // đưa bit cần truyền lên chân MOSI
    if (x > 0)
      digitalWrite(MOSI, HIGH);
    else
      digitalWrite(MOSI, LOW);
    mData = mData << 1; // dịch dữ liệu cần gửi lên 1 bits
    clockSignal(); // phát 1 xung clock gửi dữ liệu đi
    delay(2);
  }
  digitalWrite(SS, HIGH);
}

/*
* Function: spiSoftReceiveMaster
* Description: Hàm nhận Data từ Slave -> Master
* Input:
*   No Input
* Output:
*   return _data
*/
uint8_t spiSoftReceiveMaster()
{
  uint8_t _data = 0x00, i = 0;
  digitalWrite(SS, LOW);
  for (i = 0; i < 8; i++) {
    clockSignal();  // phát một xung clock để đọc bit tiếp theo
    delay(2);
    _data = _data << 1;     // dịch dữ liệu lên 1 bit
    _data = _data | digitalRead(MISO);    //đọc chân MISO
  }
  digitalWrite(SS, HIGH);
  return _data;
}
