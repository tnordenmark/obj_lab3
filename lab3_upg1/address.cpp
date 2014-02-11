#include "address.h"
using namespace std;

// Konstruktorer
Address::Address()
{
    street = "";
    postalno = "";
    city = "";
}

Address::Address(string s, string p, string c)
{
    street = s;
    postalno = p;
    city = c;
}

// Setters
void Address::setStreet(string s)
{
    street = s;
}

void Address::setPostalNo(string p)
{
    postalno = p;
}

void Address::setCity(string c)
{
    city = c;
}

// Överlagring av < operatorn
bool Address::operator <(const Address &a) const
{
    bool eq = false;

    if(city == a.getCity())
    {
        eq = (street) < (a.getStreet());
    }
    else
    {
        eq = (city) < (a.getCity());
    }

    return eq;
}

// Överlagring av == operatorn
bool Address::operator ==(const Address &a) const
{
    return city == a.getCity();
}
