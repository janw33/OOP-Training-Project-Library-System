#pragma once
#include <vector>
#include "Book.h"
#include "User.h"

class LibrarySystem {
private:
    //data:
    std::vector<Book>library;
    std::vector<User>users;

    //safety methods private
    bool check_user_choice(int x, int &help); 
    bool borrow_check_book_choice(int x, int &help);
    bool return_check_book_choice(int x, int& help);
    bool has_available_books();
    bool has_unavailable_books();
    bool has_user_id(int id);
    bool has_book_id(int id);

    //print:
    void print_menu_lists();
    void show_users();
    void show_all_books();
    void show_avilable_books();
    void show_unavailable_books();
    void show_user_books(int user_choice); // for now showing only book ID!

public:
    // input:
    int get_int_input();

    // cosmetical methods:
    void Pause(); 
    void clearScreen(); 

    // program functions:
    void print_menu();
    void add_book();
    void delete_book();
    void add_user(); 
    void delete_user();
    void borrow_book();
    void return_book();
    void print_lists();

    // save/load to file methods:
    void save_library();
    void load_library();
    void save_users();
    void load_users();
};