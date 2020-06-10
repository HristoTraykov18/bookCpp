#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"
#include "Chapter5.h"
#include "Chapter6.h"
#include "Chapter7.h"

void printTaskEndLine() {
	cout << string(50, '='); // Print the sign of equality 50 times
	cout << endl;
	cout << endl;
}

int main() {
	// This project includes the more interesting tasks from the C++ book I have (image of the book is included in the README)

	chapter2();
	chapter3();
	chapter4();
	chapter5();
	chapter6();
	chapter7();

	system("pause>nul"); // Don't close the console after executing the code
	return 0;
}