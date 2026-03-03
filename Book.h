#pragma once
#include <string>

class Book
{
private:
    std::string name;
    bool available;

public:
    Book(const std::string& name, bool available);
    std::string get_name() const;
    bool is_available() const;
    void borrow_book();
    void return_book();
};