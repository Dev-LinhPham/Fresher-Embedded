/*
* File: main.cpp
* Author: Linh Pham
* Date: 17/04/2023
* Description: Tạo một lớp phân số với các thuộc tính tử số và mẫu số và các phương
                thức để tính toán các phép tính toán cơ bản như cộng, trừ, nhân và
                chia
*/
#include <stdio.h>
#include <stdint.h>
#include <math.h>

using namespace std;

#define PRINT_PRACTION(content)                                             \
    int16_t UCLL = greatestCommonDivisor(totalNumerator, totalDenominator); \
    totalDenominator /= UCLL;                                               \
    totalNumerator /= UCLL;                                                 \
    printf(content, totalNumerator, totalDenominator)

/*
* Function: Class Fraction
* Description: Class biễu diễn dữ liệu và phương thức của đối tượng phân số
* Input:
*   No input
* Output:
*   Return - None
*/
class Fraction
{
private:
    int8_t numerator;
    int8_t denominator;

public:
    Fraction(const int8_t numerator = 0, const int8_t denominator = 1);

    void setNumerator(const int8_t numerator);
    void setDenominator(const int8_t denominator);

    int8_t getNumerator();
    int8_t getDenominator();
};

/*
* Function: Constructor Fraction
* Description: Nhập thông tin tử số và mẫu số
* Input:
*   numerator - const int8_t 
*   denominator - const uint8_t 
* Output:
*   Return - None
*/
Fraction::Fraction(const int8_t numerator, const int8_t denominator)
{
    if (denominator == 0)
    {
        printf("Loi nhap Mau so\n");
    }
    else if (denominator < 0)
    {
        Fraction::denominator = denominator * (-1);
        Fraction::numerator = numerator * (-1);
    }
    else
    {
        Fraction::denominator = denominator;
        Fraction::numerator = numerator;
    }
}

/*
* Function: setNumerator
* Description: Đặt tử số
* Input:
*   numerator - const int8_t 
* Output:
*   Return - None
*/
void Fraction::setNumerator(const int8_t numerator)
{
    Fraction::numerator = numerator;
}

/*
* Function: setDenominator
* Description: Đặt mẫu số
* Input:
*   denominator - const int8_t
* Output:
*   Return - None
*/
void Fraction::setDenominator(const int8_t denominator)
{
    Fraction::denominator = denominator;
}

/*
* Function: getNumerator
* Description: Lấy tử số
* Input:
*   No input
* Output:
*   numerator - int8_t 
*/
int8_t Fraction::getNumerator()
{
    return Fraction::numerator;
}

/*
* Function: getDenominator
* Description: Lấy mẫu số
* Input:
*   No input
* Output:
*   denominator - int8_t 
*/
int8_t Fraction::getDenominator()
{
    return Fraction::denominator;
}

/*
* Function: Class CalculateFraction
* Description: Class biễu diễn dữ liệu và phương thức tính toán 2 phân số
* Input:
*   No input
* Output:
*   Return - None
*/
class CalculateFraction
{
public:
    void addFraction(Fraction frt1, Fraction frt2);
    void subFraction(Fraction frt1, Fraction frt2);
    void multiFraction(Fraction frt1, Fraction frt2);
    void divisionFraction(Fraction frt1, Fraction frt2);
    int16_t leastCommonMultiple(int8_t num1, int8_t num2);
    int16_t greatestCommonDivisor(int8_t num1, int8_t num2);
};

/*
* Function: leastCommonMultiple
* Description: Tìm Bội chung nhỏ nhất
* Input:
*   num1 - int8_t 
*   num2 - int8_t 
* Output:
*   Return - None
*/
int16_t CalculateFraction::leastCommonMultiple(int8_t num1, int8_t num2)
{

    int8_t maxNum = abs(num1);
    int16_t multiNum = abs(num1 * num2);

    if (maxNum < abs(num2))
        maxNum = abs(num2);
    int16_t i;
    for (i = maxNum; i <= multiNum; i++)
    {
        if (i % num1 == 0 && i % num2 == 0)
            return i;
    }
    return 1;
}

/*
* Function: greatestCommonDivisor
* Description: Tìm Ước chung lớn nhất
* Input:
*   num1 - int8_t 
*   num2 - int8_t 
* Output:
*   Return - None
*/
int16_t CalculateFraction::greatestCommonDivisor(int8_t num1, int8_t num2)
{
    return abs(num1 * num2) / leastCommonMultiple(num1, num2);
}

/*
* Function: addFraction
* Description: Cộng 2 phân số
* Input:
*   frt1 - Fraction 
*   frt2 - Fraction 
* Output:
*   Return - None
*/
void CalculateFraction::addFraction(Fraction frt1, Fraction frt2)
{

    int16_t totalDenominator = leastCommonMultiple(frt1.getDenominator(), frt2.getDenominator());
    int16_t totalNumerator = (frt1.getNumerator() * (totalDenominator / frt1.getDenominator())) + (frt2.getNumerator() * (totalDenominator / frt2.getDenominator()));

    PRINT_PRACTION("Tong 2 phan so: %d/%d\n");
}

/*
* Function: subFraction
* Description: Trừ 2 phân số
* Input:
*   frt1 - Fraction 
*   frt2 - Fraction 
* Output:
*   Return - None
*/
void CalculateFraction::subFraction(Fraction frt1, Fraction frt2)
{
    int16_t totalDenominator = leastCommonMultiple(frt1.getDenominator(), frt2.getDenominator());
    int16_t totalNumerator = (frt1.getNumerator() * (totalDenominator / frt1.getDenominator())) - (frt2.getNumerator() * (totalDenominator / frt2.getDenominator()));

    PRINT_PRACTION("Hieu 2 phan so: %d/%d\n");
}

/*
* Function: multiFraction
* Description: Nhân 2 phân số
* Input:
*   frt1 - Fraction 
*   frt2 - Fraction 
* Output:
*   Return - None
*/
void CalculateFraction::multiFraction(Fraction frt1, Fraction frt2)
{
    int16_t totalDenominator = frt1.getDenominator() * frt2.getDenominator();
    int16_t totalNumerator = frt1.getNumerator() * frt2.getNumerator();


    PRINT_PRACTION("Tich 2 phan so: %d/%d\n");
}

/*
* Function: divisionFraction
* Description: Chia 2 phân số
* Input:
*   frt1 - Fraction 
*   frt2 - Fraction 
* Output:
*   Return - None
*/
void CalculateFraction::divisionFraction(Fraction frt1, Fraction frt2)
{
    int16_t totalDenominator = frt1.getDenominator() * frt2.getNumerator();
    int16_t totalNumerator = frt1.getNumerator() * frt2.getDenominator();

     if(totalDenominator < 0)
    {
        totalDenominator *= (-1);
        totalNumerator *= (-1);
    }
    PRINT_PRACTION("Chia 2 phan so: %d/%d\n");
}

int main(int argc, char const *argv[])
{
    Fraction frt1(-3, 4);
    Fraction frt2(5, -7 );
    CalculateFraction cf1;
    cf1.addFraction(frt1, frt2);
    cf1.multiFraction(frt1, frt2);
    cf1.divisionFraction(frt1, frt2);
    cf1.subFraction(frt1, frt2);
    return 0;
}
