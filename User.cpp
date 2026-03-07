    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include "User.h"

    using namespace std;

    User::User(string n, string s, int id)
    {
        name = n;
        surname = s;
        ID = id;
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
    const vector<int>& User::get_user_books() const
    {
        return user_ID_books;
    }
    void User::add_book(int help)
    {
        user_ID_books.emplace_back(help);
    }
    void User::remove_book(int help)
    {
        user_ID_books.erase(remove(user_ID_books.begin(), user_ID_books.end(), help), user_ID_books.end());
    }
