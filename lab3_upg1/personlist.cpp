#include <fstream>
#include <algorithm>
#include "personlist.h"
using namespace std;

// Standardkonstruktor
PersonList::PersonList()
{
    fileName = "";
}

// Överlagrad konstruktor
PersonList::PersonList(vector<Person> v, string f)
{
    pvec = v;
    fileName = f;
}

// Setter för filnamn
void PersonList::setFileName(string f)
{
    fileName = f;
}

// Lägg till person i listan
void PersonList::addPerson(Person &p)
{
    // Lägg hela personobjektet i vectorn
    pvec.push_back(p);
}

// Getter för person
Person PersonList::getPerson(int idx)
{
    Person p = pvec[idx];

    return p;
}

// Antal personer i listan (storlek på vectorn)
int PersonList::nrOfPersons()const
{
    return pvec.size();
}

// Sortera på namn, efternamn först
void PersonList::sortName()
{
    sort(pvec.begin(), pvec.end(), sortFnLn);
}

// Sortera på personnr
void PersonList::sortPersnr()
{
    sort(pvec.begin(), pvec.end(), sortPnr);

}

// Sortera på skonr
void PersonList::sortShoenr()
{
    sort(pvec.begin(), pvec.end(), sortSnr);

}

// Läs lista från fil
void PersonList::readFromFile()
{
    fstream inFile(fileName, ios::in);
    Person tmpp;

    if(!pvec.empty())
        pvec.clear();

    while(inFile >> tmpp)
        pvec.push_back(tmpp);

    inFile.close();
}

// Skriv lista till fil
void PersonList::writeToFile()
{
    // Öppna filen för skrivning
    fstream outFile(fileName, ios::out);

    // Om det gick bra att öppna filen
    if(outFile.is_open())
    {
        // Skriv vectorns innehåll till fil
        for(auto idx: pvec)
        {
           outFile << idx << endl;
        }
    }
    else
        // I/O error, om filen inte kunde öppnas
        cout << "Kunde inte öppna filen." << endl;

    // Stäng utfilen
    outFile.close();

}

// Skriv ut listan till skärm
void PersonList::printList()
{
    // Skriv ut hela listan i pvec
    for(auto idx: pvec)
    {
        printPerson(idx);
        // Radbrytning mellan varje person
        cout << endl;
    }
}
