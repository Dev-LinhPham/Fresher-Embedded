/*
* File: phamquanglinh_bt1.c
* Author: Pham Quang Linh
* Date: 07/03/2023
* Description: Bài tập tìm kiếm số lần lặp lại của phần tử trong mảng
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
//  sap xep mang theo thu tu tang dan
//  liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                              7 xuat hien 2 lan
//                                              8 xuat hien 3 lan

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
int randomN(int minN, int maxN); //Random giá trị từ minN -> maxN
void randomArray(typeArray *array, uint8_t length); //Random mảng 
void softArray(typeArray *array);// Sắp xếp mảng 
void countArray(typeArray array);// Đếm số lần xuất hiện của phần tử 
void printfArray(typeArray array);// In mảng

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
    typeArray arr;

    randomArray(&arr, 20);

    printf("\nMang da tao:\n");
    printfArray(arr);

    softArray(&arr);

    printf("\nSau khi sap xep:\n");
    printfArray(arr);
    
    countArray(arr);
    return 0;
}

/*
* Function: randomN
* Description: Random số từ giá trị min -> max
* Input:
*   minN - int (số nhỏ nhất có thể random)
*   maxN - int (số lớn nhất có thể random)
* Output:
*   trả về giá trị kiểu int trong khoảng min -> max
*/
int randomN(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN); //Trả về giá trị random cho mỗi phần tử của mảng
}

/*
* Function: randomArray
* Description: Random ra 1 mảng có size = length và các phần từ có giá trị nằm trong khoảng min -> max 
* Input:
*   array - typeArray* (trỏ tới mảng muốn random)
*   length - uint8_t (kích thước của mảng)
* Output:
*   None
*/
void randomArray(typeArray *array, uint8_t length)
{
    srand((int)time(0));

    array->size = length; //Kích thước của mảng 

    array->firstAdd = (uint8_t *)malloc(sizeof(uint8_t) * array->size); //Cấp phát động cho mảng

    for (int i = 0; i < array->size; ++i)
    {
        array->firstAdd[i] = randomN(0, 10); //Gắn giá trị cho từng phần tử của mảng
    }
}

/*
* Function: softArray
* Description: Sắp xếp mảng theo thứ tự tăng dần dựa theo thuật toán nổi bọt 
* Input:
*   array - typeArray* (trỏ tới mảng muốn sắp xếp)
* Output:
*   None
*/
void softArray(typeArray *array)
{
    // Viết dựa trên lý thuyết thuật toán sắp xếp nối bọt
    // Thực hiện vòng lặp so sánh 2 số liên tiếp nhau. Nếu a[i] > a[i+1] => Đổi chỗ.
    // Thực hiện đến khi dãy được sắp xếp.
    // VD: 5 1 4 2 8
    // (5 1) 4 2 8 => (1 5) 4 2 8
    // 1 (5 4) 2 8 => 1 (4 5) 2 8
    // 1 4 (5 2) 8 => 1 4 (2 5) 8
    // 1 4 2 (5 8) => 1 4 2 (5 8)
    // Tiếp tục lặp lại đến khi nào ko còn sự đổi chỗ.
    int check; //Biến kiểm tra trong 1 vòng lặp có sự thay đổi chỗ không
    while (1)
    {
        check = 0;
        for (int i = 0; i < array->size - 1; i++)
        {

            if (array->firstAdd[i] > array->firstAdd[i + 1]) // Nếu arr[i] > arr[i+1] -> Đổi vị trí
            {
                int empty = array->firstAdd[i];
                array->firstAdd[i] = array->firstAdd[i + 1];
                array->firstAdd[i + 1] = empty;
                check = 1; //Có sự thay đổi vị trí
            }
        }
        if (check == 0) //Không có sự thay đổi vị trí trong 1 vòng lặp -> Break khỏi vòng lặp While
            break;
    }
}

/*
* Function: countArray
* Description: Đếm số lần xuất hiện giá trị trong các phần tử của mảng
* Input:
*   array - typeArray 
* Output:
*   None
*/
void countArray(typeArray array)
{
    uint8_t counter = 1;// Biến đếm số lần xuất hiện của phần tử

    for (int i = 0; i < array.size; i++) //So sánh phần tử i với [i+1, array.size]
    {
        for (int j = i + 1; j <= array.size; j++)
        {
            if (array.firstAdd[i] == array.firstAdd[j])// Nếu 2 phần tử bằng nhau -> Tăng biến đếm
            {
                counter++;
            }
            else // Nếu gặp phần tử không bằng -> Break khỏi vòng lặp và In 
            {
                i = j - 1; // Gán i tại vị trí phần tử không bằng để đếm tiếp
                break;
            }
        }
        printf("\n%d xuat hien %d lan", array.firstAdd[i], counter);
        counter = 1;
    }
}

/*
* Function: printfArray
* Description: In ra các phần tử của mảng 
* Input:
*   array - typeArray 
* Output:
*   None
*/
void printfArray(typeArray array)
{
    for (int i = 0; i < array.size; i++)
    {
        printf("%d  ", array.firstAdd[i]);
    }
}
