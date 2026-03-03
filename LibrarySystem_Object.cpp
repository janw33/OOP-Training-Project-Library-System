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
    int choice;
    General.Print_menu();

    return 0;
}

