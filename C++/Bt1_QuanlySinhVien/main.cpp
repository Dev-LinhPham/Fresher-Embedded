#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


/*--------------------------------------MACRO NHAP THONG TIN----------------------------------*/
#define ENTER_INFORMATION(content, format, variable, condition) \
    do                                                          \
    {                                                           \
        printf(content);                                        \
        scanf(format, variable);                                \
    } while (condition)

/*------------------------------------MACRO HIEN THI THONG TIN-------------------------------*/
#define PRINT_INFORMATION(object)                                                          \
    printf(" %d\t| %s\t| %d\t|   %s\t\t|", object.getIDStudent(), object.getNameStudent(), \
           object.getAgeStudent(), object.getGenderStudent());                             \
    printf(" %.2f\t| %.2f\t| %.2f\t|", object.getScoreMath(), object.getScorePhysic(),     \
           object.getScoreChemistry());                                                    \
    printf("   %.2f\t|   %s\n", object.getScoreAvarge(), object.getRankStudent())

/*---------------------------------------CLASS SINH VIEN-------------------------------------*/
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

/*---------------------------------------ĐĂT TÊN SINH VIÊN-----------------------------------*/
void Student::setNameStudent(const char nameStudent[])
{
    strcpy(Student::nameStudent, nameStudent);
}

/*-------------------------------------ĐĂT GIỚI TÍNH SINH VIÊN-------------------------------*/
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

/*-------------------------------------ĐĂT TUỔI SINH VIÊN------------------------------------*/
void Student::setAgeStudent(uint8_t ageStudent)
{
    Student::ageStudent = ageStudent;
}

/*-------------------------------------ĐĂT ĐIỂM HÓA SINH VIÊN--------------------------------*/
void Student::setScoreChemistry(float scoreChemistry)
{
    Student::scoreChemistry = scoreChemistry;
}

/*-------------------------------------ĐĂT ĐIỂM TOÁN SINH VIÊN-------------------------------*/
void Student::setScoreMath(float scoreMath)
{
    Student::scoreMath = scoreMath;
}

/*-------------------------------------ĐĂT ĐIỂM LÝ SINH VIÊN---------------------------------*/
void Student::setScorePhysic(float scorePhysic)
{
    if (scorePhysic > 10 || scorePhysic < 0)
    {
        printf("ERROR! Diem Ly khong hop le");
        Student::scorePhysic = 0;
    }
    else
    {
        Student::scorePhysic = scorePhysic;
    }
}

