#include <iostream>
#include "library.h"

using namespace std;
using namespace domain;

Library::Library() {}

Library::~Library() {
    for (size_t i = 0; i < books.size(); ++i) {
        delete books[i]; // free each
    }
}


void Library::addBook(Book* b){
    books.push_back(b);
}

void Library::listBooks() const {
    for (size_t i = 0; i < books.size(); ++i){
        const Book* b = books[i];
        cout << "ID: " << b->id << "\n"
             << "Title: " << b->title << "\n"
             << "Auth: " << b->author << "\n"
             << "Avail: " << (b->isAvailable ? "Yes" : "NO") << "\n";
    }
}


bool Library::checkout(int bookId) {
    for (size_t i = 0; i < books.size(); ++i){
        if (books[i]->id == bookId && books[i]->isAvailable){
            books[i]->isAvailable = false;
            return true;
        }

    }
    return false;
}


bool Library::checkin(int bookId) {
    for (size_t i = 0; i < books.size(); ++i){
        if (books[i]->id == bookId && !books[i]->isAvailable){
            books[i]->isAvailable = true;
            return true;
        }

    }
    return false;
}
