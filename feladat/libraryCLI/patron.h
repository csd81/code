#ifndef PATRON_H
#define PATRON_H
#include <string>
#include <vector>
#include "loan.h"

namespace domain {

    class Patron
    {
    public:
        Patron(int i, std::string& n);
        virtual ~Patron() = default;
        int getID() const;
        const std::string getName() const;
        virtual void notify(const Loan& loan) = 0;
    private:
        int id;
        std::string name;
        std::vector<const Loan*> loans;
        enum PatronType { STUDENT, PROFESSOR };
    };

}

#endif // PATRON_H
