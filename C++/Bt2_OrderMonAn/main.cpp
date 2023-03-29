/*
 * File: main.cpp
 * Author: Linh Pham
 * Date: 27/03/2023
 * Description: Chương trình quản lý order mon an
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

/*--------------------------------------------------------MACRO---------------------------------------------------------------*/
/*
 * Function: MACRO ENTER_INFORMATION
 * Description: Macro phần nhập thông tin món ăn
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
 * Description: Macro phần hiển thị thông tin món ăn 
 * Input:
 *   object - đối tượng cần hiển thị
 *   orderNum - số thứ tự
 */
#define PRINT_INFORMATION(orderNum, object)                                                          \
    printf(" %d\t| %d\t| %s\t\t|  %.2f\t\n",orderNum, object.getIDFood(),                            \
                                    object.getNameFood(), object.getPriceFood());                             
                                
/*
 * Function: MACRO CHECK_LIST
 * Description: Macro kiểm tra danh sách có món ăn chưa
 * Input:
 *   notification - Nội dung thông báo
 *   content - Nội dung Method Menu
 */
#define CHECK_LIST(vector, notification1, notification2, content)               \
    if (vector.empty())                                                         \
    {                                                                           \
        printf(notification1);                                                  \
        printf(notification2);                                                  \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        content                                                                 \
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

/*-------------------------------------------------------CLASS FOOD-----------------------------------------------------------*/

/*
 * Function: Class Món ăn
 * Description: Chứa Property & Method sử dụng cho class Món ăn
 */
class Food
{
protected:
    int idFood;
    char nameFood[20];
    float priceFood = -1;
    
public:
    Food(const char nameFood[], const float priceFood);

    void setNameFood(const char nameFood[]);
    void setPriceFood(const float priceFood);
    
    int getIDFood();
    char* getNameFood();
    float getPriceFood();
};

/*
 * Function: Method setNameFood
 * Description: Đặt tên cho món ăn
 * Input:
 *   nameFood - char*
 */
void Food::setNameFood(const char nameFood[])
{
    strcpy(Food::nameFood, nameFood);
}

/*
 * Function: Method setPriceFood
 * Description: Đặt giá cho món ăn
 * Input:
 *   priceFood - float
 */
void Food::setPriceFood(const float priceFood)
{
    Food::priceFood = priceFood;
}

/*
 * Function: Constructor Food
 * Description: Khởi tạo dữ liệu cho mỗi món ăn
 * Input:
 *   nameFood - char* tên món ăn
 *   priceFood - float giá món ăn
 */
Food::Food(const char nameFood[], const float priceFood)
{
    // Tự động tạo ID cho Món ăn
    static int s_Id = 100;
    Food::idFood = s_Id;
    s_Id++;

    strcpy(Food::nameFood, nameFood);

    Food::priceFood = priceFood;
}

/*
 * Function: Method getIDFood
 * Description: Lấy ID của Món ăn
 * Output:
 *   idFood - int id
 */
int Food::getIDFood()
{
    return Food::idFood;
}

/*
 * Function: Method getPriceFood
 * Description: Lấy giá của Món ăn
 * Output:
 *   priceFood - float
 */
float Food::getPriceFood()
{
    return Food::priceFood;
}

/*
 * Function: Method getNameFood
 * Description: Lấy tên của Món ăn
 * Output:
 *   nameFood - char*
 */
char* Food::getNameFood()
{
    return Food::nameFood;
}
/*-------------------------------------------------------CLASS MANAGER-----------------------------------------------------------*/

/*
 * Function: Class Người Quản lý 
 * Description: Chứa Property & Method tương tác với class Food
 */
class Manager
{
private:
    vector<Food> listFood;
    int quantityTable = 0;

public:

    void setQuantityTable(int quantityTable);
    int getQuantityTable();
    vector<Food> getListFood();

    void addFood();
    void fixFood();
    void earseFood();
    void displayListFood();
};

/*
 * Function: Method setQuantityTable
 * Description: Đặt số lượng bàn
 * Input:
 *   
 */
void Manager::setQuantityTable(int quantityTable)
{
    Manager::quantityTable = quantityTable;
}

/*
 * Function: Method setQuantityTable
 * Description: Lấy số lượng bàn
 * Output:
 *   quantityTable - int
 */
int Manager::getQuantityTable()
{
    return Manager::quantityTable;
}

/*
 * Function: Method getListFood
 * Description: Lấy data danh sách món ăn đã tạo
 * Output:
 *   listFood - vector<Food>
 */
vector<Food> Manager::getListFood(){
    return Manager::listFood;
}

/*
 * Function: Method addFood
 * Description: Thêm món ăn mới 
 */
void Manager::addFood()
{
    char name[20];
    float price;
    int key;

    DOWHILE_METHODMENU
    (
        printf("/* THEM MON AN MOI */\n");

        ENTER_INFORMATION("Nhap ten mon: ", "%s", &name, 0);

        ENTER_INFORMATION("Nhap gia (nghin dong): ", "%f", &price, price < 0);

        Food food(name, price);

        listFood.push_back(food);

        printf("- Nhan phim '1' => De tiep tuc Them mon moi\n");
    );
}

/*
 * Function: Method fixFood
 * Description: Sửa món 
*/
void Manager::fixFood()
{
    int key;
    int id;
    char name[20];
    float price;
    vector<Food> *ptr = &listFood;
    bool haveFood = false;

    CHECK_LIST
    (
        listFood,
        "Danh sach Mon An trong!\n",
        "KHONG THE SUA MON!\n",

        
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
        int orderNum  = 1;
        for (Food food : listFood) 
            {
                PRINT_INFORMATION(orderNum, food);
                orderNum++;
            }

        DOWHILE_METHODMENU
            (
                printf("/* SUA THONG TIN MON AN */\n");

                ENTER_INFORMATION("Nhap ID mon an: ", "%d", &id, 0);

                for (int index = 0; index < ptr->size(); index++)
                {
            
                    if ((ptr->at(index)).getIDFood() == id)
                    {
                        ENTER_INFORMATION("Nhap ten mon: ", "%s", &name, 0);
                        ENTER_INFORMATION("Nhap gia (nghin dong): ", "%f", &price, price < 0);

                        (ptr->at(index)).setNameFood(name);
                        (ptr->at(index)).setPriceFood(price);

                        haveFood = 1;

                        break;
                    }
                }

                if(haveFood != 1)
                {
                    printf("KHONG TIM THAY MON AN CAN SUA\n");
                }
                printf("- Nhan phim '1' => De tiep tuc sua mon an\n");
            );
    );
}

/*
 * Function: Method displayListFood
 * Description: Hiển thị danh sách món ăn
*/
void Manager::displayListFood()
{
    int key;

    CHECK_LIST
    (
        listFood,
        "Danh sach Mon An trong!\n",
        "KHONG THE HIEN THI!\n",

        DOWHILE_METHODMENU
            (
                printf("\n-----------------------DANH SACH MON AN--------------------------\n");
                printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
                int orderNum  = 1;
                for (Food food : listFood) 
                {
                    PRINT_INFORMATION(orderNum, food);
                    orderNum++;
                }

                printf("- Nhan phim '1' => De Hien thi Danh sach Mon an\n");
            );
    );
}

/*
 * Function: Method earseFood
 * Description: Xoa mon an theo ID
*/
void Manager::earseFood()
{
    int key;
    int id;
    vector<Food> *ptr = &listFood;
    bool haveFood = false;

    CHECK_LIST
    (
        listFood,
        "Danh sach Mon An trong!\n",
        "KHONG THE XOA MON AN!\n",
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
        int orderNum  = 1;
        for (Food food : listFood) 
            {
                PRINT_INFORMATION(orderNum, food);
                orderNum++;
            }

        DOWHILE_METHODMENU
            (
                printf("/* XOA SINH MON AN */\n");

                ENTER_INFORMATION("Nhap ID Mon an: ", "%d", &id, 0);

                for (int index = 0; index < ptr->size(); index++)
                {
                    if ((ptr->at(index)).getIDFood() == id)
                    {
                        ptr->erase(ptr->begin() + index);
                        haveFood = 1;
                        printf("*Da xoa mon an*\n");

                        break;
                    }
                }

                if (haveFood != 1)
                {
                    printf("KHONG TIM THAY MON AN\n");
                }

                printf("- Nhan phim '1' => De tiep tuc Xoa mon an\n");
            );
    );
}

/*
 * Function: runManagerProgram
 * Description: Chương trình của quản lý
 */
void runManagerProgram(Manager *mn)
{
    int key;
    int quantity = 0;
    Manager *manager = mn;

    do
    {
        printf("------QUAN LY------\n");
        printf("1. Them mon\n");
        printf("2. Sua mon\n");
        printf("3. Xoa mon\n");
        printf("4. Danh sach mon an\n");
        printf("5. Dat so luong ban\n");
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        ENTER_INFORMATION("- Nhan phim : ", "%d", &key, key > 5 || key < 0);

        switch (key)
        {
        case 1:
            manager->addFood();
            break;
        case 2:
            manager->fixFood();
            break;
        case 3:
            manager->earseFood();
            break;
        case 4:
            manager->displayListFood();
            break;
        case 5:
            printf("Nhap so luong ban: ");
            scanf("%d",&quantity);
            manager->setQuantityTable(quantity);
            break;
        case 0:
            return;
        default:
            break;
        }

    } while (key);
}
/*---------------------------------------------------CLASS ORDERED FOOD--------------------------------------------------------*/

/*
 * Function: Class OrderedFood
 * Description: Quản lý thông tin những món đã được Order
 */
class OrderedFood  
{
protected:
    int quantityFood = 0;
    char nameFood[20];
    float priceFood = -1;
    int idFood;

public:
    
    OrderedFood(const int id, const char nameFood[], const float priceFood, const int quantity);

    void setQuantityFood(const int quantity);

    int getQuantityFood();
    char* getNameFood();
    float getPriceFood();
    int getIDFood();

};

/*
 * Function: Constructor OrderedFood
 * Description: Khởi tạo dữ liệu cho mỗi món ăn đã gọi
 * Input:
 *   id - int 
 *   nameFood - char*
 *   priceFood - float
 *   quantity - int
 */
OrderedFood::OrderedFood(const int id, const char nameFood[], const float priceFood, const int quantity)
{
    OrderedFood::idFood = id;

    strcpy(OrderedFood::nameFood, nameFood);

    OrderedFood::priceFood = priceFood;

    OrderedFood::quantityFood = quantity;
}

/*
 * Function: Method setQuantityFood
 * Description: Set số lượng của mỗi món ăn
 * Input:
 *  quantity - int 
 */
void OrderedFood::setQuantityFood(const int quantity)
{
    OrderedFood::quantityFood = quantity;
}

/*
 * Function: Method getQuantityFood
 * Description: Lấy số lượng của mỗi món ăn
 * Output:
 *  quantity - int 
 */
int OrderedFood::getQuantityFood()
{
    return OrderedFood::quantityFood;
}

/*
 * Function: Method getIDFood
 * Description: Lấy ID của món ăn đã gọi
 * Output:
 *  idFood - int 
 */
int OrderedFood::getIDFood()
{
    return OrderedFood::idFood;
}

/*
 * Function: Method getNameFood
 * Description: Lấy tên của món ăn đã gọi
 * Output:
 *  nameFood - char*
 */
char* OrderedFood::getNameFood()
{
    return OrderedFood::nameFood;
}

/*
 * Function: Method getPriceFood
 * Description: Lấy giá của món ăn đã gọi
 * Output:
 *  priceFood - float
 */
float OrderedFood::getPriceFood()
{
    return OrderedFood::priceFood;
}
/*---------------------------------------------------CLASS DINNER TABLE--------------------------------------------------------*/

/*
 * Function: Class Bàn ăn
 * Description: Chứa Property & Method sử dụng cho class Employee
 */
class DinnerTable
{
private:
    bool stateTable = 0;
    float totalMoney = 0;
    vector<OrderedFood> listOrderedFood;
    vector<Food> copyListFood; 

public:
    DinnerTable(Manager manager);

    void orderFood();
    void displayOrderedFood();
    void getTotalMoney();
    bool getStateTable();
    void updateListFood(Manager manager);
};

/*
 * Function: Constructor Dinner Table
 * Description: Khởi tạo dữ liệu cho bàn ăn, Copy data danh sách món ăn của Quản lý đã tạo để gọi món
 * Input:
 *   manager - Manager
 */
DinnerTable::DinnerTable(Manager manager)
{
    for (auto data : manager.getListFood())
    {
        copyListFood.push_back(data);
    }
}

/*
 * Function: orderFood
 * Description: Gọi món ăn
 */
void DinnerTable::orderFood()
{
    int key;
    int id;
    int quantity;
    vector<Food> *ptr = &copyListFood;
    bool haveFood = false;

    CHECK_LIST
    (
        copyListFood,
        "Danh sach Mon An trong!\n",
        "KHONG THE HIEN THI!\n",
        
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
        printf("STT\t|  ID\t| Ten mon\t| Gia(Nghin dong)\n");
        int orderNum  = 1;
        for (Food food : copyListFood) 
            {
                PRINT_INFORMATION(orderNum, food);
                orderNum++;
            }

        DOWHILE_METHODMENU
            (
                printf("/* GOI MON AN */\n");

                ENTER_INFORMATION("Nhap ID mon an: ", "%d", &id, 0);

                for (int index = 0; index < ptr->size(); index++)
                {
            
                    if ((ptr->at(index)).getIDFood() == id)
                    {
                        
                        ENTER_INFORMATION("Nhap so luong: ", "%d", &quantity, quantity < 0);

                        OrderedFood food((ptr->at(index)).getIDFood(), (ptr->at(index)).getNameFood(), (ptr->at(index)).getPriceFood(), quantity);

                        listOrderedFood.push_back(food);
                        
                        stateTable = 1;
                        haveFood = 1;

                        break;
                    }
                }

                if(haveFood != 1)
                {
                    printf("KHONG TIM THAY MON AN CAN GOI\n");
                }
                printf("- Nhan phim '1' => De tiep tuc goi mon an\n");
            );
    );
}

/*
 * Function: displayOrderedFood
 * Description: Hiển thị món ăn đã gọi
 */
void DinnerTable::displayOrderedFood()
{

    int key;

    CHECK_LIST
    (
        copyListFood,
        "Danh sach Mon An trong!\n",
        "KHONG THE HIEN THI!\n",
        DOWHILE_METHODMENU
            (
                printf("\n-----------------------DANH SACH MON AN--------------------------\n");
                printf("STT\t|  ID\t| Ten mon\t| Soluong\n");
                int orderNum  = 1;
                for (OrderedFood food : listOrderedFood) 
                {
                    printf(" %d\t| %d\t| %s\t\t|  %d\t\n",orderNum, food.getIDFood(), food.getNameFood(), food.getQuantityFood());                                  
                    orderNum++;
                }

                printf("- Nhan phim '1' => De Hien thi Danh sach Mon an da goi\n");
            );
    );
}

/*
 * Function: getTotalMoney
 * Description: Tính tổng tiền món ăn đã gọi
 */
void DinnerTable::getTotalMoney()
{
    int key;

    CHECK_LIST
    (
        listOrderedFood,
        "Danh sach Mon An da goi trong!\n",
        "KHONG THE TINH TIEN!\n",
        printf("\n-----------------------DANH SACH MON AN--------------------------\n");
                printf("STT\t|  ID\t| Ten mon\t| Soluong\n");
                int orderNum  = 1;
                for (OrderedFood food : listOrderedFood) 
                {
                    printf(" %d\t| %d\t| %s\t\t|  %d\t\n",orderNum, food.getIDFood(),food.getNameFood(), food.getQuantityFood());                         
                    orderNum++;
                }
        DOWHILE_METHODMENU
            (
                for (OrderedFood food : listOrderedFood) 
                {
                    DinnerTable::totalMoney += food.getPriceFood() * food.getQuantityFood();
                }

                printf("=> Tong tien: %.2f (nghin dong)\n",DinnerTable::totalMoney);
                listOrderedFood.clear();
                stateTable = 0;
            );
    );
}

/*
 * Function: Method getStateTable
 * Description: Lấy trạng thái của mỗi bàn, xem bàn đó đã có người ăn chưa 
 * Output:
 *   stateTable - bool 
 */
bool DinnerTable::getStateTable()
{
    return DinnerTable::stateTable;
}

/*
 * Function: Method updateListFood
 * Description: LCập nhật danh sách món ăn khi người Quản Lý thay đổi  
 */
void DinnerTable::updateListFood(Manager manager)
{
    copyListFood.clear();
    for (auto data : manager.getListFood())
    {
        copyListFood.push_back(data);
    }
}
/*-----------------------------------------------------CLASS EMPLOYEE--------------------------------------------------------*/

/*
 * Function: Class Nhân viên
 * Description: Chứa Property & Method sử dụng cho chương trình của nhân viên
 */
class Employee
{
private:
    vector<DinnerTable> listTable;
    int quantityTable = 0;

public:
    void displayStateTable();
    void selectTable(int numTable);

    int getQuantityTable();
    void getDataFromManager(Manager *manager);
    void updateDataFromManager(Manager *manager);
};

/*
 * Function: Method getDataFromManager
 * Description: Lấy data danh sách món ăn và số bàn mà Quản lý đã setup
 * Input:
 *  manager: Manager*
 */
void Employee::getDataFromManager(Manager *manager)
{
    Employee::quantityTable = manager->getQuantityTable();
    for(int i = 0; i < Employee::quantityTable; i++)
    {
        DinnerTable dinnerTable(*manager);
        listTable.push_back(dinnerTable);
    }
}

/*
 * Function: Method updateDataFromManager
 * Description: Cập nhât data danh sách món ăn và số bàn mà Quản lý đã setup
 * Input:
 *  manager: Manager*
 */
void Employee::updateDataFromManager(Manager *manager)
{
    int lastQuantityTable = Employee::quantityTable;
    Employee::quantityTable = manager->getQuantityTable();
    for(int i = 0; i < lastQuantityTable; i++)
    {
        DinnerTable dinnerTable(*manager);
        listTable.at(i).updateListFood(*manager);
    }
    for(int i = lastQuantityTable; i < Employee::quantityTable; i++)
    {
        DinnerTable dinnerTable(*manager);
        listTable.push_back(dinnerTable);
    }
}

/*
 * Function: Method getQuantityTable
 * Description: Lấy số bàn Quản lý đã setup
 * Output:
 *  quantityTable - int 
 */
int Employee::getQuantityTable()
{
    return Employee::quantityTable;
}

/*
 * Function: Method displayStateTable
 * Description: Hiển thị trạng thái bàn 
 */
void Employee::displayStateTable()
{
    CHECK_LIST(
        listTable,
        "Ban an chua duoc Quan Ly setup!\n",
        "KHONG THE HIEN THI DANH SACH BAN AN!\n",
    
        printf("-------Trang thai ban------\n");
        printf("Ban:     |");
        for(int i = 1; i <= Employee::quantityTable; i++)
        {
            printf(" %d |",i);
        }
        printf("\nT.Thai:  |");
        for(int i = 0; i < Employee::quantityTable; i++)
        {
            if(listTable.at(i).getStateTable() == 1){
                printf(" x |");
            }
            else
            {
                printf("   |");
            }
        }
    );
}

/*
 * Function: Method selectTable
 * Description: Lựa chọn bàn ăn
 * Input:
 *  numTable - int
 */
void Employee::selectTable(int numTable)
{
    int key;

    CHECK_LIST(
        listTable,
        "Ban an chua duoc Quan Ly setup!\n",
        "KHONG THE CHON BAN AN!\n",
        printf("------BAN %d------\n",numTable + 1);
        printf("1. Goi mon\n");
        printf("2. Danh sach mon da goi\n");
        printf("3. Tinh tien\n");
        printf("0. Thoat\n");
        ENTER_INFORMATION("- Nhan phim : ", "%d", &key, key > 3 || key < 0);

        switch (key)
        {
        case 1:
            listTable.at(numTable).orderFood();
            break;
        case 2:
            listTable.at(numTable).displayOrderedFood();
            break;
        case 3:
            listTable.at(numTable).getTotalMoney();
            break;
        case 0:
            return;
        default:
            break;
        }
    );
}

/*
 * Function: runEmployeeProgram
 * Description: Chương trình dành cho Nhân Viên
 * Input:
 *  employee - Employee*
 */
void runEmployeeProgram(Employee *employee)
{

    int key;

    do
    {
        printf("------NHAN VIEN------\n");
        employee->displayStateTable();
        printf("\n0. Thoat\n");
        printf("-------------------------------------------\n");
        ENTER_INFORMATION("- Chon ban : ", "%d", &key, key > employee->getQuantityTable() || key < 0);

        switch (key)
        {
        case 0:
            return;
        default:
            employee->selectTable(key-1);
            break;
        }
    } while (1);
}

/*
 * Function: runMainProgram
 * Description: Chương trình Order mon an
 */
void runMainProgram()
{

    int key;
    Manager manager;
    Employee employee;

    do
    {
        printf("------CHUONG TRINH QUAN LY ORDER MON AN------\n");
        printf("1. Quan ly\n");
        printf("2. Nhan Vien\n");
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        ENTER_INFORMATION("- Nhan phim : ", "%d", &key, key > 2 || key < 0);

        switch (key)
        {
        case 1:
            runManagerProgram(&manager);
            employee.getDataFromManager(&manager); 
            break;
        case 2:
            employee.updateDataFromManager(&manager);
            runEmployeeProgram(&employee);
            break;
        case 0:
            exit(0);
        default:
            break;
        }

    } while (1);
}

/*-----------------------------------------------------MAIN--------------------------------------------------------*/

int main(int argc, char const *argv[])
{
    runMainProgram();

    return 0;
}
