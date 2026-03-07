#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Book.h"
#include "User.h"
#include "LibrarySystem.h"

using namespace std;

    bool LibrarySystem::check_user_choice(int x, int& help)
    {
    for (int i = 0; i < users.size(); i++)
    {
        if (x == users[i].get_ID())
        {
            help = i;
            return true;
        }
    }
    return false;
    }

    bool LibrarySystem::borrow_check_book_choice(int x, int& help)
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (x == library[i].get_ID() && library[i].is_available() == true)
            {
                help = i;
                return true;
            }
        }
        return false;
    }

    bool LibrarySystem::return_check_book_choice(int x, int& help)
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (x == library[i].get_ID() && library[i].is_available() == false)
            {
                help = i;
                return true;
            }
        }
        return false;
    }

    bool LibrarySystem::has_available_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available())
                return true;
        }
        return false;
    }

    bool LibrarySystem::has_unavailable_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (!library[i].is_available())
                return true;
        }
        return false;
    }

    bool LibrarySystem::has_user_id(int id)
    {
        for (int i = 0; i < users.size(); i++)
        {
            if (id == users[i].get_ID())
                return true;
        }
        return false;
    }

    bool LibrarySystem::has_book_id(int id)
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (id == library[i].get_ID())
                return true;
        }
        return false;
    }



    int LibrarySystem::availableBooksCount()
    {
        int j = 0;
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available())
            {
                j++;
            }
        }
        return j;
    }



    void LibrarySystem::print_menu_lists()
    {
        cout << "Which list of book do you want to see?" << endl;
        cout << "1 - List of all books" << endl;
        cout << "2 - List of available books" << endl;
        cout << "3 - List of unavailable books" << endl;
        cout << "4 - exit" << endl;
    }

    void LibrarySystem::show_users()
    {
        for (int i = 0; i < users.size(); i++) 
        {
            cout << users[i].get_ID() << " - " << users[i].get_name() << " " << users[i].get_surname() << endl;
        }
    }

    void LibrarySystem::show_all_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            cout << library[i].get_ID() << " - " << library[i].get_name() << endl;
        }
    }

    void LibrarySystem::show_available_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available())
            {
                cout << library[i].get_ID() << " - " << library[i].get_name() << endl;
            }
        }
    }

    void LibrarySystem::show_unavailable_books()
    {
        for (int i = 0; i < library.size(); i++)
        {
            if (library[i].is_available() == false)
            {
                cout << library[i].get_ID() << " - " << library[i].get_name() << endl;
            }
        }
    }

    void LibrarySystem::show_user_books(int user_choice)
    {
        for (int j = 0; j < users[user_choice].get_user_books().size(); j++)
        {
            for (int i = 0; i < library.size(); i++)
            {
                if (library[i].get_ID() == users[user_choice].get_user_books()[j])
                    cout << users[user_choice].get_user_books()[j] << " - " << library[i].get_name() << endl;
            }
        }
    }



    int LibrarySystem::get_int_input()
    {
        int x;
        while (!(cin >> x))
        {
            cout << "You must enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        return x;
    }


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



    void LibrarySystem::print_menu()
    {
        cout << "Hello! What do you want to do" << endl;
        cout << "1 - Add a new book" << endl;
        cout << "2 - Delete book" << endl;
        cout << "3 - Add a new user" << endl;
        cout << "4 - Delete user" << endl;
        cout << "5 - Borrow the book" << endl;
        cout << "6 - Return the book" << endl;
        cout << "7 - Show books lists" << endl;
        cout << "8 - Show library statistic " << endl;
        cout << "9 - Exit" << endl;
    }

    void LibrarySystem::add_book()
    {
        string name;
        int ID = library.size() + 1;

        cout << "Enter book name: " << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        library.emplace_back(name, ID, true);
        cout << "The book has been added" << endl;

        Pause();
        clearScreen();
    }

    void LibrarySystem::delete_book()
    {
        if (!has_available_books())
        {
            cout << "No available books!" << endl;
            Pause();
            clearScreen();
            return;
        }

        int book_choice; int book_index;

        cout << "Enter book ID:" << endl;
        show_available_books();
        book_choice = get_int_input();

        if (!borrow_check_book_choice(book_choice, book_index))
        {
            cout << "Invalid book ID" << endl;
            Pause();
            clearScreen();
            return;
        }

        library.erase(library.begin()+ book_index);
        cout << "Book was removed succesfully" << endl;

        Pause();
        clearScreen();
    }

    void LibrarySystem::add_user()
    {
        string name;
        string surname;
        int ID = users.size()+1;


        cout << "Enter your name" << endl; cin >> name;
        cout << "Enter your surname" << endl; cin >> surname;

        users.emplace_back(name, surname, ID);
        cout << "The user has been added" << endl;

        Pause();
        clearScreen();
    }

    void LibrarySystem::delete_user()
    {
        int user_choice;
        int user_index;

        if (users.empty())
        {
            cout << "There is no users!" << endl;
            Pause();
            clearScreen();
            return;
        }

        cout << "Enter user ID:" << endl;
        show_users();
        user_choice = get_int_input();

        if (!check_user_choice(user_choice, user_index))
        {
            cout << "User ID is writen incorrectly!" << endl;
            Pause();
            clearScreen();
            return;
        }

        if (users[user_index].get_user_books().size() != 0)
        {
            cout << "This user has books!" << endl;
            Pause();
            clearScreen();
            return;
        }

        users.erase(users.begin() + user_index);
        cout << "User was removed succesfully" << endl;

        Pause();
        clearScreen();
    }

    void LibrarySystem::borrow_book() 
    {
        int user_choice;
        int book_choice;
        int user_index;
        int book_index;

        if (users.empty()) 
        {
            cout << "There are no users!" << endl;
            Pause();
            clearScreen();
            return;
        }

        cout << "Enter user ID:" << endl;
        show_users();
        user_choice = get_int_input();

        if (!check_user_choice(user_choice, user_index))
        {
            cout << "User ID is writed incorrectly!" << endl;
            Pause();
            clearScreen();
            return;
        }

        if (users[user_index].get_user_books().size() >= 3)
        {
            cout << "User can't borrow more than 3 books" << endl;
            Pause();
            clearScreen();
        return;
        }

        if(!has_available_books()) 
        {
            cout << "There is no book available" << endl;
            Pause();
            clearScreen();
            return;
        }

            cout << "Enter book ID:" << endl;
            show_available_books();
            book_choice = get_int_input();

        if (!borrow_check_book_choice(book_choice, book_index))
        {
            cout << "Book ID was writed incorrectly" << endl;
            Pause();
            clearScreen();
            return;
        }

       users[user_index].add_book(library[book_index].get_ID());
       library[book_index].borrow_book();
       cout << "Book is succesfully borrowed!" << endl;
       Pause();
       clearScreen();
    }

    void LibrarySystem::return_book()
    {
        int user_choice;
        int book_choice;
        int user_index;
        int book_index; // in library

        if (users.empty())
        {
            cout << "There are no users!" << endl;
            Pause();
            clearScreen();
            return;
        }

            cout << "Select a user who wants to return a book:" << endl;
            show_users();
            user_choice = get_int_input();

        if (!check_user_choice(user_choice, user_index))
        {
            cout << "User ID is writed incorrectly!" << endl;
            Pause();
            clearScreen();
            return;
        }

        if (users[user_index].get_user_books().size() == 0)
        {
            cout << "This user has no books" << endl;
            Pause();
            clearScreen();
            return;
        }

            cout << "Select a book to return: " << endl;
            show_user_books(user_index);
            book_choice = get_int_input();

       if (!return_check_book_choice(book_choice, book_index))
       {
            cout << "Book ID was writed incorrectly" << endl;
            Pause();
            clearScreen();
            return;
       }

            users[user_index].remove_book(library[book_index].get_ID());
            library[book_index].return_book();

            cout << "Book is succesfully returned!" << endl;

            Pause();
            clearScreen();
    }

    void LibrarySystem::print_lists()
    {
        if (library.empty())
        {
            cout << "There is no books!" << endl;
            Pause();
            clearScreen();
            return;
        }

        int help_choice = 0;

        while (help_choice != 4)
        {
            print_menu_lists();
            help_choice = get_int_input();

            switch (help_choice)
            {

            case 1:
            if (library.empty())
            {
                cout << "There are no books" << endl;
                Pause();
                clearScreen();
                break;
            }

                show_all_books();
                Pause();
                break;

            case 2:
            if (!has_available_books())
            {
                cout << "There are no avilable books" << endl;
                Pause();
                clearScreen();
                break;
            }
                    
                show_available_books();
                Pause();
                break;

            case 3:
            if (!has_unavailable_books())
            {
                cout << "There are no unavailable books" << endl;
                Pause();
                clearScreen();
                return;
            }

                show_unavailable_books();
                Pause();
                break;

            case 4: break;

            default:
                cout << "This is not an option!" << endl;
                Pause();
                break;
            }
        }
        clearScreen();
    }

    void LibrarySystem::show_statisctic()
    {
        cout << "Total books: " << library.size() << endl;
        cout << "Available: " << availableBooksCount() << endl;
        cout << "Unavailable: " << library.size() - availableBooksCount() << endl;
        cout << "Users: " << users.size() << endl;
        Pause();
        clearScreen();
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
        string name;
        string ID_str;
        string check;
        bool available;
        while (getline(book_list, name)&& getline(book_list, ID_str) && getline(book_list, check))
        {
            if (check == "YES")
                available = true;
            else
                available = false;

            int ID = stoi(ID_str);
            library.emplace_back(name, ID , available);
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
        if (!user_list)
            return;

        string name;
        string surname;
        string id_str;
        string books_count_str;

        while (getline(user_list, name) && getline(user_list, surname) && getline(user_list, id_str) && getline(user_list, books_count_str))
        {
            int user_id = stoi(id_str);
            int books_count = stoi(books_count_str);

            users.emplace_back(name, surname, user_id);

            for (int i = 0; i < books_count; i++)
            {
                string book_id_str;
                getline(user_list, book_id_str);

                int book_id = stoi(book_id_str);
                users.back().add_book(book_id);
            }
        }
    }
    