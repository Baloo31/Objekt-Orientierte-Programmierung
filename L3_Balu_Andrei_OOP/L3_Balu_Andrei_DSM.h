#pragma once
#include <string>
#include <vector>
using namespace std;

struct link {
	string from;
	string to;
	int weight;
};

class DSM {
private:
	vector<string> elements; // Die Elemente (Zeilen und Spalten)
	int nrElements; // Anzahl der Elemente

	vector<link> links; // Die Verbindungen (die Elemente der Matrix)
	int nrLinks; // Anzahl der Verbindungen

public:
	// Konstruiert eine Matrix mit Default-Namen der Elemente
	DSM(int elementCount);

	// Konstruiert eine Matrix aus gegebene Elemente
	DSM(const vector<string>& elementNames);

	// Kopierkonstruktor
	DSM(const DSM& dsm);

	// Andert die Name einer Element, falls dieser existiert
	void set_element_name(int index, string name);

	// Getter fur Name der validen Elemente
	string const get_name(int index);

	// Bestimmt die Grosse der Matrix
	int const size();

	// Verbindet zwei Elemente
	void add_link(string from_element, string to_element, int weight);

	// Entfernt eine existierende Verbindung
	void delete_link(string from_element, string to_element);

	// Uberpruft ob eine bestimmte Verbindung gibt
	bool const have_link(string from_element, string to_element);

	// Gibt das Gewicht einer existierende Verbindung zuruck
	int const link_weight(string from_element, string to_element);

	// Zahlt die to-Verbindungen einer Element
	int const count_to_links(string element_name);

	// Zahlt die from-Verbindungen einer Element
	int const count_from_links(string element_name);

	// Zahlt alle Verbindungen
	int const count_all_links();

	//Bestimmt die Densitat der Matrix
	double const calculate_matrix_density();

	// Destruktor
	~DSM();
};
