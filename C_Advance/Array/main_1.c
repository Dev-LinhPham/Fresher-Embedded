#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint8_t size;
    uint8_t *firstAdd;
} typeArray;

void importArray(typeArray *arr)
{
    printf("\nNhap so phan tu: ");
    scanf("%d", &(arr->size));

    arr->firstAdd = (uint8_t *)malloc(sizeof(uint8_t) * arr->size);

    for (int i = 0; i < arr->size; i++)
    {
        printf("\nNhap arr[%d]: ", i);
        scanf("%d", &(arr->firstAdd[i]));
    }
}

void exportArray(typeArray arr)
{
    printf("\nMang da tao:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("\t%d", arr.firstAdd[i]);
    }
}

void addElement(typeArray *arr)
{
    int value, index;
    printf("\nNhap gia tri chen: ");
    scanf("%d", &value);

    printf("\nNhap index can chen: ");
    scanf("%d", &index);

    arr->size += 1;
    arr->firstAdd = (uint8_t *)realloc(arr->firstAdd, sizeof(uint8_t) * arr->size);
    for (int i = arr->size - 1; i > index; i--)
    {
        arr->firstAdd[i] = arr->firstAdd[i - 1];
    }
    arr->firstAdd[index] = value;
}

void eraseElement(typeArray *arr)
{
    int index;

    printf("\nNhap index can xoa: ");
    scanf("%d", &index);

    for (int i = index; i < arr->size - 1; i++)
    {
        arr->firstAdd[i] = arr->firstAdd[i + 1];
    }

    arr->size -= 1;
    arr->firstAdd = (uint8_t *)realloc(arr->firstAdd, sizeof(uint8_t) * arr->size);
}

void findElement(typeArray arr)
{
    int value;
    int check = 1;
    printf("\nNhap phan tu can tim kiem: ");
    scanf("%d", &value);

    for (int i = 0; i < arr.size; i++)
    {
        if (arr.firstAdd[i] == value)
        {
            printf("\nGia tri %d o vi tri %d", value, i);
            check = 0;
        }
    }
    if (check)
        printf("\nKhong tim thay gia tri %d", value);
}

void normalSort(typeArray arr)
{
    // Giong sap xep chon (selectionSort) nhung khac cach trien khai

    for (int i = 0; i < arr.size - 1; i++)
    {
        for (int j = i + 1; j < arr.size; j++)
        {
            if (arr.firstAdd[i] > arr.firstAdd[j])
            {
                int empty = arr.firstAdd[i];
                arr.firstAdd[i] = arr.firstAdd[j];
                arr.firstAdd[j] = empty;
            }
        }
    }
    printf("\nMang sau sap xep:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("\t%d", arr.firstAdd[i]);
    }
}

void selectionSort(typeArray arr)
{
    int min;
    for (int i = 0; i < arr.size - 1; i++)
    {
        min = i + 1;
        for (int j = i + 2; j < arr.size; j++)
        {
            if (arr.firstAdd[min] > arr.firstAdd[j])
                min = j;
        }
        if (arr.firstAdd[i] > arr.firstAdd[min])
        {
            int empty = arr.firstAdd[i];
            arr.firstAdd[i] = arr.firstAdd[min];
            arr.firstAdd[min] = empty;
        }
    }
    printf("\nMang sau sap xep:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("\t%d", arr.firstAdd[i]);
    }
}

void bubbleSort(typeArray arr) //Cach trien khai toi uu hon cach cu 
{
    int check;
    while (1)
    {
        check = 0;
        for (int i = 0; i < arr.size - 1; i++)
        {

            if (arr.firstAdd[i] > arr.firstAdd[i + 1])
            {
                int empty = arr.firstAdd[i];
                arr.firstAdd[i] = arr.firstAdd[i + 1];
                arr.firstAdd[i + 1] = empty;
                check = 1;
            }
        }
        if (check == 0)
            break;
    }
    printf("\nMang sau sap xep:\n");
    for (int i = 0; i < arr.size; i++)
    {
        printf("\t%d", arr.firstAdd[i]);
    }
}

int main(int argc, char const *argv[])
{
    typeArray arr;
    importArray(&arr);
    exportArray(arr);
    // addElement(&arr);
    // exportArray(arr);
    //  eraseElement(&arr);
    //  exportArray(arr);
    //  findElement(arr);
    // normalSort(arr);
    //selectionSort(arr);
    bubbleSort(arr);
    return 0;
}
