#pragma once
#include "Repository.h"
using namespace repository;

namespace managerRepository {

    class ManagerRepository : public Repository {
    public:
        // Defaultconstructor
        ManagerRepository();

        // Copyconstructor
        ManagerRepository(const ManagerRepository& other);

        // Fugt ein Auto in die Liste von Autos hinzu
        bool einfugen(const Auto& carToAdd);

        // Loscht ein Auto aus der Liste von Autos
        bool loschen(const Auto& carToDelete);

        // Aktualisiert ein Auto aus der Liste von Autos
        bool update(const Auto& carToUpdate);

        // Destructor
        ~ManagerRepository();
    };
}
