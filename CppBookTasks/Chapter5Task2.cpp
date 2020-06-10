#include "Chapter5.h"

# define M_PI           3.14159265358979323846  /* pi */

class ComplexNumber {
public:
	double real;
	double imaginary;

	ComplexNumber(double realNum, double imaginaryNum) { // Constructor with 2 parameters
		real = realNum;
		imaginary = imaginaryNum;
	}

	ComplexNumber Conjugate() {
		return ComplexNumber(real, -imaginary);
	}

	double getNorm() {
		return abs(sqrt((real * real) + (imaginary * imaginary)));
	}

	void showValues() {
		printf("Real part = %.2f\n", real);
		printf("Imaginary part = %.2f\n", imaginary);
	}

	// Overriding operators

	bool operator== (ComplexNumber cn) {
		return real == cn.real && imaginary == cn.imaginary;
	}

	ComplexNumber operator+ (ComplexNumber cn) {
		return ComplexNumber(real + cn.real, imaginary + cn.imaginary);
	}

	ComplexNumber operator- (ComplexNumber cn) {
		return ComplexNumber(
			real - cn.real, 
			imaginary - cn.imaginary);
	}

	ComplexNumber operator* (ComplexNumber cn) {
		return ComplexNumber(
			real * cn.real - imaginary * cn.imaginary, 
			real * cn.imaginary + imaginary * cn.real);
	}

	ComplexNumber operator* (double d) {
		return ComplexNumber(real * d, imaginary * d);
	}

	ComplexNumber operator/ (double d) {
		return ComplexNumber(real / d, imaginary / d);
	}

	/*~ComplexNumber() { // Destructor
		printf("Deleted object");
	}*/
};

class TrigonometricComplexNumber : public ComplexNumber {
public:
	TrigonometricComplexNumber(double realNum, double imaginaryNum) : ComplexNumber(realNum, imaginaryNum) { }

	void showValues() {
		ComplexNumber::showValues();
		double cosfi = real / getNorm();
		double sinfi = imaginary / getNorm();
		printf("Trigonometric representation: %.4f", getNorm() * (cosfi + sinfi));
	}

	/*~TrigonometricComplexNumber() { // Destructor
	printf("Deleted object");
	}*/
};

void chapter5Task2() {
	printf("TASK 2: Program with class for complex numbers\n");

	ComplexNumber cn = ComplexNumber(5.8, 15.2);
	ComplexNumber cn2 = ComplexNumber(25.7, 5.1);
	TrigonometricComplexNumber tcn = TrigonometricComplexNumber(25.5, 6);

	printf("cn values:\n");
	cn.showValues();

	printf("c2 values:\n");
	cn2.showValues();

	printf("cn - cn2:\n");
	(cn - cn2).showValues();

	printf("cn + cn2:\n");
	(cn + cn2).showValues();

	printf("cn * cn2:\n");
	(cn * cn2).showValues();

	printf("cn * 5:\n");
	(cn * 5).showValues();

	printf("cn / 5:\n");
	(cn / 5).showValues();

	printf("cn * 5 / 5:\n");
	(cn * 5 / 5).showValues();

	printf("cn conjugate:\n");
	cn.Conjugate().showValues();

	tcn.showValues();

	printTaskEndLine(); // Used from Main
}