#include <iostream>
#include "L2_Balu_Andrei_AufgabeA_rational.h"
#include <assert.h>
#include <exception>

using namespace std;

void test_create() {
	cout << "Test Konstruktor - ";
	try {
		Rational unwishedObj{ 4, 0 };
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		Rational normalObj{ 4, 2 };
		assert(true);
		assert(normalObj.get_denominator() == 2);
		assert(normalObj.get_numerator() == 4);
	}
	catch (exception&) {
		assert(false);
	}
	try {
		Rational anotherNormalObj{ -9, 5 };
		assert(true);
		assert(anotherNormalObj.get_denominator() == 5);
		assert(anotherNormalObj.get_numerator() == -9);
	}
	catch (exception&) {
		assert(false);
	}
	cout << "SUCCES" << endl;
}

void test_denominator_setter() {
	cout << "Test set_denominator() - ";
	Rational nr1{ 2, 3 };
	assert((nr1.set_denominator(4) == true) && (nr1.get_denominator() == 4));
	assert((nr1.set_denominator(0) == false) && (nr1.get_denominator() == 4));
	cout << "SUCCES" << endl;
}

void test_numerator_setter() {
	cout << "Test set_numerator() - ";
	Rational nr{ 4, 3 };
	assert((nr.get_numerator() == 4) && (nr.get_denominator() == 3));
	nr.set_numerator(-2);
	assert((nr.get_numerator() == -2) && (nr.get_denominator() == 3));
	nr.set_numerator(0);
	assert((nr.get_numerator() == 0) && (nr.get_denominator() == 3));
	cout << "SUCCES" << endl;
}

void test_reduce() {
	cout << "Test reduce() - ";
	Rational nr1{ 22, 6 };
	nr1.reduce();
	assert((nr1.get_denominator() == 3) && (nr1.get_numerator() == 11));
	Rational nr2{ 1, 6 };
	nr2.reduce();
	assert((nr2.get_denominator() == 6) && (nr2.get_numerator() == 1));
	Rational nr3{ 0, 19 };
	nr3.reduce();
	assert((nr3.get_denominator() == 1) && (nr3.get_numerator() == 0));
	Rational nr4{ 11, 11 };
	nr4.reduce();
	assert((nr4.get_denominator() == 1) && (nr4.get_numerator() == 1));
	Rational nr5{ 0, 15 };
	nr5.reduce();
	assert((nr5.get_denominator() == 1) && (nr5.get_numerator() == 0));
	cout << "SUCCES" << endl;
}

void test_inverse() {
	cout << "Test inverse() - ";
	Rational nr1{ 0, 3 };
	try {
		nr1.inverse();
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	Rational nr2{ 12, 11 };
	nr2.inverse();
	assert((nr2.get_denominator() == 12) && (nr2.get_numerator() == 11));
	cout << "SUCCES" << endl;
}

void test_compare() {
	cout << "Test compare() - ";
	Rational a{ 1, 2 };
	Rational b{ 2, 4 };
	assert((a.compare(b) == 0) && (b.compare(a) == 0));
	Rational c{ 1, 3 };
	assert((a.compare(c) == 1) && (c.compare(a) == -1));
	Rational d{ -2, -2 };
	Rational e{ 2, 2 };
	assert((d.compare(e) == 0) && (e.compare(d) == 0));
	Rational f{ -2, 1 };
	Rational g{ 2, -1 };
	assert((f.compare(g) == 0) && (g.compare(f) == 0));
	Rational h{ -2, 1 };
	Rational i{ 2, 1 };
	assert((h.compare(i) == -1) && (i.compare(h) == 1));
	cout << "SUCCES" << endl;
}


void test_add() {
	cout << "Test add - ";
	Rational nr1{10, 2};
	Rational nr2{ 4, 5 };

	Rational rez1 = nr1.add(nr2);
	rez1.reduce();
	assert((rez1.get_numerator() == 29) && (rez1.get_denominator() == 5));

	Rational rez2 = nr1 + nr2;
	rez2.reduce();
	assert((rez2.get_numerator() == 29) && (rez2.get_denominator() == 5));

	Rational rez3 = nr2.add(rez2);
	assert((rez3.get_numerator() == 33) && (rez3.get_denominator() == 5));

	cout << "SUCCES" << endl;
}

void test_sub() {
	cout << "Test subtract - ";
	Rational nr1{ 10, 2 };
	Rational nr2{ 4, 5 };

	Rational rez1 = nr1.subtract(nr2);
	rez1.reduce();
	assert((rez1.get_numerator() == 21) && (rez1.get_denominator() == 5));

	Rational rez2 = nr1 - nr2;
	rez2.reduce();
	assert((rez2.get_numerator() == 21) && (rez2.get_denominator() == 5));
	cout << "SUCCES" << endl;
}

void test_mul() {
	cout << "Test mul - ";
	Rational nr1{ 1, 2 };
	Rational nr2{ 7, 7 };

	Rational rez1 = nr1.multiply(nr2);
	rez1.reduce();
	assert((rez1.get_numerator() == 1) && (rez1.get_denominator() == 2));

	Rational rez2 = nr1 * nr2;
	rez2.reduce();
	assert((rez2.get_numerator() == 1) && (rez2.get_denominator() == 2));
	cout << "SUCCES" << endl;
}

void test_div() {
	cout << "Test div - ";
	Rational nr1{ 1, 2 };
	Rational nr2{ 1, 4 };

	Rational rez1 = nr1.divide(nr2);
	rez1.reduce();
	assert((rez1.get_numerator() == 2) && (rez1.get_denominator() == 1));

	Rational rez2 = nr1 / nr2;
	rez2.reduce();
	assert((rez2.get_numerator() == 2) && (rez2.get_denominator() == 1));

	Rational nr3{ 0, 1 };
	Rational rez3 = nr3 / nr1;
	rez3.reduce();
	assert((rez3.get_numerator() == 0) && (rez2.get_denominator() == 1));
	try {
		Rational rez4 = nr2.divide(nr3);
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	try {
		Rational rez5 = nr1 / nr3;
		assert(false);
	}
	catch (exception&) {
		assert(true);
	}
	cout << "SUCCES" << endl;
}

int main() {
	test_denominator_setter();
	test_numerator_setter();
	test_reduce();
	test_inverse();
	test_compare();
	test_create();
	test_add();
	test_sub();
	test_mul();
	test_div();

	Rational reihe[5] = { { 1, 2 }, { 3, 4 }, { 5, 5 }, { 20, 10 }, { 100, 4} };
	Rational sum{ 0, 1 };
	for (int index = 0; index < 5; index++) {
		sum = sum + reihe[index];
	}
	sum.reduce();
	cout << "Die Summe der Reihe: " << sum.get_numerator() << "/" << sum.get_denominator();
	return 0;
}