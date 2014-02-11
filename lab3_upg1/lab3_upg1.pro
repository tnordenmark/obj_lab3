TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    address.cpp \
    func.cpp \
    name.cpp \
    person.cpp \
    personlist.cpp \
    userinterface.cpp

QMAKE_CXXFLAGS = -W -Wall -Wextra -pedantic -std=c++11
QMAKE_LFLAGS = -W -Wall -Wextra -pedantic -std=c++11

HEADERS += \
    address.h \
    func.h \
    name.h \
    person.h \
    personlist.h \
    userinterface.h

