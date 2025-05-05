#ifndef STUDENT_H
#define STUDENT_H

#include "patron.h"

class Student : public Patron
{
public:
    using Patron::Patron;
    void notify(const Loan& loan) override {
        std::cout << "email: book: "  << loan.getBookId() <<
            " is due " << loan.getDueDate().toString() << "\n";
    }
};

#endif // STUDENT_H
