#pragma once
#include "Repository.h"
using namespace repository;

namespace controller {

	class Controller {
	private:
		Repository repo;
	public:
		// Constructor
		Controller();

		// Constructor
		Controller(const Repository& repo);

		// Copyconstructor
		Controller(const Controller& other);

		// Fugt ein Produkt zur Repository ein
		void einfugen(const Produkt& newProdukt);

		// Loscht ein Produkt aus Repository
		bool loschen(string name, string herkunft, Datum haltbarkeitsdatum);

		// Aktualisiert die Daten eines Produktes aus Repository
		bool update(const Produkt& prod);

		// Zeigt die Produkte welcher Namen eine Zeichenkette enthalten
		vector<Produkt> auflisten(string zeichenkette);

		// Zeigt die Produkte welche die Menge weniger als eine gegebene Wert haben
		vector<Produkt> zeigeKnapp(int menge);

		// Zeigt die Produkte nach Haltbarkeitsdatum sortiert
		vector<Produkt> sortDatum();

		// Destructor
		~Controller();
	};
}

