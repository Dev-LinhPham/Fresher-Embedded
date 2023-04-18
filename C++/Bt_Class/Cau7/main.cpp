/*
* File: main.cpp
* Author: Linh Pham
* Date: 18/04/2023
* Description: Tạo một lớp ngày tháng năm với các thuộc tính ngày, tháng và năm, và
                các phương thức để tính tuổi của người và kiểm tra xem một ngày nhất
                định có phải là ngày nghỉ lễ hay không.
*/
#include <stdio.h>
#include <stdint.h>

#define CONDITION(condition, content1, content2) \
    while (condition)                            \
    {                                            \
        printf(content1);                        \
        printf(content2);                        \
        scanf("%d", &day);                       \
    }



/*
* Function: Class Schedule
* Description: Class biễu diễn dữ liệu và phương thức của Lịch trình
* Input:
*   No input
* Output:
*   Return - None
*/
class Schedule
{
private:
    uint8_t day;
    uint8_t month;
    uint16_t year;

    uint8_t checkLeapYear(uint16_t year);

public:
    Schedule(const uint8_t day, const uint8_t month, const uint16_t year);

    uint8_t getDay();
    uint8_t getMonth();
    uint16_t getYear();
    void checkHolidays(const uint8_t day, const uint8_t month);
    void calculateAge();
};

/*
* Function: checkLeapYear
* Description: Kiểm tra có phải năm nhuận không
* Input:
*   year - uint16_t 
* Output:
*   1 - True
*   0 - False
*/
uint8_t Schedule::checkLeapYear(uint16_t year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/*
* Function: Constructor Schedule
* Description: Nhập thông tin ngày tháng năm
* Input:
*   day - const uint8_t 
*   month - const uint8_t 
*   year - const uint16_t
* Output:
*   Return - None
*/
Schedule::Schedule(const uint8_t day, const uint8_t month, const uint16_t year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        CONDITION(day > 31 || day < 1, "Khong dung ngay!\n", "Nhap ngay: ")
        break;
    case 2:
        if (checkLeapYear(year))
        {
            CONDITION(day > 29 || day < 1, "Khong dung ngay!\n", "Nhap ngay: ")
        }
        else
        {
            CONDITION(day > 28 || day < 1, "Khong dung ngay!\n", "Nhap ngay: ")
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        CONDITION(day > 30 || day < 1, "Khong dung ngay!\n", "Nhap ngay: ")
        break;
    default:
        while (month > 12 || day < 1)
        {
            printf("Khong dung thang!\n");
            printf("Nhap thang: ");
            scanf("%d", &month);
        }
        break;
    }
    Schedule::day = day;
    Schedule::month = month;
    Schedule::year = year;
}

/*
* Function: getDay
* Description: Lấy ngày
* Input:
*   No input
* Output:
*   Return - day
*/
uint8_t Schedule::getDay()
{
    return Schedule::day;
}

/*
* Function: getMonth
* Description: Lấy tháng
* Input:
*   No input
* Output:
*   Return - month
*/
uint8_t Schedule::getMonth()
{
    return Schedule::month;
}

/*
* Function: getYear
* Description: Lấy năm
* Input:
*   No input
* Output:
*   Return - year
*/
uint16_t Schedule::getYear()
{
    return Schedule::year;
}

/*
* Function: checkHolidays
* Description: Kiểm tra ngày lễ
* Input:
*   day - const uint8_t
*   month - const uint8_t
* Output:
*   Return - none
*/
void Schedule::checkHolidays(const uint8_t day, const uint8_t month)
{
    if (day == 1 && month == 1)
    {
        printf("Tet duong lich!!\n");
    }
    else if (day == 30 && month == 4)
    {
        printf("Thong nhat dat nuoc!!\n");
    }
    else if (day == 1 && month == 5)
    {
        printf("Quoc te lao dong!!\n");
    }
    else if (day == 2 && month == 9)
    {
        printf("Quoc khanh Viet Nam!!\n");
    }
    else
    {
        printf("Ngay Binh thuong\n");
    }
}

/*
* Function: calculateAge
* Description: Tính tuổi người
* Input:
*   No input
* Output:
*   Return - none
*/
void Schedule::calculateAge()
{

    uint16_t yearNow;
    do
    {
        printf("Nhap nam hien tai: ");
        scanf("%d", &yearNow);
    }while(yearNow - year < 0);
    printf("Tuoi la: %d",yearNow - year);
}

int main(int argc, char const *argv[])
{
    Schedule Linh(30, 4, 1999);

    Linh.checkHolidays(1,1);

    Linh.calculateAge();

    return 0;
}
