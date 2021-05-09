#pragma once
#include <string>
#include "Datum.h"

using namespace datum;
using namespace std;

namespace autos {

	class Auto {
	private:
		string modell;
		string marke;
		Datum erstzulassungsdatum;
		int kilometer;
		double preis;
		int leistung;
		string treibstoff;
	public:
		// Constructor
		Auto(string modell, string marke, Datum erstzulassungsjahr, int kilometer, double preis, int leistung, string treibstoff);

		// Copyconstructor
		Auto(const Auto& other);

		// Getters
		string get_modell() const;
		string get_marke() const;
		Datum get_erstzulassungsdatum() const;
		int get_kilometer() const;
		double get_preis() const;
		int get_leistung() const;
		string get_treibstoff() const;

		// Setters
		void set_modell(string modell);
		void set_marke(string marke);
		void set_erstzulassungsdatum(Datum erstzulassungsdatum);
		void set_kilometer(int kilometer);
		void set_preis(double preis);
		void set_leistung(int leistung);
		void set_treibstoff(string treibstoff);

		bool const operator==(const Auto& other);

		// Destructor
		~Auto();
	};

}