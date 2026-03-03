#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Each variable called help is a helper variable that is used only inside a particular method.
// j is a cosmetical variable!
class User {
    string name;
    string surname;
    vector<string>List_of_user_books;
public: 
    User(string n, string s)
    {
        name = n;
        surname = s;
    }
    string getname()
    {
        return name;
    }
    string getsurname()
    {
        return surname;
    }
    int get_size_of_List_of_user_books()
    {
        return List_of_user_books.size();
    }
    vector<string>get_List_of_user_books()
    {
        return List_of_user_books;
    }
    void user_add_book(string help)
    {
        List_of_user_books.push_back(help);
    }
    void user_remove_book(string help)
    {
        List_of_user_books.erase(remove(List_of_user_books.begin(), List_of_user_books.end(), help), List_of_user_books.end());
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
    void return_book()
    {
        available = true;
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
    bool is_there_any_book()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].getbool())
                return true;
        }
        return false;
    }

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
        cout << "Give me your name" << endl;
        cin >> help_name;
        cout << "Give me your surname" << endl;
        cin >> help_surname;
        User help(help_name, help_surname); //temporary adding user and pushing him into the list
        users.push_back(help);
    }

    void borrow_book() // dodaj sprawdzenie pozniej!
    {
        cout << "Who want to borrow the book?" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << ". " << users[i].getname() << " " << users[i].getsurname() << endl;
        }
        int user_choice;
        cin >> user_choice;
        cout << "Which book he want to borrow?" << endl;
        if (is_there_any_book())
        {
            for (int i = 0; i < library.size(); i++)
            {
                if (library[i].getbool())
                {
                    cout << i + 1 << ". " << library[i].getname() << endl;
                }
            }
            int book_choice;
            cin >> book_choice;
            user_choice -= 1; // The user selects a number starting from 1, so we need to subtract 1 to match the program's indexing.
            book_choice -= 1;
            users[user_choice].user_add_book(library[book_choice].getname());
            library[book_choice].borrow_book();
        }
        else
        {
            cout << "There is no book available" << endl;
        }
    }

    void return_the_book()
    {
        int j = 1;
        cout << "Who want to return the book?" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << ". " << users[i].getname() << " " << users[i].getsurname() << endl;
        }
        int user_choice;
        cin >> user_choice;
        user_choice -= 1;
        cout << "Which book does he want to return?" << endl;
        if (users[user_choice].get_size_of_List_of_user_books() != 0)
        {
            for (int i = 0; i < users[user_choice].get_size_of_List_of_user_books(); i++)
            {
                cout << i + 1 << ". " << users[user_choice].get_List_of_user_books()[i] << endl;
            }
            int book_choice;
            cin >> book_choice;
            book_choice -= 1;
            users[user_choice].user_remove_book(users[user_choice].get_List_of_user_books()[book_choice]);
            library[book_choice].return_book();
        }
        else
        {
            cout << "This user does not have any book!" << endl;
        }
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
                int j = 1;
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].getbool())
                    {
                        cout << j << ". " << library[i].getname() << endl;
                        j++;
                    }
                }
                break;
            }
            case 3:
            {
                int j = 1;
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].getbool() == false)
                    {
                        cout << j << ". " << library[i].getname() << endl;
                        j++;
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
            General.return_the_book();
            break;
        }
        case 5:
        {
            General.list_of_books();
            break;
        }
        case 6:
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        default:
        {
            cout << endl << "This is not an option!";
            break;
        }
        }
    }
}

