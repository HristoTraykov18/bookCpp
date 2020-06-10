#include "Chapter6.h"

class TaskObject {
	int _arr_len;
	TaskObject **_obj_array;

public:
	TaskObject() {
		_arr_len = 0;
		_obj_array = new TaskObject *[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			_obj_array[i] = 0;
	}

	TaskObject(int arr_len) {
		_arr_len = arr_len;
		_obj_array = new TaskObject *[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			_obj_array[i] = NULL;
	}

	void addToArray(TaskObject *object_to_add) {
		for (int i = 0; i < _arr_len; i++)
		{
			if (_obj_array[i] != NULL) {
				if (i != _arr_len - 1)
					continue;
				else {
					char answer;
					printf("There already is object pointer at position %d. Would you like to replace it (Y/n): ", _arr_len - 1);
					cin >> answer;
					if (tolower(answer) != 'n') {
						_obj_array[_arr_len - 1] = object_to_add;
						printf("Replaced last object pointer\n");
					}
					else
						printf("Nothing changed\n");
				}
			}
			else {
				_obj_array[i] = object_to_add;
				printf("Added new object pointer to the array at position %d\n", i);
				break;
			}
		}
	}

	void addToArray(TaskObject *object_to_add, int position) {
		if (position >= 0 && position < _arr_len) {
			if (_obj_array[position]) {
				char answer;
				printf("There already is object pointer at position %d. Would you like to replace it (Y/n): ", position);
				cin >> answer;
				if (tolower(answer) != 'n') {
					_obj_array[position] = object_to_add;
					printf("Replaced object pointer at position %d\n", position);
				}
				else
					printf("Nothing changed\n");
			}
			else {
				_obj_array[position] = object_to_add;
				printf("Added new object pointer to the array at position %d\n", position);
			}
		}
		else
			printf("Invalid position! Valid options are 0-%d. Your input was %d.\n", _arr_len - 1, position);
	}

	void checkElement(int position) {
		if (position >= 0 && position < _arr_len) {
			if (_obj_array[position])
				printf("Object pointer at position %d exists\n", position);
			else
				printf("No object pointer at position %d\n", position);
		}
		else
			printf("Invalid position! Valid options are 0-%d. Your input was %d.\n", _arr_len - 1, position);
	}

	void removeFromArray(int position) {
		if (position >= 0 && position < _arr_len) {
			if (_obj_array[position]) {
				_obj_array[position] = NULL;
				printf("Deleted object pointer at position %d\n", position);
			}
			else
				printf("No object pointer at position %d\n", position);
		}
		else
			printf("Invalid position! Valid options are 0-%d. Your input was %d.\n", _arr_len - 1, position);
	}

	void showObjectPositions() {
		printf("Very basic way to show on which positions the array has object pointers\n");
		printf("[ ");
		for (int i = 0; i < _arr_len; i++)
		{
			if (_obj_array[i] == NULL)
				printf("X "); // If there isn't object pointer print X
			else
				printf("O "); // If there is object pointer print O
		}
		printf("]\n");
	}
};

void chapter6Task5() {
	printf("TASK 5: Program with class containing field, which is array of pointers to objects\n");
	int arr_len;
	printf("Enter length of array in object: ");
	cin >> arr_len;

	if (arr_len < 1)
		printf("Invalid length!\n");
	else {
		TaskObject *to = new TaskObject(arr_len);
		for (int i = 0; i < arr_len; i++)
			to->addToArray(new TaskObject(arr_len));

		to->showObjectPositions();

		to->addToArray(new TaskObject(arr_len), 2);
		to->addToArray(new TaskObject(arr_len));

		to->checkElement(0);
		to->checkElement(arr_len - 1);
		to->checkElement(20);

		to->removeFromArray(arr_len - 1);
		to->removeFromArray(0);
		to->showObjectPositions();
	}

	printTaskEndLine(); // Used from Main
}