#include <iostream>
#include "UI.h"
using namespace UserInterface;

/*
Liest eine valide Datum (tag/monat/jahr)
*/
void readDatum(int& tag, int& monat, int& jahr) {
	while (true) {
		cout << "Tag: "; cin >> tag;
		cout << "Monat: "; cin >> monat;
		cout << "Jahr: "; cin >> jahr;
		try {
			Auto prod = Auto("a", "a", Datum(tag, monat, jahr), 100, 400, 100, "a");
			break;
		}
		catch (exception&) {
			cout << "Diese Datum existiert nicht!\nBitte die Datum nochmal einfugen!\n";
		}
	}
}

/*
Liest eine valide Kilometeranzahl
*/
void readKilometer(int& kilometer) {
	while (true) {
		cout << "Kilometer: "; cin >> kilometer;
		try {
			Auto prod = Auto("a", "a", Datum(1, 1, 2020), kilometer, 400, 100, "a");
			break;
		}
		catch (exception&) {
			cout << "Kilometeranzahl ist invalid!\nBitte die Kilometer nochmal einfugen!\n";
		}
	}
}

/*
Liest eine valide Preis
*/
void readPreis(double& preis) {
	while (true) {
		cout << "Preis: "; cin >> preis;
		try {
			Auto prod = Auto("a", "a", Datum(1, 1, 2020), 100, preis, 100, "a");
			break;
		}
		catch (exception&) {
			cout << "Preis ist invalid!\nBitte die Preis nochmal einfugen!\n";
		}
	}
}

/*
Liest eine valide Leistung
*/
void readLeistung(int& leistung) {
	while (true) {
		cout << "Leistung: "; cin >> leistung;
		try {
			Auto prod = Auto("a", "a", Datum(1, 1, 2020), 100, 400, leistung, "a");
			break;
		}
		catch (exception&) {
			cout << "Leistung (in PS) ist invalid!\nBitte die Leistung nochmal einfugen!\n";
		}
	}
}


/*
UI Constructor
*/
UI::UI() {
	bool manager = false; int opt = 0;
	while (true) {
		cout << "-------------------------------------------------------------------------------\n";
		cout << "		~Wie mochten Sie die Anwendung offnen?~\nOption: 1 - Offnen als Kunde\nOption: 2 - Offnen als Manager\n";
		cout << "-------------------------------------------------------------------------------\nWahlen Sie eine Option: ";
		cin >> opt;
		cout << "-------------------------------------------------------------------------------\n";
		if (opt == 1 || opt == 2) break;
		cout << "Diese Option ist ungultig!\n";
		cout << "-------------------------------------------------------------------------------\n";
		system("pause");
		system("CLS");
	}
	if (opt == 1) {
		manager = false;
	}
	else {
		manager = true;
	}
	this->controller = Controller(manager);
}


/* UI Constructor */
UI::UI(const Controller& cont) {
	this->controller = cont;
}


/*
UI Menu
*/
void UI::run() {
	// Anwendung enthalt schon am Anfang ein Paar Autos
	vector<Auto> autos;
	Auto auto1 = Auto("Megane", "Renault", Datum(4, 10, 2019), 30000, 25000.05, 180, "Benzin"); autos.push_back(auto1);
	Auto auto2 = Auto("Logan", "Dacia", Datum(13, 2, 2006), 200000, 3000.75, 90, "GPL"); autos.push_back(auto2);
	Auto auto3 = Auto("Ibiza", "Seat", Datum(15, 12, 2003), 198045, 1000.5, 75, "Diesel"); autos.push_back(auto3);
	Auto auto4 = Auto("Golf", "Volkswagen", Datum(31, 10, 2006), 235672, 2500, 115, "Benzin"); autos.push_back(auto4);
	Auto auto5 = Auto("Tico", "Daewoo", Datum(4, 10, 2002), 150000, 450, 60, "Diesel"); autos.push_back(auto5);
	Auto auto6 = Auto("Cayenne", "Porsche", Datum(1, 12, 2017), 109000, 49099.99, 385, "Benzin"); autos.push_back(auto6);
	this->controller.setAutos(autos);

	// Menu
	int opt = 1;
	while (opt != 0) {
		system("CLS");
		cout << "-------------------------------------------------------------------------------\n"
			"                                      ~Menu~\n"
			"Option 0: Exit\n"
			"Option 1: Einfugen eines Autos\n"
			"Option 2: Loschen eines Autos\n"
			"Option 3: Aktualisieren eines Autos\n"
			"Option 4: Suchen eines Modells\n"
			"Option 5: Suchen einer Marke\n"
			"Option 6: Filtern nach Alter\n"
			"Option 7: Filtern nach Kilometer\n"
			"Option 8: Zeigen der Autos sortiert nach Preis\n"
			"Option 9: Einfugen in der Liste von Lieblingsautos\n"
			"Option 10: Anzeigen der Liste von Lieblingsautos\n"
			"-------------------------------------------------------------------------------\n";
		cout << "Wahlen Sie eine Option: ";  cin >> opt;
		if (opt < 0 || opt > 10) {
			cout << "-------------------------------------------------------------------------------\n";
			cout << "Diese Option ist ungultig!\n";
			system("pause");
		}
		else {
			if (opt == 1) this->einfugen();
			if (opt == 2) this->loschen();
			if (opt == 3) this->update();
			if (opt == 4) this->searchModell();
			if (opt == 5) this->searchMarke();
			if (opt == 6) this->filterAlter();
			if (opt == 7) this->filterKilometer();
			if (opt == 8) this->showPriceSorted();
			if (opt == 9) this->addToFavoriten();
			if (opt == 10) this->showFavoriten();
		}
	}
}

