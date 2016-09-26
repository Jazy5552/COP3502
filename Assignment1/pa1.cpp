#include "pa1.h"
#include <iostream>

using namespace std;

int main() {
	int **square1, **square2, **square3;
	int N;

	cout << "Enter the size of the magic square: ";
	cin >> N;

	square1 = createMagicSquare(N);
	square2 = createVMirMagicSquare(square1, N); //Cheeky
	square3 = createHMirMagicSquare(square1, N); //Cheeky

	cout << "\nMagic Square #1 is: \n\n";
	printMagicSquare(square1, N);
	cout << "\nChecking the sums of every row:      ";
	printRowSums(square1, N);
	cout << "\nChecking the sums of every column:   ";
	printColSums(square1, N);
	cout << "\nChecking the sums of every diagonal: ";
	printDiagSums(square1, N);

	cout << "\nMagic Square #2 is: \n\n";
	printMagicSquare(square2, N);
	cout << "\nChecking the sums of every row:      ";
	printRowSums(square2, N);
	cout << "\nChecking the sums of every column:   ";
	printColSums(square2, N);
	cout << "\nChecking the sums of every diagonal: ";
	printDiagSums(square2, N);

	cout << "\nMagic Square #3 is: \n\n";
	printMagicSquare(square3, N);
	cout << "\nChecking the sums of every row:      ";
	printRowSums(square3, N);
	cout << "\nChecking the sums of every column:   ";
	printColSums(square3, N);
	cout << "\nChecking the sums of every diagonal: ";
	printDiagSums(square3, N);

	cout << endl; //Leave the command line clean
	delete2DArray(square1, N);
	delete2DArray(square2, N);
	delete2DArray(square3, N);
	return 0;
}

