#pragma once
#include <vector>
#include <string>

class User 
{
private:
    std::string name;
    std::string surname;
    int ID;
    std::vector<int>user_ID_books;

public:
    User(std::string n, std::string s, int id);

    // getters:
    std::string get_name() const;
    std::string get_surname() const;
    int get_ID() const;
    const std::vector<int> &get_user_books() const;

    void add_book(int help);
    void remove_book(int help);
};