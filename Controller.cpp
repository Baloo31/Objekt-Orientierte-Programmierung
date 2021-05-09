#include "Controller.h"
#include "ManagerRepository.h"
#include "ClientRepository.h"
using namespace controller;
using namespace managerRepository;
using namespace clientRepository;

Controller::Controller() {
	this->repo = make_shared<ClientRepository>();
}

Controller::Controller(bool manager) {
	if (manager) {
		this->repo = make_shared<ManagerRepository>();
	}
	else {
		this->repo = make_shared<ClientRepository>();
	}
}

void Controller::setAutos(const vector<Auto>& autos) {
	this->repo->setAutos(autos);
}

bool Controller::einfugen(const Auto& carToAdd) {
	return this->repo->einfugen(carToAdd);
}

bool Controller::loschen(const Auto& carToDelete) {
	return this->repo->loschen(carToDelete);
}

bool Controller::update(const Auto& carToUpdate) {
	return this->repo->update(carToUpdate);
}

bool Controller::addToFavoriten(const Auto& carToAdd) {
	return this->repo->addToFavoriten(carToAdd);
}

bool Controller::showFavoriten() const {
	return this->repo->showFavoriten();
}

bool Controller::searchModell(const string& modell) const {
	return this->repo->searchModell(modell);
}

bool Controller::searchMarke(const string& marke) const {
	return this->repo->searchMarke(marke);
}

bool Controller::filterAlter(const Datum& alter) const {
	return this->repo->filterAlter(alter);
}

bool Controller::filterKilometer(const int& kilometer) const {
	return this->repo->filterKilometer(kilometer);
}

void Controller::showPriceSorted() {
	this->repo->showPriceSorted();
}

Controller::~Controller() {
}