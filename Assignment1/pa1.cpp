#include "pa1.h"
#include <iostream>

using namespace std;

int main() {
	int** mSquare = createMagicSquare(3);
	cout << mSquare << endl;

	printMagicSquare(mSquare, 3);
	return 0;
}

