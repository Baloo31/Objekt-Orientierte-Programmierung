#pragma once

namespace datum {
    class Datum {
    private:
        int tag;
        int monat;
        int jahr;

    public:
        // Constructor
        Datum(int tag, int monat, int jahr);

        // Constructor
        Datum(const Datum& other);

        // Defaultconstructor
        Datum();

        // Getters & setters
        int getTag() const;
        int getMonat() const;
        int getJahr() const;
        void setTag(int tag);
        void setMonat(int monat);
        void setJahr(int jahr);

        bool const operator==(const Datum& other);
        bool const operator<(const Datum& other);

        // Destructor
        ~Datum();
    };
}
