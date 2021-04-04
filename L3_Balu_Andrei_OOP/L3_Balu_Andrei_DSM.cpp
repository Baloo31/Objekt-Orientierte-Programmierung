#include "L3_Balu_Andrei_DSM.h"
#include <exception>
using namespace std;


/*
Konstruiert eine Matrix mit Default-Namen der Elemente
Anz Elemente soll psoitiv sein
*/
DSM::DSM(int elementCount) {
	if (elementCount >= 0) {
		this->nrElements = elementCount;

		this->elements = {};
		for (int index = 0; index < elementCount; index++) {
			this->elements.push_back("element" + to_string(index + 1));
		}

		this->nrLinks = 0;
		this->links = {};
	} else throw exception();
}


/*
Konstruiert eine Matrix aus gegebene Elemente
Wird erst uberpruft ob die Elemente eindeutig sind
*/
DSM::DSM(const vector<string>& elementNames) {
	
	for (int indexOne = 0; indexOne < elementNames.size()-1; indexOne++) {
		for (int indexTwo = indexOne+1; indexTwo < elementNames.size(); indexTwo++) {
			if (elementNames[indexOne] == elementNames[indexTwo]) {
				throw exception();
			}
		}
	}
	this->elements = elementNames;
	this->nrElements = elementNames.size();
	this->nrLinks = 0;
	this->links = {};
}


/*
Kopierkonstruktor
Wird aufgeruft beim initialisieren einer Matrix mit das Wert einer schon konstruirte Matrix
*/
DSM::DSM(const DSM& otherDsm) {
	this->elements = otherDsm.elements;
	this->nrElements = otherDsm.nrElements;
	this->nrLinks = otherDsm.nrLinks;
	this->links = otherDsm.links;
}


/*
Bestimmt die Grosse der Matrix
Die Matrix ist quadratisch, also Size = anzElemente^2
*/
int const DSM::size() {
	return (this->nrElements * this->nrElements);
}


/*
Andert die Name einer Element auf eine bestimmte Stelle
Man untersucht ob die Stelle valid ist
Wenn die Name das vorige ist, wird nichts aktualisiert
Man uberpruft ob die neue Name auf eine andere Stelle schon existiert (Kein Element darf zwei mal vorkommen)
Man durchquert alle Verbindungen und wo der alte Name vorkommt wird er aktualisiert
*/
void DSM::set_element_name(int index, string name){
	if ((index >= 0) and (index < this->nrElements)) {
		if (name != this->elements[index]) {
			for (int pos = 0; pos < this->nrElements; pos++) {
				if ((this->elements[pos] == name) && (pos != index)) {
					throw exception();
				}
			}
			string elToReplace = this->elements[index];
			for (int pos = 0; pos < this->nrLinks; pos++) {
				if (this->links[pos].to == elToReplace) {
					this->links[pos].to = name;
				}
				if (this->links[pos].from == elToReplace) {
					this->links[pos].from = name;
				}
			}
			this->elements[index] = name;
		}
	}
	else throw exception();
}


/*
Getter fur Name der validen Elemente
Man untersucht ob der index valid ist
*/
string const DSM::get_name(int index) {
	if ((index >= 0) and (index < this->nrElements)) {
		return this->elements[index];
	}
	throw exception();
}


/*
Macht eine Verbindung zwischen zwei Elementen
Die Elemente der Matrix durfen keine Verbindungen zu sich selbst haben
Man untersucht ob die zwei Elementen existieren
Wenn ja, dan wird untersucht ob die Verbindung schon existiert um sie zu aktualisieren(Gewicht)
Wenn nicht, dann werden sie eingefugt zusammen mit der Verbindung

*/
void DSM::add_link(string from_element, string to_element, int weight) {
	if (from_element != to_element) {
		bool from_elementExists = false, to_elementExists = false;
		for (int index = 0; index < this->nrElements; index++) {
			if (from_elementExists && to_elementExists) {
				break;
			}
			if (this->elements[index] == from_element) {
				from_elementExists = true;
			}
			if (this->elements[index] == to_element) {
				to_elementExists = true;
			}
		}

		if (from_elementExists && to_elementExists) {
			bool exists = false;
			for (int index = 0; index < this->nrLinks; index++) {
				if ((this->links[index].to == to_element) && (this->links[index].from == from_element)) {
					this->links[index].weight = weight;
					exists = true;
					break;
				}
			}
			if (!exists) {
				link newLink = { from_element, to_element, weight };
				this->links.push_back(newLink);
				this->nrLinks++;
			}
		}
		else {
			if (!from_elementExists) {
				this->elements.push_back(from_element);
				this->nrElements++;
			}
			if (!to_elementExists) {
				this->elements.push_back(to_element);
				this->nrElements++;
			}
			link newLink = { from_element, to_element, weight };
			this->links.push_back(newLink);
			this->nrLinks++;
		}
	}
	else throw exception();
}


