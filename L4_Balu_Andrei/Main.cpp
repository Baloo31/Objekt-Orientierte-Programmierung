#include "UI.h"
#include "Tests.h"
#include <iostream>
using namespace UserInterface;

int main() {
	// Teste werden durchgefuhrt
	testAll();
	cout << "Alle Teste wurden erfolgreich beendet!\n";

	// Anwendung wird gestartet
	UI userInterface = UI();
	userInterface.run();
	cout << "                         ~Anwendung wurde erfolgreich beendet~\n\n";
	return 0;
}