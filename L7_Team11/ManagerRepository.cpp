#include "ManagerRepository.h"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace managerRepository;

/*
Defaultconstructor
*/
ManagerRepository::ManagerRepository() {
    this->autos = {};
}


/*
Copyconstructor
*/
ManagerRepository::ManagerRepository(const ManagerRepository& other) {
    this->autos = other.autos;
}

vector<Auto> ManagerRepository::getAutos() const {
    return this->autos;
}

void ManagerRepository::setAutos(const vector<Auto>& _autos) {
    this->autos = _autos;
}

/*
Ergibt die Position eines Autos in der Liste (-1 falls dieses Auto nicht existiert)
*/
int ManagerRepository::suche(const Auto& carToSearch) {
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
bool ManagerRepository::fugeEin(const Auto& carToAdd) {
    this->autos.push_back(carToAdd);
    return true;
}


/*
Loscht ein Auto aus der Liste von Autos
*/
bool ManagerRepository::losche(const Auto& carToDelete) {
    int idx = this->suche(carToDelete);
    if (idx != -1) {
        this->autos.erase(this->autos.begin() + idx);
        return true;
    }
    return false;
}


/*
Aktualisiert ein Auto aus der Liste von Autos
*/
bool ManagerRepository::aktualisiere(const Auto& carToUpdate) {
    int idx = this->suche(carToUpdate);
    if (idx != -1) {
        this->autos[idx].set_preis(carToUpdate.get_preis());
        this->autos[idx].set_leistung(carToUpdate.get_leistung());
        this->autos[idx].set_kilometer(carToUpdate.get_kilometer());
        return true;
    }
    return false;
}

/*
Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
*/
bool ManagerRepository::sucheModell(const string& modell) const {
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
bool ManagerRepository::sucheMarke(const string& marke) const {
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
vector<Auto> ManagerRepository::filterAlter(const int& alter) const {
    int idx = 0;
    vector<Auto> output = {};
    while (idx < this->autos.size()) {
        if (this->autos[idx].get_erstzulassungsjahr() > alter) {
            output.push_back(this->autos[idx]);
        }
        idx += 1;
    }
    return output;
}

/*
Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
*/
vector<Auto> ManagerRepository::filterKilometer(const int& kilometer) const {
    int idx = 0;
    vector<Auto> output = {};
    while (idx < this->autos.size()) {
        if (this->autos[idx].get_kilometer() < kilometer) {
            output.push_back(this->autos[idx]);
        }
        idx += 1;
    }
    return output;
}

/*
Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu (In Fall einer Kunde)
*/
bool ManagerRepository::fugeZurFavoritenEin(const Auto& carToAdd) {
    return false;
}

/*
Zeigt die Liste von Lieblingsautos (In Fall einer Kunde)
*/
vector<Auto> ManagerRepository::zeigeFavoriten() const {
    vector<Auto> out = {};
    return out;
}

void ManagerRepository::operator=(const ManagerRepository& other) {
    this->autos = other.autos;
}

/*
Zeigt alle Autos aus der Liste sortiert steigend nach Preis
*/
vector<Auto> ManagerRepository::zeigeNachPreisSortiert() {
    sort(this->autos.begin(), this->autos.end(), [](Auto elem1, Auto elem2) { return (elem1.get_preis() < elem2.get_preis()); });
    return this->autos;
}

void ManagerRepository::leseAusDateien(string dFile, string fFile) {
    ifstream datei;
    datei.open(dFile);
    string erstes_feld;
    string zweites_feld;
    string drittes_feld;
    string viertes_feld;
    string funftes_feld;
    string sechstes_feld;
    string siebtes_feld;

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
    datei.close();
}


void ManagerRepository::schreibeInDateien(string dFile, string fFile) {
    ofstream datei(dFile);
    for (int idx = 0; idx < this->autos.size(); idx++) {
        datei << this->autos[idx].get_modell() << "," << this->autos[idx].get_marke() << "," << this->autos[idx].get_erstzulassungsjahr() << ","
            << this->autos[idx].get_kilometer() << ","
            << this->autos[idx].get_preis() << "," << this->autos[idx].get_leistung() << "," << this->autos[idx].get_treibstoff() << "\n";
    }
    datei.close();
}

/*
Destructor
*/
ManagerRepository::~ManagerRepository() {
}
