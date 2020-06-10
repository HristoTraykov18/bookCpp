#include "Chapter2.h"

void chapter2() {
	printf("CHAPTER 2\n");
	printf("TASK 20: Fill array with random elements and order them as follows:\n");
	printf("- even numbers in descending order\n- odd numbers in ascending order\n");

	int numArr[10];
	int arrLen = sizeof(numArr) / sizeof(numArr[0]);

	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	printf("\nInitial array: ");
	for (int i = 0; i < arrLen; i++)
	{
		numArr[i] = rand() % 50; // Add random numbers from 0 to 50 to the array and print them
		printf("%3d %s", numArr[i], ((i < arrLen - 1) ? " " : "\n"));
	}

	int evenNums = 0;

	for (int i = 0; i < arrLen; i++) // Count the even numbers
		if (numArr[i] % 2 == 0)
			evenNums++;

	for (int i = evenNums; i < arrLen; i++) // Move the even numbers to the first part of the array
	{
		if (numArr[i] % 2 == 0)
		{
			for (int k = 0; k <= evenNums; k++)
			{
				if (numArr[k] % 2 == 1) {
					int temp = numArr[i];
					numArr[i] = numArr[k];
					numArr[k] = temp;
				}
			}
		}
	}

	for (int i = 1; i < arrLen; i++)
	{
		int temp = 0;
		if (i < evenNums)
		{ // Even numbers in descending order
			for (int k = i; k > 0; k--)
			{
				if (numArr[k] > numArr[k - 1]) {
					temp = numArr[k - 1];
					numArr[k - 1] = numArr[k];
					numArr[k] = temp;
				}
			}
		}
		else { // Odd numbers in ascending order
			for (int k = i; k < arrLen - 1; k++)
			{
				if (numArr[k] > numArr[k + 1]) {
					temp = numArr[k + 1];
					numArr[k + 1] = numArr[k];
					numArr[k] = temp;
				}
			}
		}
	}

	cout << "Sorted array: ";
	for (int i = 0; i < arrLen; i++)
		printf("%3d %s", numArr[i], ((i < arrLen - 1) ? " " : ""));

	printTaskEndLine(); // Used from Main
}