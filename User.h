#pragma once
#include <vector>
#include <string>

class User 
{
private:
    std::string name;
    std::string surname;
    std::vector<std::string>List_of_user_books;
public:
    User(std::string, std::string);
    std::string get_name();
    std::string get_surname();
    std::vector<std::string>get_List_of_user_books();
    int get_size_of_List_of_user_books();
    void user_add_book(std::string help);
    void user_remove_book(std::string help);
};