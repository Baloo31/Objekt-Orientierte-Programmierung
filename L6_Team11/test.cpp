#include "test.h"
#include "AbstractRepository.h"
#include "ManagerRepository.h"
#include "KundeRepository.h"
#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
using namespace kunde;
using namespace abstrakterRepo;
using namespace managerRepository;
using namespace kundeRepository;

void testManagerBehaviour() {
	cout << "Test Manager Behaviour\n";
	// Autos
	Auto auto1 = Auto("Megane", "Renault", 2019, 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", 2006, 200000, 3000.75, 90, "GPL");
	Auto auto3 = Auto("Ibiza", "Seat", 2003, 198045, 1000.5, 75, "Diesel");
	Auto auto4 = Auto("Golf", "Volkswagen", 2006, 235672, 2500, 115, "Benzin");
	Auto auto5 = Auto("Tico", "Daewoo", 2002, 150000, 450, 60, "Diesel");
	Auto auto6 = Auto("Cayenne", "Porsche", 2017, 109000, 49099.99, 385, "Benzin");

	// Manager Repository
	shared_ptr<AbstrakterRepository<Auto>> repManager = make_shared<ManagerRepository>();

	//Teste fur der einfugen Methode aus der Sicht des Managers
	assert(repManager->fugeEin(auto1));
	assert(repManager->fugeEin(auto2));
	assert(repManager->fugeEin(auto3));
	vector<Auto> v1 = repManager->getAutos();
	assert(v1.size() == 3);
	assert(repManager->fugeEin(auto4));
	vector<Auto> v2 = repManager->getAutos();
	assert(v2.size() == 4);

	//Teste fur der losch Methode aus der Sicht des Managers
	assert(repManager->losche(auto2));
	vector<Auto> v3 = repManager->getAutos();
	assert(v3.size() == 3);

	assert(!repManager->losche(auto5));
	assert(!repManager->losche(Auto("Sandero", "Dacia", 2009, 15000, 401, 75, "Diesel")));
	vector<Auto> v4 = repManager->getAutos();
	assert(v4.size() == 3);

	//Teste fur der update Methode aus der Sicht des Managers
	assert(repManager->aktualisiere(Auto("Golf", "Volkswagen", 2006, 2352, 300, 15, "Benzin")));
	assert(!repManager->aktualisiere(Auto("Golf", "Volkswagen", 2006, 2352, 300, 15, "GPL")));
	assert(!repManager->aktualisiere(Auto("X1", "BMW", 2019, 30000, 25000.05, 180, "Benzin")));
	vector<Auto> v5 = repManager->getAutos();
	assert(v5.size() == 3);

	//Teste fur einfugen in der Liste von Lieblingsautos aus der Sicht des Managers
	assert(!repManager->fugeZurFavoritenEin(auto1));
	assert(!repManager->fugeZurFavoritenEin(auto5));

	//Teste fur Anzeigen der Liste von Lieblingsautos aus der Sicht des Managers
	assert(!repManager->zeigeFavoriten());
}

void testClientBehaviour() {
	cout << "Test Client Behaviour\n";
	// Autos
	Auto auto1 = Auto("Megane", "Renault", 2019, 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", 2006, 200000, 3000.75, 90, "GPL");
	Auto auto3 = Auto("Ibiza", "Seat", 2003, 198045, 1000.5, 75, "Diesel");
	Auto auto4 = Auto("Golf", "Volkswagen", 2006, 235672, 2500, 115, "Benzin");
	Auto auto5 = Auto("Tico", "Daewoo", 2002, 150000, 450, 60, "Diesel");
	Auto auto6 = Auto("Cayenne", "Porsche", 2017, 109000, 49099.99, 385, "Benzin");
	vector<Auto> autoBox = { auto1, auto2, auto3, auto4, auto5, auto6 };

	// Client Repository
	Kunde kunde = Kunde("etwas");
	shared_ptr<AbstrakterRepository<Auto>> repClient = make_shared<KundeRepository>(kunde);

	//Teste fur den einfug, losch und update Methoden aus der Sicht eines Kundens
	assert(repClient->fugeEin(auto1) == false);
	assert(repClient->losche(auto5) == false);
	assert(repClient->aktualisiere(auto1) == false);
	assert(repClient->aktualisiere(auto2) == false);

	//Teste fur einfugen in der Liste von Lieblingsautos aus der Sicht eines Kundes
	vector<Auto> v1 = repClient->getAutos();
	assert(v1.size() == 0);
	repClient->setAutos(autoBox);
	assert(repClient->fugeZurFavoritenEin(auto1));
	assert(repClient->fugeZurFavoritenEin(auto2));
	assert(repClient->fugeZurFavoritenEin(auto3));
	assert(repClient->fugeZurFavoritenEin(auto4));
	assert(repClient->fugeZurFavoritenEin(auto5));
	assert(repClient->fugeZurFavoritenEin(auto6));


	//Teste fur anzeigen der Liste von Lieblingsautos aus der Sicht des Managers
	assert(repClient->zeigeFavoriten());
}

void testUserBehaviour() {
	cout << "Test User Behaviour\n";
	Auto auto1 = Auto("Megane", "Renault", 2019, 30000, 25000.05, 180, "Benzin");
	Auto auto2 = Auto("Logan", "Dacia", 2006, 200000, 3000.75, 90, "GPL");
	Auto auto3 = Auto("Ibiza", "Seat", 2003, 198045, 1000.5, 75, "Diesel");
	Auto auto4 = Auto("Golf", "Volkswagen", 2006, 235672, 2500, 115, "Benzin");
	Auto auto5 = Auto("Tico", "Daewoo", 2002, 150000, 450, 60, "Diesel");
	Auto auto6 = Auto("Cayenne", "Porsche", 2017, 109000, 49099.99, 385, "Benzin");
	vector<Auto> autoBox = { auto1, auto2, auto3, auto4, auto5 };

	shared_ptr<AbstrakterRepository<Auto>> repManager = make_shared<ManagerRepository>();
	repManager->setAutos(autoBox);
	Kunde kunde = Kunde("etwas");
	shared_ptr<AbstrakterRepository<Auto>> repClient = make_shared<KundeRepository>(kunde);
	repClient->setAutos(autoBox);

	//Teste fur das Suchen nach Marke
	assert(!repManager->sucheMarke("Prosche"));
	assert(repManager->sucheMarke("Dacia"));
	assert(repClient->sucheMarke("Renault"));
	assert(!repClient->sucheMarke("Random"));

	//Teste fur das Suchen nach Modell
	assert(!repManager->sucheModell("Cayenne"));
	assert(repManager->sucheModell("Logan"));
	assert(repClient->sucheModell("Golf"));
	assert(!repClient->sucheModell("Random"));

	//Teste fur das Filtern nach Alter
	assert(repManager->filterAlter(2017));
	assert(repClient->filterAlter(2017));
	assert(!repManager->filterAlter(2020));
	assert(!repClient->filterAlter(2020));

	//Teste fur das Filtern nach Anzahl der Kilometer
	assert(repManager->filterKilometer(35000));
	assert(repClient->filterKilometer(35000));
	assert(!repManager->filterKilometer(0));
	assert(!repClient->filterKilometer(0));

	//Teste fur anzeigen der Liste von Autos sortiert nach Preis 
	repManager->zeigeNachPreisSortiert();
	repClient->zeigeNachPreisSortiert();
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

	//Test Auto
	try {
		Auto auto1 = Auto("a", "b", 2021, -100, 1000, 115, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Auto auto1 = Auto("a", "b", 2021, 0, -100, 115, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Auto auto1 = Auto("a", "b", 2021, 0, 1000, 0, "Benzin");
		assert(false);
	}
	catch (exception&) {
	}

	try {
		Auto auto1 = Auto("a", "b", -1000, 0, 1000, 115, "Benzin");
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