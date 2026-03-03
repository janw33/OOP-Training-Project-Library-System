#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class LibrarySystem {
private:
    std::vector<Book>library;
    std::vector<User>users;
    bool is_there_any_book(); 
public:
    void print_menu();
    void add_book();
    void add_user();
    void borrow_book();
    void return_the_book();
    void list_of_books();
    
};