#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Book.h"
#include "User.h"
#include "LibrarySystem.h"

using namespace std;

    

    void LibrarySystem::Pause()
    {
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void LibrarySystem::clearScreen()
    {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    }

    bool LibrarySystem::has_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available())
                return true;
        }
        return false;
    }

    bool LibrarySystem::check_user_choice(int x, int &help)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (to_string(x) == users[i].get_ID())
            {
                help = i;
                return true;
            }
        }
        return false;
    }

    bool LibrarySystem::check_book_choice(int x, int &help)
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (to_string(x) == library[i].get_ID())
            {
                help = i;
                return true;
            }
        }
        return false;
    }

    void LibrarySystem::show_users()
    {
        for (int i = 0; i < users.size(); i++) // showing list of users
        {
            cout << users[i].get_ID() << " - " << users[i].get_name() << " " << users[i].get_surname() << endl;
        }
    }

    void LibrarySystem::show_avilable_books()
    {
        for (int i = 0; i < library.size(); i++) 
        {
            if (library[i].is_available())
            {
                cout << library[i].get_ID() << " - " << library[i].get_name() << endl;
            }
        }
    }

    void LibrarySystem::show_user_books(int user_choice)
    {
        for (int i = 0; i < users[user_choice].get_user_books().size(); i++)
        {
            cout << i + 1 << ". " << users[user_choice].get_user_books()[i] << endl;
        }
    }

    void LibrarySystem::print_menu()
    {
        cout << "Hello! What do you want to do" << endl;
        cout << "1 - Add a new book" << endl;
        cout << "2 - Add a new user" << endl;
        cout << "3 - Borrow the book" << endl;
        cout << "4 - Return the book" << endl;
        cout << "5 - Show list of available books" << endl;
        cout << "6 - Exit" << endl;
        cout << "7 - Restart the program" << endl;
    }

    void LibrarySystem::add_book()
    {
        cout << "Enter book name: " << endl;
        string help;
        getline(cin, help);
        int help_ID = rand() % 99999 + 1;
        library.emplace_back(help, to_string(help_ID), true);
        LibrarySystem::clearScreen();
    }

    void LibrarySystem::add_user()
    {
        string help_name;
        string help_surname;
        int help_ID = rand() % 99999 + 1;

        cout << "Enter your name" << endl; cin >> help_name;
        cout << "Enter your surname" << endl; cin >> help_surname;

        //temporary user added to the list
        User help(help_name, help_surname, to_string(help_ID));
        users.push_back(help);

        LibrarySystem::clearScreen();
    }

    void LibrarySystem::borrow_book() // dodaj sprawdzenie pozniej!
    {
        int user_choice;
        int book_choice;
        int user_index;
        int book_index;

        if (users.empty()) 
        {
            cout << "There are no users!" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

        cout << "Enter user ID:" << endl;
        show_users();
        cin >> user_choice;

        if (!check_user_choice(user_choice, user_index))
        {
            cout << "User ID is writed incorrectly!" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

        if (users[user_index].get_user_books().size() >= 3)
        {
            cout << "User can't borrow more than 3 books" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
        return;
        }

        if(!has_books()) //if there are no available books they can't be shown
        {
            cout << "There is no book available" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

            cout << "Enter book ID:" << endl;
            show_avilable_books();
            cin >> book_choice;

        if (!check_book_choice(book_choice, book_index))
        {
            cout << "Book ID was writed incorrectly" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

       users[user_index].add_book(library[book_index].get_name());
       library[book_index].borrow_book();
       LibrarySystem::Pause();
       LibrarySystem::clearScreen();
    }

    void LibrarySystem::return_book()
    {
        int user_choice;
        int book_choice;
        int user_index;
        int book_index;

        if (users.empty())
        {
            cout << "There are no users!" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

            cout << "Select a user who wants to return a book:" << endl;
            show_users();
            cin >> user_choice;

        if (!check_user_choice(user_choice, user_index))
        {
            cout << "User ID is writed incorrectly!" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }
            cout << "Select a book to return: " << endl;

        if (users[user_choice].get_user_books().size() != 0)
        {
            cout << "This user has no books" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
        }

            show_user_books(user_choice);
            cin >> book_choice;

       if (!check_book_choice(book_choice, book_index))
       {
            cout << "Book ID was writed incorrectly" << endl;
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
            return;
       }

            users[user_index].remove_book(users[user_index].get_user_books()[book_index]);
            library[book_index].return_book();
            LibrarySystem::Pause();
            LibrarySystem::clearScreen();
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
            LibrarySystem::clearScreen();

            switch (help_choice)
            {
            case 1:
            {
                if (library.size()!= 0)
                {
                    for (int i = 0; i < library.size(); i++)
                    {
                        cout << i + 1 << ". " << library[i].get_name() << endl;
                    }
                }
                else
                {
                    cout << "There are no books" << endl;
                }

                break;
            }
            case 2:
            {
                if (has_books())
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
                }
                else cout << "There are no avilable books" << endl;

                break;
            }
            case 3:
            {
                if (!has_books())
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
                }
                else cout << "There are no unavailable books" << endl;

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
        LibrarySystem::clearScreen();
    }

    void LibrarySystem::save_library()
    {
        ofstream book_list("book_list.txt");

        for (int i = 0; i < library.size(); i++)
        {
            book_list <<library[i].get_name() << endl;
            book_list << library[i].get_ID() << endl;
            if (library[i].is_available())
                book_list << "YES" << endl;
            else
                book_list << "NO" << endl;
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
        string help_ID;
        string help;
        bool temp;
        while (getline(book_list, help_name)&& getline(book_list, help_ID) && getline(book_list, help))
        {
            if (help == "YES")
                temp = true;
            else
                temp = false;
            library.emplace_back(help_name,help_ID, temp);
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
            user_list << users[i].get_user_books().size() << endl;

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

        string name;
        string surname;
        string id;
        string books_count_str;
        string book_name;

        while (getline(user_list, name) && getline(user_list, surname) && getline(user_list, id) && getline(user_list, books_count_str))
        {
            int books_count = stoi(books_count_str);
            users.emplace_back(name, surname, id);

            for (int i = 0; i < books_count; i++)
            {
                getline(user_list, book_name);
                users.back().add_book(book_name);
            }
        }
    }
    