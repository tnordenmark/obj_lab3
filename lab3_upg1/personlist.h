#ifndef PERSONLIST_H
#define PERSONLIST_H
#include <vector>
#include <string>
#include <iostream>
#include "person.h"
#include "func.h"

class PersonList
{
    private:
        // Medlemsattribut
        std::vector<Person> pvec;
        std::string fileName;
    public:
        // Standardkonstruktor
        PersonList();
        // Överlagrad konstruktor
        PersonList(std::vector<Person> v, std::string f);

        // Setters
        void setFileName(std::string f);

        // Getters
        std::string getFileName()const {return fileName;}

        //Medlemsfunktioner
        void addPerson(Person &p);
        Person getPerson(int idx);
        int nrOfPersons()const;
        void sortName();
        void sortPersnr();
        void sortShoenr();
        void readFromFile();
        void writeToFile();
        void printList();
};

#endif // PERSONLIST_H
