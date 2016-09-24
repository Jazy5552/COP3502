#ifndef PA1_H
#define PA1_H

#include <cstdio> //Sweet printf <3

//Create a magic square of NxN dimensions using the Siamese method 
//and return through int** (2 dimensional array). 
//Function will dynamically allocate memory so remember to delete it later!
int** createMagicSquare(int N) {
	//Create the NxN array
	int** arr = new int*[N];
	for (int i=0; i<N; i++) {
		arr[i] = new int[N];
	}

	//Set the inital position to be centered horizontally on the top row
	int yPos = 0;
	int xPos = N / 2;

	//Populate the magic square
	for (int i=1; i<=N*N; i++) {
		if (arr[yPos][xPos] == 0) {
			//Current position is empty so just put a number in
			arr[yPos][xPos] = i;
		} else {
			//Perform the Siamese shift (Up shift + Right shift)
			//Pretty crude formula...
			if (arr[(yPos+(N-1))%N][(xPos+1)%N] == 0) {
				//Spot is empty! Store value here
				//Set the new positions
				//Shift 1 up and 1 right (Wrapping around when necessary
				yPos = (yPos+(N-1))%N;
				xPos = (xPos+1)%N;

				arr[yPos][xPos] = i; 
			} else if (arr[(yPos + 1)%N][xPos] == 0) {
				//Spot is taken so just shift 1 down
				//Set the new positions
				yPos = (yPos+1)%N;
				//xPos = xPos;
				
				arr[yPos][xPos] = i;
			} else {
				printf("Error in the magic square. Further debugging necessary!\n");
				//Wierd...
			}
		}
	}
	return arr;
}

//TODO Returns a new 2d array of size NxN that is a rotated version of the one given
//in clockwise rotation
int** createRotMagicSquare(int** arr, int N) {

}

//TODO Returns a new 2d array of size NxN that is a mirrored version of the one given
//over the horizontal
int ** createMirMagicSquare(int** arr, int N) {

}

//Prints the magic square
//NOTE: Maybe I should make this return a string? Leave the printing for main
void printMagicSquare(int** arr, int N) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void delete2DArray(int** arr, int N) {
	for (int i=0; i<N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}


#endif
