#include "Repository.h"
#include <iostream>
#include <Algorithm>
using namespace repository;

/*
Defaultconstructor
*/
Repository::Repository() {
	this->autos = {};
}

/*
Copyconstructor
*/
Repository::Repository(const Repository& other) {
	this->autos = other.autos;
}

/*
Getter
*/
vector<Auto> Repository::getAutos()const {
	return this->autos;
}

/*
Ergibt die Position eines Autos in der Liste (-1 falls dieses Auto nicht existiert)
*/
int Repository::suchen(const Auto& carToSearch) {
	int gef = -1;
	int idx = 0;
	while (idx < this->autos.size() && gef == -1) {
		if (this->autos[idx] == carToSearch) {
			gef = idx;
		}
		idx += 1;
	}
	return gef;
}

/*
Setter
*/
void Repository::setAutos(vector<Auto> autos) {
	this->autos = autos;
}

/*
Fugt ein Auto in die Liste von Autos hinzu (In Fall einer Manager)
*/
bool Repository::einfugen(const Auto& carToAdd) {
	cout << "Nur Managers durfen Autos einfugen!\n";
	return false;
}

/*
Loscht ein Auto aus der Liste von Autos (In Fall einer Manager)
*/
bool Repository::loschen(const Auto& carToAdd) {
	cout << "Nur Managers durfen Autos loschen!\n";
	return false;
}

/*
Aktualisiert ein Auto aus der Liste von Autos
*/
bool Repository::update(const Auto& carToAdd) {
	cout << "Nur Managers durfen Autos aktualisieren!\n";
	return false;
}

/*
Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
*/
bool Repository::searchModell(const string& modell) const {
	int idx = 0;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_modell() == modell) {
			return true;
		}
		idx += 1;
	}
	return false;
}

/*
Bestimmt ob eine gegebene Marke eines Autos in die Liste von Autos existiert
*/
bool Repository::searchMarke(const string& marke) const {
	int idx = 0;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_marke() == marke) {
			return true;
		}
		idx += 1;
	}
	return false;
}

/*
Zeigt alle Autos deren Datum neuer als eine angegebene Datum sind
*/
bool Repository::filterAlter(const Datum& alter) const {
	int idx = 0; bool show = false;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_erstzulassungsdatum() > alter) {
			cout << this->autos[idx].get_modell() << " - "
				<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsdatum().getTag()
				<< "/" << this->autos[idx].get_erstzulassungsdatum().getMonat() << "/" << this->autos[idx].get_erstzulassungsdatum().getJahr()
				<< " - " << this->autos[idx].get_kilometer() << " - " << this->autos[idx].get_preis() << " - " << this->autos[idx].get_leistung()
				<< " - " << this->autos[idx].get_treibstoff() << "\n";
			show = true;
		}
		idx += 1;
	}
	if (!show) {
		cout << "Die Liste enthalt keine Autos neuer als die angegebene Datum\n";
	}
	return show;
}

/*
Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
*/
bool Repository::filterKilometer(const int& kilometer) const {
	int idx = 0; bool show = false;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_kilometer() < kilometer) {
			cout << this->autos[idx].get_modell() << " - " 
				<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsdatum().getTag() 
				<< "/" << this->autos[idx].get_erstzulassungsdatum().getMonat() << "/" << this->autos[idx].get_erstzulassungsdatum().getJahr() 
				<< " - " << this->autos[idx].get_kilometer() << " - " << this->autos[idx].get_preis() << " - " << this->autos[idx].get_leistung() 
				<< " - " << this->autos[idx].get_treibstoff() << "\n";
			show = true;
		}
		idx += 1;
	}
	if (!show) {
		cout << "Die Liste enthalt keine Autos mit weniger Kilometer als die angegebenen Kilometer\n";
	}
	return show;
}

/*
Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu (In Fall einer Kunde)
*/
bool Repository::addToFavoriten(const Auto& carToAdd) {
	return false;
}

/*
Zeigt die Liste von Lieblingsautos (In Fall einer Kunde)
*/
bool Repository::showFavoriten() const {
	return false;
}

void Repository::operator=(const Repository& other) {
	this->autos = other.autos;
}

/*
Zeigt alle Autos aus der Liste sortiert steigend nach Preis
*/
void Repository::showPriceSorted() {
	vector<Auto> new_vec = this->autos;
	sort(this->autos.begin(), this->autos.end(), [](Auto elem1, Auto elem2) { return (elem1.get_preis() < elem2.get_preis()); });
	int idx = 0;
	while (idx < this->autos.size()) {
		cout << this->autos[idx].get_modell() << " - "
			<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsdatum().getTag()
			<< "/" << this->autos[idx].get_erstzulassungsdatum().getMonat() << "/" << this->autos[idx].get_erstzulassungsdatum().getJahr()
			<< " - " << this->autos[idx].get_kilometer() << " - " << this->autos[idx].get_preis() << " - " << this->autos[idx].get_leistung()
			<< " - " << this->autos[idx].get_treibstoff() << "\n";
		idx += 1;
	}
}

/*
Destructor
*/
Repository::~Repository() {
}