/*
Entfernt eine existierende Verbindung
Die Elemente der Matrix konnen keine Verbindungen zu sich selbst haben
Man durchquert die Verbindungen: wenn sie gefunden wird, wird sie entfernt
*/
void DSM::delete_link(string from_element, string to_element) {
	if (from_element != to_element) {
		// int from_elementOccurrences = 0, to_elementOccurrences = 0;
		// bool deleted = false;
		for (int index = 0; index < this->nrLinks; index++) {
			/*
			if (this->links[index].to == from_element || this->links[index].from == from_element) {
				from_elementOccurrences++;
			}
			
			if (this->links[index].to == to_element || this->links[index].from == to_element) {
				to_elementOccurrences++;
			}
			*/
			if ((this->links[index].to == to_element) && (this->links[index].from == from_element)) {
				this->links.erase(this->links.begin() + index);
				this->nrLinks--;
				// deleted = true;
				break;
			}
		}
		
		/*
		if ((from_elementOccurrences == 1) && deleted) {
			for (int index = 0; index < this->nrElements; index++) {
				if (this->elements[index] == from_element) {
					this->elements.erase(this->elements.begin() + index);
					this->nrElements--;
					break;
				}
			}
		}
		if ((to_elementOccurrences == 1) && deleted) {
			for (int index = 0; index < this->nrElements; index++) {
				if (this->elements[index] == to_element) {
					this->elements.erase(this->elements.begin() + index);
					this->nrElements--;
					break;
				}
			}
		}
		*/
	}
	else throw exception();
}


/*
Bestimmt ob eine bestimmte Verbindung existiert
Ein Element hat keine Verbindung zur sich selbst
Man durchquert die Verbindungen und wenn man sie findet ergibt die Methode true, sonst false
*/
bool const DSM::have_link(string from_element, string to_element) {
	if (from_element != to_element) {
		for (int index = 0; index < this->nrLinks; index++) {
			if ((this->links[index].to == to_element) && (this->links[index].from == from_element)) {
				return true;
			}
		}
		return false;
	}
	throw exception();
}


/*
Bestimmt das Gewicht einer Verbindung
Ein Element hat keine Verbindung zur sich selbst
Man durchquert die Verbindungen, falls die Verbindung existiert wird sein Gewicht zuruckgegeben
Verlangen des Gewichtes einer Verbindung die nicht existiert macht keinem Sinn (exception)
*/
int const DSM::link_weight(string from_element, string to_element) {
	if (from_element != to_element) {
		for (int index = 0; index < this->nrLinks; index++) {
			if ((this->links[index].to == to_element) && (this->links[index].from == from_element)) {
				return this->links[index].weight;
			}
		}
		throw exception(); 
	}
	throw exception();
}


/*
Zahlt die to-Verbindungen einer Element
Durchquert alle Verbindungen und zahlt die Erscheinungen des Elementes als to-Element 
*/
int const DSM::count_to_links(string element_name) {
	int count = 0;
	for (int index = 0; index < this->nrLinks; index++) {
		if (this->links[index].to == element_name){
			count++;
		}
	}
	return count;
}


/*
Zahlt die from-Verbindungen einer Element
Durchquert alle Verbindungen und zahlt die Erscheinungen des Elementes als from-Element
*/
int const DSM::count_from_links(string element_name) {
	int count = 0;
	for (int index = 0; index < this->nrLinks; index++) {
		if (this->links[index].from == element_name) {
			count++;
		}
	}
	return count;
}


/*
Gibt die Anzahl der Verbindungen
*/
int const DSM::count_all_links() {
	return this->nrLinks;
}


/*
Bestimmt die Densitat der Matrix
Hat keinem Sinn fur eine Matrix die keine Verbindungen haben kann (Weil man in diesem Fall durch Null teilt)
*/
double const DSM::calculate_matrix_density() {
	if (this->nrElements > 1) {
		return this->count_all_links() / (this->size() - this->nrElements);
	}
	throw exception();
}


/*
Destruktor
Loscht das Objekt und befreit dem Speicherplatz
*/
DSM::~DSM() {
}
