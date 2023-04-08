/*
* File: phamquanglinh_bt2.c
* Author: Pham Quang Linh
* Date: 07/03/2023
* Description: Bài tập Đọc số tiền 
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*-------------------------ĐỔI TỪ SỐ RA CHỮ----------------------*/
// VD: 1354765 => MOT TRIEU BA TRAM NAM MUOI TU NGHIN BAY TRAM SAU MUOI LAM DONG
// Ý tưởng: Chia số làm 3 Phần, xử lý từng Phần & In
// VD: 1354765 => |"1"|"354"|"765"|
//             => |"1"| hàng Triệu
//             => |"354"| hàng Nghìn
//             => |"765"| hàng Đồng
// Phần hàng "Nghìn" + hàng "Đồng"  được xử lý ra từng TH => Nhảy đến hàm printCase() để in.


/*
* Function: Struct typeArray
* Description: Chứa các member cần thiết để có 1 mảng là Size & địa chỉ đầu tiên của mảng
* Input:
*   None
* Output:
*   None
*/
typedef struct
{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

/*
* Function: Funtion Code
* Description: Hiển thị các hàm chức năng để tương tác với chương trình
* Input:
*   None
* Output:
*   None
*/
void readUnit(uint8_t num); //Đọc phần đơn vị
void readDecimal(uint8_t dec); //Đọc phần thập phân
void inputNumber(uint32_t *number, typeArray *array); //Nhập số cần đọc
void printCase(uint8_t binTotal, typeArray array, uint8_t idx_last); //Đọc hàng "Nghìn" hoặc hàng "Đồng"
void readNumber(typeArray array); //Đọc số nhập vào ra chữ


/*
* Function: Main
* Description: Chạy chương trình 
* Input:
*   None
* Output:
*   None
*/
int main(int argc, char const *argv[])
{
    uint32_t num;
    typeArray arr;

    inputNumber(&num, &arr);
    readNumber(arr);
    return 0;
}

/*
* Function: readUnit
* Description: Đổi chữ số nhập vào ra chữ 
* Input:
*   num - uint8_t (chữ số nhập vào)
* Output:
*   None
*/
void readUnit(uint8_t num)
{
    switch (num)
    {
    case 0:
        printf("KHONG ");
        break;
    case 1:
        printf("MOT ");
        break;
    case 2:
        printf("HAI ");
        break;
    case 3:
        printf("BA ");
        break;
    case 4:
        printf("BON ");
        break;
    case 5:
        printf("NAM ");
        break;
    case 6:
        printf("SAU ");
        break;
    case 7:
        printf("BAY ");
        break;
    case 8:
        printf("TAM ");
        break;
    case 9:
        printf("CHIN ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*
* Function: readDecimal
* Description: Đọc phần thập phân của từng hàng số
* Input:
*   dec - uint8_t (Vị trí chữ số nhập vào)
* Output:
*   None
*/
void readDecimal(uint8_t dec)
{
    switch (dec)
    {
    case 0:
        printf("DONG\n");
        break;
    case 1:
    case 4:
        printf("MUOI ");
        break;
    case 3:
        printf("NGHIN  ");
        break;
    case 2:
    case 5:
        printf("TRAM ");
        break;
    case 6:
        printf("TRIEU  ");
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*
* Function: inputNumber
* Description: Nhập số cần đọc và tách các thành các chữ số gán vào phần tử mảng
* Input:
*   number - uint32_t (số nhập vào)
*   array - typeArray* (Mảng chứa các chữ số của số nhập vào)
* Output:
*   None
*/
void inputNumber(uint32_t *number, typeArray *array)
{
    //Nhập số > 0 & < 1*10^6 
    do
    {
        printf("\nEnter Number: ");
        scanf("%d", number);
    } while (*number < 0 || *number > 10000000);

    array->size = 7; //Giới hạn 7 chữ số -> fix cứng là 7
    array->firstAdd = (uint8_t *)calloc(array->size, sizeof(uint8_t)); //Cấp phát cho mảng chứa chữ số

    // Tách từng chữ số và nhập ngược vào mảng
    uint32_t reNum = *number; //Lưu số sau khi bỏ chữ số cuối
    uint32_t last; //Lấy chữ số cuối cùng của số nhập vào

    for (int i = 0; i < array->size; i++)
    {
        last = reNum % 10;
        array->firstAdd[i] = last;
        reNum /= 10;
    }
}

/*
* Function: printCase
* Description: Hàm in hàng "Nghìn" & "Đồng"
* Input:
*   binTotal - uint8_t (giá trị tổng sau khi mã hóa nhị phân của hàng)
*   array - typeArray (Mảng chứa các chữ số của số nhập vào)
*   idx_last - uint8_t (vị trí chữ số cuối cùng của hàng)
* Output:
*   None
*/
void printCase(uint8_t binTotal, typeArray array, uint8_t idx_last)
{
    //Kiểm tra & in ra chữ số đầu tiên hàng "Nghìn" hoặc hàng "Đồng"
    int check = 0; //Kiểm tra các chữ số đứng trước nó lớn hơn 0
    for (int i = idx_last + 2; i < array.size; i++)
    {
        if (array.firstAdd[i] > 0)
            check = 1;
    }
    if (check)// Nếu lớn hơn 0 thì đọc chữ số đầu tiên của hàng
    {
        readUnit(array.firstAdd[(idx_last + 2)]);
        readDecimal(idx_last + 2);
        //Nếu chữ số cuối cùng > 0 & chữ số giữa = 0 -> Thêm "LINH" VD: 102 
        if (array.firstAdd[(idx_last)] > 0 && array.firstAdd[(idx_last + 1)] == 0)
            printf("LINH ");
    }

    //Kiểm tra & in ra chữ số tiếp theo hàng "Nghìn" hoặc hàng "Đồng"
    //Giả sử 1 hàng là ABC 
    //A: giá trị của chữ số, a hệ số nhị phân của chữ số)
    //a = (A > 0) ? 1 : 0 , b c tương tự
    //binTotal = a.2^0 + b.2^1 + c.2^2
    switch (binTotal)
    {
    //A >= 0, B = 0, C = 0
    case 0:
    case 1:
        readDecimal(idx_last);//Đọc phần thập phân chữ số cuối cùng
        break;
    //A = 0, B > 0, C = 0 hoặc A > 0, B > 0, C = 0
    case 2:
    case 3:
        if (array.firstAdd[(idx_last + 1)] > 1) //Kiểm tra chữ số giữa của hàng, nếu > 1 -> Đọc phần đơn vị + thập phân 
        {                                                                           
            readUnit(array.firstAdd[(idx_last + 1)]);
            readDecimal(idx_last + 1);
        }
        else
        {
            readDecimal(idx_last + 1);//Nếu = 1 -> Đọc phần thập phân, in "MUOI"
        }
        readDecimal(idx_last);//Đọc phần thập phân chữ số cuối cùng
        break;
    //A = 0, B = 0, C > 0 hoặc A > 0, B = 0, C > 0
    case 4:
    case 5:
        readUnit(array.firstAdd[(idx_last)]); //Đọc phần đơn vị + thập phân chữ số cuối cùng
        readDecimal(idx_last);
        break;
    //A = 0, B > 0, C > 0 hoặc A > 0, B > 0, C > 0
    case 6:
    case 7:
        if (array.firstAdd[(idx_last + 1)] > 1) //Kiểm tra chữ số giữa của hàng, nếu > 1 -> Đọc phần đơn vị + thập phân 
        {
            readUnit(array.firstAdd[(idx_last + 1)]);
            readDecimal(idx_last + 1);
        }
        else
        {
            readDecimal(idx_last + 1); //Nếu = 1 -> Đọc phần thập phân, in "MUOI"
        }
        if (array.firstAdd[(idx_last)] == 5) //Kiểm tra chữ số giữa của hàng, nếu = 5 -> Đọc " LAM" + thập phân 
        {
            printf("LAM ");
            readDecimal(idx_last);
        }
        else
        {
            readUnit(array.firstAdd[(idx_last)]);//Nếu khác 5 -> Đọc phần đơn vị + thập phân
            readDecimal(idx_last);
        }
        break;
    default:
        printf("ERROR!! KHONG HOP LE\n");
        break;
    }
}

/*
* Function: readNumber
* Description: Hàm đọc chữ số nhập vào
* Input:
*   array - typeArray (Mảng chứa các chữ số của số nhập vào)
* Output:
*   None
*/
void readNumber(typeArray array)
{
    //Đọc hàng "Triệu"
    if (array.firstAdd[array.size - 1] > 0)// Nếu hàng "Triệu" > 0 mới đọc
    {
        readUnit(array.firstAdd[array.size - 1]);
        readDecimal(array.size - 1);
    }

    //Tính toán tổng nhị phân các chữ số hàng "Nghìn"
    uint8_t binTotal_1 = 0;
    for (int i = array.size - 4; i < array.size - 1; i++)
    {
        uint8_t bin = (array.firstAdd[i] > 0) ? 1 : 0;
        binTotal_1 = binTotal_1 * 2 + bin;
    }

    //Tính toán tổng nhị phân các chữ số hàng "Đồng"
    uint8_t binTotal_2 = 0;
    for (int i = array.size - 7; i < array.size - 4; i++)
    {
        uint8_t bin = (array.firstAdd[i] > 0) ? 1 : 0;
        binTotal_2 = binTotal_2 * 2 + bin;
    }

    // Tính toán các TH phần "Nghìn" + phần "Đồng"
    if (binTotal_1 + binTotal_2 == 0) //Nếu tổng nhị phân 2 hàng = 0 -> Ko đọc gì 
    {
        printf("DONG\n");
    }
    else
    {
        if (binTotal_1 > 0)
        {
            printCase(binTotal_1, array, array.size - 4);
            if (binTotal_2 > 0)
                //Nếu tổng nhị phân hàng "Nghìn" > 0 & tổng nhị phân hàng "Đồng" > 0
                //Đọc hàng "Nghìn" + "Đồng"
                printCase(binTotal_2, array, array.size - 7);
            else
                //Nếu tổng nhị phân hàng "Nghìn" > 0 & tổng nhị phân hàng "Đồng" = 0
                //Đọc hàng "Nghìn"
                printf("DONG\n");
        }
        else
        {
            //Nếu tổng nhị phân hàng "Nghìn" = 0 & tổng nhị phân hàng "Đồng" > 0
            //Đọc hàng "Đồng"
            printCase(binTotal_2, array, array.size - 7);
        }
    }
}


