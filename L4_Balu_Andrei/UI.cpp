#include <iostream>
#include "UI.h"
using namespace UserInterface;

/* 
UI Constructor
*/
UI::UI() {
	this->controller = Controller();
}


/* UI Constructor */
UI::UI(const Controller& cont) {
	this->controller = cont;
}


/*
UI Menu 
*/
void UI::run() {
	// Repository enthalt am Anfang der Anwendung 10 Produkte
	this->controller.einfugen(Produkt("Apfel", "Rumanien", 800, 1, Datum(6, 6, 2021)));
	this->controller.einfugen(Produkt("Banana", "Uganda", 1000, 2, Datum(14, 10, 2022)));
	this->controller.einfugen(Produkt("Bierne", "Bulgarien", 500, 1, Datum(7, 8, 2021)));
	this->controller.einfugen(Produkt("Melone", "Rumanien", 60, 1, Datum(9, 10, 2021)));
	this->controller.einfugen(Produkt("Trauben", "Frankreich", 400, 2, Datum(11, 12, 2022)));
	this->controller.einfugen(Produkt("Kurbis", "Rumanien", 80, 5, Datum(10, 10, 2023)));
	this->controller.einfugen(Produkt("Zitrone", "Indien", 1000, 1, Datum(3, 1, 2023)));
	this->controller.einfugen(Produkt("Erdbeere", "Spanien", 600, 1, Datum(29, 12, 2021)));
	this->controller.einfugen(Produkt("Pflaume", "Griechenland", 550, 1, Datum(10, 2, 2024)));
	this->controller.einfugen(Produkt("Orange", "Turkei", 150, 1, Datum(17, 10, 2024)));
	// Menu
	int opt = 1;
	while (opt != 0) {
		cout << "-------------------------------------------------------------------------------\n"
			"                                      ~Menu~\n"
			"Option 0: Exit\n"
			"Option 1: Einfugen einer Produkt\n"
			"Option 2: Loschen einer Produkt\n"
			"Option 3: Bearbeiten einer Produkt\n"
			"Option 4: Anzeigen der Produkte die knapp sind\n"
			"Option 5: Auflisten im Bezug euf einer Zeichenkette\n"
			"Option 6: Nach Haltbarkeitsdatum sortiert anzeigen\n"
			"-------------------------------------------------------------------------------\n";
		cout << "Wahlen Sie eine Option: ";  cin >> opt;
		if (opt < 0 || opt > 6) {
			cout << "Diese Option ist ungultig!\n";
		}
		else {
			if (opt == 1) this->einfugen();
			if (opt == 2) this->loschen();
			if (opt == 3) this->update();
			if (opt == 4) this->zeigeKnapp();
			if (opt == 5) this->auflisten();
			if (opt == 6) this->sortDatum();
		}
	}
}


/* 
Verlangt von Benutzer ein Input (Nutzlich beim Anschauen der Resultate)
*/
void UI::askEnterAnyKey() {
	cout << "Bitte fugen Sie etwas ein um fortzugehen...";
	string anyKey;
	cin >> anyKey;
	cout << endl;
}


/* 
Verlangt das gebrauchte Input fur das Einfugen einer Produkt und kommnunziert durch controller mit dem Repository 
*/
void UI::einfugen() {
	string name; string herkunft; int menge; int preis; int jahr; int monat; int tag;
	cout << "-------------------------------------------------------------------------------\n"
		    "-Einfugen einer Produkt-\n";
	cout << "Name: "; cin >> name;
	cout << "Herkunft: "; cin >> herkunft;
	
	// Menge wird gelesen bis sie gultig ist
	while (true) {
		cout << "Menge: "; cin >> menge;
		try {
			Produkt prod = Produkt("a", "a", menge, 1, Datum(1, 1, 2022));
			break;
		}
		catch (exception&){
			cout << "Die Menge soll eine ganze Zahl strikt grosser als 0 sein!\n";
		}
	}

	// Preis wird gelesen bis sie gultig ist
	while (true) {
		cout << "Preis: "; cin >> preis;
		try {
			Produkt prod = Produkt("a", "a", 1, preis, Datum(1, 1, 2022));
			break;
		}
		catch (exception&) {
			cout << "Die Preis soll eine ganze Zahl strikt grosser als 0 sein!\n";
		}
	}

	// Die Datum wird gelesen bis sie gultig ist 
	while (true) {
		cout << "Tag: "; cin >> tag;
		cout << "Monat: "; cin >> monat;
		cout << "Jahr: "; cin >> jahr;
		try {
			Produkt prod = Produkt("a", "a", 1, 1, Datum(tag, monat, jahr));
			break;
		}
		catch (exception&) {
			cout << "Diese Datum existiert nicht!\nBitte die Datum nochmal einfugen!\n";
		}
	}

	this->controller.einfugen(Produkt(name, herkunft, menge, preis, Datum(tag, monat, jahr)));
	cout << "Produkt erfolgreich eingefugt!" << endl;
	this->askEnterAnyKey();
}


/* 
Verlangt das gebrauchte Input fur das Loschen einer Produkt und kommnunziert durch controller mit dem Repository 
*/
void UI::loschen() {
	string name; string herkunft; int jahr; int monat; int tag;
	cout << "-------------------------------------------------------------------------------\n"
		    "-Loschen einer Produkt-\n";
	cout << "Name: "; cin >> name;
	cout << "Herkunft: "; cin >> herkunft;

	// Die Datum wird gelesen bis sie gultig ist 
	while (true) {
		cout << "Tag: "; cin >> tag;
		cout << "Monat: "; cin >> monat;
		cout << "Jahr: "; cin >> jahr;
		try {
			Produkt prod = Produkt("a", "a", 1, 1, Datum(tag, monat, jahr));
			break;
		}
		catch (exception&) {
			cout << "Diese Datum existiert nicht!\nBitte die Datum nochmal einfugen!\n";
		}
	}

	if (this->controller.loschen(name, herkunft, Datum(tag, monat, jahr))) {
		cout << "Produkt erfolgreich geloscht!" << endl;
	}
	else {
		cout << "Produkt existiert nicht!" << endl;
	}
	this->askEnterAnyKey();
}


