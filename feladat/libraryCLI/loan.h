#ifndef LOAN_H
#define LOAN_H
#include "date.h"

namespace domain {
    class Loan
    {

    public:
        Loan(int bookId, int patronId, const std::string& due);
        Loan(const Loan& other);                 // copy ctor
        Loan& operator=(const Loan& other);     // copy assignment
        int getBookId() const;
        int getPatronId() const;
        const utils::Date& getDueDate() const;
    private:
        int bookId, patronId;
        std::string  dueDate;
    };
}

#endif // LOAN_H
