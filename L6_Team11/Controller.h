#pragma once
#include "Auto.h"
#include "ManagerRepository.h"
#include "KundeRepository.h"
#include "AbstractRepository.h"
#include <memory>
using namespace autos;
using namespace managerRepository;
using namespace kundeRepository;
using namespace abstrakterRepo;

namespace controller {

	class Controller {
	private:
		shared_ptr<AbstrakterRepository<Auto>> repo;
	public:
		// Default costructor
		Controller();

		// Constructor
		Controller(bool manager);

		// Fugt ein Produkt zur Repository ein
		bool fugeEin(const Auto& autoFurEinfugen);

		// Loscht ein Produkt aus Repository
		bool losche(const Auto& autoFurLoschen);

		// Aktualisiert die Daten eines Produktes aus Repository
		bool aktualisiere(const Auto& autoFurAktualisieren);

		// Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
		bool sucheModell(const string& modell) const;

		// Bestimmt ob eine gegebene Marke eines Autos in die Liste von Autos existiert
		bool sucheMarke(const string& marke) const;

		// Zeigt alle Autos deren Datum neuer als eine angegebene Datum sind 
		bool filterAlter(const int& alter) const;

		// Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
		bool filterKilometer(const int& kilometer) const;

		// Zeigt alle Autos aus der Liste sortiert steigend nach Preis
		void zeigeNachPreisSortiert();

		// Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu 
		bool fugeZurFavoritenEin(const Auto& autoFurEinfugen);

		// Zeigt die Liste von Lieblingsautos
		bool zeigeFavoriten() const;

		void leseAusDateien();

		void schreibeInDateien();

		// Destructor
		~Controller();
	};
}
