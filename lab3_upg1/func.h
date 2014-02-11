#ifndef FUNC_H
#define FUNC_H
#include "person.h"

void invalidChoice();
bool sortPnr(const Person &p1, const Person &p2);
bool sortSnr(const Person &p1, const Person &p2);
bool sortFnLn(const Person &p1, const Person &p2);
void printPerson(Person const &p);

#endif // FUNC_H
