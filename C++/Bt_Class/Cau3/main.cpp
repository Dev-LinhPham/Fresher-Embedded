/*
* File: main.cpp
* Author: Linh Pham
* Date: 05/04/2023
* Description: Tạo một lớp hình tròn với bán kính và các phương thức để tính chu vi
                và diện tích của hình tròn.
*/
#include <stdio.h>
#include <math.h>

#define PI 3.14

/*
* Function: Class Circle
* Description: Class biễu diễn dữ liệu và phương thức của đối tượng hình tròn
*/
class Circle
{
private:
    float radius;
    float perimeter = 0;
    float areaOfCircle = 0;

public:
    Circle(float radius);

    float calculateAreaOfCircle();
    float calculatePerimeter();

    float getRadius() { return radius; };
};

/*
* Function: Constructor Circle
* Description: Nhập bán kinh hình tròn
* Input:
*   radius - float
*/
Circle::Circle(float radius)
{
    Circle::radius = radius;
}

/*
* Function: calculatePerimeter
* Description: Tính toán chu vi hình tròn
* Output:
*   perimeter - float
*/
float Circle::calculatePerimeter()
{
    Circle::perimeter = radius * 2 * PI;
    return perimeter;
}

/*
* Function: calculateAreaOfCircle
* Description: Tính toán diện tích hình tròn
* Output:
*   areaOfCircle - float
*/
float Circle::calculateAreaOfCircle()
{
    Circle::areaOfCircle = pow(radius, 2) * PI;
    return areaOfCircle;
}

int main(int argc, char const *argv[])
{
    Circle circle(4);

    printf("Dien tich: %f\n",circle.calculateAreaOfCircle());
    printf("Chu vi: %f\n",circle.calculatePerimeter());

    return 0;
}
