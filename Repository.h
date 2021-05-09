#pragma once
#include "Auto.h"
#include "vector"
using namespace autos;

namespace repository {

    class Repository {
    protected:
        vector<Auto> autos;

    public:
        // Defaultconstructor
        Repository();

        // Copyconstructor
        Repository(const Repository& other);

        // Getter
        vector<Auto> getAutos() const;

        // Setter
        void setAutos(vector<Auto> autos);

        // Ergibt die Position eines Autos in der Liste (-1 falls dieses Auto nicht existiert)
        int suchen(const Auto& carToSearch);

        // Fugt ein Auto in die Liste von Autos hinzu (In Fall einer Manager)
        virtual bool einfugen(const Auto& carToAdd);

        // Loscht ein Auto aus der Liste von Autos (In Fall einer Manager)
        virtual bool loschen(const Auto& carToDelete);

        // Aktualisiert ein Auto aus der Liste von Autos
        virtual bool update(const Auto& carToUpdate);

        // Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert 
        bool searchModell(const string& modell) const;

        // Bestimmt ob eine gegebene Marke eines Autos in die Liste von Autos existiert
        bool searchMarke(const string& marke) const;

        // Zeigt alle Autos deren Datum neuer als eine angegebene Datum sind
        bool filterAlter(const Datum& alter) const;

        // Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
        bool filterKilometer(const int& kilometer) const;

        // Zeigt alle Autos aus der Liste sortiert steigend nach Preis
        void showPriceSorted();

        // Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu (In Fall einer Kunde)
        virtual bool addToFavoriten(const Auto& carToAdd);

        // Zeigt die Liste von Lieblingsautos (In Fall einer Kunde)
        virtual bool showFavoriten() const;

        void operator=(const Repository& other);

        // Destructor
        virtual ~Repository();
    };
}
