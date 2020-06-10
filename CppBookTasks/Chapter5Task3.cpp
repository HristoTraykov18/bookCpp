#include "Chapter5.h"

class Vector {
protected:
	double cX;
	double cY;

public:
	Vector() { // Constructor without parameters
		cX = 0.0;
		cY = 0.0;
	}

	Vector(double coordinateX, double coordinateY) { // Constructor with 2 parameters
		cX = coordinateX;
		cY = coordinateY;
	}

	void showValues() {
		printf("X = %.2f ", cX);
		printf("Y = %.2f\n", cY);
	}

	// Overriding operators

	double operator* (Vector v) {
		return cX * v.cX + cY * v.cY;
	}

	Vector operator+ (Vector v) {
		return Vector(cX + v.cX, cY + v.cY);
	}

	Vector operator- (Vector v) {
		return Vector(cX - v.cX, cY - v.cY);
	}

	Vector operator* (double n) {
		return Vector(cX * n, cY * n);
	}

	Vector operator/ (double n) {
		return Vector(cX / n, cY / n);
	}

	/*~Vector() { // Destructor
	printf("Deleted object");
	}*/
};

class Vector3D : public Vector {
	double cZ;

public:
	Vector3D() : Vector() { cZ = 0.0; } // Constructor without parameters

	Vector3D(double coordinateX, double coordinateY, double coordinateZ) : Vector(coordinateX, coordinateY) { // Constructor with 3 parameters
		cZ = coordinateZ;
	}

	void showValues() {
		printf("X = %.2f ", cX);
		printf("Y = %.2f ", cY);
		printf("Z = %.2f\n", cZ);
	}
	// Overriding operators

	double operator* (Vector3D v) {
		return cX * v.cX + cY * v.cY + cZ * v.cZ;
	}

	Vector3D operator+ (Vector3D v) {
		return Vector3D(cX + v.cX, cY + v.cY, cZ + v.cZ);
	}

	Vector3D operator- (Vector3D v) {
		return Vector3D(cX - v.cX, cY - v.cY, cZ - v.cZ);
	}

	Vector3D operator* (double n) {
		return Vector3D(cX * n, cY * n, cZ * n);
	}

	Vector3D operator/ (double n) {
		return Vector3D(cX / n, cY / n, cZ / n);
	}

	/*~Vector3D() { // Destructor
	printf("Deleted object");
	}*/
};

void chapter5Task3() {
	printf("TASK 3: Program with class for vectors\n");

	Vector vect = Vector(5, 10);
	Vector vect2 = Vector(15, 20);

	printf("vect + vect2: ");
	(vect + vect2).showValues();

	printf("vect - vect2: ");
	(vect - vect2).showValues();

	printf("vect * vect2: %.2f\n", (vect * vect2));

	printf("vect * 5: ");
	(vect * 5).showValues();

	printf("vect / 5: ");
	(vect / 5).showValues();

	Vector3D vect3d = Vector3D(6, 9, 7);
	Vector3D vect3d2 = Vector3D(4, 22, 13);

	printf("vect3d + vect3d2: ");
	(vect3d + vect3d2).showValues();

	printf("vect3d - vect3d2: ");
	(vect3d - vect3d2).showValues();

	printf("vect3d * vect3d2: %.2f\n", (vect * vect2));

	printf("vect3d * 5: ");
	(vect3d * 5).showValues();

	printf("vect3d / 5: ");
	(vect3d / 5).showValues();

	printTaskEndLine(); // Used from Main
}