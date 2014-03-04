#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "userinterface.h"
#include "func.h"
#include "personlist.h"
using namespace std;

//------------------------------------------------------------------------------
// showMenu
//------------------------------------------------------------------------------
// Uppgift: Visar en huvudmeny
// Indata :
// Utdata : Menyn skrivs till skärmen
//------------------------------------------------------------------------------
void UserInterface::showMenu()
{
    cout << "=========================" << endl;
    cout << "        Huvudmeny" << endl;
    cout << "1. Lägg till person" << endl;
    cout << "2. Skriv ut lista" << endl;
    cout << "3. Spara på fil" << endl;
    cout << "4. Läs från fil" << endl;
    cout << "5. Sortera på namn" << endl;
    cout << "6. Sortera på persnr" << endl;
    cout << "7. Sortera på skonr" << endl;
    cout << "8. Avsluta" << endl;
    cout << "=========================" << endl;
}

//------------------------------------------------------------------------------
// menuChoice
//------------------------------------------------------------------------------
// Uppgift: Hanterar menyval för en huvudmeny
// Indata :
// Utdata : menuChoice returneras som en integer
//------------------------------------------------------------------------------
int UserInterface::menuChoice()
{
    // Lagra menyvalet
    int menuChoice;

    // Fråga efter och läs in menyvalet med teckenverifiering
    while ((cout << "Menyval: ")
             && (!(cin >> menuChoice)
             || menuChoice < 1
             || menuChoice > 8))
    {
        invalidChoice();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Returnera menyvalet som en integer
    return menuChoice;
}

//------------------------------------------------------------------------------
// addPerson
//------------------------------------------------------------------------------
// Uppgift: Läser in en person och lägger till personen i en vector
// Indata : Ett objekt av typen PersonLista
// Utdata : Funktionen lägger till en person i vectorn
//------------------------------------------------------------------------------
void UserInterface::addPerson(PersonList &plist)
{
    // Skapa de objekt som behövs
    Person p;
    Name n;
    Address a;

    // Variabler för inmatad data
    string fname, lname, street, postalno, city, persnr, skonrstr;

    // Läs bort huvudmenyns newline
    cin.get();

    // Fråga efter, mata in och tilldela data till rätt objekts attribut
    cout << "Förnamn: ";
    getline(cin, fname);
    n.setFirstName(fname);

    cout << "Efternamn: ";
    getline(cin, lname);
    n.setLastName(lname);

    cout << "Gatuadress: ";
    getline(cin, street);
    a.setStreet(street);

    cout << "Postnr: ";
    getline(cin, postalno);
    a.setPostalNo(postalno);

    cout << "Stad: ";
    getline(cin, city);
    a.setCity(city);

    // Sätt Person-objektets "vanliga" variabler persNr och skoNr till rätt inmatad data
    cout << "Personnr: ";
    getline(cin, persnr);
    p.setPersNr(persnr);

    // Eftersom det är lite vanskligt att blanda cin >> och getline använder jag
    // getline till en temporär skonrsträng och omvandlar sen till int innan den
    // sparas i Person-objektet
    cout << "Skonr: ";
    getline(cin, skonrstr);
    int skonr = 0;
    stringstream skostream(skonrstr);
    skostream >> skonr;
    p.setSkoNr(skonr);

    // Tilldela objekten Name och Address i klassen Person sina objekt
    p.setName(n);
    p.setAddress(a);

    // Lägg hela personobjektet i vectorn
    plist.addPerson(p);

}

// Skriver ut personlistan mha funktionen i PersonLista
void UserInterface::printList(PersonList &plist)
{
    plist.printList();
}

// Frågar efter filnamn och sparar listan till dito
void UserInterface::saveToFile(PersonList &plist)
{
    string fn;
    cout << "Ange filnamn: ";
    cin >> fn;

    plist.setFileName(fn);

    plist.writeToFile();
}

// Frågar efter filnamn och läser listan från dito
void UserInterface::readFromFile(PersonList &plist)
{
    string fn;
    cout << "Ange filnamn: ";
    cin >> fn;

    plist.setFileName(fn);

    plist.readFromFile();
}

// Sorterar listan efter namn mha funktion i PersonLista
void UserInterface::sortName(PersonList &plist)
{
    plist.sortName();
}

// Sorterar listan efter persnr mha funktion i PersonLista
void UserInterface::sortPersnr(PersonList &plist)
{
    plist.sortPersnr();
}

// Sorterar listan efter skonr mha funktion i PersonLista
void UserInterface::sortShoenr(PersonList &plist)
{
    plist.sortShoenr();
}

// Standardkonstruktor
UserInterface::UserInterface()
{
}

// Huvudfunktion som kör hela programmet
int UserInterface::run()
{
    PersonList plist;

    // Skapa testpersoner
    Person p1(Name("Arne", "Andersson"), Address("Storgatan 4", "83146", "Östersund"), "810512-8417", 44);
    Person p2(Name("Caesar", "Caligula"), Address("Kejsargatan 10", "55567", "Rom"), "141212-8415", 36);
    Person p3(Name("Daniel", "Dragan"), Address("Storgatan 10", "83146", "Östersund"), "651012-8245", 39);
    Person p4(Name("Beata", "Bertilsson"), Address("Esplanaden 5", "83132", "Östersund"), "610721-8216", 38);
    Person p5(Name("Bo", "Caligula"), Address("Torget 10", "531 42", "Landvetter"), "610721-8216", 38);

    // Lägg till testpersoner
    plist.addPerson(p1);
    plist.addPerson(p2);
    plist.addPerson(p3);
    plist.addPerson(p4);
    plist.addPerson(p5);

    // Lagra menyvalet
    int menu_choice;

    do
    {
        // Visa huvudmenyn
        showMenu();
        // Hämta menyvalet
        menu_choice = menuChoice();

        // Hantera huvudmenyns olika val
        switch(menu_choice)
        {
            case 1:
                // Lägg till person
                addPerson(plist);
                break;
            case 2:
                // Skriv ut listan till skärm
                printList(plist);
                break;
            case 3:
                saveToFile(plist);
                break;
            case 4:
                readFromFile(plist);
                break;
            case 5:
                sortName(plist);
                break;
            case 6:
                sortPersnr(plist);
                break;
            case 7:
                sortShoenr(plist);
                break;
            case 8:
                // Avsluta program
                cout << "Avslutar program..." << endl;
                return 0;
            default:
                // Bör inte hända, skriver felmeddelande
                invalidChoice();
        }
        // Upprepa så länge menyvalet inte är 3
    }while(menu_choice != 8);

    return 0;
}
