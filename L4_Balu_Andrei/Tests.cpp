#include "Tests.h"
#include "Repository.h"
#include <cassert>
#include <exception>
using namespace repository;

/*
Testet die Methode fur Einfugen eines Produktes
*/
void testAdd() {
	Datum datum = Datum(10, 8, 2021);
	Produkt produkt = Produkt("prod1", "etwas", 1, 1, datum);
	vector<Produkt> produkte;
	produkte.push_back(produkt);

	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 1);
	assert(repo.getProdukte()[0].getMenge() == 1);

	for (int rep = 0; rep < 10; rep++) { 
		repo.einfugen(produkt);
	}
	assert(repo.getProdukte().size() == 1);
	assert(repo.getProdukte()[0].getMenge() == 11);

	Produkt produktZwei = Produkt("prod2", "etwas", 1, 1, datum);
	repo.einfugen(produktZwei);
	assert(repo.getProdukte().size() == 2);
}


/*
Testet die Konstruktion der Objekte der Klassen:
Datum, Produkt und Repository
*/
void testCreate() {
	Repository testsRepo = Repository();
	assert(testsRepo.getProdukte().size() == 0);

	try {
		Datum datum = Datum(-1, 2, 2001);
		assert(false);
	}
	catch (exception&) {
	}
	try {
		Datum datum = Datum(31, 2, 2040);
		assert(false);
	}
	catch (exception&) {
	}
	try {
		Datum datum = Datum(15, 2, -1);
		assert(false);
	}
	catch (exception&) {
	}
	Datum datum = Datum(10, 8, 2021);

	try {
		Produkt produkt = Produkt("a", "a", -3, 4, datum);
		assert(false);
	}
	catch (exception&) {
	}
	try {
		Produkt produkt = Produkt("a", "a", 3, -4, datum);
		assert(false);
	}
	catch (exception&) {
	}

	Produkt produkt = Produkt("prod1", "etwas", 1, 1, datum);
	vector<Produkt> produkte;
	produkte.push_back(produkt);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 1);
}


/*
Testet die Methode welche ein Objekt loscht
*/
void testRemove() {
	Datum datum = Datum(10, 8, 2021);

	Produkt produktEins = Produkt("prod1", "etwas", 1, 1, datum);
	Produkt produktZwei = Produkt("prod2", "etwas", 1, 1, datum);
	Produkt produktDrei = Produkt("prod3", "etwas", 1, 1, datum);

	vector<Produkt> produkte;
	produkte.push_back(produktEins);
	produkte.push_back(produktZwei);
	produkte.push_back(produktDrei);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 3);

	// Produkt existiert nicht, also er wird nicht geloscht
	assert(repo.loschen("nichts", "nichts", datum) == false);

	// prod2 wird geloscht
	assert(repo.loschen("prod2", "etwas", datum));
	assert(repo.getProdukte().size());
	assert((repo.getProdukte()[0] == produktEins));
	assert((repo.getProdukte()[1] == produktDrei));
}


/*
Testet die Methode welche ein Objekt aktualisiert
*/
void testUpdate() {
	Datum datum = Datum(10, 8, 2021);

	Produkt produktEins = Produkt("prod1", "etwas", 1, 1, datum);
	Produkt produktZwei = Produkt("prod2", "etwas", 1, 1, datum);
	Produkt produktDrei = Produkt("prod3", "etwas", 1, 1, datum);

	vector<Produkt> produkte;
	produkte.push_back(produktEins);
	produkte.push_back(produktZwei);
	produkte.push_back(produktDrei);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 3);

	// Produkt existiert nicht, also er wird nicht aktualisiert
	assert(repo.loschen("nichts", "nichts", datum) == false);

	assert(repo.getProdukte()[2].getPreis() == 1);
	assert(repo.getProdukte()[2].getMenge() == 1);

	// prod3 wird aktualisiert
	Produkt prodDreiNeu = Produkt("prod3", "etwas", 10, 10, datum);
	assert(repo.update(prodDreiNeu));
	assert(repo.getProdukte().size() == 3);

	assert(repo.getProdukte()[2].getPreis() == 10);
	assert(repo.getProdukte()[2].getMenge() == 10);
}


/*
Testet ob die richtige Produkte bestimmt werden 
(Name enthalt die gegebene Zeichenkette)
*/
void testAuflisten() {
	Datum datum = Datum(10, 8, 2021);

	Produkt produktEins = Produkt("prod1", "etwas", 1, 1, datum);
	Produkt produktZwei = Produkt("Prod2", "etwas", 1, 1, datum);
	Produkt produktDrei = Produkt("prod3", "etwas", 1, 1, datum);

	vector<Produkt> produkte;
	produkte.push_back(produktDrei);
	produkte.push_back(produktZwei);
	produkte.push_back(produktEins);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 3);

	vector<Produkt> outputEins = repo.auflisten("prod");
	assert(outputEins[0] == produktEins);
	assert(outputEins[1] == produktDrei);

	vector<Produkt> outputZwei = repo.auflisten("");
	assert(outputZwei[0] == produktZwei);
	assert(outputZwei[1] == produktEins);
	assert(outputZwei[2] == produktDrei);
}


/*
Testet ob die richtige Produkte bestimmt werden
(Menge weniger als ein als ein Wert)
*/
void testZeigeKnapp() {
	Datum datum = Datum(10, 8, 2021);

	Produkt produktEins = Produkt("prod1", "etwas", 1, 1, datum);
	Produkt produktZwei = Produkt("Prod2", "etwas", 1, 1, datum);
	Produkt produktDrei = Produkt("prod3", "etwas", 1, 1, datum);

	vector<Produkt> produkte;
	produkte.push_back(produktDrei);
	produkte.push_back(produktZwei);
	produkte.push_back(produktEins);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 3);

	vector<Produkt> outputEins = repo.zeigeKnapp(1);
	assert(outputEins[0] == produktDrei);
	assert(outputEins[1] == produktZwei);
	assert(outputEins[2] == produktEins);

	vector<Produkt> outputZwei = repo.zeigeKnapp(0);
	assert(outputZwei.size() == 0);

	vector<Produkt> outputDrei = repo.zeigeKnapp(-2);
	assert(outputDrei.size() ==  0);
}


/*
Testet ob die richtige Produkte bestimmt werden
(Die existierende Produkte sortiert nach ihrer Haltbarkeitsdatum)
*/
void testSortDatum() {
	Datum datumEins = Datum(10, 8, 2021);
	Datum datumZwei = Datum(12, 8, 2021);
	Datum datumDrei = Datum(10, 8, 2023);

	Produkt produktEins = Produkt("prod1", "etwas", 1, 1, datumEins);
	Produkt produktZwei = Produkt("prod2", "etwas", 1, 1, datumZwei);
	Produkt produktDrei = Produkt("prod3", "etwas", 1, 1, datumDrei);

	vector<Produkt> produkte;
	produkte.push_back(produktDrei);
	produkte.push_back(produktZwei);
	produkte.push_back(produktEins);
	Repository repo = Repository(produkte);
	assert(repo.getProdukte().size() == 3);

	vector<Produkt> outputEins = repo.sortDatum();
	assert(outputEins[0] == produktEins);
	assert(outputEins[1] == produktZwei);
	assert(outputEins[2] == produktDrei);
	assert(outputEins.size() == 3);
}

void testAll() {
	testCreate();
	testAdd();
	testRemove();
	testUpdate();
	testAuflisten();
	testZeigeKnapp();
	testSortDatum();
}
