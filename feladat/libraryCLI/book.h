#ifndef BOOK_H
#define BOOK_H
#include <string>
// #include "date.h"

namespace domain{
    struct Book    {
        int id;
        std::string title;
        std::string author;
//         utils::Date publishDate;
        bool isAvailable;

        Book(int bookId, const std::string& bookTitle, const std::string& bookAuthor)
            : id(bookId), title(bookTitle), author(bookAuthor), isAvailable(true) {}
    };

}
#endif // BOOK_H
