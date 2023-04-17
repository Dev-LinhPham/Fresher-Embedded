/*
* File: main.cpp
* Author: Linh Pham
* Date: 11/04/2023
* Description: Tạo một lớp động vật với các thuộc tính tên, tuổi và trọng lượng, và các
                phương thức để tính chỉ số BMI, so sánh tuổi và trọng lượng của các
                động vật khác nhau.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
* Function: Class Animal
* Description: Class biễu diễn dữ liệu và phương thức của đối tượng động vật
* Input:
*   No input
* Output:
*   Return - None
*/
class Animal
{
private:
    char nameAnimal[20];
    uint8_t ageAnimal;
    float weightAnimal;
    float heightAnimal;
    float bmiAnimal;

public:
    Animal(const char nameAnimal[] = "a", const uint8_t ageAnimal = 0, const float weightAnimal = 0, const float heightAnimal = 0);

    void setNameAnimal(const char nameAnimal[]);
    void setAgeAnimal(const uint8_t ageAnimal);
    void setWeightAnimal(const float weightAnimal);
    void setHeightAnimal(const float heightAnimal);

    char *getNameAnimal();
    uint8_t getAgeAnimal();
    float getWeightAnimal();
    float getHeightAnimal();

    float calculateBMI();
};

/*
* Function: Constructor Animal
* Description: Nhập thông tin dữ liệu về động vật
* Input:
*   nameAnimal - const char 
*   ageAnimal - const uint8_t 
*   weightAnimal - const float
*   heightAnimal - const float
* Output:
*   Return - None
*/
Animal::Animal(const char nameAnimal[], const uint8_t ageAnimal, const float weightAnimal, const float heightAnimal)
{
    strcpy(Animal::nameAnimal, nameAnimal);

    Animal::ageAnimal = ageAnimal;

    Animal::weightAnimal = weightAnimal;

    Animal::heightAnimal = heightAnimal;
}

/*
* Function: setNameAnimal
* Description: Đặt tên của động vật
* Input:
*   nameAnimal - const char 
* Output:
*   Return - None
*/
void Animal::setNameAnimal(const char nameAnimal[])
{
    strcpy(Animal::nameAnimal, nameAnimal);
}

/*
* Function: setWeightAnimal
* Description: Đặt cân nặng của động vật
* Input:
*   weightAnimal - const float
* Output:
*   Return - None
*/
void Animal::setWeightAnimal(const float weightAnimal)
{
    Animal::weightAnimal = weightAnimal;
}

/*
* Function: setAgeAnimal
* Description: Đặt tuổi của động vật
* Input:
*   ageAnimal - const uint8_t
* Output:
*   Return - None
*/
void Animal::setAgeAnimal(const uint8_t ageAnimal)
{
    Animal::ageAnimal = ageAnimal;
}

/*
* Function: setHeightAnimal
* Description: Đặt chiều cao của động vật
* Input:
*   heightAnimal - const float
* Output:
*   Return - None
*/
void Animal::setHeightAnimal(const float heightAnimal)
{
    Animal::heightAnimal = heightAnimal;
}

/*
* Function: getNameAnimal
* Description: Lấy tên của động vật
* Input:
*   No input
* Output:
*   nameAnimal - char * 
*/
char *Animal::getNameAnimal()
{
    return Animal::nameAnimal;
}

/*
* Function: getAgeAnimal
* Description: Lấy tuổi của động vật
* Input:
*   No input
* Output:
*   ageAnimal - uint8_t 
*/
uint8_t Animal::getAgeAnimal()
{
    return Animal::ageAnimal;
}

/*
* Function: getWeightAnimal
* Description: Lấy cân nặng của động vật
* Input:
*   No input
* Output:
*   weightAnimal - float 
*/
float Animal::getWeightAnimal()
{
    return Animal::weightAnimal;
}

/*
* Function: getHeightAnimal
* Description: Lấy chiều cao của động vật
* Input:
*   No input
* Output:
*   heightAnimal - float 
*/
float Animal::getHeightAnimal()
{
    return Animal::heightAnimal;
}

/*
* Function: calculateBMI
* Description: Tính toán chỉ số BMI
* Input:
*   No input
* Output:
*   bmiAnimal - float 
*/
float Animal::calculateBMI()
{
    Animal::bmiAnimal = Animal::weightAnimal / (Animal::heightAnimal * Animal::heightAnimal);
    return Animal::bmiAnimal;
}

/*
* Function: Class compareAnimal
* Description: Class chứa phương thức so sánh thông tin của các động vật
* Input:
*   No input
* Output:
*   Return - None
*/
class compareAnimal
{
private:
    Animal firstAnimal;
    Animal secondAnimal;

public:
    compareAnimal(Animal firstAnimal, Animal secondAnimal);

    void compareAgeAnimal();
    void compareWeightAnimal();
};

/*
* Function: Constructor compareAnimal
* Description: Nhập thông tin dữ liệu của 2 con vật cần so sánh 
* Input:
*   firstAnimal - Animal
*   secondAnimal - Animal 
* Output:
*   Return - None
*/
compareAnimal::compareAnimal(Animal firstAnimal, Animal secondAnimal)
{
    compareAnimal::firstAnimal = firstAnimal;
    compareAnimal::secondAnimal = secondAnimal;
}

/*
* Function: compareAgeAnimal
* Description: So sánh tuổi 2 con vật 
* Input:
*   No input
* Output:
*   Return - None
*/
void compareAnimal::compareAgeAnimal()
{
    if (firstAnimal.getAgeAnimal() > secondAnimal.getAgeAnimal())
    {
        printf("%s lon tuoi hon %s\n", firstAnimal.getNameAnimal(), secondAnimal.getNameAnimal());
    }
    else
    {
        if (firstAnimal.getAgeAnimal() == secondAnimal.getAgeAnimal())
        {
            printf("%s bang tuoi hon %s\n", firstAnimal.getNameAnimal(), secondAnimal.getNameAnimal());
        }
        else
        {
            printf("%s lon tuoi hon %s\n", secondAnimal.getNameAnimal(), firstAnimal.getNameAnimal());
        }
    }
}

/*
* Function: compareWeightAnimal
* Description: So sánh cân nặng 2 con vật 
* Input:
*   No input
* Output:
*   Return - None
*/
void compareAnimal::compareWeightAnimal()
{
    if (firstAnimal.getWeightAnimal() > secondAnimal.getWeightAnimal())
    {
        printf("%s nang hon %s\n", firstAnimal.getNameAnimal(), secondAnimal.getNameAnimal());
    }
    else
    {
        if (firstAnimal.getWeightAnimal() == secondAnimal.getWeightAnimal())
        {
            printf("%s bang can nang %s\n", firstAnimal.getNameAnimal(), secondAnimal.getNameAnimal());
        }
        else
        {
            printf("%s nang hon %s\n", secondAnimal.getNameAnimal(), firstAnimal.getNameAnimal());
        }
    }
}

int main(int argc, char const *argv[])
{
    Animal animal1("Trau", 5, 150, 0.65);
    Animal animal2("Bo", 7, 125.8, 1.2);

    printf("BMI cua %s la: %.2f\n", animal1.getNameAnimal(), animal1.calculateBMI());
    printf("BMI cua %s la: %.2f\n", animal2.getNameAnimal(), animal2.calculateBMI());
    compareAnimal cpA(animal1, animal2);
    cpA.compareAgeAnimal();
    cpA.compareWeightAnimal();
    return 0;
}
