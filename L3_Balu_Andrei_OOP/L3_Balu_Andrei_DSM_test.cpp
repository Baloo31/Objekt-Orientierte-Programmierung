#include <iostream>
#include <assert.h>
#include "L3_Balu_Andrei_DSM.h"
#include <vector>
#include <string>

using namespace std;

void testCreateOne() {
	cout << "Test DSM Create 1 - ";

	try{
		DSM dsm = { -1 };
		assert(false);
	}
	catch (exception&) {
	}

	try {
		DSM dsm = { -100 };
		assert(false);
	}
	catch (exception&) {
	}

	DSM dsm = { 0 };
	assert(dsm.size() == 0);

	DSM dSm = { 1 };
	assert(dSm.size() == 1);

	DSM dsm1 = { 100 };
	// Eine neue Matrix soll am Anfang keine Verbindungen haben
	assert(dsm1.count_all_links() == 0);

	// Size der Matrix ist anzahl Elemente hoch zwei
	assert(dsm1.size() == 10000);

	// Die selbst-generierte Namen der Elemente
	for (int idx = 0; idx < 100; idx++) {
		assert(dsm1.get_name(idx) == "element" + to_string(idx + 1));
		assert(dsm1.count_to_links("element" + to_string(idx + 1)) == 0);
		assert(dsm1.count_from_links("element" + to_string(idx + 1)) == 0);
	}

	// Nur die vorher uberprufte Elemente sollen gultig sein 
	try {
		dsm1.get_name(101);
		assert(false);
	}
	catch (exception&){
	}
	try {
		dsm1.get_name(-1);
		assert(false);
	}
	catch (exception&) {
	}
	
	cout << "SUCCES" << endl;
}

void testCreateTwo() {
	cout << "Test DSM Create 2 - ";

	// Die Elemente sollen eindeutig sein
	vector<string> vec = { "El2", "El1", "El3", "El3" };
	try {
		DSM dsm = { vec };
		assert(false);
	}
	catch (exception&){
	}

	vector<string> vec1 = { "El1", "El2", "El3", "El4" };
	DSM dsm1 = { vec1 };

	// Eine neue Matrix soll am Anfang keine Verbindungen haben
	assert(dsm1.count_all_links() == 0);

	// Size der Matrix ist anzahl Elemente hoch zwei
	assert(dsm1.size() == 16);

	// Die Namen die spezifiziert wurden
	assert(dsm1.get_name(0) == "El1");
	assert(dsm1.get_name(1) == "El2");
	assert(dsm1.get_name(2) == "El3");
	assert(dsm1.get_name(3) == "El4");

	// Nur die vorige 4 Elemente sollen gultig sein 
	try {
		dsm1.get_name(4);
		assert(false);
	}
	catch (exception&) {
	}
	try {
		dsm1.get_name(-1);
		assert(false);
	}
	catch (exception&) {
	}

	cout << "SUCCES" << endl;
}

void testCreateThree() {
	cout << "Test DSM Create 3 - ";

	DSM dsm1 = { 3 };
	dsm1.add_link("element1", "element2", 10);
	dsm1.add_link("element2", "element1", 10);
	assert(dsm1.count_all_links() == 2);
	assert(dsm1.count_to_links("element1") == 1);
	assert(dsm1.count_from_links("element1") == 1);
	assert(dsm1.count_to_links("element2") == 1);
	assert(dsm1.count_from_links("element2") == 1);
	// dsm1 hat 2 El und 2 Verbindungen
	
	// In dsm2 wird alles aus der aktuelle dsm1 kopiert
	DSM dsm2 = dsm1;

	assert(dsm2.size() == 9);

	// Untersuchen ob die Elemente gut kopiert wurden
	assert(dsm2.get_name(0) == "element1");
	assert(dsm2.get_name(1) == "element2");
	assert(dsm2.get_name(2) == "element3");
	try {
		dsm2.get_name(3);
		assert(false);
	} catch (exception&){
	}

	// Untersuchen ob die Verbindungen gut kopiert wurden
	assert(dsm2.count_all_links() == 2);
	assert(dsm2.count_to_links("element1") == 1);
	assert(dsm2.count_from_links("element1") == 1);
	assert(dsm2.count_to_links("element2") == 1);
	assert(dsm2.count_from_links("element2") == 1);
	assert(dsm2.count_to_links("element3") == 0);
	assert(dsm2.count_from_links("element3") == 0);
	assert(dsm2.have_link("element1", "element2"));
	assert(dsm2.link_weight("element1", "element2") == 10);
	assert(dsm2.have_link("element2", "element1"));
	assert(dsm2.link_weight("element2", "element1") == 10);
	try {
		dsm2.link_weight("element2", "element1");
	}
	catch (exception&) {
	}
	cout << "SUCCES" << endl;
}

