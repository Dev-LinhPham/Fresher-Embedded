/*
 * File: main.cpp
 * Author: Linh Pham
 * Date: 24/03/2023
 * Description: Chương trình quản lý sinh viên
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
 * Function: MACRO ENTER_INFORMATION
 * Description: Macro phần nhập thông tin Sinh Viên
 * Input:
 *   content - Nội dung cần nhập
 *   format - định dạng kiểu dữ liệu
 *   variable - biến cần nhập vào
 *   condition - điều kiện để nhập
 */
#define ENTER_INFORMATION(content, format, variable, condition) \
    do                                                          \
    {                                                           \
        printf(content);                                        \
        scanf(format, variable);                                \
    } while (condition)

/*
 * Function: MACRO PRINT_INFORMATION
 * Description: Macro phần hiển thị thông tin Sinh Viên
 * Input:
 *   object - đối tượng cần hiển thị
 */
#define PRINT_INFORMATION(object)                                                          \
    printf(" %d\t| %s\t| %d\t|   %s\t\t|", object.getIDStudent(), object.getNameStudent(), \
           object.getAgeStudent(), object.getGenderStudent());                             \
    printf(" %.2f\t| %.2f\t| %.2f\t|", object.getScoreMath(), object.getScorePhysic(),     \
           object.getScoreChemistry());                                                    \
    printf("   %.2f\t|   %s\n", object.getScoreAvarge(), object.getRankStudent())

/*
 * Function: MACRO CHECK_LISTSTUDENT
 * Description: Macro kiểm tra danh sách có sinh viên không
 * Input:
 *   notification - Nội dung thông báo
 *   content - Nội dung Method Menu
 */
#define CHECK_LISTSTUDENT(notification, content) \
    if (listStudent.empty())                     \
    {                                            \
        printf("Danh sach Sinh Vien trong !\n"); \
        printf(notification);                    \
    }                                            \
    else                                         \
    {                                            \
        content                                  \
    }

/*
 * Function: MACRO DOWHILE_METHODMENU
 * Description: Macro sử dụng chức năng của từng method
 * Input:
 *   content - Nội dung chức năng của từng method
 */
#define DOWHILE_METHODMENU(content)                            \
    do                                                         \
    {                                                          \
        content                                                \
        printf("- Nhan phim '0' => De Thoat chuc nang\n");     \
        scanf("%d", &key);                                     \
    } while (key == 1)

/*
 * Function: Class Sinh viên
 * Description: Chứa Property & Method sử dụng cho class sinh viên
 */
class Student
{
private:
    uint8_t idStudent;
    char nameStudent[20];
    char genderStudent[4];
    uint8_t ageStudent;
    float scoreMath = -1;
    float scorePhysic = -1;
    float scoreChemistry = -1;
    float scoreAvarge = -1;
    char rankStudent[11];

public:
    Student(const char nameStudent[], const char genderStudent[], const uint8_t ageStudent,
            float scoreMath, float scorePhysic, float scoreChemistry);

    void setNameStudent(const char nameStudent[]);
    void setGenderStudent(const char genderStudent[]);
    void setAgeStudent(uint8_t ageStudent);
    void setScoreMath(float scoreMath);
    void setScorePhysic(float scorePhysic);
    void setScoreChemistry(float scoreChemistry);

    uint8_t getIDStudent();
    char *getNameStudent();
    char *getGenderStudent();
    uint8_t getAgeStudent();
    float getScoreMath();
    float getScorePhysic();
    float getScoreChemistry();
    float getScoreAvarge();
    char *getRankStudent();
};

/*
 * Function: Method setNameStudent
 * Description: Đặt tên cho sinh viên
 * Input:
 *   nameStudent - Mảng chuỗi kí tự chứa tên
 */
void Student::setNameStudent(const char nameStudent[])
{
    strcpy(Student::nameStudent, nameStudent);
}

/*
 * Function: Method setGenderStudent
 * Description: Đặt giới tính cho sinh viên
 * Input:
 *   genderStudent - Mảng chuỗi kí tự chưa giới tính
 */
