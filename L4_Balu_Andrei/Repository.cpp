#include "Repository.h"
#include <Algorithm>
using namespace repository;


/*
Constructor
*/
Repository::Repository() {
	this->produkte = {};
}


/*
Constructor
*/
Repository::Repository(const vector<Produkt>& produkte) {
	this->produkte = produkte;
}


/*
Copyconstructor
*/
Repository::Repository(const Repository& other) {
	this->produkte = other.produkte;
}


/*
Getter fur die Liste von Produkte
*/
vector<Produkt> Repository::getProdukte() const {
	return this->produkte;
}


/*
Fugt ein Produkt zur Repository ein
Falls dieser Produkt schon existiert, wird nur die neue Menge zur Menge addiert
Sonst wird er direkt eingefugt
*/
void Repository::einfugen(const Produkt& newProdukt) {
	bool found = false;
	for (int index = 0; index < this->produkte.size(); index++) {
		if (this->produkte[index] == newProdukt) {
			this->produkte[index].setMenge(this->produkte[index].getMenge() + newProdukt.getMenge());
			found = true;
			break;
		}
	}
	if (!found) {
		this->produkte.push_back(newProdukt);
	}
}


/*
Loscht ein Produkt aus dem Repository
Ergibt true, falls den Produkt entfernt wurde
Ergibt falsch, falls den Produkt nicht gefunden wurde
*/
bool Repository::loschen(string name, string herkunft, Datum haltbarkeitsdatum) {
	for (int index = 0; index < this->produkte.size(); index++) {
		if (this->produkte[index].getName() == name && 
			this->produkte[index].getHerkunft() == herkunft 
			&& this->produkte[index].getHaltbarkeitsdatum() == haltbarkeitsdatum) {
			this->produkte.erase(this->produkte.begin() + index);
			return true;
		}
	}
	return false;
}


/*
Bearbeitet ein Produkt aus dem Repository
Ergibt true, falls den Produkt aktualisiert wurde
Ergibt falsch, falls den Produkt nicht gefunden wurde
*/
bool Repository::update(const Produkt& prod) {
	for (int index = 0; index < this->produkte.size(); index++) {
		if (this->produkte[index] == prod) {
			this->produkte[index].setMenge(prod.getMenge());
			this->produkte[index].setPreis(prod.getPreis());
			return true;
		}
	}
	return false;
}


/*
Zeigt alle Produkte deren Namen eine bestimmte Zeichenkette enthalten
Falls eine leere Zeichenkette gelesen wird, werden alle Produkte gezeigt
Die Produkte werden in beiden Falle alphabetishc nach der Name sortiert
*/
vector<Produkt> Repository::auflisten(string zeichenkette) {
	vector<Produkt> gesuchteProdukte = {};
	if (zeichenkette == "") {
		gesuchteProdukte = this->produkte;
		sort(gesuchteProdukte.begin(), gesuchteProdukte.end(), [](Produkt obj1, Produkt obj2) { return (obj1.getName() < obj2.getName()); });
		return gesuchteProdukte;
	}
	for (int index = 0; index < this->produkte.size(); index++){
		if (this->produkte[index].getName().find(zeichenkette) != string::npos) {
			gesuchteProdukte.push_back(this->produkte[index]);
		}
	}
	sort(gesuchteProdukte.begin(), gesuchteProdukte.end(), [](Produkt obj1, Produkt obj2) { return (obj1.getName() < obj2.getName()); });
	return gesuchteProdukte;
}


/*
Zeigt alle Produkte deren Menge kleiner als eine gegebene Menge ist
*/
vector<Produkt> Repository::zeigeKnapp(int menge) {
	vector<Produkt> gesuchteProdukte = {};
	for (int index = 0; index < this->produkte.size(); index++) {
		if (this->produkte[index].getMenge() <= menge) {
			gesuchteProdukte.push_back(this->produkte[index]);
		}
	}
	return gesuchteProdukte;
}


/*
Zeigt alle Produkte aus dem Repository
Die Produkte sind nach Haltbarkeitsdatum steigend sortiert
*/
vector<Produkt> Repository::sortDatum() {
	vector<Produkt> gesuchteProdukte = this->produkte;
	sort(gesuchteProdukte.begin(), gesuchteProdukte.end(), [](Produkt obj1, Produkt obj2) { return (obj1.getHaltbarkeitsdatum() < obj2.getHaltbarkeitsdatum()); });
	return gesuchteProdukte;
}


void Repository::operator=(const Repository& other){
	this->produkte = other.produkte;
}


/*
Destructor
*/
Repository::~Repository() {
}