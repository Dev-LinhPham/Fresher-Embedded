/*
* File: main.cpp
* Author: Linh Pham
* Date: 17/04/2023
* Description: Tạo một lớp người với các thuộc tính tên, tuổi và địa chỉ, và các
                phương thức để in thông tin của người đó và tính tuổi của người đó.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
* Function: Class Person
* Description: Class biễu diễn dữ liệu và phương thức của đối tượng con nguoi
* Input:
*   No input
* Output:
*   Return - None
*/
class Person
{
private:
    char namePerson[20];
    uint8_t agePerson;
    char addressHome[20];

public:
    Person(const char namePerson[], const uint8_t agePerson, const char addressHome[]);

    void setNamePerson(const char namePerson[]);
    void setAgePerson(const uint8_t agePerson);
    void setAdressHome(const char addressHome[]);

    char *getNamePerson();
    uint8_t getAgePerson();
    char *getAdressHome();
    void getInforPerson();

    void calculateAge(uint16_t yearBirth, uint16_t yearPersent);
};

/*
* Function: Constructor Person
* Description: Nhập thông tin dữ liệu về con người
* Input:
*   namePerson - const char 
*   agePerson - const uint8_t 
*   addressHome - const char
* Output:
*   Return - None
*/
Person::Person(const char namePerson[], const uint8_t agePerson, const char addressHome[])
{
    strcpy(Person::namePerson, namePerson);

    Person::agePerson = agePerson;

    strcpy(Person::addressHome, addressHome);
}

/*
* Function: setNamePerson
* Description: Đặt tên cho con người
* Input:
*   namePerson - const char 
* Output:
*   Return - None
*/
void Person::setNamePerson(const char namePerson[])
{
    strcpy(Person::namePerson, namePerson);
}

/*
* Function: setAdressHome
* Description: Đặt địa chỉ của con người
* Input:
*   addressHome - const char
* Output:
*   Return - None
*/
void Person::setAdressHome(const char addressHome[])
{
    strcpy(Person::addressHome, addressHome);
}

/*
* Function: setAgePerson
* Description: Đặt tuổi cho con người
* Input:
*   agePerson - const uint8_T
* Output:
*   Return - None
*/
void Person::setAgePerson(const uint8_t agePerson)
{
    Person::agePerson = agePerson;
}

/*
* Function: getAdressHome
* Description: Lấy địa chỉ của con người
* Input:
*   No input
* Output:
*   addressHome - char * 
*/
char *Person::getAdressHome()
{
    return Person::addressHome;
}

/*
* Function: getNamePerson
* Description: Lấy tên của con người
* Input:
*   No input
* Output:
*   namePerson - char * 
*/
char *Person::getNamePerson()
{
    return Person::namePerson;
}

/*
* Function: getAgePerson
* Description: Lấy tuổi của con người
* Input:
*   No input
* Output:
*   agePerson - uint8_t 
*/
uint8_t Person::getAgePerson()
{
    return Person::agePerson;
}

/*
* Function: getInforPerson
* Description: Lấy thông tin của con người
* Input:
*   No input
* Output:
*   None 
*/
void Person::getInforPerson()
{
    printf("Ho ten: %s\n", Person::namePerson);
    printf("Tuoi: %d\n", Person::agePerson);
    printf("Dia chi: %s\n", Person::addressHome);
}

/*
* Function: calculateAge
* Description: Tính toán tuổi của con người dựa vào năm sinh
* Input:
*   yearBirth - uint8_t
*   yearPersent - uint8_t
* Output:
*   None 
*/
void Person::calculateAge(uint16_t yearBirth, uint16_t yearPersent)
{
    printf("Tuoi la: %d", yearPersent - yearBirth);
}

int main(int argc, char const *argv[])
{
    Person person1("Pham Linh", 23, "Ha Noi");

    person1.getInforPerson();

    person1.calculateAge(2001, 2023);
    return 0;
}
