#pragma once
class Rational {

private:
	int numerator;
	int denominator;

public:
	//Konstruktor
	Rational(int num, int den);

	//Getter fur Attribut numerator
	int const get_numerator();

	//Getter fur Attribut denominator
	int const get_denominator();


	//Setter fur Attribut numerator
	void set_numerator(int value);

	//Setter fur Attribut numerator
	bool set_denominator(int value);

	
	//Addizion zweier rationale Zahlen
	Rational add(Rational other);

	//Subtraktion zweier rationale Zahlen
	Rational subtract(Rational other);

	//Multiplikation zweier rationale Zahlen
	Rational multiply(Rational other);

	//Division zweier rationale Zahlen
	Rational divide(Rational other);


	//Uberschreiben des Operators '+'
	Rational operator + (Rational other); 

	//Uberschreiben des Operators '*'
	Rational operator * (Rational other);

	//Uberschreiben des Operators '-'
	Rational operator - (Rational other);

	//Uberschreiben des Operators '/'
	Rational operator / (Rational other);

	//Veraendert eine Rationale Zahl
	//in seine Irreduzible Form (basiert auf ggt)
	void reduce();

	//Kehrt eine Rationale Zahl um
	void inverse();

	//Vergleicht zwei Rationale Zahlen
	int compare(Rational other);

	//Destruktor
	~Rational();
};