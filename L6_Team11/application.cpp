#include <iostream>
#include "test.h"
#include "UI.h"
using namespace UserInterface;

int main() {
	// Teste werden durchgefuhrt
	testAll();

	// Anwendung wird gestartet
	UI userInterface = UI();
	userInterface.run();
	cout << "                         ~Anwendung wurde erfolgreich beendet~\n\n";
	return 0;
}