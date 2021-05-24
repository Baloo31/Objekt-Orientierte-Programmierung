#include "KundeRepository.h"
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace kundeRepository;

/*
Defaultcontructor
*/
KundeRepository::KundeRepository() {
	this->autos = {};
	this->favoriten = {};
	this->kunde = Kunde();
}

/*
Constructor
*/
KundeRepository::KundeRepository(const Kunde& _kunde) {
	this->autos = {};
	this->favoriten = {};
	this->kunde = _kunde;
}


/*
Copyconstructor
*/
KundeRepository::KundeRepository(const KundeRepository& other) {
	this->autos = other.autos;
	this->favoriten = other.favoriten;
	this->kunde = other.kunde;
}

vector<Auto> KundeRepository::getAutos() const {
	return this->autos;
}

void KundeRepository::setAutos(const vector<Auto>& _autos) {
	this->autos = _autos;
}

/*
Ergibt die Position eines Autos in der Liste (-1 falls dieses Auto nicht existiert)
*/
int KundeRepository::suche(const Auto& carToSearch) {
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
Fugt ein Auto in die Liste von Autos hinzu
*/
bool KundeRepository::fugeEin(const Auto& carToAdd) {
	cout << "Nur Managers durfen Autos einfugen!\n";
	return false;
}


/*
Loscht ein Auto aus der Liste von Autos
*/
bool KundeRepository::losche(const Auto& carToDelete) {
	cout << "Nur Managers durfen Autos loschen!\n";
	return false;
}


/*
Aktualisiert ein Auto aus der Liste von Autos
*/
bool KundeRepository::aktualisiere(const Auto& carToUpdate) {
	cout << "Nur Managers durfen Autos aktualisieren!\n";
	return false;
}

/*
Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
*/
bool KundeRepository::sucheModell(const string& modell) const {
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
bool KundeRepository::sucheMarke(const string& marke) const {
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
bool KundeRepository::filterAlter(const int& alter) const {
	int idx = 0; bool show = false;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_erstzulassungsjahr() > alter) {
			cout << this->autos[idx].get_id() << " - "<< this->autos[idx].get_modell() << " - "
				<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsjahr()
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
bool KundeRepository::filterKilometer(const int& kilometer) const {
	int idx = 0; bool show = false;
	while (idx < this->autos.size()) {
		if (this->autos[idx].get_kilometer() < kilometer) {
			cout << this->autos[idx].get_id() << " - " << this->autos[idx].get_modell() << " - "
				<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsjahr()
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
bool KundeRepository::fugeZurFavoritenEin(const Auto& carToAdd) {
	int idx = this->suche(carToAdd);
	if (idx != -1) {
		this->favoriten.push_back(this->autos[idx]);
		return true;
	}
	return false;
}

/*
Zeigt die Liste von Lieblingsautos (In Fall einer Kunde)
*/
bool KundeRepository::zeigeFavoriten() const {
	int idx = 1; bool show = false;
	cout << this->kunde.get_name() << "\n";
	while (idx <= this->favoriten.size()) {
		cout << "Favorite" << idx << ": " << this->favoriten[idx - 1].get_modell() << " - " << this->favoriten[idx - 1].get_marke()
			<< " - " << this->favoriten[idx - 1].get_erstzulassungsjahr()
			<< " - " << this->favoriten[idx - 1].get_kilometer() << " - "
			<< this->favoriten[idx - 1].get_preis() << " - " << this->favoriten[idx - 1].get_leistung() << " - " << this->favoriten[idx - 1].get_treibstoff() << "\n";
		idx += 1;
		show = true;
	}
	if (!show) {
		cout << "Die Liste von Lieblingsautos ist leer!\n";
	}
	return true;
}

void KundeRepository::operator=(const KundeRepository& other) {
	this->autos = other.autos;
	this->favoriten = other.favoriten;
	this->kunde = other.kunde;
}

/*
Zeigt alle Autos aus der Liste sortiert steigend nach Preis
*/
void KundeRepository::zeigeNachPreisSortiert() {
	vector<Auto> new_vec = this->autos;
	sort(this->autos.begin(), this->autos.end(), [](Auto elem1, Auto elem2) { return (elem1.get_preis() < elem2.get_preis()); });
	int idx = 0;
	while (idx < this->autos.size()) {
		cout << this->autos[idx].get_modell() << " - "
			<< this->autos[idx].get_marke() << " - " << this->autos[idx].get_erstzulassungsjahr()
			<< " - " << this->autos[idx].get_kilometer() << " - " << this->autos[idx].get_preis() << " - " << this->autos[idx].get_leistung()
			<< " - " << this->autos[idx].get_treibstoff() << "\n";
		idx += 1;
	}
}


void KundeRepository::leseAusDateien() {
	ifstream datei;
	// Offnen der Datei mit Autos
	datei.open("daten.txt");
	string erstes_feld;
	string zweites_feld;
	string drittes_feld;
	string viertes_feld;
	string funftes_feld;
	string sechstes_feld;
	string siebtes_feld;

	// Lesen der Autos aus der Datei
	while (getline(datei, erstes_feld, ',')) {
		getline(datei, zweites_feld, ',');
		getline(datei, drittes_feld, ',');
		int kilometer = stoi(drittes_feld);
		getline(datei, viertes_feld, ',');
		int erstzulassungsjahr = stoi(viertes_feld);
		getline(datei, funftes_feld, ',');
		double preis = stod(funftes_feld);
		getline(datei, sechstes_feld, ',');
		int leistung = stoi(sechstes_feld);
		getline(datei, siebtes_feld, '\n');
		this->autos.push_back(Auto(erstes_feld, zweites_feld, kilometer, erstzulassungsjahr, preis, leistung, siebtes_feld));
	}

	// Schliessen der Datei
	datei.close();

	ifstream datei2;
	// Offnen der Datei mit Lieblingsautos jeder Kunde
	datei2.open("favoriten.txt");
	string feld_name;
	string erstes_feld2;
	string zweites_feld2;
	string drittes_feld2;
	string viertes_feld2;
	string funftes_feld2;
	string sechstes_feld2;
	string siebtes_feld2;
	bool gefunden = false;
	string ende;
	string out;

	// Lesen aus der Datei
	while (getline(datei2, feld_name, ';')) {
		if (feld_name == this->kunde.get_name()) {
			while (getline(datei2, erstes_feld2, ',')) {
				if (erstes_feld2 == "!") break;
				getline(datei2, zweites_feld2, ',');
				getline(datei2, drittes_feld2, ',');
				int kilometer2 = stoi(drittes_feld2);
				getline(datei2, viertes_feld2, ',');
				int erstzulassungsjahr2 = stoi(viertes_feld2);
				getline(datei2, funftes_feld2, ',');
				double preis2 = stod(funftes_feld2);
				getline(datei2, sechstes_feld2, ',');
				int leistung2 = stoi(sechstes_feld2);
				getline(datei2, siebtes_feld2, ';');
				this->favoriten.push_back(Auto(erstes_feld2, zweites_feld2, kilometer2, erstzulassungsjahr2, preis2, leistung2, siebtes_feld2));
				getline(datei2, out, ';');
				if (out == "-") break;
			}
			gefunden = true;
		}
		if (gefunden) break;
		getline(datei2, ende, '\n');
	}
	// Schliessen der Datei
	datei2.close();
}


void KundeRepository::schreibeInDateien() {
	// Offnen der Datei mit Autos
	ofstream datei("daten.txt");
	// Schreiben in der Datei
	for (int idx = 0; idx < this->autos.size(); idx++) {
		datei << this->autos[idx].get_modell() << "," << this->autos[idx].get_marke() << "," << this->autos[idx].get_erstzulassungsjahr() << ","
			<< this->autos[idx].get_kilometer() << ","
			<< this->autos[idx].get_preis() << "," << this->autos[idx].get_leistung() << "," << this->autos[idx].get_treibstoff() << "\n";
	}
	// Schliessen der Datei
	datei.close();

	ifstream datei2;
	// Offnen der Datei mit Lieblingsautos
	datei2.open("favoriten.txt");
	vector<string> namen;
	vector<string> rest;
	string feld_name;
	string ende;

	// Lesen aus der Datei
	while (getline(datei2, feld_name, ';')) {
		namen.push_back(feld_name);
		getline(datei2, ende, '\n');
		rest.push_back(ende);
	}
	// Schliessen der Datei
	datei2.close();

	// Offnen der Datei mit Lieblingsautos
	ofstream daten("favoriten.txt");
	bool gefunden = false;
	// Schreiben in Datei
	for (int idx = 0; idx < namen.size(); idx++) {
		if (namen[idx] == kunde.get_name()) {
			daten << namen[idx] << ";";
			if (this->favoriten.size() == 0) daten << "!,\n";
			for (int idx = 0; idx < this->favoriten.size(); idx++) {
				daten << this->favoriten[idx].get_modell() << "," << this->favoriten[idx].get_marke() << ","
					<< this->favoriten[idx].get_erstzulassungsjahr() << "," << this->favoriten[idx].get_kilometer() << ","
					<< this->favoriten[idx].get_preis() << "," << this->favoriten[idx].get_leistung() << "," << this->favoriten[idx].get_treibstoff() << ";";
				if (idx == this->favoriten.size() - 1) daten << "-;\n";
				else daten << "+;";
			}
			gefunden = true;
		}
		else {
			daten << namen[idx] << ";" << rest[idx] << "\n";
		}
	}
	if (!gefunden) {
		daten << kunde.get_name() << ";";
		if (this->favoriten.size() == 0) daten << "!,\n";
		for (int idx = 0; idx < this->favoriten.size(); idx++) {
			daten << this->favoriten[idx].get_modell() << "," << this->favoriten[idx].get_marke() << ","
				<< this->favoriten[idx].get_erstzulassungsjahr() << "," << this->favoriten[idx].get_kilometer() << ","
				<< this->favoriten[idx].get_preis() << "," << this->favoriten[idx].get_leistung() << "," << this->favoriten[idx].get_treibstoff() << ";";
			if (idx == this->favoriten.size() - 1) daten << "-;\n";
			else daten << "+;";
		}
	}
	// Schliessen der Datei
	datei.close();
}

/*
Destructor
*/
KundeRepository::~KundeRepository() {
}