#include <iostream> // cout, cin
#include "func.h"
#include "name.h"
using namespace std;

//------------------------------------------------------------------------------
// invalidChoice
//------------------------------------------------------------------------------
// Uppgift: Skriver ut felmeddelande vid ogiltig inmatning
// Indata :
// Utdata : Funktionen skriver ut ett felmeddelande
//------------------------------------------------------------------------------
void invalidChoice()
{
    cout << "Ogiltigt val, mata in en siffra mellan 1 och 8." << endl;
}

//------------------------------------------------------------------------------
// sortPnr
//------------------------------------------------------------------------------
// Uppgift: Sorterar personlista efter personnr
// Indata : två objekt av typen Person
// Utdata : Returnerar true om p1 personnr är mindre än p2 personnr
//------------------------------------------------------------------------------
bool sortPnr(const Person &p1, const Person &p2)
{
    return p1.getPersNr() < p2.getPersNr();
}

//------------------------------------------------------------------------------
// sortSnr
//------------------------------------------------------------------------------
// Uppgift: Sorterar personlista efter skonr
// Indata : två objekt av typen Person
// Utdata : Returnerar true om p1 skonr är mindre än p2 skonr
//------------------------------------------------------------------------------
bool sortSnr(const Person &p1, const Person &p2)
{
    return p1.getSkoNr() < p2.getSkoNr();
}

//------------------------------------------------------------------------------
// sortFnLn
//------------------------------------------------------------------------------
// Uppgift: Sorterar personlista efter efternamn först och förnamn om efternamn
//          är lika
// Indata : två objekt av typen Person
// Utdata : Returnerar true om p1 namn är mindre än p2 namn
//------------------------------------------------------------------------------
bool sortFnLn(const Person &p1, const Person &p2)
{
    bool eq = false;

    if(p1.getName().getLastName() == p2.getName().getLastName())
    {
        eq = p1.getName().getFirstName() < p2.getName().getFirstName();
    }
    else
    {
        eq = p1.getName().getLastName() < p2.getName().getLastName();
    }

    return eq;
}

//------------------------------------------------------------------------------
// printPerson
//------------------------------------------------------------------------------
// Uppgift: Underlättar utskrift av en eller flera personer
// Indata : Ett objekt av typen Person
// Utdata : Utskrift till skärm
//------------------------------------------------------------------------------
void printPerson(const Person &p)
{
    cout << "Namn: " << p.getName().getFirstName() << " "
         << p.getName().getLastName() << endl;
    cout << "Gatuadress: " << p.getAddress().getStreet() << endl;
    cout << "Postadress: " << p.getAddress().getPostalNo()
         << " " << p.getAddress().getCity() << endl;
    cout << "Personnr: " << p.getPersNr() << endl;
    cout << "Skostorlek: " << p.getSkoNr() << endl;
}
