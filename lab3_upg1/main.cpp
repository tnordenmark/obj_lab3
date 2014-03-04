// main.cpp
// Program för att hantera en personlista enligt objektorienterade principer
//
// Thomas Nordenmark 2014-02-11
//---------------------------------------------------------------------------
#include "userinterface.h"
using namespace std;

int main()
{
    // Skapa ett userinterface-objekt
    UserInterface ui;
    // Kör huvudfunktionen på objektet
    ui.run();

    return 0;
}
