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
    LibrarySystem General;

    General.load_library();
    General.load_users();

    while (true)
    {
        General.print_menu();
        int choice;
        choice = General.get_int_input();
        General.clearScreen();
        switch (choice)
        {
        case 1: General.add_book(); break;
        case 2: General.delete_book(); break;
        case 3: General.add_user(); break;
        case 4: General.delete_user(); break;
        case 5: General.borrow_book(); break;
        case 6: General.return_book(); break;
        case 7: General.print_lists(); break;

        case 8:
            cout << "Goodbye!" << endl;
            General.save_library();
            General.save_users();
            return 0;

        default:
            cout << endl << "This is not an option!";
            break;
        }
    }
}

