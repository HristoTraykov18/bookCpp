#include "Chapter7.h"

template <class ArrayType> class ContainerTemplate {
	int _arr_len = 1;

	ArrayType* sortArray(ArrayType *arr) {
		for (int i = 0; i < _arr_len; i++)
		{
			for (int k = i; k < _arr_len - 1; k++)
			{
				if (arr[k] > arr[k + 1])
				{
					ArrayType temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}

		return arr;
	}

public:
	ArrayType *arr = new ArrayType[_arr_len];

	ContainerTemplate() {
		arr[0] = (rand() % 10) + 1; // Random number from 1 to 10 including
	}

	ContainerTemplate(ArrayType *arr_to_insert, const int arr_len) {
		_arr_len = arr_len;
		arr = new ArrayType[_arr_len];
		cout << "Created array of type " << typeid(arr).name() << ": [ ";

		for (int i = 0; i < _arr_len; i++)
			arr[i] = arr_to_insert[i];

		arr = sortArray(arr);
		 
		for (int i = 0; i < _arr_len; i++)
			cout << arr[i] << " ";
		cout << "]\n";
	}

	void addElement(ArrayType element) {
		_arr_len++;
		ArrayType *tempArr = new ArrayType[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			tempArr[i] = arr[i];

		tempArr[_arr_len - 1] = element;
		arr = new ArrayType[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			arr[i] = tempArr[i];

		arr = sortArray(arr);
		delete[] tempArr;
		cout << "Added " << element << " to array of type " << typeid(arr).name() << ".\n";
	}

	void removeLastElement() {
		_arr_len--;
		ArrayType *tempArr = new ArrayType[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			tempArr[i] = arr[i];

		arr = new ArrayType[_arr_len];

		for (int i = 0; i < _arr_len; i++)
			arr[i] = tempArr[i];

		arr = sortArray(arr);
		delete[] tempArr;
		cout << "Removed last element from " << typeid(arr).name() << " array.\n";
	}

	void operator()() {
		cout << "Array of type " << typeid(arr).name() << ": [ ";

		for (int i = 0; i < _arr_len; i++)
			cout << arr[i] << " ";
		cout << "]\n";
	}
};

void chapter7Task2() {
	printf("TASK 2: Program with template class which contains ordered array.\n\tArray elements can be added and removed, resizing the array.\n");
	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	const int arr_len = 5;
	char char_arr[arr_len];
	int int_arr[arr_len];

	for (int i = 0; i < arr_len; i++)
	{
		char_arr[i] = (rand() % 2) ? 'a' + (rand() % 26) : 'A' + (rand() % 26); // Random letter
		int_arr[i] = (rand() % 10) + 1; // Random number from 1 to 10 including
	}

	ContainerTemplate<char> charContainter(char_arr, arr_len);
	ContainerTemplate<int> intContainter(int_arr, arr_len);

	charContainter.addElement((rand() % 2) ? 'a' + (rand() % 26) : 'A' + (rand() % 26)); // Add random letter
	intContainter.addElement((rand() % 10) + 1); // Add random number from 1 to 10

	charContainter();
	intContainter();

	charContainter.removeLastElement();
	intContainter.removeLastElement();

	charContainter();
	intContainter();

	printTaskEndLine(); // Used from Main
}