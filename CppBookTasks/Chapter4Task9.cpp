#include "Chapter4.h"

double calcSin(double);
double calcCos(double);
void getDerivative(double(*)(double), double);
void getDerivative(double(*)(double), double[], double[]);
const int arr_len = 5;

void chapter4Task9() { // Main subprogram
	printf("TASK 9: Program with function that calculates derivative of a function:\n");
	printf("\tFirst arguement is pointer to a differentiable function\n");
	printf("\tSecond arguement is point in which the derivative is calculated\n");
	printf("\tOverload of the function with differentiable function,\n");
	printf("\tarray of numbers and array of output numbers\n");

	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	double input_arr[arr_len];
	double output_arr[arr_len];
	double x = ((rand() % 10000) + 1.0) / 10000.0; // Random number from 0.0001 to 0.1
	double (*cp) (double);

	printf("x = %.4f\n", x);

	printf("sin(x) = %.6f\n", calcSin(x));
	printf("cos(x) = %.6f\n", calcCos(x));

	cp = calcSin;
	printf("sin'(x) = ");
	getDerivative(cp, x);

	cp = calcCos;
	printf("cos'(x) = ");
	getDerivative(cp, x);

	printf("\nInput array: ");
	for (int i = 0; i < arr_len; i++)
	{
		input_arr[i] = ((rand() % 10000) + 1.0) / 10000.0; // Add random numbers from 0.0001 to 0.1 to the array and print them
		printf("%.4f %s", input_arr[i], ((i < arr_len - 1) ? " " : "\n"));
	}
	cp = calcSin;
	printf("\nOutput array sin(x): ");
	getDerivative(cp, input_arr, output_arr);

	cp = calcCos;
	printf("\nOutput array cos(x): ");
	getDerivative(cp, input_arr, output_arr);

	printTaskEndLine(); // Used from Main
}

// ================================ Subprograms ================================
double calcCos(double x) {
	int n = 100; // Upper function boundary
	double result = 1.0;

	for (int k = 1; k <= n; k++)
	{
		double divider = 1;
		for (int i = 2 * k; i > 1; i--)
			divider *= i;
		result += ((pow((-1), k)) * (pow(x, 2 * k))) / divider;
	}

	return result;
}

double calcSin(double x) {
	int n = 100; // Upper function boundary
	double result = x;

	for (int k = 1; k <= n; k++)
	{
		double divider = 1;
		for (int i = (2 * k) + 1; i > 1; i--)
			divider *= i;
		result += ((pow((-1), k)) * (pow(x, ((2 * k) + 1)))) / divider;
	}

	return result;
}

void getDerivative(double (*F)(double), double x) {
	double h = 0.01; // Small increase of the arguement
	printf("%.12f\n", F(x + h) - F(x));
}

void getDerivative(double (*F)(double), double in_arr[], double out_arr[]) {
	for (int i = 0; i < arr_len; i++)
		out_arr[i] = F(in_arr[i]);

	for (int i = 0; i < arr_len; i++)
		printf("%.12f %s", out_arr[i], ((i < arr_len - 1) ? " " : "\n"));
}
