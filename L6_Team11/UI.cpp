#include <iostream>
#include "UI.h"
using namespace UserInterface;

/*
Liest ein valides Jahr
*/
void readJahr(int& jahr) {
	while (true) {
		cout << "Erstzulassungsjahr: "; cin >> jahr;
		try {
			Auto prod = Auto("a", "a", jahr, 100000, 400, 100, "a");
			break;
		}
		catch (exception&) {
			cout << "Jahr ist invalid!\nBitte die Jahr nochmal einfugen!\n";
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
			Auto prod = Auto("a", "a", 2010, kilometer, 400, 100, "a");
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
			Auto prod = Auto("a", "a", 2010, 100, preis, 100, "a");
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
			Auto prod = Auto("a", "a", 2010, 100, 400, leistung, "a");
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
	this->leseAusDateien();
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
			if (opt == 1) this->fugeEin();
			if (opt == 2) this->losche();
			if (opt == 3) this->aktualisiere();
			if (opt == 4) this->sucheModell();
			if (opt == 5) this->sucheMarke();
			if (opt == 6) this->filterAlter();
			if (opt == 7) this->filterKilometer();
			if (opt == 8) this->zeigeNachPreisSortiert();
			if (opt == 9) this->fugeZurFavoritenEin();
			if (opt == 10) this->zeigeFavoriten();
		}
	}
	this->schreibeInDateien();
}

void UI::leseAusDateien() {
	this->controller.leseAusDateien();
}

void UI::schreibeInDateien() {
	this->controller.schreibeInDateien();
}

/*
Verlangt von Benutzer Input fur Einfugen
*/
void UI::fugeEin() {
	string modell; string marke; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Einfugen eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readJahr(jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.fugeEin(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
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
void UI::losche() {
	string modell; string marke; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Loschen eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readJahr(jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.losche(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
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
void UI::aktualisiere() {
	string modell; string marke; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Aktualisieren eines Autos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readJahr(jahr);
	cout << "Treibstoff: "; cin >> treibstoff;
	cout << "Jetzt folgen die Feldern die Sie verandern konnen:\n";
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);

	if (this->controller.aktualisiere(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
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
void UI::sucheModell() {
	string modell;
	cout << "-------------------------------------------------------------------------------\n"
		"-Suchen eines Modells-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	if (this->controller.sucheModell(modell)) {
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
void UI::sucheMarke() {
	string marke;
	cout << "-------------------------------------------------------------------------------\n"
		"-Suchen einer Marke-\n-------------------------------------------------------------------------------\n";
	cout << "Marke: "; cin >> marke;
	if (this->controller.sucheMarke(marke)) {
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
	int jahr;
	cout << "-------------------------------------------------------------------------------\n"
		"-Filtern nach Alter-\n-------------------------------------------------------------------------------\n";
	readJahr(jahr);
	this->controller.filterAlter(jahr);
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
void UI::zeigeNachPreisSortiert() {
	cout << "-------------------------------------------------------------------------------\n"
		"-Zeigen der Autos sortiert nach Preis-\n-------------------------------------------------------------------------------\n";
	this->controller.zeigeNachPreisSortiert();
	system("pause");
}

/*
Verlangt von Benutzer Input fur die Daten eines Autos
*/
void UI::fugeZurFavoritenEin() {
	string modell; string marke; int jahr; int kilometer; double preis; int leistung; string treibstoff;
	cout << "-------------------------------------------------------------------------------\n"
		"-Einfugen in der Liste von Lieblingsautos-\n-------------------------------------------------------------------------------\n";
	cout << "Modell: "; cin >> modell;
	cout << "Marke: "; cin >> marke;
	readJahr(jahr);
	readKilometer(kilometer);
	readPreis(preis);
	readLeistung(leistung);
	cout << "Treibstoff: "; cin >> treibstoff;

	if (this->controller.fugeZurFavoritenEin(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
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
void UI::zeigeFavoriten() {
	cout << "-------------------------------------------------------------------------------\n"
		"-Anzeigen der Liste von Lieblingsautos-\n-------------------------------------------------------------------------------\n";
	if (this->controller.zeigeFavoriten()) {
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