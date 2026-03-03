#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "LibrarySystem.h"

using namespace std;

int main()
{
    LibrarySystem General;
    General.reload_file_into_library();
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
            General.convert_library_into_file();
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

