#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "LibrarySystem.h"

using namespace std;
    

    bool LibrarySystem::is_there_any_book()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].get_is_this_book_available())
                return true;
        }
        return false;
    }

    void LibrarySystem::print_menu()
    {
        cout << "Hello! What do you want to do?" << endl;
        cout << "1 - Add new book?" << endl;
        cout << "2 - Add new user?" << endl;
        cout << "3 - Borrow the book?" << endl;
        cout << "4 - Returne the book" << endl;
        cout << "5 - Show list of available books" << endl;
        cout << "6 - Exit" << endl;
    }

    void LibrarySystem::add_book()
    {
        cout << "Give the name of book you want to add" << endl;
        string help;
        getline(cin, help);
        library.emplace_back(help, true);
    }

    void LibrarySystem::add_user()
    {
        string help_name;
        string help_surname;
        cout << "Give me your name" << endl; cin >> help_name;
        cout << "Give me your surname" << endl; cin >> help_surname;
        User help(help_name, help_surname); //temporary adding user and pushing him into the list
        users.push_back(help);
    }

    void LibrarySystem::borrow_book() // dodaj sprawdzenie pozniej!
    {
        cout << "Who want to borrow the book?" << endl;
        if (users.size() != 0)
        {
            for (int i = 0; i < users.size(); i++)
            {
                cout << i + 1 << ". " << users[i].get_name() << " " << users[i].get_surname() << endl;
            }
            int user_choice;
            cin >> user_choice;
            cout << "Which book he want to borrow?" << endl;
            if (is_there_any_book())
            {
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].get_is_this_book_available())
                    {
                        cout << i + 1 << ". " << library[i].get_name() << endl;
                    }
                }
                int book_choice;
                cin >> book_choice;
                user_choice -= 1; // The user selects a number starting from 1, so we need to subtract 1 to match the program's indexing.
                book_choice -= 1;
                users[user_choice].user_add_book(library[book_choice].get_name());
                library[book_choice].borrow_book();
            }
            else
            {
                cout << "There is no book available" << endl;
            }
        }
        else
        {
            cout << "There is no users!" << endl;
        }
    }

    void LibrarySystem::return_the_book()
    {
        int j = 1;
        cout << "Who want to return the book?" << endl;
        for (int i = 0; i < users.size(); i++)
        {
            cout << i + 1 << ". " << users[i].get_name() << " " << users[i].get_surname() << endl;
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

    void LibrarySystem::list_of_books()
    {
        int help_choice = 0;
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
                    cout << i + 1 << ". " << library[i].get_name() << endl;
                }
                break;
            }
            case 2:
            {
                int j = 1;
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].get_is_this_book_available())
                    {
                        cout << j << ". " << library[i].get_name() << endl;
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
                    if (library[i].get_is_this_book_available() == false)
                    {
                        cout << j << ". " << library[i].get_name() << endl;
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

    void LibrarySystem::convert_library_into_file()
    {
        ofstream users("library.txt");

        for (int i = 0; i < library.size(); i++)
        {
            users <<"Nazwa ksiazki to: " << library[i].get_name() << endl;
            if (library[i].get_is_this_book_available())
                users << "Czy ta ksiazka jest w bilbiotece: TAK" << endl;
            else
                users << "Czy ta ksiazka jest w bilbiotece: NIE" << endl;
        }
    }

    void LibrarySystem::reload_file_into_library()
    {
        ifstream users("library.txt");

        if (!users.is_open())
        {
            cout << "File did not open!" << endl;
            return;
        }
        string help_name;
        string help;
        bool temp;
        while (getline(users, help_name))
        {
            help_name.erase(0 , 18);
            getline(users, help);
            if (help == "Czy ta ksiazka jest w bilbiotece: TAK")
                temp = true;
            else
                temp = false;

            library.emplace_back(help_name, temp);
        }

        users.close();
    }