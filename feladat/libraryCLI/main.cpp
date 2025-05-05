#include <iostream>
#include "book.h"
#include "library.h"

using namespace std;
using namespace domain;

int main() {

    Library lib;

    lib.addBook(new  Book(1, "1984", "George Orwell") );
    lib.addBook(new  Book(2, "BNW", "Hux") );
    lib.listBooks();


    cout << "\nChecking out book with ID 1...\n";
    if (lib.checkout(1)) {
        cout << "Checkout successful!\n";
    } else {
        cout << "Checkout failed.\n";
    }

    cout << "\nBooks after checkout:\n";
    lib.listBooks();

    lib.checkin(1);
    lib.checkout(2);

    lib.listBooks();
    return 0;
}
