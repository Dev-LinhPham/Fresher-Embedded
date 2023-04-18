/*
* File: main.cpp
* Author: Linh Pham
* Date: 18/04/2023
* Description: Tạo một lớp xe hơi với các thuộc tính màu sắc, kiểu động cơ và số km
                đã đi, và các phương thức để tính toán chi phí bảo trì, kiểm tra số km
                đã đi và in thông tin về xe.
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Function: Class Car
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng ô tô
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
class Car
{
private:
    char colorCar[20];
    char typeEngineCar[20];
    uint32_t kmCar;

public:
    Car(const char colorCar[], const char typeEngineCar[], const uint32_t kmCar);

    char *getColorCar();
    char *getTypeEngineCar();
    uint32_t getKmCar();

    uint32_t maintenanceCost();
    void getInforCar();
};

/*
 * Function: Constructor Car
 * Description: Nhập thông tin ô tô
 * Input:
 *   colorCar - const char
 *   typeEngineCar - const char
 *   kmCar - const uint32_t
 * Output:
 *   Return - None
 */
Car::Car(const char colorCar[], const char typeEngineCar[], const uint32_t kmCar)
{
    strcpy(Car::colorCar, colorCar);
    strcpy(Car::typeEngineCar, typeEngineCar);
    Car::kmCar = kmCar;
}

/*
 * Function: getColorCar
 * Description: Lấy màu sắc của ô tô
 * Input:
 *   No input
 * Output:
 *   Return - colorCar
 */
char *Car::getColorCar()
{
    return colorCar;
}

/*
 * Function: getTypeEngineCar
 * Description: Lấy kiểu động cơ của ô tô
 * Input:
 *   No input
 * Output:
 *   Return - typeEngineCar
 */
char *Car::getTypeEngineCar()
{
    return typeEngineCar;
}

/*
 * Function: getKmCar
 * Description: Lấy số km của ô tô
 * Input:
 *   No input
 * Output:
 *   Return - kmCar
 */
uint32_t Car::getKmCar()
{
    return kmCar;
}

/*
 * Function: maintenanceCost
 * Description: Tính toán chi phí dựa vào số km
 * Input:
 *   No input
 * Output:
 *   Return - uint32_t
 */
uint32_t Car::maintenanceCost()
{
    if (kmCar < 10000)
    {
        return 100000;
    }
    else if (kmCar < 20000)
    {
        return 200000;
    }
    else if (kmCar < 50000)
    {
        return 500000;
    }
    else
    {
        return 1000000;
    }
}

/*
 * Function: getInforCar
 * Description: Lấy thông tin của ô tô
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
void Car::getInforCar()
{
    printf("Mau sac: %s\n", colorCar);
    printf("Dong co: %s\n", typeEngineCar);
    printf("So km: %d\n", kmCar);
}

int main(int argc, char const *argv[])
{
    Car car1("Do cherry", "Xang 2.5", 23000);

    car1.getInforCar();

    printf("Chi phi bao duong: %d", car1.maintenanceCost());
    return 0;
}
