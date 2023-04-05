/*
* File: main.cpp
* Author: Linh Pham
* Date: 05/04/2023
* Description: Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
                khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba
                điểm.
*/
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
* Function: Class Pointer2D
* Description: Class biễu diễn tọa độ điểm trong mặt phằng 2D
*/
class Pointer2D
{
private:
    int8_t ordinate;
    int8_t abscissa;

public:
    Pointer2D(int8_t ordinate = 0, int8_t abscissa = 0); // Set input = 0 để khi khai báo Contactor mà ko truyền thì sẽ mặc định = 0

    int8_t getOrdinate() { return Pointer2D::ordinate; }; // Tung - y
    int8_t getAbscissa() { return Pointer2D::abscissa; }; // Hoanh - x

};

/*
* Function: Constructor Pointer2D
* Description: Nhập tung độ, hoành độ khi khởi tạo
* Input:
*   abscissa - int8_t
*   ordinate - int8_t
*/
Pointer2D::Pointer2D(int8_t abscissa, int8_t ordinate)
{
    Pointer2D::ordinate = ordinate;
    Pointer2D::abscissa = abscissa;
}

/*
* Function: Class SpaceMath
* Description: Class biễu diễn các phép toán trong không gian
*/
class SpaceMath
{
private:
    Pointer2D firstPoint;
    Pointer2D secondPoint;
    Pointer2D thirdPoint;

    typedef enum
    {
        DISTANCE,
        AREA_OF_TRIANGLE,
    } Math;

    Math math;
    float distance = 0;
    float areaOfTriangle = 0;

public:
    SpaceMath(Pointer2D firstPoint, Pointer2D secondPoint);
    SpaceMath(Pointer2D firstPoint, Pointer2D secondPoint, Pointer2D thirdPoint);

    float calculateDistance();
    float calculateAreaOfTriangle();
};

/*
* Function: Constructor SpaceMath
* Description: Nhập 2 điểm khi khởi tạo phép toán 
* Input:
*   firstPoint - Pointer2D
*   secondPoint - Pointer2D
*/
SpaceMath::SpaceMath(Pointer2D firstPoint, Pointer2D secondPoint)
{
    SpaceMath::math = DISTANCE;

    SpaceMath::firstPoint = firstPoint;
    SpaceMath::secondPoint = secondPoint;
}

/*
* Function: Constructor SpaceMath
* Description: Nhập 3 điểm khi khởi tạo phép toán 
* Input:
*   firstPoint - Pointer2D
*   secondPoint - Pointer2D
*   thirdPoint - Pointer2D
*/
SpaceMath::SpaceMath(Pointer2D firstPoint, Pointer2D secondPoint, Pointer2D thirdPoint)
{
    SpaceMath::math = AREA_OF_TRIANGLE;

    SpaceMath::firstPoint = firstPoint;
    SpaceMath::secondPoint = secondPoint;
    SpaceMath::thirdPoint = thirdPoint;
}

/*
* Function: calculateDistance
* Description: Tính toán khoảng cách với 2 điểm 
* Output:
*   distance - float
*/
float SpaceMath::calculateDistance()
{
    if (SpaceMath::math == DISTANCE)
    {
        SpaceMath::distance = sqrt(pow((secondPoint.getAbscissa() - firstPoint.getAbscissa()), 2) + pow((secondPoint.getOrdinate() - firstPoint.getOrdinate()), 2));
    }
    else
    {
        printf("KHONG THE LUA CHON!\n");
    }
    return SpaceMath::distance;
}

/*
* Function: calculateAreaOfTriangle
* Description: Tính toán diện tích tam giác tạo bởi 3 điểm
* Output:
*   areaOfTriangle - float
*/
float SpaceMath::calculateAreaOfTriangle()
{
    if (SpaceMath::math == AREA_OF_TRIANGLE)
    {
        SpaceMath::areaOfTriangle = 0.5 * fabs((secondPoint.getAbscissa() - firstPoint.getAbscissa()) * (thirdPoint.getOrdinate() - firstPoint.getOrdinate()) - (thirdPoint.getAbscissa() - firstPoint.getAbscissa()) * (secondPoint.getOrdinate() - firstPoint.getOrdinate()));
    }
    else
    {
        printf("KHONG THE LUA CHON!\n");
    }
    return SpaceMath::areaOfTriangle;
}

int main(int argc, char const *argv[])
{
    Pointer2D first(3, 4);
    Pointer2D second(5, 1);
    Pointer2D third(-3, -8);
    SpaceMath spmt(first, second, third);

    printf("Dien tich tam giac: %f",spmt.calculateAreaOfTriangle());
    return 0;
}
