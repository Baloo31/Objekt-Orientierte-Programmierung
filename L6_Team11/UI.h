#pragma once
#include "Controller.h"
using namespace controller;

namespace UserInterface {

	class UI {
	private:
		Controller controller;
	public:
		// Defaultconstructor
		UI();

		// Constructor
		UI(const Controller& cont);

		// Startet das Menu des UI-s
		void run();

		// Verlangt von Benutzer Input fur Einfugen
		void fugeEin();

		// Verlangt von Benutzer Input fur Loschen
		void losche();

		// Verlangt von Benutzer Input fur Aktualisieren
		void aktualisiere();

		// Verlangt von Benutzer Input fur das Suchen eines Modells
		void sucheModell();

		// Verlangt von Benutzer Input fur das Suchen einer Marke
		void sucheMarke();

		// Verlangt von Benutzer Input fur filtern nach Alter
		void filterAlter();

		// Verlangt von Benutzer Input fur filtern nach Kilometer
		void filterKilometer();

		// Zeigt die Autos aus der Liste sortiert nach Preis
		void zeigeNachPreisSortiert();

		// Verlangt von Benutzer Input fur die Daten eines Autos
		void fugeZurFavoritenEin();

		// Zeigt die Autos aus der Liste von Lieblingsautos
		void zeigeFavoriten();

		void leseAusDateien();

		void schreibeInDateien();

		// Destructor
		~UI();
	};
}

