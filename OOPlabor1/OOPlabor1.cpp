#include <assert.h>
#include <iostream>
using std::cin;
using std::cout;

/*
 Bestimmt die ausgerundete Wert des Wurzels einer reeller Zahl:
 Input: Eine reelle Zahl (double)
 Output: Ausgerundete Wert der Wurzel dieser Zahl  (int)
*/
int wurzel(double number) {
	return int(round(sqrt(number)));
}

void test_wurzel() {
	assert (wurzel(7.6) == 3);
	assert (wurzel(6.0) == 2);
	assert(wurzel(1.2) == 1);
	assert(wurzel(0) == 0);
	assert(wurzel(0.2) == 0);
	assert(wurzel(0.6) == 1);
}

/*
Untersucht ob eine Zahl eine Primzahl ist 
Input:  Eine positive, naturliche Zahl "numer"
Output: true wenn die Zahl eine Primzahl ist, sonst false (bool)
*/
bool prim(int numer) {
	bool primzahl = true;
	if (numer == 0 || numer == 1) {
		primzahl = false;
	}
	else {
		for (int index = 2; index <= wurzel(numer); ++index) {
			if (numer % index == 0) {
				primzahl = false;
				break;
			}
		}
	}
	return primzahl;
}

void test_prim() {
	assert(prim(2) == true);
	assert(prim(3) == true);
	assert(prim(100) == false);
	assert(prim(101) == true);
	assert(prim(1) == false);
	assert(prim(0) == false);
}

struct folge {
	int anfang; // Anfangstelle der Folge
	int lange; // Laenge der Folge
};

/*
Bestimt die laengste Teilfolge mt der Eigenschaft: Differenz zwischen jede benachbarte Elemente ist eine Primzahl
Input: ein vektor von Zahlen (int) und die Anzahl seiner Elemente (int)
Output: Die verlangte Folge durch eine Struktur von zwei Felder dargestellt: Anfang u. Laenge, beide (int)
*/
folge get_folge(int vektor[], int anzahl) {
	int max_lange{ 0 }, max_anfang{ -1 }, lange{ 0 }, anfang{ 0 };
	for (int index = 0; index < anzahl - 1; index++) {
		if (prim(abs(vektor[index] - vektor[index+1]))) {
			lange++;
		}
		else {
			if (lange > max_lange) {
				max_lange = lange + 1;
				max_anfang = anfang;
			}
			lange = 0; anfang = index + 1;
		}
	}
	// Falls das letzte El. des Vektors zur Folge gehorte wurde die Folge fruher nicht mehr aktualisiert
	if (lange > max_lange) {
		max_lange = lange + 1;
		max_anfang = anfang;
	}
	folge folg{ max_anfang, max_lange };
	return folg;
}

void test_get_folge() {
	// Einige besondere Situationen werden getestet:
	int vek_a[1] = {};
	folge flg_a = get_folge(vek_a, 0);
	assert((flg_a.lange == 0) && (flg_a.anfang == -1));

	int vek_b[1] = { 2 };
	folge flg_b = get_folge(vek_b, 1);
	assert((flg_b.lange == 0) && (flg_b.anfang == -1));

	int vek_c[4] = { 10, 10, 12, 13 };
	folge flg_c = get_folge(vek_c, 4);
	assert((flg_c.lange == 2) && (flg_c.anfang == 1));

	int vek_d[10] = { 10, 10, 12, 13 , 15, 17, 0, 1, 1, 2};
	folge flg_d = get_folge(vek_d, 10);
	assert((flg_d.lange == 4) && (flg_d.anfang == 3));

	int vek_e[5] = { 10, 10, 12, 13 , 15 };
	folge flg_e = get_folge(vek_e, 5);
	assert((flg_e.lange == 2) && (flg_e.anfang == 1));

	int vek_f[2] = { 11, 13 };
	folge flg_f = get_folge(vek_f, 2);
	assert((flg_f.lange == 2) && (flg_f.anfang == 0));
}

int main() {
	test_wurzel(); test_prim(); test_get_folge();
	int opt;
	cout << "Welche Problem wollen Sie loesen?\n0 - Exit\n1 - Punkt a)\n2 - Punkt b)\nOption: "; cin >> opt;
	while (opt != 0) {
		if (opt == 1) {
			double number;
			cout << "Bitte fuegen Sie eine positive Zahl hin: "; cin >> number;
			while (number < 0) {
				cout << "Invalider Wert!\nBitte fuegen Sie eine positive Zahl hin: "; cin >> number;
			}
			cout << "Ausgerundete Wert seiner Quadratwurzel: " << wurzel(number) << "\n";
		}
		else if (opt == 2) {
			//int vektor[12] = { 3, 2, 4, 7, 11, 7, 11, 7, 2, 4, 7, 9 }; int anzahl = 12; // -> Folge: 7, 2, 4, 7, 9
			//int vektor[4] = { 2, 3, 4, 5 }; int anzahl = 4; // -> Nachricht: Es wurde keine Folge gefunden!
			int vektor[100], anzahl;
			cout << "Anzahl der Elemente (zwischen 0 und 100): "; cin >> anzahl;
			while ((anzahl < 0) || (anzahl > 100)) {
				cout << "Bitte eine Zahl zwischen 0 und 100 als Anzahl einfugen!\n" << "Anzahl der Elemente: "; cin >> anzahl;
			}
			for (int index = 0; index < anzahl; index++) {
				cout << "Element: "; cin >> vektor[index];
			}

			folge folg = get_folge(vektor, anzahl);

			// folg.lange > 0 -> Es gibt mindestens eine Folge
			if (folg.lange > 0) {
				cout << "Die Folge ist: ";
				for (int index = 0; index < folg.lange; index++) {
					cout << vektor[index + folg.anfang] << " ";
				}
				cout << "\n";
			}
			else {
				cout << "Es wurde keine Folge gefunden!\n";
			}
		}
		else {
			cout << "Invalide Option !\n";
		}
		cout << "Welche Problem wollen Sie loesen?\n0 - Exit\n1 - Punkt a)\n2 - Punkt b)\nOption: "; cin >> opt;
	}
	return 0;
}