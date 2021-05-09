#include "ClientRepository.h"
#include <iostream>
using namespace clientRepository;

/*
Defaultconstructor
*/
ClientRepository::ClientRepository() {
	this->autos = {};
	this->favoriten = {};
}


/*
Copyconstructor
*/
ClientRepository::ClientRepository(const ClientRepository& other) {
	this->autos = other.autos;
	this->favoriten = other.favoriten;
}


/*
Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu
*/
bool ClientRepository::addToFavoriten(const Auto& carToAdd) {
	int idx = this->suchen(carToAdd);
	if (idx != -1) {
		this->favoriten.push_back(this->autos[idx]);
		return true;
	}
	return false;
}


/*
Zeigt die Liste von Lieblingsautos
*/
bool ClientRepository::showFavoriten() const {
	int idx = 1; bool show = false;
	while (idx <= this->favoriten.size()) {
		cout << "Favorite" << idx << ": " << this->favoriten[idx - 1].get_modell() << " - " << this->favoriten[idx - 1].get_marke() 
			<< " - " << this->favoriten[idx - 1].get_erstzulassungsdatum().getTag() << "/" << this->favoriten[idx - 1].get_erstzulassungsdatum().getMonat() 
			<< "/" << this->favoriten[idx - 1].get_erstzulassungsdatum().getJahr() << " - " << this->favoriten[idx - 1].get_kilometer() << " - " 
			<< this->favoriten[idx - 1].get_preis() << " - " << this->favoriten[idx - 1].get_leistung() << " - " << this->favoriten[idx - 1].get_treibstoff() << "\n";
		idx += 1;
	}
	if (!show) {
		cout << "Die Liste von Lieblingsautos ist leer!\n";
	}
	return true;
}


/*
Destructor
*/
ClientRepository::~ClientRepository() {
}