/*
Verlangt von Benutzer Input fur Einfugen
*/
void UI::einfugen() {
	string modell; string marke; int tag; int monat; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Einfugen eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readDatum(tag, monat, jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.einfugen(Auto(modell, marke, Datum(tag, monat, jahr), kilometer, preis, leistung, treibstoff))) {
		cout << "Das Auto wurde erfolgreich eingefugt!\n";
	}
	else {
		cout << "Das Auto wurde nicht eingefugt!\n";
	}
	system("pause");
}

/*
Verlangt von Benutzer Input fur Loschen
*/
void UI::loschen() {
	string modell; string marke; int tag; int monat; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Loschen eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readDatum(tag, monat, jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.loschen(Auto(modell, marke, Datum(tag, monat, jahr), kilometer, preis, leistung, treibstoff))) {
		cout << "Das Auto wurde erfolgreich entfert!\n";
	}
	else {
		cout << "Das Auto wurde nicht etfernt!\n";
	}
	system("pause");
}

/*
Verlangt von Benutzer Input fur Aktualisieren
*/
void UI::update() {
	string modell; string marke; int tag; int monat; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Aktualisieren eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readDatum(tag, monat, jahr);
	cout << "Treibstoff: "; cin >> treibstoff;
	cout << "Jetzt folgen die Feldern die Sie verandern konnen:\n";
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);

	if (this->controller.update(Auto(modell, marke, Datum(tag, monat, jahr), kilometer, preis, leistung, treibstoff))) {
		cout << "Das Auto wurde erfolgreich aktualisiert!\n";
	}
	else {
		cout << "Das Auto wurde nicht aktualisiert!\n";
	}
	system("pause");
}

/*
Verlangt von Benutzer Input fur das Suchen eines Modells
*/
void UI::searchModell() {
	string modell;
	cout << "-------------------------------------------------------------------------------\n"
		"-Suchen eines Modells-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	if (this->controller.searchModell(modell)) {
		cout << "Das Modell existiert in der Liste!\n";
	}
	else {
		cout << "Das Modell existiert nicht in der Liste!\n";
	}
	system("pause");
}

/*
Verlangt von Benutzer Input fur das Suchen einer Marke
*/
void UI::searchMarke() {
	string marke;
	cout << "-------------------------------------------------------------------------------\n"
		"-Suchen einer Marke-\n-------------------------------------------------------------------------------\n";
	cout << "Marke: "; cin >> marke;
	if (this->controller.searchMarke(marke)) {
		cout << "Die Marke existiert in der Liste!\n";
	}
	else {
		cout << "Die Marke existiert nicht in der Liste!\n";
	}
	system("pause");
}

/*
Verlangt von Benutzer Input fur filtern nach Alter
*/
void UI::filterAlter() {
	int tag; int monat; int jahr;
	cout << "-------------------------------------------------------------------------------\n"
		"-Filtern nach Alter-\n-------------------------------------------------------------------------------\n";
	readDatum(tag, monat, jahr);
	this->controller.filterAlter(Datum(tag, monat, jahr));
	system("pause");
}

/*
Verlangt von Benutzer Input fur filtern nach Kilometer
*/
void UI::filterKilometer() {
	int kilometer;
	cout << "-------------------------------------------------------------------------------\n"
		"-Filtern nach Kilometer-\n-------------------------------------------------------------------------------\n";
	readKilometer(kilometer);
	this->controller.filterKilometer(kilometer);
	system("pause");
}

/*
Zeigt die Autos aus der Liste sortiert nach Preis
*/
void UI::showPriceSorted() {
	cout << "-------------------------------------------------------------------------------\n"
		"-Zeigen der Autos sortiert nach Preis-\n-------------------------------------------------------------------------------\n";
	this->controller.showPriceSorted();
	system("pause");
}

/*
Verlangt von Benutzer Input fur die Daten eines Autos
*/
void UI::addToFavoriten() {
	string modell; string marke; int tag; int monat; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Einfugen in der Liste von Lieblingsautos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readDatum(tag, monat, jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.addToFavoriten(Auto(modell, marke, Datum(tag, monat, jahr), kilometer, preis, leistung, treibstoff))) {
		cout << "Das Auto wurde elforgreich in der Liste von Lieblingsautos eingefugt!\n";
	}
	else {
		cout << "Das Auto wurde nicht in der Liste von Lieblingsautos eingefugt!\n";
	}
	system("pause");
}

/*
Zeigt die Autos aus der Liste von Lieblingsautos
*/
void UI::showFavoriten() {
	cout << "-------------------------------------------------------------------------------\n"
		"-Anzeigen der Liste von Lieblingsautos-\n-------------------------------------------------------------------------------\n";
	if (this->controller.showFavoriten()) {
	} 
	else {
		cout << "Nur die Kunden haben eine Liste mit Lieblingsautos, Managers nicht!\n";
	}
	system("pause");
}

/*
UI Destructor
*/
UI::~UI() {
}