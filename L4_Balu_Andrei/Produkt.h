#pragma once
#include <vector>
#include <string>
#include "Datum.h"
using namespace std;
using namespace datum;

namespace produkt {

    class Produkt {

    private:
        string name;
        string herkunft;
        int menge;
        int preis;
        Datum haltbarkeitsdatum;

    public:
        // Constructor
        Produkt(string name, string herkunft, int menge, int preis, Datum haltbarkeitsdatum);

        // Constructor
        Produkt(const Produkt& other);

        // Getters & setters
        string getName() const;
        string getHerkunft() const;
        int getMenge() const;
        int getPreis() const;
        Datum getHaltbarkeitsdatum() const;
        void setName(string name);
        void setHerkunft(string herkunft);
        void setMenge(int menge);
        void setPreis(int preis);
        void setHaltbarkeitsdatum(Datum haltbarkeitsdatum);

        bool const operator==(const Produkt& other);

        // Destructor
        ~Produkt();
    };
}
