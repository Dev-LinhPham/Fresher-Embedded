/*
  File: Slave.ino
  Author: Linh Pham
  Date: 22/04/2023
  Description: Mô phỏng quá trình truyền nhận giữa Master và Slave sử dụng giao thức I2C. File này dành cho Slave
*/

//Bus I2C
#define SDA 4
#define SCL 3
//Bit Write/Read
#define WRITE 0
#define READ 1
//Adress
#define ADDRESS 8

char dataReceive[6];//Data nhận được từ Master
uint8_t indexData = 0;//Vị trí của từng kí tự trong Data
uint8_t data1Byte = 0x00;//Data chứa dữ liệu có kích thước 1 Byte
uint8_t frameAddress = 0x00;//frame địa chỉ (7bit Address + 1bit ACK/NACK)
uint8_t sizeFrame = 0;//Lưu kích thước 1 Byte;
uint8_t readOrWrite;//Lưu chế độ
char dataSend[5] = "Slave";//Data để gửi tới Master
uint8_t mData = dataSend[indexData];//Biến tạm

bool checkStartStop = 0;//Biến kiểm tra StartStop
bool checkAddress = 0;//Biến kiểm tra địa chỉ
bool checkData = 1;////Biến kiểm tra để bắt đầu đọc DATA

/*
  Function: i2cInit
  Description: Hàm khởi động giao thức I2C
  Input:
    No input
  Output:
    No return
*/
void i2cInit()
{
  pinMode(SDA, INPUT);
  pinMode(SCL, INPUT);
}

/*
  Function: checkStop
  Description: Hàm kiểm tra tín hiệu kết thúc
  Input:
    No input
  Output:
    No return
*/
inline void checkStop()
{
  while (1) {
    if (digitalRead(SCL) == 1 && digitalRead(SDA) == 0) {
      delayMicroseconds(10);
      if (digitalRead(SCL) == 1 && digitalRead(SDA) == 1) {
        Serial.println("Sp");
        return;
      }
    }
  }
}

/*
  Function: writeData
  Description: Hàm gửi Data tới Master
  Input:
    No input
  Output:
    No return
*/
inline void writeData() {
  pinMode(SDA, OUTPUT);
  delayMicroseconds(1);
  if (sizeFrame < 8) {
    digitalWrite(SDA, (mData & 0x80) != 0);
    mData = mData << 1;
    delayMicroseconds(1);
    sizeFrame++;
    return;
  }
  else
  {
    digitalWrite(SDA, LOW);
    delayMicroseconds(50);
    indexData++;
    mData = dataSend[indexData];
    sizeFrame = 0;
    delayMicroseconds(2);
    if (indexData == 5) {
      indexData = 0;
      checkStartStop = 0;
      pinMode(SDA, INPUT);
      //Checkstop
      delayMicroseconds(20);
      checkStop();
    }
  }
  return;
}

/*
  Function: readData
  Description: Hàm đọc Data từ Master
  Input:
    No input
  Output:
    No return
*/
inline void readData() {
  if (indexData < 6) {
    if (sizeFrame < 8)
    {
      data1Byte = data1Byte << 1;
      data1Byte = data1Byte | digitalRead(SDA);
      delayMicroseconds(2);
      sizeFrame++;
      return;
    }
    else
    {
      pinMode(SDA, OUTPUT);
      digitalWrite(SDA, LOW);
      delayMicroseconds(50);
      pinMode(SDA, INPUT);
      Serial.print("Data: ");
      Serial.println((char)data1Byte);
      indexData++;
      dataReceive[indexData] = data1Byte;
      data1Byte = 0;
      sizeFrame = 0;
      delayMicroseconds(5);
    }
  }
  if (indexData == 6) {
    Serial.println("---");
    indexData = 0;
    checkData = 0;
    checkStartStop = 0;
    //Checkstop
    delayMicroseconds(20);
    checkStop();
  }
  return;
}

/*
  Function: interruptSCL
  Description: Chương trình ngắt mỗi khi có xung Clock
  Input:
    No input
  Output:
    No return
*/
void interruptSCL() {
  //Check tín hiệu bắt đầu I2C
  if (checkStartStop == 0 && sizeFrame == 0)
  {
    Serial.println("St");
    checkStartStop = 1;
    checkAddress = 1;
    return;
  }
  if (checkStartStop) {
    //Kiểm tra địa chỉ
    if (checkAddress) {
      if (sizeFrame < 8)
      {
        frameAddress = frameAddress << 1;
        frameAddress = frameAddress | digitalRead(SDA);
        delayMicroseconds(1);
        sizeFrame++;
        return;
      }
      else
      {
        pinMode(SDA, OUTPUT);
        digitalWrite(SDA, LOW);
        delayMicroseconds(50);
        pinMode(SDA, INPUT);
        readOrWrite = frameAddress & 0x01;
        frameAddress >>= 1;
        if (frameAddress == ADDRESS) {
          checkAddress = 0;
          checkData = 1;
        }
        sizeFrame = 0;
        Serial.println(frameAddress);
        delayMicroseconds(1);
        return;
      }
    }
    //Truyền nhận Data nếu địa chỉ đúng
    if (checkData) {
      if (readOrWrite == READ) {
        writeData();
        return;
      }
      else {
        readData();
        return;
      }
    }
  }
}

void setup() {
  Serial.begin(1000000);
  i2cInit();
  attachInterrupt(1, interruptSCL, FALLING);//Ngắt ngoài sườn xuống
}

void loop() {

}
