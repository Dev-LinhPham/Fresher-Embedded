/*
  File: Master.ino
  Author: Linh Pham
  Date: 22/04/2023
  Description: Mô phỏng quá trình truyền nhận giữa Master và Slave sử dụng giao thức I2C. File này dành cho Master
*/

//Bus I2C
#define SDA 3
#define SCL 4
//Bit ACK/NACK
#define ACK 1
#define NACK 0
//Bit Write/Read
#define WRITE 0
#define READ 1

char dataSend[6] = "Master";//Data để gửi tới Slave
uint8_t data1Byte = 0x00;//Data chứa dữ liệu có kích thước 1 Byte
char dataReceive[5];//Data nhận được từ Slave
uint8_t indexData = 0;//Vị trí của từng kí tự trong Data

/*
  Function: frameAddress
  Description: Khung địa chỉ (7 bits) + 1 bit Write/Read
  Input:
    addressSlave - uint8_t
    mode - uint8_t
  Output:
    returns frameAddress
*/
uint8_t frameAddress(uint8_t addressSlave, uint8_t mode)
{
  return ((addressSlave << 1) | mode);
}

/*
  Function: i2cInit
  Description: Hàm khởi động giao thức I2C, chân SDA & SCL luôn được kéo lên cao
  Input:
    No input
  Output:
    No return
*/
void i2cInit()
{
  pinMode(SDA, OUTPUT);
  pinMode(SCL, OUTPUT);

  digitalWrite(SDA, HIGH);
  digitalWrite(SCL, HIGH);
}

/*
  Function: startI2C
  Description: Hàm tín hiệu bắt đầu giao thức I2C, SDA được kéo xuống LOW sau đó đến SCL được kéo xuống LOW
  Input:
    No input
  Output:
    No return
*/
void startI2C()
{
  delayMicroseconds(10);
  digitalWrite(SDA, LOW);
  delayMicroseconds(10);
  digitalWrite(SCL, LOW);
}

/*
  Function: stopI2C
  Description: Hàm tín hiệu kết thúc giao thức I2C, SCL được kéo lên HIGH sau đó SDA mới được kéo lên HIGH
  Input:
    No input
  Output:
    No return
*/
void stopI2C()
{
  digitalWrite(SDA, LOW);
  delayMicroseconds(10);
  digitalWrite(SCL, HIGH);
  delayMicroseconds(10);
  digitalWrite(SDA, HIGH);
}

/*
  Function: clockSignal
  Description: Hàm tạo xung Clock, dùng để đồng bộ tín hiệu truyền nhận
  Input:
    No input
  Output:
    No return
*/
void clockSignal()
{
  digitalWrite(SCL, HIGH);
  delayMicroseconds(10);
  digitalWrite(SCL, LOW);
  delayMicroseconds(10);
}

/*
  Function: getAck
  Description: Hàm lấy bit ACK/NACK để xác nhận sau 1 byte truyền đi
  Input:
    No input
  Output:
    Return ACK/NACK
*/
bool getAck()
{
  pinMode(SDA, INPUT);
  delayMicroseconds(2);
  clockSignal();
  unsigned long timeT = micros();
  while (1) {
    if (!digitalRead(SDA)) {
      pinMode(SDA, OUTPUT);
      delayMicroseconds(2);
      return ACK;
    }
    if (micros() - timeT > 50) {
      pinMode(SDA, OUTPUT);
      delayMicroseconds(2);
      return NACK;
    }
  }
}

/*
  Function: sendByteData
  Description: Hàm gửi 1 Byte dữ liệu đi
  Input:
    mData - uint8_t
  Output:
    Return ACK/NACK
*/
bool sendByteData(uint8_t mData)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(SDA, (mData & 0x80) != 0);
    mData = mData << 1;
    delayMicroseconds(5);
    clockSignal();
    delayMicroseconds(10);
  }
  delayMicroseconds(50);
  return getAck();
}

/*
  Function: readData
  Description: Hàm đọc dữ liệu được gửi đến
  Input:
    No input
  Output:
    Return ACK/NACK
*/
bool readData()
{
  pinMode(SDA, INPUT);
  delayMicroseconds(1);
  for (int j = 0; j < 8; j++)
  {
    clockSignal();
    delayMicroseconds(5);
    data1Byte = data1Byte << 1;
    data1Byte = data1Byte | digitalRead(SDA);
    delayMicroseconds(10);
  }
  dataReceive[indexData] = data1Byte;
  indexData++;
  data1Byte = 0x00;
  delayMicroseconds(50);
  return getAck();
}

/*
  Function: beginTrans
  Description: Hàm gửi đi tín hiệu bắt đầu & địa chỉ Slave muốn giao tiếp
  Input:
    addressSlave - uint8_t
  Output:
    Return ACK/NACK
*/
bool beginTrans(uint8_t addressSlave)
{
  startI2C();
  delayMicroseconds(50);
  return sendByteData(addressSlave);
}

void setup()
{
  Serial.begin(1000000);
  i2cInit();
}

void loop()
{
  //Đọc Data từ Slave
  delay(2000);
  uint8_t addressSlave1 = frameAddress(8, READ);
  if (beginTrans(addressSlave1))
  {
    Serial.println("Connect");
    delay(500);
    for (int i = 0; i < 5; i++)
    {
      uint8_t x = readData();
      delayMicroseconds(100);
    }
    indexData = 0;
    pinMode(SDA, OUTPUT);
    Serial.print("Data Receive: ");
    Serial.println(String(dataReceive));
    delayMicroseconds(50);
    stopI2C();
  }

  //Gửi Data đến Slave
  delay(2000);
  uint8_t addressSlave = frameAddress(8, WRITE);
  if (beginTrans(addressSlave))
  {
    Serial.println("Connect");
    delay(500);
    for (int i = 0; i < sizeof(dataSend); i++)
    {
      sendByteData(dataSend[i]);
      delayMicroseconds(100);
    }
    Serial.println("Send Done");
    delayMicroseconds(50);
    stopI2C();
  }
}
