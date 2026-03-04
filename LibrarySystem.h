#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class LibrarySystem {
private:
    std::vector<Book>library;
    std::vector<User>users;
    bool has_books(); //check is there any books available
public:
    // cosmetical methods
    void Pause(); 
    void clearScreen(); 
    // program functions
    void print_menu();
    void add_book(); // add book to vector library
    void add_user(); 
    void borrow_book();
    void return_book();
    void print_lists();
    // save/load to file methods
    void save_library();
    void load_library();
    void save_users();
    void load_users();
};