#ifndef KUNDEREPOSITORY_H
#define KUNDEREPOSITORY_H

#endif // KUNDEREPOSITORY_H

#pragma once
#include "Auto.h"
#include "Kunde.h"
#include "AbstractRepository.h"
using namespace kunde;
using namespace autos;
using namespace abstrakterRepo;

namespace kundeRepository {

    class KundeRepository : public AbstrakterRepository<Auto> {
    private:
        Kunde kunde;
        vector<Auto> autos;
        vector<Auto> favoriten;

    public:
        // Defaultconstructor
        KundeRepository();

        // Constructor
        KundeRepository(const Kunde& _kunde);

        // Copyconstructor
        KundeRepository(const KundeRepository& other);

        // Fugt ein Auto in die Liste von Autos hinzu
        bool fugeEin(const Auto& autoFurEinfugen);

        // Loscht ein Auto aus der Liste von Autos
        bool losche(const Auto& autoFurLoschen);

        // Aktualisiert ein Auto aus der Liste von Autos
        bool aktualisiere(const Auto& autoFurAktualisieren);

        // Ergibt die Position eines Autos in der Liste (-1 falls dieses Auto nicht existiert)
        int suche(const Auto& autoFurSuchen);

        // Bestimmt ob ein gegebenen Modell eines Autos in die Liste von Autos existiert
        bool sucheModell(const string& modell) const;

        // Bestimmt ob eine gegebene Marke eines Autos in die Liste von Autos existiert
        bool sucheMarke(const string& marke) const;

        // Zeigt alle Autos deren Erstzulassungsjahr neuer als ein angegebenen Jahr sind
        vector<Auto> filterAlter(const int& jahr) const;

        // Zeigt alle Autos deren Kilometer weniger als eine angegebene Kilometeranzahl sind
        vector<Auto> filterKilometer(const int& kilometer) const;

        // Zeigt alle Autos aus der Liste sortiert steigend nach Preis
        vector<Auto> zeigeNachPreisSortiert();

        // Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu (In Fall einer Kunde)
        bool fugeZurFavoritenEin(const Auto& autoFurEinfugen);

        // Zeigt die Liste von Lieblingsautos (In Fall einer Kunde)
        vector<Auto> zeigeFavoriten() const;

        void operator=(const KundeRepository& other);

        vector<Auto> getAutos() const;

        void setAutos(const vector<Auto>& _autos);

        void schreibeInDateien(string dFile, string fFile);

        void leseAusDateien(string dFile, string fFile);

        // Destructor
        ~KundeRepository();
    };
}
