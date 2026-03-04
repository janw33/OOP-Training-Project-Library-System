    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include "User.h"

    using namespace std;

    User::User(string n, string s, string i)
    {
        name = n;
        surname = s;
        ID = i;
    }
    string User::get_name() const
    {
        return name;
    }
    string User::get_surname() const
    {
        return surname;
    }
    string User::get_ID() const
    {
        return ID;
    }
    const vector<string>& User::get_user_books() const
    {
        return user_ID_books;
    }
    void User::add_ID_book(string help)
    {
        user_ID_books.push_back(help);
    }
    void User::remove_ID_book(string help)
    {
        user_ID_books.erase(remove(user_ID_books.begin(), user_ID_books.end(), help), user_ID_books.end());
    }
