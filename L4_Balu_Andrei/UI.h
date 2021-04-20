#pragma once
#include "Controller.h"
using namespace controller;

namespace UserInterface {

	class UI {
	private:
		Controller controller;
	public:
		// Constructor
		UI();

		// Constructor
		UI(const Controller& cont);

		// Startet das Menu des UI-s
		void run();

		// Verlangt ein Input von Benutzer
		void askEnterAnyKey();

		// Verlangt von Benutzer Input fur Einfugen
		void einfugen();

		// Verlangt von Benutzer Input fur Loschen
		void loschen();

		// Verlangt von Benutzer Input fur Aktualisieren
		void update();

		// Die verlangte Produkte werden gezeigt
		void auflisten();
		void zeigeKnapp();
		void sortDatum();

		// Destructor
		~UI();
	};
}
