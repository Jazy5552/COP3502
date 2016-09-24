#include <iostream>

using namespace std;

int main() {
	int width = 5;
	int height = 3;

	int** arr = new int*[height];
	for (int i=0; i<height; i++) {
		arr[i] = new int[width];
	}

	cout << "Created" << endl;
	
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			arr[i][j] = width*i + j;
		}
	}

	cout << "Created" << endl;

	//Print addresses
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	//Print values by dereferencing the pointers
	for (int i=0; i<height; i++) {
		cout << (*arr)[i] << "\t"; //DOESNT WORK!!! Every row has some addresses of gap making this fail!
		if ((i+1) % width == 0)
			cout << endl;
	}

	cout << endl;
	return 0;
}

