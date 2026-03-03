#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Book.h"
#include "User.h"
#include "LibrarySystem.h"

using namespace std;
    

    bool LibrarySystem::has_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available())
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
        cout << "7 - Restart program" << endl;
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
        int help_ID;
        cout << "Give me your name" << endl; cin >> help_name;
        cout << "Give me your surname" << endl; cin >> help_surname;
        help_ID = rand() % 9999 + 1;
        User help(help_name, help_surname, help_ID); //temporary adding user and pushing him into the list
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
            if (has_books())
            {
                for (int i = 0; i < library.size(); i++)
                {
                    if (library[i].is_available())
                    {
                        cout << i + 1 << ". " << library[i].get_name() << endl;
                    }
                }
                int book_choice;
                cin >> book_choice;
                user_choice -= 1; // The user selects a number starting from 1, so we need to subtract 1 to match the program's indexing.
                book_choice -= 1;
                users[user_choice].add_book(library[book_choice].get_name());
                library[book_choice].borrow_book();
            }
            else
            {
                cout << "There is no book available" << endl;
            }
        }
        else
        {
            cout << "There are not any users!" << endl;
        }
    }

    void LibrarySystem::return_book()
    {
        int j = 1;
        cout << "Who want to return the book?" << endl;
        if (users.size() != 0)
        {
            for (int i = 0; i < users.size(); i++)
            {
                cout << i + 1 << ". " << users[i].get_name() << " " << users[i].get_surname() << endl;
            }
            int user_choice;
            cin >> user_choice;
            user_choice -= 1;
            cout << "Which book does he want to return?" << endl;
            if (users[user_choice].get_user_books().size() != 0)
            {
                for (int i = 0; i < users[user_choice].get_user_books().size(); i++)
                {
                    cout << i + 1 << ". " << users[user_choice].get_user_books()[i] << endl;
                }
                int book_choice;
                cin >> book_choice;
                book_choice -= 1;
                users[user_choice].remove_book(users[user_choice].get_user_books()[book_choice]);
                library[book_choice].return_book();
            }
            else
            {
                cout << "This user does not have any book!" << endl;
            }
        }
        else
        {
            cout << "There are not any users!" << endl;
        }
    }

    void LibrarySystem::print_lists()
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
                    if (library[i].is_available())
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
                    if (library[i].is_available() == false)
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

    void LibrarySystem::save_library()
    {
        ofstream book_list("book_list.txt");

        for (int i = 0; i < library.size(); i++)
        {
            book_list <<library[i].get_name() << endl;
            if (library[i].is_available())
                book_list << "TAK" << endl;
            else
                book_list << "NIE" << endl;
        }
    }

    void LibrarySystem::load_library()
    {
        ifstream book_list("book_list.txt");

        if (!book_list.is_open())
        {
            return;
        }
        string help_name;
        string help;
        bool temp;
        while (getline(book_list, help_name) && getline(book_list, help))
        {
            if (help == "TAK")
                temp = true;
            else
                temp = false;
            library.emplace_back(help_name, temp);
        }
        book_list.close();
    }

    void LibrarySystem::save_users()
    {
        ofstream user_list("user_list.txt");

        for (int i = 0; i < users.size(); i++)
        {
            user_list << users[i].get_name() << endl;
            user_list << users[i].get_surname() << endl;
            user_list << users[i].get_ID() << endl;
            user_list << users[i].get_user_books().size() << endl; // number of how much books user has
            for (int j = 0; j < users[i].get_user_books().size(); j++)
            {
                user_list << users[i].get_user_books()[j] << endl;
            }
        }
    }

    void LibrarySystem::load_users()
    {
        ifstream user_list("user_list.txt");

        if (!user_list.is_open())
        {
            return;
        }
        string help_name;
        string help_surname;
        string help_ID;
        string help; // number of how much books user has (string)
        string help_user_books;
        int help_id;
        while (getline(user_list, help_name) && getline(user_list, help_surname) && getline(user_list, help_ID) && getline(user_list, help))
        {
            help_id = stoi(help_ID);
            users.emplace_back(help_name, help_surname, help_id);
            int help1 = stoi(help); // number of how much books user has (int)
            for (int i = 0; i < help1; i++)
            {
                getline(user_list, help_user_books);
                users.back().add_book(help_user_books);
            }
        }

        user_list.close();
    }
    