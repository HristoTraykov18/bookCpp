#include "Chapter6.h"

class MainObject {
	int _object_number = (rand() % 25) + 1; // Random number from 1 to 25
	char _object_symbol = 'A' + (rand() % 26); // Random letter from A to Z (capital)

public:
	MainObject *next_obj = NULL; // Child object used to link the next object to the current object
	MainObject *prev_obj = NULL; // Parent object; Used when deleting one object from the chain

	int getNumber() {
		return _object_number;
	}
	
	char getSymbol() {
		return _object_symbol;
	}

	void showChain() {
		printf("This object has number %2d and symbol %c\n", getNumber(), getSymbol());
		
		if (next_obj)
			next_obj->showChain();
	}
};

void AddNewObjectToChain(MainObject *mo) {
	if (mo->next_obj)
		AddNewObjectToChain(mo->next_obj);
	else { // If this is the last object - create new one object 
		mo->next_obj = new MainObject;
		mo->next_obj->prev_obj = mo; // Set the new object's previous object to mo
		mo = mo->next_obj; // Set the next object of this one to the newly created object
		printf("Added object with number %d and symbol %c\n", mo->getNumber(), mo->getSymbol());
	}
}

void DeleteObjectsChain(MainObject *mo) { // Delete the entire object chain recursively
	if (mo->next_obj)
		DeleteObjectsChain(mo->next_obj);

	printf("Deleted object with number %d and symbol %c\n", mo->getNumber(), mo->getSymbol());
	delete mo;
}

bool RemoveLastObjectFromChain(MainObject *mo) { // Remove only the last object in the chain
	if (mo->next_obj) {
		if (RemoveLastObjectFromChain(mo->next_obj))
			return true;
	}

	printf("Deleted the last object with number %d and symbol %c\n", mo->getNumber(), mo->getSymbol());
	mo->prev_obj->next_obj = NULL; // Set the previous's next object to NULL because it won't exist
	delete mo;

	return true; // Deleting the last object returns true so no more objects are deleted
}

void chapter6Task3() {
	printf("TASK 3: Program that creates chain of objects.\n\tFunctionality for printing objects' values, deleting and adding objects\n");
	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	int obj_count;
	printf("Enter number of objects: ");
	cin >> obj_count;

	if (obj_count < 2)
		printf("Invalid input!\n");
	else {
		MainObject *mo = new MainObject;
		MainObject *current_mo = mo;

		for (int i = 1; i < obj_count; i++)
		{
			current_mo->next_obj = new MainObject;
			current_mo->next_obj->prev_obj = current_mo;
			current_mo = current_mo->next_obj;
		}

		printf("Objects chain:\n");
		mo->showChain();
		cout << endl;
		RemoveLastObjectFromChain(mo);
		cout << endl;
		printf("Objects chain:\n");
		mo->showChain();
		cout << endl;
		AddNewObjectToChain(mo);
		cout << endl;
		printf("Objects chain:\n");
		mo->showChain();
		cout << endl;
		DeleteObjectsChain(mo);
	}

	printTaskEndLine(); // Used from Main
}