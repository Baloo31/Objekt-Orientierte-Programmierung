#ifndef MANAGERREPOSITORY_H
#define MANAGERREPOSITORY_H

#endif // MANAGERREPOSITORY_H

#pragma once
#include "Auto.h"
#include "AbstractRepository.h"
using namespace autos;
using namespace abstrakterRepo;

namespace managerRepository {

    class ManagerRepository : public AbstrakterRepository<Auto> {
    private:
        vector<Auto> autos;

    public:
        // Defaultconstructor
        ManagerRepository();

        // Copyconstructor
        ManagerRepository(const ManagerRepository& other);

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

        void operator=(const ManagerRepository& other);

        vector<Auto> getAutos() const;

        void setAutos(const vector<Auto>& _autos);

        void leseAusDateien(string dFile, string fFile);

        void schreibeInDateien(string dFile, string fFile);

        // Destructor
        ~ManagerRepository();
    };
}
