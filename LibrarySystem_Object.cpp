#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <fstream>
#include "LibrarySystem.h"

using namespace std;

int main()
{
    srand(time(NULL));

    LibrarySystem General;

    General.load_library();
    General.load_users();

    while (true)
    {
        General.print_menu();
        int choice;
        cin >> choice;
        cin.ignore();
        General.clearScreen();
        switch (choice)
        {
        case 1:
        {
            General.add_book();
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
            General.return_book();
            break;
        }
        case 5:
        {
            General.print_lists();
            break;
        }
        case 6:
        {
            cout << "Goodbye!" << endl;
            General.save_library();
            General.save_users();
            return 0;
            break;
        }
        case 7:
        {
            cout << "Program is restarting" << endl;
            ofstream user_list("user_list.txt");
            user_list.close();
            ofstream book_list("book_list.txt");
            book_list.close();
            return 0;
            break;
        }
        default:
        {
            cout << endl << "This is not an option!";
            break;
        }
        }
    }
}

