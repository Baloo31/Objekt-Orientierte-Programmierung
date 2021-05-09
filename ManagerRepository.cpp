#include "ManagerRepository.h"
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


/*
Fugt ein Auto in die Liste von Autos hinzu
*/
bool ManagerRepository::einfugen(const Auto& carToAdd) {
	this->autos.push_back(carToAdd);
	return true;
}


/*
Loscht ein Auto aus der Liste von Autos
*/
bool ManagerRepository::loschen(const Auto& carToDelete) {
	int idx = this->suchen(carToDelete);
	if (idx != -1) {
		this->autos.erase(this->autos.begin() + idx);
		return true;
	}
	return false;
}


/*
Aktualisiert ein Auto aus der Liste von Autos
*/
bool ManagerRepository::update(const Auto& carToUpdate) {
	int idx = this->suchen(carToUpdate);
	if (idx != -1) {
		this->autos[idx].set_preis(carToUpdate.get_preis());
		this->autos[idx].set_leistung(carToUpdate.get_leistung());
		this->autos[idx].set_kilometer(carToUpdate.get_kilometer());
		return true;
	}
	return false;
}


/*
Destructor
*/
ManagerRepository::~ManagerRepository() {
}