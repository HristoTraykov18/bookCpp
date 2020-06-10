#include "Chapter4.h"

double exp(int, int);
int factorial(int);

void chapter4Task6() { // Main subprogram
	printf("TASK 6: Program that calculates exp(x) with recursive function\n");
	int x = 1;
	int n = 1;
	printf("Enter x: ");
	cin >> x;
	printf("Enter n: ");
	cin >> n;
	printf("Exp(x) = %.2f", exp(x, n));

	printTaskEndLine(); // Used from Main
}

// ================================ Subprograms ================================
double exp(int x, int n) {
	if (n > 1)
		return exp(x, n - 1) + (pow(x, n) / factorial(n));
	return 1;
}

int factorial(int n) {
	if (n > 1)
		return n * factorial(n - 1);
	return 1;
}
