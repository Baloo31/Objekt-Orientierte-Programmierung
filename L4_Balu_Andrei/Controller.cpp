#include "Controller.h"
using namespace controller;

Controller::Controller() {
	this->repo = repository::Repository();
}

Controller::Controller(const Repository& repo) {
	this->repo = repo;
}

Controller::Controller(const Controller& other) {
	this->repo = other.repo;
}

void Controller::einfugen(const Produkt& newProdukt) {
	this->repo.einfugen(newProdukt);
}

bool Controller::loschen(string name, string herkunft, Datum haltbarkeitsdatum) {
	return this->repo.loschen(name, herkunft, haltbarkeitsdatum);
}

bool Controller::update(const Produkt& prod) {
	return this->repo.update(prod);
}

vector<Produkt> Controller::auflisten(string zeichenkette) {
	return this->repo.auflisten(zeichenkette);
}

vector<Produkt> Controller::zeigeKnapp(int menge) {
	return this->repo.zeigeKnapp(menge);
}

vector<Produkt> Controller::sortDatum() {
	return this->repo.sortDatum();
}

Controller::~Controller() {
}