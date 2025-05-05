#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "book.h"
// #include "patron.h"

namespace domain{
class Library
{

public:
    Library();
    ~Library();
    void addBook(Book* b);
    void listBooks() const;

//    Book* findBook(int id);
    bool checkout(int bookId);
    bool checkin(int bookId);
private:
    std::vector<Book*> books;
//    std::vector<Patron*> patrons;
};
}

#endif // LIBRARY_H
