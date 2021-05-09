#include "Auto.h"
#include <exception>

using namespace autos;

/*
Constructor
*/
Auto::Auto(string modell, string marke, Datum erstzulassungsdatum, int kilometer, double preis, int leistung, string treibstoff) {
	if (kilometer < 0 || preis < 300 || leistung < 10) {
		throw exception();
	}
	this->modell = modell;
	this->marke = marke;
	this->erstzulassungsdatum = erstzulassungsdatum;
	this->kilometer = kilometer;
	this->preis = preis;
	this->leistung = leistung;
	this->treibstoff = treibstoff;
}


/*
Copyconstructor
*/
Auto::Auto(const Auto& other) {
	this->modell = other.modell;
	this->marke = other.marke;
	this->erstzulassungsdatum = other.erstzulassungsdatum;
	this->kilometer = other.kilometer;
	this->preis = other.preis;
	this->leistung = other.leistung;
	this->treibstoff = other.treibstoff;
}


/*
Getters & Setters
*/
string Auto::get_modell() const {
	return this->modell;
}

string Auto::get_marke() const {
	return this->marke;
}

Datum Auto::get_erstzulassungsdatum() const {
	return this->erstzulassungsdatum;
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

void Auto::set_erstzulassungsdatum(Datum erstzulassungsdatum) {
	this->erstzulassungsdatum = erstzulassungsdatum;
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
bool const Auto::operator==(const Auto& other) {
	if ((this->get_marke() == other.get_marke()) && (this->get_modell() == other.get_modell()) && (this->get_erstzulassungsdatum() == other.get_erstzulassungsdatum()) && (this->get_treibstoff() == other.get_treibstoff())) {
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