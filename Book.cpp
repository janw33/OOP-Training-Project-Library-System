#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(string n, bool a)
{
    name = n;
    available = a;
}
string Book::get_name()
{
    return name;
}
bool Book::get_is_this_book_available()
{
    return available;
}
void Book::borrow_book()
{
    available = false;
}
void Book::return_book()
{
    available = true;
}
