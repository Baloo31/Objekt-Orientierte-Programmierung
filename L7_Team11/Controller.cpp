#include "Controller.h"
#include <iostream>
using namespace controller;


Controller* Controller::instance = nullptr;

Controller* Controller::getInstance(bool manager, string username){
    if (!instance){
        instance = new Controller(manager, username);
        return instance;
    } else throw exception();
}

Controller::Controller() {
    this->repo = make_shared<KundeRepository>();
}

Controller::Controller(bool manager, string username) {
    if (manager) {
        this->repo = make_shared<ManagerRepository>();
    }
    else {
        Kunde kunde = Kunde(username);
        this->repo = make_shared<KundeRepository>(kunde);
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

vector<Auto> Controller::zeigeFavoriten() const {
    return this->repo->zeigeFavoriten();
}

bool Controller::sucheModell(const string& modell) const {
    return this->repo->sucheModell(modell);
}

bool Controller::sucheMarke(const string& marke) const {
    return this->repo->sucheMarke(marke);
}

vector<Auto> Controller::filterAlter(const int& alter) const {
    return this->repo->filterAlter(alter);
}

vector<Auto> Controller::filterKilometer(const int& kilometer) const {
    return this->repo->filterKilometer(kilometer);
}

vector<Auto> Controller::zeigeNachPreisSortiert() {
    return this->repo->zeigeNachPreisSortiert();
}

void Controller::leseAusDateien(string dFile, string fFile) {
    this->repo->leseAusDateien(dFile, fFile);
}

void Controller::schreibeInDateien(string dFile, string fFile) {
    this->repo->schreibeInDateien(dFile, fFile);
}

Controller::~Controller() {
    delete this->instance;
}
