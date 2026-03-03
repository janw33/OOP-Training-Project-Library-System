#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Each variable called help is a helper variable that is used only inside a particular method.

class User {
    string name;
    string surname;
    int age;
    vector<string>List_of_user_books;
public: 
    User(string n, string s, int a)
    {
        name = n;
        surname = s;
        age = a;
    }
    string getname()
    {
        return name;
    }
    string getsurname()
    {
        return surname;
    }
    void user_add_book(string help)
    {
        List_of_user_books.push_back(help);
    }
};

class Book
{
    string name;
    bool available;
public:
    Book(string n = "", bool a = true)
    {
        name = n;
        available = a;
    }
    void borrow_book()
    {
        available = false;
    }
    string getname()
    {
        return name;
    }
    bool getbool()
    {
        return available;
    }
};

class LibrarySystem {

    vector<Book>library;
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
        library.push_back(Book(help, true));
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

    void borrow_book() // dodaj sprawdzenie pozniej!
    {
        int j = 1; // j is a cosmetical variable!
        cout << "Which book do you want to borrow?" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << ". " << users[i].getname() << " " << users[i].getsurname() << endl;
        }
        int user_choice;
        cin >> user_choice;
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].getbool())
            {
                cout << j << ". " << library[i].getname() << endl;
                j++;
            }
        }
        int book_choice;
        cin >> book_choice;
        user_choice -= 1; // The user selects a number starting from 1, so we need to subtract 1 to match the program's indexing.
        book_choice -= 1;
        users[user_choice].user_add_book(library[book_choice].getname());
        library[book_choice].borrow_book();
    }

    void list_of_books()
    {
        int help_choice=0;
        while (help_choice != 4)
        {
            cout << "Which list of book do you want to see?" << endl;
            cout << "1 - List of all books" << endl;
            cout << "2 - List of available books" << endl;
            cout << "3 - List of unavailable books" << endl;
            cout << "4 - exit" << endl;
            cin >> help_choice;
            switch (help_choice)
            {
            case 1:
            {
                for (int i = 0; i < library.size(); i++)
                {
                    cout << i + 1 << ". " << library[i].getname() << endl;
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].getbool())
                    {
                        cout << i + 1 << ". " << library[i].getname() << endl;
                    }
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].getbool() == false)
                    {
                        cout << i + 1 << ". " << library[i].getname() << endl;
                    }
                }
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                cout << "This is not an option!" << endl;
                break;
            }
            }
        }
    }
};
int main()
{
    LibrarySystem General;
    while (true)
    {
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
            General.borrow_book();
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            General.list_of_books();
            break;
        }
        default:
        {
            cout << endl << "This is not an option!";
            break;
        }
        }
    }
    return 0;
}

