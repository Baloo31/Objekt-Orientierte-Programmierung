#ifndef ABSTRACTREPOSITORY_H
#define ABSTRACTREPOSITORY_H

#endif // ABSTRACTREPOSITORY_H

#pragma once
#include<vector>
#include<string>
using namespace std;

namespace abstrakterRepo {
    template <class Entitat>
    class AbstrakterRepository
    {
    public:
        virtual bool fugeEin(const Entitat& elementFurEinfugen) = 0;

        virtual bool losche(const Entitat& elementFurLoschen) = 0;

        virtual bool aktualisiere(const Entitat& elementFurAktualisieren) = 0;

        virtual bool fugeZurFavoritenEin(const Entitat& elementFurEinfugen) = 0;

        virtual vector<Entitat> zeigeFavoriten() const = 0;

        virtual bool sucheMarke(const string& value) const = 0;

        virtual bool sucheModell(const string& value) const = 0;

        virtual vector<Entitat> filterAlter(const int& value) const = 0;

        virtual vector<Entitat> filterKilometer(const int& value) const = 0;

        virtual vector<Entitat> zeigeNachPreisSortiert() = 0;

        virtual void leseAusDateien(string dFile, string fFile) = 0;

        virtual void schreibeInDateien(string dFile, string fFile) = 0;

        virtual vector<Entitat> getAutos() const = 0;

        virtual void setAutos(const vector<Entitat>& entitaten) = 0;

        virtual ~AbstrakterRepository() {};
    };
}
