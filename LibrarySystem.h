#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class LibrarySystem {
private:
    std::vector<Book>library;
    std::vector<User>users;
    bool has_books(); 
public:
    void print_menu();
    void add_book();
    void add_user();
    void borrow_book();
    void return_book();
    void print_lists();
    void save_library();
    void load_library();
    void save_users();
    void load_users();
};