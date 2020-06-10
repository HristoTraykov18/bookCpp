#include "Chapter6.h"

class MainObject {
	int _arr_len;
	double *_object_array;

public:
	MainObject(int arr_len) { // Constructor with 1 parameter
		_arr_len = arr_len;
		_object_array = new double[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			_object_array[i] = (rand() % _arr_len) + 1.0; // Random number from 1 to _arr_len
	}

	MainObject(int arr_len, double value) { // Constructor with 2 parameters
		_arr_len = arr_len;
		_object_array = new double[arr_len];

		for (int i = 0; i < arr_len; i++)
			_object_array[i] = value;
	}

	void displayArray() {
		printf("[");
		for (int i = 0; i < _arr_len; i++)
			printf("%.2f%s%s", _object_array[i], i < _arr_len - 1 ? "," : "", i < _arr_len - 1 ? " " : "");
		printf("]\n");
	}

	// Overriding operators

	double operator[](int index) {
		return (*this)._object_array[index];
	}

	double operator()() { // If the class is called as function, return sum of the values in the array
		double result = 0;
		for (int i = 0; i < _arr_len; i++)
			result += _object_array[i];

		return result;
	}

	MainObject operator+(MainObject mo) { // Adding object arrays
		MainObject new_mo = MainObject(_arr_len);

		for (int i = 0; i < _arr_len; i++)
			new_mo._object_array[i] = (* this)[i] + mo[i];

		return new_mo;
	}

	MainObject operator-(MainObject mo) { // Subtracting object arrays
		MainObject new_mo = MainObject(_arr_len);

		for (int i = 0; i < _arr_len; i++)
			new_mo._object_array[i] = (* this)[i] - mo[i];

		return new_mo;
	}

	MainObject operator*(MainObject mo) { // Multiplying object arrays
		MainObject new_mo = MainObject(_arr_len);

		for (int i = 0; i < _arr_len; i++)
			new_mo._object_array[i] = (* this)[i] * mo[i];

		return new_mo;
	}

	MainObject operator/(MainObject mo) { // Dividing object arrays
		MainObject new_mo = MainObject(_arr_len);

		for (int i = 0; i < _arr_len; i++)
			new_mo._object_array[i] = (* this)[i] / mo[i];

		return new_mo;
	}
};

void chapter6Task2() {
	printf("TASK 2: Program with object with integer array. Override the basic operators\n");
	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	int len;
	double val;

	printf("Enter length of arrays in objects: ");
	cin >> len;

	printf("Enter value to fill in the second object's array: ");
	cin >> val;

	MainObject objectA = MainObject(len);
	MainObject objectB = MainObject(len, val);
	cout << "Sum of elements of objectA array: " << objectA() << endl;
	cout << "Sum of elements of objectB array: " << objectB() << endl;

	MainObject objectC = objectA + objectB;

	printf("objectC array: "); 
	objectC.displayArray();

	cout << "Sum of elements of objectC array: " << objectC() << endl;

	int index_of_el;
	cout << "Which element would you like to check in objectC? ";
	cin >> index_of_el;
	cout << "The element is " << objectC[index_of_el - 1] << endl;

	printf("objectA - objectB return the array: "); 
	(objectA - objectB).displayArray();

	printf("objectA * objectB return the array: ");
	(objectA * objectB).displayArray();

	printf("objectA / objectB return the array: ");
	(objectA / objectB).displayArray();

	printTaskEndLine(); // Used from Main
}