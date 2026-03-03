#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Each variable called help is a helper variable that is used only inside a particular method.

class User {
    string name;
    string surname;
    int age;
public: 
    User(string n, string s, int a){
        name = n;
        surname = s;
        age = a;
}
};

class Library
{
    vector<string>List_of_all_books;
    vector<string>List_of_available_books;
    vector<string>List_of_unavailable_books;
public:

    void add_book_to_library(string help)
    {
        List_of_all_books.push_back(help);
        List_of_available_books.push_back(help);
        List_of_unavailable_books.push_back(help);
    }
};

class LibrarySystem {

Library General_library;

public:
    void Print_menu()
    {
        cout << "Hello! What do you want to do?";
        cout << "1 - Add new book?";
        cout << "2 - Add new user?";
        cout << "3 - Borrow the book?";
        cout << "4 - Returne the book";
        cout << "5 - Show list of available books";
    }

    void add_book()
    {
        cout <<"Give the name of book you want to add" << endl;
        string help;
        getline(cin, help);
        General_library.add_book_to_library(help);
    }

};
int main()
{
    LibrarySystem General;

    General.Print_menu();
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
        case 1:
        {
            General.add_book();
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        default:
        {
            cout << endl << "This is not an option!";
            break;
        }
    }
    return 0;
}

