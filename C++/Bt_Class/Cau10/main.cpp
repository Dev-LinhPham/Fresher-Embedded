/*
* File: main.cpp
* Author: Linh Pham
* Date: 18/04/2023
* Description: Tạo một lớp sách với các thuộc tính tên sách, tác giả, năm xuất bản
                và số lượng, và các phương thức để in thông tin sách, mượn sách và
                trả sách
*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vector>

using namespace std;

/*
 * Function: Class Book
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng Sách
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
class Book
{
private:
    char nameBook[50];
    char authorBook[50];
    uint16_t yearPublish;
    uint16_t quantityBook;

public:
    Book(const char nameBook[], const char authorBook[], const uint16_t yearPublish, const uint16_t quantityBook);

    void setQuantityBook(uint16_t quantityBook);
    char *getNameBook();
    char *getAuthorBook();
    uint16_t getYearPublish();
    uint16_t getQuantityBook();

    void getInforBook();
};

/*
 * Function: Constructor Book
 * Description: Nhập thông tin quyển sách
 * Input:
 *   nameBook - const char
 *   authorBook - const char
 *   yearPublish - const uint16_t
 *   quantityBook - const uint16_t
 * Output:
 *   Return - None
 */
Book::Book(const char nameBook[], const char authorBook[], const uint16_t yearPublish, const uint16_t quantityBook)
{
    strcpy(Book::nameBook, nameBook);
    strcpy(Book::authorBook, authorBook);
    Book::yearPublish = yearPublish;
    Book::quantityBook = quantityBook;
}

/*
 * Function: getNameBook
 * Description: Lấy tên của quyển sách
 * Input:
 *   No input
 * Output:
 *   Return - nameBook
 */
char *Book::getNameBook()
{
    return nameBook;
}

/*
 * Function: getAuthorBook
 * Description: Lấy tên tác giả của quyển sách
 * Input:
 *   No input
 * Output:
 *   Return - authorBook
 */
char *Book::getAuthorBook()
{
    return authorBook;
}

/*
 * Function: getYearPublish
 * Description: Lấy năm xuất bản của quyển sách
 * Input:
 *   No input
 * Output:
 *   Return - yearPublish
 */
uint16_t Book::getYearPublish()
{
    return yearPublish;
}

/*
 * Function: getQuantityBook
 * Description: Lấy số lượng của quyển sách
 * Input:
 *   No input
 * Output:
 *   Return - quantityBook
 */
uint16_t Book::getQuantityBook()
{
    return quantityBook;
}

/*
 * Function: getInforBook
 * Description: Lấy thông tin quyển sách
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
void Book::getInforBook()
{
    printf("Ten sach: %s\n", nameBook);
    printf("Tac gia: %s\n", authorBook);
    printf("Nam XB: %d\n", yearPublish);
    printf("So luong: %d\n", quantityBook);
}

/*
 * Function: setQuantityBook
 * Description: Đặt số lượng quyển sách
 * Input:
 *   quantityBook - uint16_t
 * Output:
 *   Return - None
 */
void Book::setQuantityBook(uint16_t quantityBook)
{
    Book::quantityBook = quantityBook;
}

/*
 * Function: Class Library
 * Description: Class biễu diễn dữ liệu và phương thức của đối tượng thư viện
 * Input:
 *   No input
 * Output:
 *   Return - None
 */
class Library
{
private:
    static vector<Book> listOfBook;

public:
    void addBook(Book book);
    void borrowBook(const char nameBook[], const uint16_t quantityBook);
    void backBook(const char nameBook[], const uint16_t quantityBook);
};

vector<Book> Library::listOfBook;

/*
 * Function: addBook
 * Description: Thêm sách vào thư viện
 * Input:
 *   book - Book
 * Output:
 *   Return - None
 */
void Library::addBook(Book book)
{
    listOfBook.push_back(book);
}

/*
 * Function: borrowBook
 * Description: Mượn sách của thư viện
 * Input:
 *   nameBook - const char
 *   quantityBook - const uint16_t
 * Output:
 *   Return - None
 */
void Library::borrowBook(const char nameBook[], const uint16_t quantityBook)
{
    if (listOfBook.empty())
    {
        printf("Danh sach sach trong!\n");
    }
    else
    {
        for (Book &book : listOfBook)
        {
            if (strcmp(book.getNameBook(), nameBook) == 0)
            {
                if (quantityBook < book.getQuantityBook())
                {
                    printf("Muon sach thanh cong\n");
                    book.setQuantityBook(book.getQuantityBook() - quantityBook);
                    break;
                }
                else
                {
                    printf("Khong du so luong\n");
                    break;
                }
            }
        }
    }
}

/*
 * Function: backBook
 * Description: Trả sách cho thư viện
 * Input:
 *   nameBook - const char
 *   quantityBook - const uint16_t
 * Output:
 *   Return - None
 */
void Library::backBook(const char nameBook[], const uint16_t quantityBook)
{
    if (listOfBook.empty())
    {
        printf("Danh sach sach trong!\n");
    }
    else
    {
        for (Book &book : listOfBook)
        {
            if (strcmp(book.getNameBook(), nameBook) == 0)
            {
                printf("Tra sach thanh cong\n");
                book.setQuantityBook(book.getQuantityBook() + quantityBook);
                break;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Book book1("Machine Learning", "Huu Tiep", 2019, 150);
    Book book2("Giai Thuat", "Minh Hoang", 2001, 223);
    Book book3("Pho Wall", "Peter Lynch", 2016, 50);
    Book book4("Huyen Thoai", "Roland Barthes", 2008, 35);

    Library lb1;

    lb1.addBook(book1);
    lb1.addBook(book2);
    lb1.addBook(book3);
    lb1.addBook(book4);

    lb1.borrowBook("Machine Learning", 20);
    lb1.borrowBook("Pho Wall", 500);
    lb1.borrowBook("Giai Thuat", 75);

    lb1.backBook("Machine Learning", 5);
    return 0;
}
