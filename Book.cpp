#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(string n, int id, bool a)
{
    name = n;
    ID = id;
    available = a;
}
string Book::get_name() const
{
    return name;
}
int Book::get_ID() const
{
    return ID;
}
bool Book::is_available() const
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
