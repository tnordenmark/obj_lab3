#include <fstream>
#include <algorithm>
#include "personlist.h"
using namespace std;

PersonList::PersonList()
{
    fileName = "";
}

PersonList::PersonList(vector<Person> v, string f)
{
    pvec = v;
    fileName = f;
}

void PersonList::setFileName(string f)
{
    fileName = f;
}

void PersonList::addPerson(Person &p)
{
    // Lägg hela personobjektet i vectorn
    pvec.push_back(p);
}

Person PersonList::getPerson(int idx)
{
    Person p = pvec[idx];

    return p;
}

int PersonList::nrOfPersons()const
{
    return pvec.size();
}

void PersonList::sortName()
{
    sort(pvec.begin(), pvec.end(), sortFnLn);
}

void PersonList::sortPersnr()
{
    sort(pvec.begin(), pvec.end(), sortPnr);

}

void PersonList::sortShoenr()
{
    sort(pvec.begin(), pvec.end(), sortSnr);

}

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

