#pragma once
#include <string>

class Book
{
private:
    std::string name;
    bool available;
public:
    Book(std::string, bool);
    std::string get_name();
    bool get_is_this_book_available();
    void borrow_book();
    void return_book();
};