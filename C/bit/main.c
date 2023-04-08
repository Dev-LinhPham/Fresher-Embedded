#include<stdio.h>
#include<stdint.h>
/*
    Thao tác BIT
    Ứng dụng trong bài toán viết hàm digitalWrite của Arduino
    Giả sử 1 vdk có 8 chân (Port A)
    Ứng dụng với các vdk 32bit, 64bit
*/
#define HIGH 1
#define LOW 0
uint8_t portA = 0;

void digitalWrite(uint8_t pin, uint8_t status){
    (status==1) ? (portA = portA | (0b00000001 <<pin)) : (portA = portA & ~(0b00000001 <<pin));
}

/*
    VD: digitalWrite(3, 1);
    - 0b10000000 >> 3
    - 0b00010000 OR portA
    - 0bxxx1xxxx

        digitalWrite(4, 0);
    - 0b10000000 >> 4
    - 0b00001000 -> ~ 0b11110111 & portA
    - 0bxxxx0xxx

*/
int main(int argc, char const *argv[])
{
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(1,HIGH);

    printf("%x\n",portA);
    return 0;
}


