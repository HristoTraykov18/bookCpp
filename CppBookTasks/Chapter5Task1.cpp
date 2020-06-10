#include "Chapter5.h"

class Parallelepiped {
protected:
	double width;
	double height;
	double length;

public:
	Parallelepiped() {
		width = 10.0;
		height = 15.0;
		length = 20.0;
		printf("Parallelepiped created with default values, width = %.0f, height = %.0f, length = %.0f\n", width, height, length);
	}

	Parallelepiped(double w, double h, double l) {
		width = w;
		height = h;
		length = l;
		printf("Parallelepiped created with custom values, width = %.0f, height = %.0f, length = %.0f\n", width, height, length);
	}

	void showValues() {
		printf("Width = %.2f\n", width);
		printf("Height = %.2f\n", height);
		printf("Length = %.2f\n", length);
		printf("Volume = %.2f\n", calcVolume());
	}

	double calcVolume() {
		return width * height * length;
	}
};

class BetterParallelepiped : public Parallelepiped {
	double area = NULL;
	double density = NULL;

public:
	BetterParallelepiped() : Parallelepiped() {}

	BetterParallelepiped(double w, double h, double l) : Parallelepiped(w, h, l) {}

	double calcArea() {
		area = 2 * ((width * height) + (width * length) + (height * length)); // 2 * (ab + ac + bc)
		return area;
	}

	double calcDensity() {
		density = area / calcVolume();
		return density;
	}

	void showValues() {
		Parallelepiped::showValues();
		printf("Area = %.2f\n", calcArea());
		printf("Density = %.2f\n\n", calcDensity());
	}

	BetterParallelepiped operator- (BetterParallelepiped p) {
		return BetterParallelepiped(height - p.height, width - p.width, length - p.length);
	}
};

void chapter5Task1() {
	printf("TASK 1: Program with class for parallelepipeds\n");

	BetterParallelepiped bp = BetterParallelepiped(20, 30, 50);
	BetterParallelepiped bp2 = BetterParallelepiped();
	BetterParallelepiped bp3 = bp - bp2;

	bp.showValues();
	bp2.showValues();
	bp3.showValues();

	printTaskEndLine(); // Used from Main
}