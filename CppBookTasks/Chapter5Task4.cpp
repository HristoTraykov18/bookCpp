#include "Chapter5.h"

class Car {
protected:
	string _brand;
	string _color;
	double _fuelCapacity; // In liters
	double _fuelConsumption; // In liters

public:
	Car() { // Constructor without parameters
		_brand = "";
		_color = "";
		_fuelCapacity = 0.0;
		_fuelConsumption = 0.0;
	}

	Car(string brand, string color, double fuelCapacity, double fuelConsumption) { // Constructor with 4 parameters
		_brand = brand;
		_color = color;
		_fuelCapacity = fuelCapacity;
		_fuelConsumption = fuelConsumption;
	}

	void showValues() {
		cout << "Brand = " << _brand << endl;
		cout << "Color = " << _color << endl;
		cout << "Fuel capacity = " << _fuelCapacity << endl;
		cout << "Fuel consumption = " << _fuelConsumption << endl;
	}

	double calcDistance() { // Calculate the distance that can be travelled with full fuel tank
		return _fuelCapacity / _fuelConsumption * 100;
	}

	/*~Car() { // Destructor
	printf("Deleted object");
	}*/
};

class Truck : public Car {
	double _loadCapacity;

public:
	Truck() : Car() { _loadCapacity = 0.0; } // Constructor without parameters

	Truck(string brand, string color, double fuelCapacity, double fuelConsumption, double loadCapacity) 
		: Car(brand, color, fuelCapacity, fuelConsumption) { // Constructor with 5 parameters
		_loadCapacity = loadCapacity;
	}

	double CostPerKm(double fuelPrice) {
		return _fuelConsumption / 100.0 * fuelPrice;
	}

	/*~Truck() { // Destructor
	printf("Deleted object");
	}*/
};

void chapter5Task4() {
	printf("TASK 4: Program with class for cars and trucks\n");
	double fuelCost = 2.52;

	Car c1 = Car("Ferrari", "red", 100, 4.8);
	printf("The car can travel %.2f kilometers with full fuel tank.\n", c1.calcDistance());

	Truck t1 = Truck("JT", "black", 180, 8.2, 40);
	printf("The truck can travel %.2f kilometers with full fuel tank.\n", t1.calcDistance());
	printf("Cost per kilometer: %.2f", t1.CostPerKm(fuelCost));

	printTaskEndLine(); // Used from Main
}