void Student::setGenderStudent(const char genderStudent[])
{
    if (strcmp((char *)"Nam", genderStudent) != 0 && strcmp((char *)"Nu", genderStudent) != 0)
    {
        printf("ERROR! Gioi tinh khong hop le");
    }
    else
    {
        strcpy(Student::genderStudent, genderStudent);
    }
}

/*
 * Function: Method setAgeStudent
 * Description: Đặt tuổi cho sinh viên
 * Input:
 *   ageStudent - uint8_t tuổi
 */
void Student::setAgeStudent(uint8_t ageStudent)
{
    Student::ageStudent = ageStudent;
}

/*
 * Function: Method setScoreChemistry
 * Description: Đặt điểm hóa cho sinh viên
 * Input:
 *   scoreChemistry - float điểm hóa
 */
void Student::setScoreChemistry(float scoreChemistry)
{
    Student::scoreChemistry = scoreChemistry;
}

/*
 * Function: Method setScoreMath
 * Description: Đặt điểm toán cho sinh viên
 * Input:
 *   scoreMath - float điểm toán
 */
void Student::setScoreMath(float scoreMath)
{
    Student::scoreMath = scoreMath;
}

/*
 * Function: Method setScoreMath
 * Description: Đặt điểm lý cho sinh viên
 * Input:
 *   scoreMath - float điểm lý
 */
void Student::setScorePhysic(float scorePhysic)
{
    Student::scorePhysic = scorePhysic;
}

/*
 * Function: Constructor Student
 * Description: Khởi tạo dữ liệu cho mỗi Sinh viên
 * Input:
 *   nameStudent - Mảng chuỗi kí tự chứa tên
 *   genderStudent - Mảng chuỗi kí tự chưa giới tính
 *   ageStudent - uint8_t tuổi
 *   scoreMath - float điểm lý
 *   scoreChemistry - float điểm hóa
 *   scoreMath - float điểm toán
 */
Student::Student(const char nameStudent[], const char genderStudent[], const uint8_t ageStudent,
                 const float scoreMath, const float scorePhysic, const float scoreChemistry)
{
    // Tự động tạo ID cho Sinh viên
    static uint8_t s_Id = 100;
    Student::idStudent = s_Id;
    s_Id++;

    strcpy(Student::nameStudent, nameStudent);

    Student::setGenderStudent(genderStudent);

    Student::ageStudent = ageStudent;

    Student::scoreMath = scoreMath;

    Student::scorePhysic = scorePhysic;

    Student::scoreChemistry = scoreChemistry;
}

/*
 * Function: Method getIDStudent
 * Description: Lấy ID của Sinh viên
 * Output:
 *   idStudent - uint8_t id
 */
uint8_t Student::getIDStudent()
{
    return Student::idStudent;
}

/*
 * Function: Method getNameStudent
 * Description: Lấy tên của Sinh viên
 * Output:
 *   nameStudent - char* tên
 */
char *Student::getNameStudent()
{
    return Student::nameStudent;
}

/*
 * Function: Method getGenderStudent
 * Description: Lấy giới tính của Sinh viên
 * Output:
 *   genderStudent - char* giới tính
 */
char *Student::getGenderStudent()
{
    return Student::genderStudent;
}

/*
 * Function: Method getAgeStudent
 * Description: Lấy tuổi của Sinh viên
 * Output:
 *   ageStudent - uint8_t tuổi
 */
uint8_t Student::getAgeStudent()
{

    return Student::ageStudent;
}

/*
 * Function: Method getScoreChemistry
 * Description: Lấy điểm hóa của Sinh viên
 * Output:
 *   scoreChemistry - float điểm hóa
 */
float Student::getScoreChemistry()
{
    return Student::scoreChemistry;
}

/*
 * Function: Method getScorePhysic
 * Description: Lấy điểm lý của Sinh viên
 * Output:
 *   scorePhysic - float điểm lý
 */
float Student::getScorePhysic()
{
    return Student::scorePhysic;
}

