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

    void add_book_library(string help)
    {
        List_of_all_books.push_back(help);
        List_of_available_books.push_back(help);
    }
};

class LibrarySystem {

Library library;
vector<User>users;

public:
    void print_menu()
    {
        cout << "Hello! What do you want to do?"<<endl;
        cout << "1 - Add new book?" << endl;
        cout << "2 - Add new user?" << endl;
        cout << "3 - Borrow the book?" << endl;
        cout << "4 - Returne the book" << endl;
        cout << "5 - Show list of available books" << endl;
    }

    void add_book_system()
    {
        cout <<"Give the name of book you want to add" << endl;
        string help;
        getline(cin, help);
        library.add_book_library(help);
    }
    
    void add_user() 
    {
        string help_name;
        string help_surname;
        int help_age;
        cout << "Give me your name" << endl;
        cin >> help_name;
        cout << "Give me your surname" << endl;
        cin >> help_surname;
        cout << "Give me your age" << endl;
        cin >> help_age;
        User help(help_name, help_surname, help_age); //temporary adding user and pushing him into the list
        users.push_back(help);
    }
};
int main()
{
    LibrarySystem General;

    General.print_menu();
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
        case 1:
        {
            General.add_book_system();
            break;
        }
        case 2:
        {
            General.add_user();
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

