#pragma once
#include <string>

class Book
{
private:
    std::string name;
    int ID;
    bool available;

public:
    Book(std::string name, int id, bool available);

    std::string get_name() const;
    int get_ID() const;
    bool is_available() const;

    void borrow_book();
    void return_book();
};