/*------------------------------------CONSTRUCTOR SINH VIÊN----------------------------------*/
Student::Student(const char nameStudent[], const char genderStudent[], const uint8_t ageStudent,
                 const float scoreMath, const float scorePhysic, const float scoreChemistry)
{
    //Tự động tạo ID cho Sinh viên
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

/*-------------------------------------LẤY ID SINH VIÊN-------------------------------------*/
uint8_t Student::getIDStudent()
{
    return Student::idStudent;
}

/*-------------------------------------LẤY TÊN SINH VIÊN-----------------------------------*/
char *Student::getNameStudent()
{
    return Student::nameStudent;
}

/*----------------------------------LẤY GIỚI TÍNH SINH VIÊN-------------------------------*/
char *Student::getGenderStudent()
{
    return Student::genderStudent;
}

/*-------------------------------------LẤY TUỔI SINH VIÊN----------------------------------*/
uint8_t Student::getAgeStudent()
{

    return Student::ageStudent;
}

/*----------------------------------LẤY ĐIỂM HÓA SINH VIÊN--------------------------------*/
float Student::getScoreChemistry()
{
    return Student::scoreChemistry;
}

/*----------------------------------LẤY ĐIỂM LÝ SINH VIÊN--------------------------------*/
float Student::getScorePhysic()
{
    return Student::scorePhysic;
}

/*----------------------------------LẤY ĐIỂM TOÁN SINH VIÊN------------------------------*/
float Student::getScoreMath()
{
    return Student::scoreMath;
}

/*-----------------------------LẤY ĐIỂM TRUNG BÌNH SINH VIÊN-----------------------------*/
float Student::getScoreAvarge()
{
    Student::scoreAvarge = (Student::scoreMath + Student::scorePhysic + Student::scoreChemistry) / 3;
    return Student::scoreAvarge;
}

/*-----------------------------------LẤY HỌC LỰC SINH VIÊN-------------------------------*/
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

/*---------------------------------------CLASS MENU-------------------------------------*/
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

/*-------------------------------------THÊM SINH VIÊN-----------------------------------*/
void Menu::addStudent()
{
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
    uint8_t key;

    do
    {
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
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");
        scanf("%d", &key);

    } while (key == 1);
}

/*-----------------------------HIỂN THỊ DANH SÁCH SINH VIÊN-----------------------------*/
void Menu::displayStudent()
{
    uint8_t key;

    do
    {

        printf("\n------------------------------------DANH SACH SINH VIEN-----------------------------------\n");
        printf("  ID\t| Ten\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
        for (Student student : listStudent)
        {
            PRINT_INFORMATION(student);
        }

        printf("- Nhan phim '1' => De Hien thi Danh sach\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");

    } while (key == 1);
}

/*-----------------------------CẬP NHẬT THÔNG TIN SINH VIÊN----------------------------*/
void Menu::updateStudent()
{
    char name[20];
    char gender[4];
    uint8_t age;
    float math;
    float physic;
    float chemistry;
    uint8_t id;
    uint8_t key;
    vector<Student> *ptr = &listStudent;

    do
    {
        printf("/* CAP NHAT THONG TIN SINH VIEN */\n");

        ENTER_INFORMATION("Nhap ID sinh vien: ", "%d", &id, 0);

        for (int index = 0; index < ptr->size(); index++)
        {
            if ((ptr->at(index)).getIDStudent() == id)
            {
                ENTER_INFORMATION("Nhap ten: ", "%s", &name, 0);

                ENTER_INFORMATION("Nhap tuoi: ", "%d", &age, age > 100 || age < 1);

                ENTER_INFORMATION("Nhap gioi tinh: ", "%s", &gender, 0);

                ENTER_INFORMATION("Nhap diem toan: ", "%f", &math, math > 10 || math < 0);

                ENTER_INFORMATION("Nhap diem ly: ", "%f", &physic, physic > 10 || physic < 0);

                ENTER_INFORMATION("Nhap diem hoa: ", "%f", &chemistry, chemistry > 10 || chemistry < 0);

                (ptr->at(index)).setNameStudent(name);
                (ptr->at(index)).setAgeStudent(age);
                (ptr->at(index)).setGenderStudent(gender);
                (ptr->at(index)).setScoreMath(math);
                (ptr->at(index)).setScorePhysic(physic);
                (ptr->at(index)).setScoreChemistry(chemistry);

                break;
            }
        }

        printf("- Nhan phim '1' => De tiep tuc cap nhat Thong tin sinh vien\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");
        scanf("%d", &key);

    } while (key == 1);
}

/*-----------------------------------XÓA SINH VIÊN-------------------------------------*/
void Menu::eraseStudent()
{

    uint8_t id;
    uint8_t key;
    vector<Student> *ptr = &listStudent;

    do
    {
        printf("/* XOA SINH VIEN */\n");

        ENTER_INFORMATION("Nhap ID sinh vien: ", "%d", &id, 0);

        for (int index = 0; index < ptr->size(); index++)
        {
            if ((ptr->at(index)).getIDStudent() == id)
            {
                ptr->erase(ptr->begin() + index);

                break;
            }
        }

        printf("- Nhan phim '1' => De tiep tuc Xoa sinh vien\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");
        scanf("%d", &key);

    } while (key == 1);
}

/*----------------------------------TÌM KIẾM SINH VIÊN----------------------------------*/
void Menu::searchStudent()
{

    char name[20];
    uint8_t key;
    vector<Student> *ptr = &listStudent;

    do
    {
        printf("/* TIM KIEM SINH VIEN */\n");

        ENTER_INFORMATION("Nhap tem sinh vien: ", "%s", &name, 0);

        for (int index = 0; index < ptr->size(); index++)
        {
            if (strcmp(ptr->at(index).getNameStudent(), name) == 0)
            {
                printf("  ID\t| Ten\t| Tuoi\t|  Gioi Tinh\t|  Toan\t|  Ly\t|  Hoa\t|   DiemTB\t|  HocLuc\n");
                PRINT_INFORMATION(ptr->at(index));
                break;
            }
        }

        printf("- Nhan phim '1' => De tiep tuc Tim kiem sinh vien\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");
        scanf("%d", &key);

    } while (key == 1);
}

/*--------------------------------HÀM ĐỔI CHỖ SINH VIÊN---------------------------------*/
void swap(Student *student1, Student *student2)
{
    Student student = *student1;
    *student1 = *student2;
    *student2 = student;
}

/*-------------------------------SẮP XẾP SINH VIÊN THEO GPA----------------------------*/
void Menu::softOfByGPA()
{
    uint8_t key;

    do
    {
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

        printf("Da sap xep Danh sach Sinh Vien theo GPA\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");

    } while (key == 1);
}

/*---------------------------------SẮP XẾP SINH VIÊN THEO TÊN-----------------------------*/
void Menu::softOfByName()
{
    uint8_t key;

    do
    {
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

        printf("Da sap xep Danh sach Sinh Vien theo Ten\n");
        printf("- Nhan phim Bat ky => De Thoat chuc nang\n");

    } while (key == 1);
}

/*-------------------------------------CHẠY CHƯƠNG TRÌNH----------------------------------*/
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
