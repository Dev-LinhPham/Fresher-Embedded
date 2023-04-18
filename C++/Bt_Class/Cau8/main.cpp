/*
* File: main.cpp
* Author: Linh Pham
* Date: 18/04/2023
* Description: Tạo một lớp tài khoản ngân hàng với các thuộc tính số tài khoản, tên tài
                khoản và số dư, và các phương thức để rút, nộp tiền và kiểm tra số dư
                trong tài khoản
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 * Function: Class BankAccount
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng tài khoản ngân hàng
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
class BankAccount
{
private:
    uint8_t idAccount;
    char nameAccount[20];
    uint32_t moneyAccount;

public:
    BankAccount(const char nameAccount[], const uint8_t idAccount, const uint32_t moneyAccount);

    char *getNameAccount();
    uint8_t getIDAccount();
    uint32_t getMoneyAccount();

    void takeMoney();
    void checkMoney();
    void addMoney();
};

/*
 * Function: Constructor BankAccount
 * Description: Nhập thông tin tài khoản ngân hàng
 * Input:
 *   nameAccount - const char
 *   idAccount - const uint8_t
 *   moneyAccount - const uint32_t
 * Output:
 *   Return - None
 */
BankAccount::BankAccount(const char nameAccount[], const uint8_t idAccount, const uint32_t moneyAccount)
{
    strcpy(BankAccount::nameAccount, nameAccount);

    BankAccount::idAccount = idAccount;

    BankAccount::moneyAccount = moneyAccount;
}

/*
 * Function: getNameAccount
 * Description: Lấy tên tài khoản
 * Input:
 *   No input
 * Output:
 *   Return - nameAccount
 */
char *BankAccount::getNameAccount()
{
    return BankAccount::nameAccount;
}

/*
 * Function: getIDAccount
 * Description: Lấy ID tài khoản ngân hàng
 * Input:
 *   No input
 * Output:
 *   Return - idAccount
 */
uint8_t BankAccount::getIDAccount()
{
    return BankAccount::idAccount;
}

/*
 * Function: getMoneyAccount
 * Description: Lấy số dư tài khoản
 * Input:
 *   No input
 * Output:
 *   Return - moneyAccount
 */
uint32_t BankAccount::getMoneyAccount()
{
    return BankAccount::moneyAccount;
}

/*
 * Function: addMoney
 * Description: Nạp tiền vào tài khoản ngân hàng
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
void BankAccount::addMoney()
{
    uint32_t money;
    printf("Nhap so tien can nap: ");
    scanf("%d", &money);
    printf("So du: %d dong\n", moneyAccount += money);
}

/*
 * Function: takeMoney
 * Description: Rút tiền từ tài khoản ngân hàng
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
void BankAccount::takeMoney()
{
    uint32_t money;
    do
    {
        printf("Nhap so tien can rut: ");
        scanf("%d", &money);
    }while(money > moneyAccount);
    printf("So du: %d dong\n", moneyAccount -= money);
}

/*
 * Function: checkMoney
 * Description: Kiểm tra số dư tài khoản ngân hàng
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
void BankAccount::checkMoney()
{
    printf("So du: %d dong\n", moneyAccount);
}

int main(int argc, char const *argv[])
{
    BankAccount account("Quang Linh", 123, 1000000);

    account.checkMoney();

    account.takeMoney();

    account.addMoney();
    return 0;
}
