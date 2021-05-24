#include "Controller.h"
#include <iostream>
using namespace controller;

Controller::Controller() {
	this->repo = make_shared<KundeRepository>();
}

Controller::Controller(bool manager) {
	if (manager) {
		this->repo = make_shared<ManagerRepository>();
	}
	else {
		system("CLS");
		cout << "-------------------------------------------------------------------------------\n";
		string name;
		cout << "Name des Kundes: "; cin >> name;
		Kunde kunde = Kunde(name);
		this->repo = make_shared<KundeRepository>(kunde);
		system("pause");
	}
}

bool Controller::fugeEin(const Auto& autoFurEinfugen) {
	return this->repo->fugeEin(autoFurEinfugen);
}

bool Controller::losche(const Auto& autoFurLoschen) {
	return this->repo->losche(autoFurLoschen);
}

bool Controller::aktualisiere(const Auto& autoFurAktualisieren) {
	return this->repo->aktualisiere(autoFurAktualisieren);
}

bool Controller::fugeZurFavoritenEin(const Auto& autoFurEinfugen) {
	return this->repo->fugeZurFavoritenEin(autoFurEinfugen);
}

bool Controller::zeigeFavoriten() const {
	return this->repo->zeigeFavoriten();
}

bool Controller::sucheModell(const string& modell) const {
	return this->repo->sucheModell(modell);
}

bool Controller::sucheMarke(const string& marke) const {
	return this->repo->sucheMarke(marke);
}

bool Controller::filterAlter(const int& alter) const {
	return this->repo->filterAlter(alter);
}

bool Controller::filterKilometer(const int& kilometer) const {
	return this->repo->filterKilometer(kilometer);
}

void Controller::zeigeNachPreisSortiert() {
	this->repo->zeigeNachPreisSortiert();
}

void Controller::leseAusDateien() {
	this->repo->leseAusDateien();
}

void Controller::schreibeInDateien() {
	this->repo->schreibeInDateien();
}

Controller::~Controller() {
}