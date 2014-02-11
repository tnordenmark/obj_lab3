#include "name.h"
using namespace std;

// Konstruktorer
Name::Name()
{
    firstName = "";
    lastName = "";
}

Name::Name(string fn, string ln)
{
    firstName = fn;
    lastName = ln;
}

// Setters
void Name::setFirstName(string fn)
{
    firstName = fn;
}

void Name::setLastName(string ln)
{
    lastName = ln;
}

bool Name::operator<(const Name &name) const
{
    bool eq = false;

    if(lastName == name.getLastName())
    {
        eq = (firstName) < (name.getFirstName());
    }
    else
    {
        eq = (lastName) < (name.getLastName());
    }

    return eq;
}

bool Name::operator ==(const Name &name) const
{
    bool eq = false;

    if(lastName == name.getLastName())
    {
        eq = (firstName) < (name.getLastName());
    }
    else
    {
        eq = (lastName) < (name.getLastName());
    }

    return eq;
}