void testSetElementName() {
	cout << "Test DSM Set Element Name - ";

	DSM dsm1 = { 10 };
	dsm1.add_link("element10", "element8", 1);
	dsm1.add_link("element2", "element10", 12);

	assert(dsm1.count_all_links() == 2);
	assert(dsm1.have_link("element10", "element8"));
	assert(dsm1.have_link("element2", "element10"));

	// Die Name eines Elementes wird verandert
	dsm1.set_element_name(9, "changed");

	// Die Veranderung passiert nicht
	dsm1.set_element_name(9, "changed");

	assert(dsm1.get_name(9) == "changed");
	// Die Erscheinungen der Name in Verbindungen wird auch aktualisiert um sie zu Behalten
	assert(dsm1.have_link("changed", "element8"));
	assert(dsm1.have_link("element2", "changed"));

	// Element "changed" existiert schon auf eine andere Stelle
	try {
		dsm1.set_element_name(3, "changed");
		assert(false);
	}
	catch (exception&) {
	}

	// Index ist invalid
	try {
		dsm1.set_element_name(-10, "etwas");
		assert(false);
	}
	catch (exception&) {
	}

	cout << "SUCCES" << endl;
}

void testGetName() {
	cout << "Test DSM Get Name - ";

	// Falls Index ist invalid
	DSM dsm1 = { 100 };
	try {
		dsm1.get_name(-1);
		assert(false);
	} 
	catch (exception&) {
	}

	// Man durchquert die Elemente und ruft get_name fur jede Element
	for (int idx = 0; idx < 100; idx++) {
		assert(dsm1.get_name(idx) == "element"+ to_string(idx+1));
	}
	cout << "SUCCES" << endl;
}

void testSize() {
	cout << "Test DSM Size - ";

	DSM dsm = { 2 };

	int nrElem = 2;
	while (dsm.size() < 10000) {
		// Man pruft die Size Schritt fur Schritt
		assert(dsm.size() == nrElem * nrElem);
		// Man fugt je eine Verbindung mit einem umbekannten Element, so wird Size immer grosser
		dsm.add_link(dsm.get_name(nrElem - 1), "element" + to_string(nrElem+1), 1);
		nrElem++;
	}
	assert(dsm.size() == 10000);

	cout << "SUCCES" << endl;
}

void testAddLink() {
	cout << "Test DSM Add Link - ";

	DSM dsm = { 10 };
	// Verbindet zwei Elemente aus dsm
	dsm.add_link("element1", "element2", 10);
	assert(dsm.have_link("element1", "element2"));
	assert(dsm.link_weight("element1", "element2") == 10);

	// Uberschreibt die Gewicht
	dsm.add_link("element1", "element2", 3);
	assert(dsm.have_link("element1", "element2"));
	assert(dsm.link_weight("element1", "element2") == 3);

	// Fugt die neue Element ein und macht die Verbindung
	dsm.add_link("element1", "newEl", 26);
	assert(dsm.have_link("element1", "newEl"));
	assert(dsm.link_weight("element1", "newEl") == 26);

	// Funktoniert auch falls beide Elemente umbekannt sind
	dsm.add_link("new1", "new2", 14);
	assert(dsm.have_link("new1", "new2"));
	assert(dsm.link_weight("new1", "new2") == 14);

	// Man darf keine Verbindung zur Element selbst haben
	try {
		dsm.add_link("abc", "abc", 10);
		assert(false);
	}
	catch (exception&) {
	}

	cout << "SUCCES" << endl;
}

void testDeleteLink() {
	cout << "Test DSM Delete Link - ";

	DSM dsm = { 10 };
	assert(dsm.have_link("element3", "element4") == false);
	dsm.add_link("element3", "element4", 16);
	assert(dsm.have_link("element3", "element4") == true);

	dsm.delete_link("element3", "element4");
	// Verbindung existiert nicht mehr
	assert(dsm.have_link("element3", "element4") == false);
	
	assert(dsm.have_link("element3", "element4") == false);
	dsm.delete_link("element3", "element4");
	assert(dsm.have_link("element3", "element4") == false);

	// Wird uberpruft ob die Verbindung gultig ist
	try {
		dsm.delete_link("el", "el");
		assert(false);
	}
	catch (exception&) {
	}

	cout << "SUCCES" << endl;
}

