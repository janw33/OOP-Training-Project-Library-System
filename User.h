#pragma once
#include <vector>
#include <string>

class User 
{
private:
    std::string name;
    std::string surname;
    std::string ID;
    std::vector<std::string>user_books;
public:
    User(std::string n, std::string s, std::string i);
    std::string get_name() const;
    std::string get_surname() const;
    std::string get_ID() const;
    const std::vector<std::string>& get_user_books() const;
    void add_book(std::string help);
    void remove_book(std::string help);
};