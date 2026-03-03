#include <iostream>
#include <vector>

using namespace std;

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
};

class LibrarySystem {
public:
    void Print_menu()
    {
        cout << "Hello! What do you want to do?";
        cout << endl << "1 - Add new book?";
        cout << endl << "2 - Add new user?";
        cout << endl << "3 - Borrow the book?";
        cout << endl << "4 - Returne the book";
        cout << endl << "5 - Show list of available books";
    }
};
int main()
{
    LibrarySystem General;
    
    General.Print_menu();
    int choice;
    cin >> choice;

    switch (choice)
    {
        case 1:
        {
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

