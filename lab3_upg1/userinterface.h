#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "personlist.h"

class UserInterface
{
    private:
        PersonList plist;
        void showMenu();
        int menuChoice();
        void addPerson(PersonList &plist);
        void printList(PersonList &plist);
        void saveToFile(PersonList &plist);
        void readFromFile(PersonList &plist);
        void sortName(PersonList &plist);
        void sortPersnr(PersonList &plist);
        void sortShoenr(PersonList &plist);
    public:
        // Standardkonstruktor
        UserInterface();
        // Huvudfunktion som kör hela programmet
        int run();
};

#endif // USERINTERFACE_H
