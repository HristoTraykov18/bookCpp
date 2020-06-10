#include "Chapter4.h"

void chapter4Task5() { // Main subprogram
	int sum_natural_numbers(int, int);
	printf("TASK 5: Program that calculates sum of n^k with recursive function\n");
	int n = 1;
	int k = 1;
	printf("Enter n: ");
	cin >> n;
	printf("Enter k: ");
	cin >> k;
	printf("Sum = %d", sum_natural_numbers(n, k));

	printTaskEndLine(); // Used from Main
}

// ================================ Subprograms ================================
int sum_natural_numbers(int n, int k) {
	if (n > 1)
		return (int)pow(n, k) + sum_natural_numbers(n - 1, k);
	return 1;
}
