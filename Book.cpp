#include <iostream>
#include "Book.h"

using namespace std;

Book::Book(const string& n, bool a)
{
    name = n;
    available = a;
}
string Book::get_name() const
{
    return name;
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
