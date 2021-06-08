#include "Auto.h"
#include <exception>

using namespace autos;

int Auto::nrOfInstances = 0;

/*
Constructor
*/
Auto::Auto(string modell, string marke, int erstzulassungsjahr, int kilometer, double preis, int leistung, string treibstoff) {
    if (kilometer < 0 || preis < 300 || leistung < 10 || erstzulassungsjahr < 1800) {
        throw exception();
    }
    this->modell = modell;
    this->marke = marke;
    this->erstzulassungsjahr = erstzulassungsjahr;
    this->kilometer = kilometer;
    this->preis = preis;
    this->leistung = leistung;
    this->treibstoff = treibstoff;
    this->id = nrOfInstances;
    nrOfInstances++;
}


/*
Copyconstructor
*/
Auto::Auto(const Auto& other) {
    this->modell = other.modell;
    this->marke = other.marke;
    this->erstzulassungsjahr = other.erstzulassungsjahr;
    this->kilometer = other.kilometer;
    this->preis = other.preis;
    this->leistung = other.leistung;
    this->treibstoff = other.treibstoff;
    this->id = other.id;
}


/*
Getters & Setters
*/
int Auto::get_id() const {
    return this->id;
}

string Auto::get_modell() const {
    return this->modell;
}

string Auto::get_marke() const {
    return this->marke;
}

int Auto::get_erstzulassungsjahr() const {
    return this->erstzulassungsjahr;
}

int Auto::get_kilometer() const {
    return this->kilometer;
}

double Auto::get_preis() const {
    return this->preis;
}

int Auto::get_leistung() const {
    return this->leistung;
}

string Auto::get_treibstoff() const {
    return this->treibstoff;
}

void Auto::set_modell(string modell) {
    this->modell = modell;
}

void Auto::set_marke(string marke) {
    this->marke = marke;
}

void Auto::set_erstzulassungsjahr(int erstzulassungsjahr) {
    if (erstzulassungsjahr > 1800) {
        this->erstzulassungsjahr = erstzulassungsjahr;
    }
    else {
        throw exception();
    }
}

void Auto::set_kilometer(int kilometer) {
    if (kilometer < 0) {
        throw exception();
    }
    else {
        this->kilometer = kilometer;
    }
}

void Auto::set_preis(double preis) {
    if (preis < 300) {
        throw exception();
    }
    else {
        this->preis = preis;
    }
}

void Auto::set_leistung(int leistung) {
    if (leistung < 10) {
        throw exception();
    }
    else {
        this->leistung = leistung;
    }
}

void Auto::set_treibstoff(string treibstoff) {
    this->treibstoff = treibstoff;
}


/*
Bestimmt wenn zwei Autos gleich sind
*/
bool Auto::operator==(const Auto& other) {
    if ((this->get_marke() == other.get_marke()) && (this->get_modell() == other.get_modell()) && (this->get_erstzulassungsjahr() == other.get_erstzulassungsjahr()) && (this->get_treibstoff() == other.get_treibstoff())) {
        return true;
    }
    else {
        return false;
    }
}

/*
Destructor
*/
Auto::~Auto() {
}
