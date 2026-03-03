    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include "User.h"

    using namespace std;

    User::User(string n, string s)
    {
        name = n;
        surname = s;
    }
    string User::get_name()
    {
        return name;
    }
    string User::get_surname()
    {
        return surname;
    }
    vector<string>User::get_List_of_user_books()
    {
        return List_of_user_books;
    }
    int User::get_size_of_List_of_user_books()
    {
        return List_of_user_books.size();
    }
    void User::user_add_book(string help)
    {
        List_of_user_books.push_back(help);
    }
    void User::user_remove_book(string help)
    {
        List_of_user_books.erase(remove(List_of_user_books.begin(), List_of_user_books.end(), help), List_of_user_books.end());
    }
