#pragma once
#include "Repository.h"
using namespace repository;

namespace clientRepository {

    class ClientRepository : public Repository {
    private:
        vector<Auto> favoriten;

    public:
        // Defaultconstructor
        ClientRepository();

        // Copyconstructor
        ClientRepository(const ClientRepository& other);

        // Fugt ein Auto aus der Liste von Autos zur Liste von Lieblingsautos hinzu
        bool addToFavoriten(const Auto& carToAdd);

        // Zeigt die Liste von Lieblingsautos
        bool showFavoriten() const;

        // Destructor
        ~ClientRepository();
    };
}