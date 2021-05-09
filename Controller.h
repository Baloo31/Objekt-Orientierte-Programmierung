#pragma once
#include "Repository.h"
#include <memory>
using namespace repository;

namespace controller {

	class Controller {
	private:
		shared_ptr<Repository> repo;
	public:
		// Default costructor
		Controller();

		// Constructor
		Controller(bool manager);

		// Fugt ein Produkt zur Repository ein
		bool einfugen(const Auto& carToAdd);

		// Loscht ein Produkt aus Repository
		bool loschen(const Auto& carToDelete);

		// Aktualisiert die Daten eines Produktes aus Repository
		bool update(const Auto& carToUpdate);

		// Setter
		void setAutos(const vector<Auto>& autos);

		// Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
		bool searchModell(const string& modell) const;

		// Bestimmt ob eine gegebene Marke eines Autos in die Liste von Autos existiert
		bool searchMarke(const string& marke) const;

		// Zeigt alle Autos deren Datum neuer als eine angegebene Datum sind 
		bool filterAlter(const Datum& alter) const;

		// Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
		bool filterKilometer(const int& kilometer) const;

		// Zeigt alle Autos aus der Liste sortiert steigend nach Preis
		void showPriceSorted();

		// Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu 
		bool addToFavoriten(const Auto& carToAdd);

		// Zeigt die Liste von Lieblingsautos
		bool showFavoriten() const;

		// Destructor
		~Controller();
	};
}
