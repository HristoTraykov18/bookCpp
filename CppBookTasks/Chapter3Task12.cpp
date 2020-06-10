#include "Chapter3.h"

void chapter3() {
	printf("CHAPTER 3\n");
	printf("TASK 12: Program that calculates the product mathematical work of rectangular matrices");
	srand((unsigned int)time(0)); // Use current time as seed for random generator avoiding data loss warning

	int matrixA_row;
	int matrixA_col;
	int matrixB_row;
	int matrixB_col;

	printf("\nEnter matrix A rows: ");
	cin >> matrixA_row;
	printf("Enter matrix A columns and matrix B rows: ");
	cin >> matrixA_col;
	matrixB_row = matrixA_col;

	printf("Matrix A:\n");
	int **matrixA = new int *[matrixA_row];
	for (int i = 0; i < matrixA_row; i++) // Fill matrix A with random numbers and show them
	{
		matrixA[i] = new int [matrixA_col];
		for (int k = 0; k < matrixA_col; k++)
		{
			matrixA[i][k] = rand() % 10;
			printf("%2d%s", matrixA[i][k], k < matrixA_col - 1 ? " " : "\n");
		}
	}

	printf("\nEnter matrix B columns: ");
	cin >> matrixB_col;

	printf("Matrix B:\n");
	int **matrixB = new int *[matrixB_row];
	for (int i = 0; i < matrixB_row; i++) // Fill matrix B with random numbers and show them
	{
		matrixB[i] = new int[matrixB_col];
		for (int k = 0; k < matrixB_col; k++)
		{
			matrixB[i][k] = rand() % 10;
			printf("%2d%s", matrixB[i][k], k < matrixB_col - 1 ? " " : "\n");
		}
	}

	printf("\nMatrix C:\n");
	int **matrixC = new int *[matrixA_row];
	for (int i = 0; i < matrixA_row; i++) // Calculate matrix C and show it
	{
		matrixC[i] = new int[matrixB_col];
		for (int j = 0; j < matrixB_col; j++)
		{
			int sum = 0;
			for (int k = 0; k < matrixA_col; k++)
				sum += matrixA[i][k] * matrixB[k][j];
			matrixC[i][j] = sum; // C[i][j] = SUM(A[i][k] * B[k][j])
			printf("%3d%s", matrixC[i][j], j < matrixB_col - 1 ? " " : "\n");
		}
	}

	// Delete the memory
	for (int i = 0; i < matrixA_row; i++)
		delete[] matrixA[i];
	for (int i = 0; i < matrixB_row; i++)
		delete[] matrixB[i];
	for (int i = 0; i < matrixA_row; i++)
		delete[] matrixC[i];

	delete[] matrixA;
	delete[] matrixB;
	delete[] matrixC;

	printTaskEndLine(); // Used from Main
}