#ifndef AUTO_H
#define AUTO_H

#endif // AUTO_H

#pragma once
#include <string>

using namespace std;

namespace autos {

    class Auto {
    private:
        string modell;
        string marke;
        int erstzulassungsjahr;
        int kilometer;
        double preis;
        int leistung;
        string treibstoff;
        int id;
        static int nrOfInstances;

    public:
        // Constructor
        Auto(string modell, string marke, int erstzulassungsjahr, int kilometer, double preis, int leistung, string treibstoff);

        // Copyconstructor
        Auto(const Auto& other);

        // Getters
        int get_id() const;
        string get_modell() const;
        string get_marke() const;
        int get_erstzulassungsjahr() const;
        int get_kilometer() const;
        double get_preis() const;
        int get_leistung() const;
        string get_treibstoff() const;

        // Setters
        void set_modell(string modell);
        void set_marke(string marke);
        void set_erstzulassungsjahr(int erstzulassungsjahr);
        void set_kilometer(int kilometer);
        void set_preis(double preis);
        void set_leistung(int leistung);
        void set_treibstoff(string treibstoff);

        bool operator==(const Auto& other);

        // Destructor
        ~Auto();
    };

}
