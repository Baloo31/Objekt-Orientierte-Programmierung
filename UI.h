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
		void einfugen();

		// Verlangt von Benutzer Input fur Loschen
		void loschen();

		// Verlangt von Benutzer Input fur Aktualisieren
		void update();

		// Verlangt von Benutzer Input fur das Suchen eines Modells
		void searchModell();
		
		// Verlangt von Benutzer Input fur das Suchen einer Marke
		void searchMarke();

		// Verlangt von Benutzer Input fur filtern nach Alter
		void filterAlter();

		// Verlangt von Benutzer Input fur filtern nach Kilometer
		void filterKilometer();

		// Zeigt die Autos aus der Liste sortiert nach Preis
		void showPriceSorted();

		// Verlangt von Benutzer Input fur die Daten eines Autos
		void addToFavoriten();

		// Zeigt die Autos aus der Liste von Lieblingsautos
		void showFavoriten();

		// Destructor
		~UI();
	};
}