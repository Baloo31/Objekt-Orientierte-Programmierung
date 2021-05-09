#include "Tests.h"
#include "Repository.h"
#include "ManagerRepository.h"
#include "ClientRepository.h"
#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
using namespace repository;
using namespace managerRepository;
using namespace clientRepository;

void testManagerBehaviour() {
	cout << "Test Manager Behaviour\n";
	// Autos
	Auto auto1 = Auto("Megane", "Renault", Datum(4, 10, 2019), 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", Datum(13, 2, 2006), 200000, 3000.75, 90, "GPL"); 
	Auto auto3 = Auto("Ibiza", "Seat", Datum(15, 12, 2003), 198045, 1000.5, 75, "Diesel"); 
	Auto auto4 = Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 235672, 2500, 115, "Benzin"); 
	Auto auto5 = Auto("Tico", "Daewoo", Datum(4, 10, 2002), 150000, 450, 60, "Diesel"); 
	Auto auto6 = Auto("Cayenne", "Porsche", Datum(1, 12, 2017), 109000, 49099.99, 385, "Benzin");

	// Manager Repository
	shared_ptr<Repository> repManager = make_shared<ManagerRepository>();
	
	//Teste fur der einfugen Methode aus der Sicht des Managers
	assert(repManager->einfugen(auto1));
	assert(repManager->einfugen(auto2));
	assert(repManager->einfugen(auto3));
	vector<Auto> v1 = repManager->getAutos();
	assert(v1.size() == 3);
	assert(repManager->einfugen(auto4));
	vector<Auto> v2 = repManager->getAutos();
	assert(v2.size() == 4);

	//Teste fur der losch Methode aus der Sicht des Managers
	assert(repManager->loschen(auto2));
	vector<Auto> v3 = repManager->getAutos();
	assert(v3.size() == 3);

	assert(!repManager->loschen(auto5));
	assert(!repManager->loschen(Auto("Sandero", "Dacia", Datum(4, 8, 2009), 15000, 401, 75, "Diesel")));
	vector<Auto> v4 = repManager->getAutos();
	assert(v4.size() == 3);

	//Teste fur der update Methode aus der Sicht des Managers
	assert(repManager->update(Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 2352, 300, 15, "Benzin")));
	assert(!repManager->update(Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 2352, 300, 15, "GPL")));
	assert(!repManager->update(Auto("X1", "BMW", Datum(4, 10, 2019), 30000, 25000.05, 180, "Benzin")));
	vector<Auto> v5 = repManager->getAutos();
	assert(v5.size() == 3);

	//Teste fur einfugen in der Liste von Lieblingsautos aus der Sicht des Managers
	assert(!repManager->addToFavoriten(auto1));
	assert(!repManager->addToFavoriten(auto5));

	//Teste fur Anzeigen der Liste von Lieblingsautos aus der Sicht des Managers
	assert(!repManager->showFavoriten());
}

void testClientBehaviour(){
	cout << "Test Client Behaviour\n";
	// Autos
	Auto auto1 = Auto("Megane", "Renault", Datum(4, 10, 2019), 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", Datum(13, 2, 2006), 200000, 3000.75, 90, "GPL");
	Auto auto3 = Auto("Ibiza", "Seat", Datum(15, 12, 2003), 198045, 1000.5, 75, "Diesel");
	Auto auto4 = Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 235672, 2500, 115, "Benzin");
	Auto auto5 = Auto("Tico", "Daewoo", Datum(4, 10, 2002), 150000, 450, 60, "Diesel");
	Auto auto6 = Auto("Cayenne", "Porsche", Datum(1, 12, 2017), 109000, 49099.99, 385, "Benzin");
	vector<Auto> autoBox = { auto1, auto2, auto3, auto4, auto5, auto6 };

	// Client Repository
	shared_ptr<Repository> repClient = make_shared<ClientRepository>();

	//Teste fur den einfug, losch und update Methoden aus der Sicht eines Kundens
	assert(repClient->einfugen(auto1) == false);
	assert(repClient->loschen(auto5) == false);
	assert(repClient->update(auto1) == false);
	assert(repClient->update(auto2) == false);

	//Teste fur einfugen in der Liste von Lieblingsautos aus der Sicht eines Kundes
	vector<Auto> v1 = repClient->getAutos();
	assert(v1.size() == 0);
	repClient->setAutos(autoBox);
	assert(repClient->addToFavoriten(auto1));
	assert(repClient->addToFavoriten(auto2));
	assert(repClient->addToFavoriten(auto3));
	assert(repClient->addToFavoriten(auto4));
	assert(repClient->addToFavoriten(auto5));
	assert(repClient->addToFavoriten(auto6));


	//Teste fur anzeigen der Liste von Lieblingsautos aus der Sicht des Managers
	assert(repClient->showFavoriten());
}

