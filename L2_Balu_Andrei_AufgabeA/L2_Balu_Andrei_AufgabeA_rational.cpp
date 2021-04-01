#include "L2_Balu_Andrei_AufgabeA_rational.h"
#include <exception>
using namespace std;

Rational::Rational(int num, int den) {
	if (den != 0) {
		this->numerator = num;
		this->denominator = den;
	}
	else {
		throw exception();
	}
}

int const Rational::get_numerator() {
	return this->numerator;
}

void Rational::set_numerator(int value) {
	this->numerator = value;
}

int const Rational::get_denominator() {
	return this->denominator;
}

bool Rational::set_denominator(int value) {
	if (value == 0) {
		return false;
	}
	this->denominator = value;
	return true;
}

int Rational::compare(Rational other) {
	int numFirstNr = this->get_numerator() * other.get_denominator();
	int numSecondNr = other.get_numerator() * this->get_denominator();
	if (numFirstNr < numSecondNr) return -1;
	else if (numFirstNr == numSecondNr) return 0;
	return 1;
}

void Rational::inverse() {
	if (get_numerator() != 0) {
		int denominator = this->get_denominator();
		this->denominator = this->numerator;
		this->numerator = denominator;
	}
	else throw exception();
}

void Rational::reduce(){
	int numerator = get_numerator();
	int denominator = get_denominator();
	if (numerator != 0) {
		// ggt wird hier bestimmt
		while (numerator != denominator) {
			if (numerator > denominator)
				numerator -= denominator;
			else denominator -= numerator;
		}
		this->numerator /= numerator;
		this->denominator /= numerator;
	}
	else {
		this->denominator = 1;
	}
}

Rational Rational::add(Rational other) {
	int newNumerator, newDenominator;
	if (this->get_denominator() == other.get_denominator()) {
		newNumerator = this->get_numerator() + other.get_numerator();
		newDenominator = this->get_denominator();
	}
	else {
		newNumerator = this->get_numerator() * other.get_denominator() + other.get_numerator() * this->get_denominator();
		newDenominator = this->get_denominator() * other.get_denominator();
	}
	return Rational{ newNumerator, newDenominator };
}

Rational Rational::subtract(Rational other) {
	int newNumerator, newDenominator;
	if (this->get_denominator() == other.get_denominator()) {
		newNumerator = this->get_numerator() - other.get_numerator();
		newDenominator = this->get_denominator();
	}
	else {
		newNumerator = this->get_numerator() * other.get_denominator() - other.get_numerator() * this->get_denominator();
		newDenominator = this->get_denominator() * other.get_denominator();
	}
	return Rational{ newNumerator, newDenominator };
}

Rational Rational::multiply(Rational other) {
	int newNumerator = this->get_numerator() * other.get_numerator();
	int newDenominator = this->get_denominator() * other.get_denominator();
	return Rational(newNumerator, newDenominator);
}

Rational Rational::divide(Rational other) {
	if (other.get_numerator() != 0) {
		int newNumerator = this->get_numerator() * other.get_denominator();
		int newDenominator = this->get_denominator() * other.get_numerator();
		return Rational(newNumerator, newDenominator);
	}
	throw exception(); 
}

Rational Rational::operator + (Rational other) {
	return this->add(other);
}

Rational Rational::operator / (Rational other) {
	return this->divide(other);
}

Rational Rational::operator * (Rational other) {
	return this->multiply(other);
}

Rational Rational::operator - (Rational other) {
	return this->subtract(other);
}

Rational::~Rational() {
}