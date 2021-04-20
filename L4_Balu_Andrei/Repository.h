#pragma once
#include "Produkt.h"
using namespace produkt;

namespace repository {

    class Repository {
    private:
        vector<Produkt> produkte;

    public:
        // Constructor
        Repository();

        // Constructor
        Repository(const vector<Produkt>& produkte);

        // Copyconstructor
        Repository(const Repository& other);

        // Getter fur die Liste der Produkte
        vector<Produkt> getProdukte() const;

        // Fugt ein Produkt zur Repository ein
        void einfugen(const Produkt& newProdukt);

        // Loscht ein Produkt aus Repository
        bool loschen(string name, string herkunft, Datum haltbarkeitsdatum);

        // Aktualisiert die Daten eines Produktes aus Repository
        bool update(const Produkt& prod);

        // Zeigt die Produkte welcher Namen eine Zeichenkette enthalten
        vector<Produkt> auflisten(string zeichenkette);

        // Zeigt die Produkte welche die Menge weniger als eine gegebene Wert haben
        vector<Produkt> zeigeKnapp(int menge);

        // Zeigt die Produkte nach Haltbarkeitsdatum sortiert
        vector<Produkt> sortDatum();

        void operator=(const Repository& other);

        // Destructor
        ~Repository();
    };
}
