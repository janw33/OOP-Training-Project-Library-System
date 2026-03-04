#pragma once
#include <string>

class Book
{
private:
    std::string name;
    std::string ID;
    bool available;

public:
    Book(std::string name, std::string id, bool available);
    std::string get_name() const;
    std::string get_ID() const;
    bool is_available() const;
    void borrow_book();
    void return_book();
};