void testHaveLink() {
	cout << "Test DSM Have Link - ";

	DSM dsm = { 5 };

	// Am Anfang hat man keine Verbindungen
	assert(dsm.have_link("element1", "element2") == false);
	assert(dsm.have_link("element2", "element1") == false);

	// Fugen eine Verbindung ein
	dsm.add_link("element1", "element2", 12);

	assert(dsm.have_link("element1", "element2") == true);
	assert(dsm.have_link("element2", "element1") == false);

	// Die Verbindung wird geloscht
	dsm.delete_link("element1", "element2");

	assert(dsm.have_link("element1", "element2") == false);
	assert(dsm.have_link("element2", "element1") == false);

	cout << "SUCCES" << endl;
}

void testLinkWeight() {
	cout << "Test DSM Link Weight - ";

	DSM dsm = { 5 };

	// Es macht kein Sinn um die Gewicht einer Verbindung die nicht existiert zu fragen
	try {
		dsm.link_weight("elemOne", "elemTwo");
		assert(false);
	}
	catch (exception&) {
	}

	// Hier existiert die Verbindung
	dsm.add_link("elemOne", "elemTwo", 100);
	assert(dsm.link_weight("elemOne", "elemTwo") == 100);

	cout << "SUCCES" << endl;

}

void testCountLinks() {
	cout << "Test DSM Count Links - ";

	DSM dsm = { 5 };

	// Man fugt 6 Verbindungen ein nur zwischen 3 Elemente
	dsm.add_link("element1", "element2", 12);
	dsm.add_link("element2", "element1", 12);
	dsm.add_link("element2", "element3", 12);
	dsm.add_link("element3", "element2", 12);
	dsm.add_link("element1", "element3", 12);
	dsm.add_link("element3", "element1", 12);

	// Count_all_links soll gleich mit Anz der Verbindungen die eingefugt wurden
	assert(dsm.count_all_links() == 6);

	assert(dsm.count_to_links("element1") == 2);
	assert(dsm.count_to_links("element2") == 2);
	assert(dsm.count_to_links("element3") == 2);
	assert(dsm.count_to_links("element4") == 0);
	assert(dsm.count_to_links("element5") == 0);

	assert(dsm.count_from_links("element1") == 2);
	assert(dsm.count_from_links("element2") == 2);
	assert(dsm.count_from_links("element3") == 2);
	assert(dsm.count_from_links("element4") == 0);
	assert(dsm.count_from_links("element5") == 0);


	cout << "SUCCES" << endl;
}

void testMatrixDensity() {
	cout << "Test DSM Density - ";

	// dsmLeer ist eine leere Matrix
	DSM dsmLeer = { 0 };

	// dsmOneEl hat ur ein Element
	DSM dsmOneEl = { 1 };

	// Die Densitat hat Sinn nur fur ein Matrix welche Verbindungen haben kann

	// Ohne Elemente hat man keine Verbindungen
	try {
		dsmLeer.calculate_matrix_density();
		assert(false);
	} 
	catch (exception&) {
	}

	// Ein Element darf keine Verbindung zur sich selbst haben
	try {
		dsmOneEl.calculate_matrix_density();
		assert(false);
	}
	catch (exception&) {
	}

	DSM dsm = { 3 };
	// Keine Verbindungen -> Density = 0
	assert(dsm.calculate_matrix_density() == 0);

	dsm.add_link("element1", "element2", 12);
	dsm.add_link("element2", "element1", 12);
	dsm.add_link("element2", "element3", 12);
	dsm.add_link("element3", "element2", 12);
	dsm.add_link("element1", "element3", 12);
	dsm.add_link("element3", "element1", 12);

	// Alle Verbindungen -> Density = 1
	assert(dsm.calculate_matrix_density() == 1);

	dsm.delete_link("element1", "element3");
	dsm.delete_link("element1", "element2");

	// Jetzt sind 4/6 Verbindungen, also ist Density eine Zahl in Intervall (0,1)
	assert(dsm.calculate_matrix_density() == 4 / 6);

	cout << "SUCCES" << endl;
}

int main(){
	testCreateOne();
	testCreateTwo();
	testCreateThree();
	testSetElementName();
	testGetName();
	testSize();
	testAddLink();
	testDeleteLink();
	testHaveLink();
	testLinkWeight();
	testCountLinks();
	testMatrixDensity();
	return 0;
}
