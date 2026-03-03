    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include "User.h"

    using namespace std;

    User::User(string n, string s, int i)
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
    int User::get_ID() const
    {
        return ID;
    }
    const vector<string>& User::get_user_books() const
    {
        return user_books;
    }
    void User::add_book(string help)
    {
        user_books.push_back(help);
    }
    void User::remove_book(string help)
    {
        user_books.erase(remove(user_books.begin(), user_books.end(), help), user_books.end());
    }
