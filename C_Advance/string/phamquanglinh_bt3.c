#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// char arr[] = "The Grammy award-winning singer. Who has been less active on digital platforms in recent weeks. Explained her decision to distance herself from social media platforms during an appearance on the Conan OBrien Needs a Friend podcast, alongside her brother Finneas";

// Cau 1: Viet mot chuyen dao nguoc VD: "Finneas brother her alongside .... Grammy The"
// cau 2: In Hoa chu cai dau tien sau dau cham
// Cau 3: Chuyen doi tat ca doan van thanh chu thuong
// Cau 4: Chuyen doi tat ca doan van thanh chu hoa

typedef struct
{
    uint16_t size;
    char *firstAdd;
} typeString;

/*------------------------------FUNCTION CODE-----------------------------*/
void importString(typeString *string);// Nhập chuỗi
void exportString(typeString string);// Xuất chuỗi
int sizeString(typeString string);// Tính kích thước của chuỗi 
void revereString(typeString string);// Đảo ngược chuỗi
void firstCapitalize(typeString string);// Viết hoa chữ cái đầu tiên sau dấu "."
void lowerCaseAll(typeString string);// Viết thường cả chuỗi 
void upperCaseAll(typeString string);// Viết hoa cả chuỗi 

/*---------------------------------MAIN-----------------------------------*/
int main(int argc, char const *argv[])
{

    typeString str;
    
    importString(&str);
    printf("\nXUAT CHUOI:  ");
    exportString(str);

    revereString(str);
    firstCapitalize(str);

    upperCaseAll(str);

    lowerCaseAll(str);
    return 0;
}


/*-----------------------------NHẬP CHUÔI------------------------------*/
/*  *string: trỏ tới chuỗi cần nhập  */
void importString(typeString *string)
{
    printf("NHAP SO KY TU : ");
    scanf("%d", &(string->size));

    string->firstAdd = (char *)malloc(sizeof(char) * string->size);

    getchar();
    printf("NHAP CHUOI: ");
    fgets(string->firstAdd, sizeof(char) * string->size, stdin);// Sử dụng hàm fgets để nhập cả ký tự ' '
}

/*-----------------------------XUẤT CHUỖI------------------------------*/
/*  string: tham trị tới chuỗi  */
void exportString(typeString string)
{
    puts(string.firstAdd);
}

/*------------------------ĐẾM SỐ KÝ TỰ CỦA CHUỖI-----------------------*/
/*  string: tham trị tới chuỗi  */
int sizeString(typeString string)
{
    int i = 0;
    for (; string.firstAdd[i] != '\0'; i++);//Nếu chưa gặp kí tự '\0' (NULL) thì tăng i
        
    // Khong dem ky tu '\0'(NULL)
    return i - 1;
}

/*----------------------------ĐẢO NGƯỢC CHUỖI----------------------------*/
/*  string: tham trị tới chuỗi  */
void revereString(typeString string)
{
    //word đếm số từ trong chuỗi 
    uint16_t word = (string.firstAdd[0] != ' ') ? 1 : 0;//Nếu ký tự đầu tiên khác ' ' thì là 1 từ
    uint16_t *index; //Lưu vị trí chữ cái đầu tiên của mỗi từ
    uint8_t sizeIndex = 0;//Tính size cho index

    index = (uint16_t *)malloc(sizeof(uint16_t) * string.size); // Cấp phát động cho index có size = sizeof("chuỗi")

    // Nếu ký tự đầu tiên là từ thì gán vị trí chữ cái đầu tiên = 0
    if (word)
    {
        index[sizeIndex] = 0;
        sizeIndex++;
    }

    // Đếm số từ trong chuỗi
    for (int i = 0; i < sizeString(string); i++)
    {
        if (string.firstAdd[i] == ' ' && string.firstAdd[i + 1] != ' ')//Nếu ký từ i = ' ' và ký tự i+1 = chữ cái -> 1 từ
        {
            word++;//Tăng lên 1 từ
            index[sizeIndex] = i + 1;//Lưu vị trí chữ cái đầu tiên của mỗi từ
            sizeIndex++;
        }
    }

    // Cấp phát lại cho index tránh tốn tài nguyên
    index = (uint16_t *)realloc(index, sizeof(uint16_t) * (sizeIndex));

    //Duyệt ngược lại mảng lưu vị trí chữ cái đầu tiên của mỗi từ 
    printf("\nDAO NGUOC CHUOI:  ");
    //In từ đầu tiên
    //Lấy vị trí chữ cái đầu tiên của từ cuối cùng
    for (int i = index[sizeIndex - 1]; i < sizeString(string); i++)
    {
        printf("%c", string.firstAdd[i]);
    }
    printf(" ");

    //In các từ tiếp theo
    for (int i = sizeIndex - 2; i >= 0; i--)
    {
        for (int j = index[i]; j < index[i+1]; j++)//In từ ký tự đầu tiên của từ đến ký tự đầu tiên của từ tiếp theo
            printf("%c", string.firstAdd[j]);
    }
    printf("\n");
}

/*------------------------VIẾT HOA CHỮ CÁI ĐẦU TIÊN SAU DẤU "."-----------------------*/
/*  string: tham trị tới chuỗi  */
void firstCapitalize(typeString string)
{
    for (int i = 0; i < sizeString(string); i++)
    {
        if (string.firstAdd[i] == '.')
        {
            if (string.firstAdd[i + 2] >= 'a' && string.firstAdd[i + 2] <= 'z')
                string.firstAdd[i + 2] -= 32;
        }
    }

    printf("\nIN HOA CHU CAI SAU DAU '.':  ");
    exportString(string);
}

/*------------------------IN HOA TẤT CẢ CÁC CHỮ-----------------------*/
/*  string: tham trị tới chuỗi  */
void upperCaseAll(typeString string)
{

    for (int i = 0; i < string.size; i++)
    {
        if (string.firstAdd[i] >= 'a' && string.firstAdd[i] <= 'z')
            string.firstAdd[i] -= 32;
    }

    printf("\nIN HOA:  ");
    exportString(string);
}

/*------------------------IN THƯỜNG TẤT CẢ CÁC CHỮ-----------------------*/
/*  string: tham trị tới chuỗi  */
void lowerCaseAll(typeString string)
{

    for (int i = 0; i < string.size; i++)
    {
        if (string.firstAdd[i] >= 'A' && string.firstAdd[i] <= 'Z')
            string.firstAdd[i] += 32;
    }

    printf("\nIN THUONG:  ");
    exportString(string);
}
