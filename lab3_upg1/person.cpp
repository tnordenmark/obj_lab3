#include <iostream>
#include "person.h"
using namespace std;

Person::Person()
{
    persNr = "";
    skoNr = 0;
}

Person::Person(Name n, Address a, std::string p, int s)
{
    name = n;
    address = a;
    persNr = p;
    skoNr = s;
}

// Setters
void Person::setName(Name n)
{
    name = n;
}

void Person::setAddress(Address a)
{
    address = a;
}

void Person::setPersNr(std::string p)
{
    persNr = p;
}

void Person::setSkoNr(int s)
{
    skoNr = s;
}

// Överlagring av < operatorn
bool Person::operator<(const Person &p) const
{
    bool eq = false;

    if(name == p.getName())
    {
        eq = (address) < (p.getAddress());
    }
    else
    {
        eq = (name) < (p.getName());
    }

    return eq;
}

// Överlagring av == operatorn
bool Person::operator ==(const Person &p) const
{
    return name == p.getName();
}

// Avgränsare för utskrift till fil
const char DELIM = '|';

// Överlagring av utskriftsoperatorn
std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.getName().getFirstName() << DELIM << p.getName().getLastName() << DELIM;
    os << p.getAddress().getStreet() << DELIM << p.getAddress().getPostalNo() << DELIM;
    os << p.getAddress().getCity() << DELIM << p.getPersNr()<< DELIM << p.getSkoNr();

    return os;
}

// Överlagring av inmatningsoperatorn
std::istream &operator>>(std::istream &is, Person &p)
{
    Name n;
    Address a;
    string s;

    getline(is, s, DELIM);
    n.setFirstName(s);

    getline(is, s, DELIM);
    n.setLastName(s);
    p.setName(n);

    getline(is, s, DELIM);
    a.setStreet(s);

    getline(is, s, DELIM);
    a.setPostalNo(s);

    getline(is, s, DELIM);
    a.setCity(s);
    p.setAddress(a);

    getline(is, s, DELIM);
    p.setPersNr(s);

    int x;
    is >> x;
    is.get();
    p.setSkoNr(x);

    return is;
}


