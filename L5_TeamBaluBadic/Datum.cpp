#include "Datum.h"
#include <exception>
using namespace datum;
using namespace std;

/*
Constructor
*/
Datum::Datum(int tag, int monat, int jahr) {
    // Man Uberpruft ob die Jahr gultig ist
    if (jahr < 1000)
        throw exception();
    this->jahr = jahr;

    // Man Uberpruft ob die Monat gultig ist
    if (monat < 1 || monat > 12)
        throw exception();
    this->monat = monat;

    // Man Uberpruft ob die Tag gultig ist
    if (tag < 1 || tag > 31)
        throw exception();
    if (monat == 2 && tag > 28)
        throw exception();
    if ((monat == 4 || monat == 6 || monat == 9 || monat == 11) && tag > 30)
        throw exception();
    this->tag = tag;
}

/*
Copyconstructor
*/
Datum::Datum(const Datum& other) {
    this->jahr = other.getJahr();
    this->monat = other.getMonat();
    this->tag = other.getTag();
}

/*
Defaultconstructor
*/
Datum::Datum() {
    this->jahr = 1;
    this->monat = 1;
    this->tag = 1;
}



/*
Getters & setters
*/
int Datum::getJahr() const {
    return this->jahr;
}

int Datum::getMonat() const {
    return this->monat;
}

int Datum::getTag() const {
    return this->tag;
}

void Datum::setMonat(int monat) {
    if (monat < 1 || monat > 12)
        throw exception();
    this->monat = monat;
}

void Datum::setJahr(int jahr) {
    if (jahr < 0)
        throw exception();
    this->jahr = jahr;
}

void Datum::setTag(int tag) {
    if (tag < 1 || tag > 31)
        throw exception();
    if (monat == 2 && tag > 28)
        throw exception();
    if (monat == 4 || monat == 6 || monat == 9 || monat == 11 && tag > 30)
        throw exception();
    this->tag = tag;
}

bool const Datum::operator==(const Datum& other) {
    if ((this->getTag() == other.getTag()) && (this->getMonat() == other.getMonat()) && (this->getJahr() == other.getJahr())) {
        return true;
    }
    return false;
}

bool const Datum::operator<(const Datum& other) {
    if (this->getJahr() < other.getJahr()) {
        return true;
    }
    else if (this->getJahr() > other.getJahr()) {
        return false;
    }
    else if (this->getMonat() < other.getMonat()) {
        return true;
    }
    else if (this->getMonat() > other.getMonat()) {
        return false;
    }
    else if (this->getTag() < other.getTag()) {
        return true;
    }
    else if (this->getTag() > other.getTag()) {
        return false;
    }
    return false;
}

bool const Datum::operator>(const Datum& other) {
    if (this->getJahr() > other.getJahr()) {
        return true;
    }
    else if (this->getJahr() < other.getJahr()) {
        return false;
    }
    else if (this->getMonat() > other.getMonat()) {
        return true;
    }
    else if (this->getMonat() < other.getMonat()) {
        return false;
    }
    else if (this->getTag() > other.getTag()) {
        return true;
    }
    else if (this->getTag() < other.getTag()) {
        return false;
    }
    return false;
}

/*
Destructor
*/
Datum::~Datum() {
}
