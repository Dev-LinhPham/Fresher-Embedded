/*
* File: main.cpp
* Author: Linh Pham
* Date: 05/04/2023
* Description: Tạo một lớp hình chữ nhật với các thuộc tính chiều dài, chiều rộng và
                các phương thức để tính chu vi, diện tích, đường chéo và kiểm tra xem
                nó có phải là hình vuông hay không.
*/
#include <stdio.h>
#include <math.h>

/*
* Function: Class Rectangle
* Description: Class biễu diễn dữ liệu và phương thức của đối tượng hình chữ nhật
*/
class Rectangle
{
private:
    float width;
    float length;
    float perimeter = 0;
    float areaOfRectangle = 0;
    float diagonal = 0;

public:
    Rectangle(float length = 0, float width = 0);

    float calculatePerimeter();
    float calculateAreaOfRectangle();
    float calculateDiagonal();
    void checkSquare();

    float getWidthRectangle() { return width; };
    float getLengthRectangle() { return length; };

};

/*
* Function: Constructor Rectangle
* Description: Nhập chiều dài, chiều rộng khi khởi tạo
* Input:
*   length - float
*   width - float
*/
Rectangle::Rectangle(float length, float width)
{
    Rectangle::width = width;
    Rectangle::length = length;
}

/*
* Function: calculatePerimeter
* Description: Tính toán chu vi hình chữ nhật
* Output:
*   perimeter - float
*/
float Rectangle::calculatePerimeter()
{
    Rectangle::perimeter = (width + length) * 2;
    return perimeter;
}

/*
* Function: calculateAreaOfRectangle
* Description: Tính toán diện tích hình chữ nhật
* Output:
*   areaOfRectangle - float
*/
float Rectangle::calculateAreaOfRectangle()
{
    Rectangle::areaOfRectangle = width * length;
    return areaOfRectangle;
}

/*
* Function: calculateDiagonal
* Description: Tính toán đường chéo hình chữ nhật
* Output:
*   diagonal - float
*/
float Rectangle::calculateDiagonal()
{
    Rectangle::diagonal = sqrt(pow(width, 2) + pow(length, 2));
    return diagonal;
}

/*
* Function: checkSquare
* Description: Kiểm tra có phải hình vuông ko 
*/
void Rectangle::checkSquare()
{
    if (length == width)
    {
        printf("Day la hinh vuong\n");
    }
    else
    {
        printf("Day la hinh chu nhat\n");
    }
}

int main(int argc, char const *argv[])
{
    Rectangle rectangle(4,4);

    printf("Chu vi: %f\n",rectangle.calculatePerimeter());
    printf("Duong cheo: %f\n",rectangle.calculateDiagonal());
    printf("Dien tich: %f\n",rectangle.calculateAreaOfRectangle());

    rectangle.checkSquare();


    return 0;
}
