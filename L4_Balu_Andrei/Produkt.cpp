#include "Produkt.h"
using namespace produkt;

/*
Constructor
*/
Produkt::Produkt(string name, string herkunft, int menge, int preis, Datum haltbarkeitsdatum) {
    if (menge > 0 && preis > 0) {
        this->name = name;
        this->herkunft = herkunft;
        this->haltbarkeitsdatum = haltbarkeitsdatum;
        this->menge = menge;
        this->preis = preis;
    }
    else throw exception();
}

/*
Copyconstructor
*/
Produkt::Produkt(const Produkt& other) {
    this->name = other.getName();
    this->herkunft = other.getHerkunft();
    this->haltbarkeitsdatum = other.getHaltbarkeitsdatum();
    this->menge = other.getMenge();
    this->preis = other.getPreis();
}



/*
Getters & setters
*/
string Produkt::getName() const {
    return this->name;
}

string Produkt::getHerkunft() const {
    return this->herkunft;
}

Datum Produkt::getHaltbarkeitsdatum() const {
    return this->haltbarkeitsdatum;
}

int Produkt::getMenge() const {
    return this->menge;
}

int Produkt::getPreis() const {
    return this->preis;
}

void Produkt::setName(string name) {
    this->name = name;
}

void Produkt::setHerkunft(string herkunft) {
    this->herkunft = herkunft;
}

void Produkt::setHaltbarkeitsdatum(Datum haltbarkeitsdatum) {
    this->haltbarkeitsdatum = haltbarkeitsdatum;
}

void Produkt::setMenge(int menge) {
    if (menge > 0) {
        this->menge = menge;
    }
    else {
        throw exception();
    }
}

void Produkt::setPreis(int preis) {
    if (preis > 0) {
        this->preis = preis;
    }
    else {
        throw exception();
    }
}

bool const Produkt::operator==(const Produkt& other) {
    if (this->getHaltbarkeitsdatum() == other.getHaltbarkeitsdatum() && this->getHerkunft() == other.getHerkunft() && this->getName() == other.getName()) {
        return true;
    }
    return false;
}

/*
Destructor
*/
Produkt::~Produkt(){
}