/*
 * Function: Method getScoreMath
 * Description: Lấy điểm toán của Sinh viên
 * Output:
 *   scoreMath - float điểm toán
 */
float Student::getScoreMath()
{
    return Student::scoreMath;
}

/*
 * Function: Method getScoreAvarge
 * Description: Tính toán &Lấy điểm toán của Sinh viên
 * Output:
 *   scoreAvarge - float điểm TBinh
 */
float Student::getScoreAvarge()
{
    Student::scoreAvarge = (Student::scoreMath + Student::scorePhysic + Student::scoreChemistry) / 3;
    return Student::scoreAvarge;
}

/*
 * Function: Method getRankStudent
 * Description: Xét học lực dựa vào điểm TB
 * Output:
 *   getRankStudent - char* rankStudent
 */
char *Student::getRankStudent()
{
    float score = Student::getScoreAvarge();

    if (score >= 8.00)
    {
        strcpy(Student::rankStudent, "Gioi");
    }
    else if (score >= 6.50)
    {
        strcpy(Student::rankStudent, "Kha");
    }
    else if (score >= 5.00)
    {
        strcpy(Student::rankStudent, "Trung Binh");
    }
    else
    {
        strcpy(Student::rankStudent, "Yeu");
    }

    return Student::rankStudent;
}

/*
 * Function: Class Menu
 * Description: Chứa Property & Method sử dụng cho chương trình quản lý sinh viên
 */
class Menu
{
private:
    vector<Student> listStudent;

public:
    void addStudent();
    void displayStudent();
    void updateStudent();
    void eraseStudent();
    void searchStudent();
    void softOfByGPA();
    void softOfByName();
};

/*
 * Function: Method addStudent
 * Description: Thêm TT Sinh viên vào danh sách
 */
