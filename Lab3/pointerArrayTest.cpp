#include <iostream>

using namespace std;

int main() {
	int width = 8;
	int height = 6;

	int** arr = new int*[width];
	for (int i=0; i<width; i++) {
		arr[i] = new int[height];
	}

	
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			arr[i][j] = 10*i + j;
		}
	}

	//Print addresses
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			cout << &arr[i][j] << "\t";
		}
		cout << endl;
	}

	//Print values by dereferencing the pointers
	for (int i=0; i<height*width; i++) {
		cout << *(*(arr)+i) << "\t";
		if ((i+1) % width == 0)
			cout << endl;
	}

	cout << endl;
	return 0;
}