void testUserBehaviour() {
	cout << "Test User Behaviour\n";
	Auto auto1 = Auto("Megane", "Renault", Datum(4, 10, 2019), 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", Datum(13, 2, 2006), 200000, 3000.75, 90, "GPL");
	Auto auto3 = Auto("Ibiza", "Seat", Datum(15, 12, 2003), 198045, 1000.5, 75, "Diesel");
	Auto auto4 = Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 235672, 2500, 115, "Benzin");
	Auto auto5 = Auto("Tico", "Daewoo", Datum(4, 10, 2002), 150000, 450, 60, "Diesel");
	Auto auto6 = Auto("Cayenne", "Porsche", Datum(1, 12, 2017), 109000, 49099.99, 385, "Benzin");
	vector<Auto> autoBox = { auto1, auto2, auto3, auto4, auto5};

	shared_ptr<Repository> repManager = make_shared<ManagerRepository>();
	repManager->setAutos(autoBox);
	shared_ptr<Repository> repClient = make_shared<ClientRepository>();
	repClient->setAutos(autoBox);

	//Teste fur das Suchen nach Marke
	assert(!repManager->searchMarke("Prosche"));
	assert(repManager->searchMarke("Dacia"));
	assert(repClient->searchMarke("Renault"));
	assert(!repClient->searchMarke("Random"));

	//Teste fur das Suchen nach Modell
	assert(!repManager->searchModell("Cayenne"));
	assert(repManager->searchModell("Logan"));
	assert(repClient->searchModell("Golf"));
	assert(!repClient->searchModell("Random"));

	//Teste fur das Filtern nach Alter
	assert(repManager->filterAlter(Datum(1, 10, 2017)));
	assert(repClient->filterAlter(Datum(1, 10, 2017)));
	assert(!repManager->filterAlter(Datum(1, 1, 2020)));
	assert(!repClient->filterAlter(Datum(1, 1, 2020)));

	//Teste fur das Filtern nach Anzahl der Kilometer
	assert(repManager->filterKilometer(35000));
	assert(repClient->filterKilometer(35000));
	assert(!repManager->filterKilometer(0));
	assert(!repClient->filterKilometer(0));

	//Teste fur anzeigen der Liste von Autos sortiert nach Preis 
	repManager->showPriceSorted();
	repClient->showPriceSorted();
	vector<Auto> autoBoxPriceSorted = { auto5, auto3, auto4, auto2, auto1 };
	vector<Auto> v1 = repManager->getAutos();
	vector<Auto> v2 = repClient->getAutos();
	for (int index = 0; index < v1.size() - 1; index++) {
		assert(v1[index] == v2[index]);
		assert(v1[index] == autoBoxPriceSorted[index]);
	}
}

void testCreate() {
	cout << "Test create\n";
	// Test Datum
	try {
		Datum dat = Datum(31, 2, 2003);
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Datum dat = Datum(-1, 5, 2004);
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Datum dat = Datum(12, 13, 2004);
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Datum dat = Datum(1, 1, -1);
		assert(false);
	}
	catch (exception&) {
	}

	//Test Auto
	try {
		Auto auto1 = Auto("a", "b", Datum(1, 1, 2021), -100, 1000, 115, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Auto auto1 = Auto("a", "b", Datum(1, 1, 2021), 0, -100, 115, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Auto auto1 = Auto("a", "b", Datum(1, 1, 2021), 0, 1000, 0, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}
}

void testAll() {
	testCreate();
	testManagerBehaviour();
	testClientBehaviour();
	testUserBehaviour();
	system("CLS");
}