/* 
Verlangt das gebrauchte Input fur das Bearbeiten einer Produkt und kommnunziert durch controller mit dem Repository 
*/
void UI::update() {
	string name; string herkunft; int menge; int preis; int jahr; int monat; int tag;
	cout << "-------------------------------------------------------------------------------\n"
		    "-Bearbeiten einer Produkt-\n";
	cout << "Name: "; cin >> name;
	cout << "Herkunft: "; cin >> herkunft;

	// Menge wird gelesen bis sie gultig ist
	while (true) {
		cout << "Menge: "; cin >> menge;
		try {
			Produkt prod = Produkt("a", "a", menge, 1, Datum(1, 1, 2022));
			break;
		}
		catch (exception&) {
			cout << "Die Menge soll eine ganze Zahl strikt grosser als 0 sein!\n";
		}
	}

	// Preis wird gelesen bis sie gultig ist
	while (true) {
		cout << "Preis: "; cin >> preis;
		try {
			Produkt prod = Produkt("a", "a", 1, preis, Datum(1, 1, 2022));
			break;
		}
		catch (exception&) {
			cout << "Die Preis soll eine ganze Zahl strikt grosser als 0 sein!\n";
		}
	}

	// Die Datum wird gelesen bis sie gultig ist 
	while (true) {
		cout << "Tag: "; cin >> tag;
		cout << "Monat: "; cin >> monat;
		cout << "Jahr: "; cin >> jahr;
		try {
			Produkt prod = Produkt("a", "a", 1, 1, Datum(tag, monat, jahr));
			break;
		}
		catch (exception&) {
			cout << "Diese Datum existiert nicht!\nBitte die Datum nochmal einfugen!\n";
		}
	}

	if (this->controller.update(Produkt(name, herkunft, menge, preis, Datum(tag, monat, jahr)))) {
		cout << "Produkt erfolgreich aktualisiert!" << "\n";
	}
	else {
		cout << "Produkt existiert nicht!" << "\n";
	}
	this->askEnterAnyKey();
}


/* 
Verlangt von Benutzer das gebrauchte Menge
Output der Option die der Benutzer verlangen hat
*/
void UI::zeigeKnapp() {
	cout << "-------------------------------------------------------------------------------\n";
	int menge;

	// Menge wird gelesen bis sie gultig ist
	while (true) {
		cout << "Menge: "; cin >> menge;
		try {
			Produkt prod = Produkt("a", "a", menge, 1, Datum(1, 1, 2022));
			break;
		}
		catch (exception&) {
			cout << "Die Menge soll eine ganze Zahl strikt grosser als 0 sein!\n";
		}
	}
	vector<Produkt> dataToShow = this->controller.zeigeKnapp(menge);
	if (dataToShow.size() == 0){
		cout << "Keine Produkte gefunden!\n";
	}
	else {
		for (int index = 0; index < dataToShow.size(); index++) {
			Produkt current = dataToShow[index];
			cout << current.getName() << " - " << current.getHerkunft()
				<< " - " << current.getHaltbarkeitsdatum().getTag() << "/" << current.getHaltbarkeitsdatum().getMonat() << "/" << current.getHaltbarkeitsdatum().getJahr()
				<< " - " << current.getPreis() << " - " << current.getMenge() << "\n";
		}
	}
	this->askEnterAnyKey();
}


/*
Output der Option die der Benutzer verlangen hat
*/
void UI::auflisten() {
	cout << "-------------------------------------------------------------------------------\n";
	string zeichenkette;
	cout << "Zeichenkette: "; 
	cin.get(); 
	getline(cin, zeichenkette);
	vector<Produkt> dataToShow = this->controller.auflisten(zeichenkette);
	if (dataToShow.size() == 0) {
		cout << "Keine Produkte gefunden!\n";
	}
	else {
		for (int index = 0; index < dataToShow.size(); index++) {
			Produkt current = dataToShow[index];
			cout << current.getName() << " - " << current.getHerkunft()
				<< " - " << current.getHaltbarkeitsdatum().getTag() << "/" << current.getHaltbarkeitsdatum().getMonat() << "/" << current.getHaltbarkeitsdatum().getJahr()
				<< " - " << current.getPreis() << " - " << current.getMenge() << "\n";
		}
	}
	this->askEnterAnyKey();
}


/*
Output der Option die der Benutzer verlangen hat
*/
void UI::sortDatum() {
	cout << "-------------------------------------------------------------------------------\n";
	vector<Produkt> dataToShow = this->controller.sortDatum();
	if (dataToShow.size() == 0) {
		cout << "Keine Produkte gefunden!\n";
	}
	else {
		for (int index = 0; index < dataToShow.size(); index++) {
			Produkt current = dataToShow[index];
			cout << current.getName() << " - " << current.getHerkunft()
				<< " - " << current.getHaltbarkeitsdatum().getTag() << "/" << current.getHaltbarkeitsdatum().getMonat() << "/" << current.getHaltbarkeitsdatum().getJahr()
				<< " - " << current.getPreis() << " - " << current.getMenge() << "\n";
		}
	}
	this->askEnterAnyKey();
}


/*
UI Destructor
*/
UI::~UI() {
}