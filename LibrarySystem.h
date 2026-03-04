#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class LibrarySystem {
private:
    std::vector<Book>library;
    std::vector<User>users;
    bool has_books(); //check is there any books available
    //safety methods
    bool check_user_choice(int x, int &help); 
    bool check_book_choice(int x, int &help);
    //print
    void show_users();
    void show_avilable_books();
    void show_user_books(int user_choice);
public:
    // cosmetical methods:
    void Pause(); 
    void clearScreen(); 

    // program functions:
    void print_menu();
    void add_book(); // add book to vector library
    void add_user(); 
    void borrow_book();
    void return_book();
    void print_lists();

    // save/load to file methods:
    void save_library();
    void load_library();
    void save_users();
    void load_users();
};