void Menu::addStudent()
{
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
    uint8_t key;

    DOWHILE_METHODMENU
    (
        printf("/* KHAI BAO THONG TIN SINH VIEN */\n");

        ENTER_INFORMATION("Nhap ten: ", "%s", &name, 0);

        ENTER_INFORMATION("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);

        ENTER_INFORMATION("Nhap gioi tinh: ", "%s", &gender, 0);

        ENTER_INFORMATION("Nhap diem toan: ", "%f", &math, math > 10 || math < 0);

        ENTER_INFORMATION("Nhap diem ly: ", "%f", &physic, physic > 10 || physic < 0);

        ENTER_INFORMATION("Nhap diem hoa: ", "%f", &chemistry, chemistry > 10 || chemistry < 0);

        Student student(name, gender, age, math, physic, chemistry);

        listStudent.push_back(student);

        printf("- Nhan phim '1' => De tiep tuc Them sinh vien\n");
    );
}

/*
 * Function: Method displayStudent
 * Description: Hiển thị danh sách sinh viên
 */
void Menu::displayStudent()
{
    uint8_t key;

    CHECK_LISTSTUDENT
    (
        "KHONG THE HIEN THI!\n",
        DOWHILE_METHODMENU
            (
                printf("\n------------------------------------DANH SACH SINH VIEN-----------------------------------\n");
                printf("  ID\t| Ten\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
                for (Student student : listStudent) 
                {
                    PRINT_INFORMATION(student);
                }

                printf("- Nhan phim '1' => De Hien thi Danh sach\n");
            );
    );        

}

/*
 * Function: Method updateStudent
 * Description: Cập nhật thông tin Sinh viên theo ID
 */
void Menu::updateStudent()
{
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;

    uint8_t choice;
    uint8_t key;
    uint8_t id;
    vector<Student> *ptr = &listStudent;
    bool haveStudent = false;
    
    CHECK_LISTSTUDENT
    (
        "KHONG THE CAP NHAT THONG TIN !\n",
        DOWHILE_METHODMENU
        (
            printf("/* CAP NHAT THONG TIN SINH VIEN */\n");

            ENTER_INFORMATION("Nhap ID sinh vien: ", "%d", &id, 0);
            
            for (int index = 0; index < ptr->size(); index++)
            {
            

                if ((ptr->at(index)).getIDStudent() == id)
                {
                    printf("------CHON THONG TIN CAN CAP NHAT------\n");
                    printf("1. TEN\n");
                    printf("2. TUOI\n");
                    printf("3. GIOI TINH\n");
                    printf("4. DIEM TOAN\n");
                    printf("5. DIEM LY\n");
                    printf("6. DIEM HOA\n");
                    printf("7. Thoat\n");
                    printf("-------------------------------------------\n");
                    ENTER_INFORMATION("- Nhan phim : ", "%d", &choice, 0);
                    
                    switch (choice)
                    {
                    case 1:
                        ENTER_INFORMATION("Nhap ten: ", "%s", &name, 0);
                        (ptr->at(index)).setNameStudent(name);
                        break;
                    case 2:
                        ENTER_INFORMATION("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);
                        (ptr->at(index)).setAgeStudent(age);
                        break;
                    case 3:
                        ENTER_INFORMATION("Nhap gioi tinh: ", "%s", &gender, 0);
                        (ptr->at(index)).setGenderStudent(gender);
                        break;
                    case 4:
                        ENTER_INFORMATION("Nhap diem toan: ", "%f", &math, math > 10 || math < 0);
                        (ptr->at(index)).setScoreMath(math);
                        break;
                    case 5:
                        ENTER_INFORMATION("Nhap diem ly: ", "%f", &physic, physic > 10 || physic < 0);
                        (ptr->at(index)).setScorePhysic(physic);
                        break;
                    case 6:
                        ENTER_INFORMATION("Nhap diem hoa: ", "%f", &chemistry, chemistry > 10 || chemistry < 0);
                        (ptr->at(index)).setScoreChemistry(chemistry);
                        break;
                    case 7:
                        break;
                    default:
                        printf("KHONG DUNG LUA CHON, VUI LONG NHAP LAI\n");
                        break;
                    }

                    haveStudent = 1;

                    break;
                }
            }
            
            if (haveStudent != 1)
            {
                printf("KHONG TIM THAY SINH VIEN\n");
            }

            printf("- Nhan phim '1' => De tiep tuc cap nhat Thong tin sinh vien\n");

        );
    ); 
}

/*
 * Function: Method eraseStudent
 * Description: Xóa Sinh viên theo ID
 */
void Menu::eraseStudent()
{

    uint8_t id;
    uint8_t key;
    bool haveStudent = false;
    vector<Student> *ptr = &listStudent;

    CHECK_LISTSTUDENT
    (
        "KHONG THE XOA SINH VIEN !\n",
        DOWHILE_METHODMENU
        (
            printf("/* XOA SINH VIEN */\n");

            ENTER_INFORMATION("Nhap ID sinh vien: ", "%d", &id, 0);

            for (int index = 0; index < ptr->size(); index++)
            {
                if ((ptr->at(index)).getIDStudent() == id)
                {
                    ptr->erase(ptr->begin() + index);
                    haveStudent = 1;
                    printf("*Da xoa sinh vien*\n");

                    break;
                }
            }

            if (haveStudent != 1)
            {
                printf("KHONG TIM THAY SINH VIEN\n");
            }

            printf("- Nhan phim '1' => De tiep tuc Xoa sinh vien\n");
        );
    ); 
}

/*
 * Function: Method searchStudent
 * Description: Tìm kiếm thông tin Svien theo tên
 */
void Menu::searchStudent()
{

    char name[20];
    uint8_t key;
    bool haveStudent = false;
    vector<Student> *ptr = &listStudent;

    CHECK_LISTSTUDENT
    (
        "KHONG THE TIM KIEM SINH VIEN !\n",
        DOWHILE_METHODMENU
        (
            printf("/* TIM KIEM SINH VIEN */\n");

            ENTER_INFORMATION("Nhap ten sinh vien: ", "%s", &name, 0);

            for (int index = 0; index < ptr->size(); index++)
            {
                if (strcmp(ptr->at(index).getNameStudent(), name) == 0)
                {
                    printf("  ID\t| Ten\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
                    PRINT_INFORMATION(ptr->at(index));
                    haveStudent = 1;

                    break;
                }
            }

            if (haveStudent != 1)
            {
                printf("KHONG TIM THAY SINH VIEN\n");
            }

            printf("- Nhan phim '1' => De tiep tuc Tim kiem sinh vien\n");
        );
    ); 

}

/*
 * Function: swap
 * Description: Đổi chỗ 2 sinh viên dùng cho thuật toán sắp xếp
 * Input:
 *   student1 - Con trỏ kiểu Student
 *   student2 - Con trỏ kiểu Student
 */
void swap(Student *student1, Student *student2)
{
    Student student = *student1;
    *student1 = *student2;
    *student2 = student;
}

/*
 * Function: Method softOfByGPA
 * Description: Sắp xếp sinh viên theo điểm TB
 */
void Menu::softOfByGPA()
{
    uint8_t key;

    CHECK_LISTSTUDENT
    (
        "KHONG THE SAP XEP SINH VIEN THEO GPA !\n",
        DOWHILE_METHODMENU
        (
            for (int indexA = 0; indexA < listStudent.size() - 1; indexA++)
            {
                Student *student1 = &listStudent.at(indexA);
                for (int indexB = 1; indexB < listStudent.size(); indexB++)
                {
                    Student *student2 = &listStudent.at(indexB);
                    if (student1->getScoreAvarge() > student2->getScoreAvarge())
                    {
                        swap(student1, student2);
                    }
                }
            }

            printf("*Da sap xep Danh sach Sinh Vien theo GPA*\n");
        );
    ); 
}

/*
 * Function: Method softOfByName
 * Description: Sắp xếp sinh viên theo tên Sinh viên
 */
void Menu::softOfByName()
{
    uint8_t key;

    CHECK_LISTSTUDENT
    (
        "KHONG THE SAP XEP SINH VIEN THEO TEN !\n",
        DOWHILE_METHODMENU
        (
            for (int indexA = 0; indexA < listStudent.size() - 1; indexA++)
            {
                Student *student1 = &listStudent.at(indexA);
                for (int indexB = 1; indexB < listStudent.size(); indexB++)
                {
                    Student *student2 = &listStudent.at(indexB);
                    if (student1->getNameStudent()[0] > student2->getNameStudent()[0])
                    {
                        swap(student1, student2);
                    }
                }
            }

            printf("*Da sap xep Danh sach Sinh Vien theo Ten*\n");
        );
    ); 
}

/*
 * Function: runProgram
 * Description: Chương trình quản lý sinh viên
 */
void runProgram()
{

    uint8_t key;
    Menu menu;

    do
    {
        printf("------CHUONG TRINH QUAN LY SINH VIEN------\n");
        printf("1. Them Sinh Vien\n");
        printf("2. Cap nhat Thong Tin Sinh Vien\n");
        printf("3. Xoa Sinh Vien boi ID\n");
        printf("4. Tim kiem Thong Tin theo Ten \n");
        printf("5. Sap Xep Sinh Vien theo GPA\n");
        printf("6. Sap Xep Sinh Vien theo Ten\n");
        printf("7. Hien thi Danh Sach Sinh Vien\n");
        printf("8. Thoat\n");
        printf("-------------------------------------------\n");
        ENTER_INFORMATION("- Nhan phim de tiep tuc chuong trinh: ", "%d", &key, key > 8 || key < 1);

        switch (key)
        {
        case 1:
            menu.addStudent();
            break;
        case 2:
            menu.updateStudent();
            break;
        case 3:
            menu.eraseStudent();
            break;
        case 4:
            menu.searchStudent();
            break;
        case 5:
            menu.softOfByGPA();
            break;
        case 6:
            menu.softOfByName();
            break;
        case 7:
            menu.displayStudent();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
        }
    } while (1);
}

/*------------------------------------------MAIN--------------------------------------------*/

int main(int argc, char const *argv[])
{
    runProgram();
    return 0;
}
