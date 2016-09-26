#ifndef PA1_H
#define PA1_H

#include <cstdio> //Sweet printf <3

//Create a magic square of NxN dimensions using the Siamese method 
//and return through int** (2 dimensional array). 
//Function will dynamically allocate memory so remember to delete it later!
int **createMagicSquare(int N) {
	//Create the NxN array
	int **arr = new int*[N];
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

//Returns a new 2d array of size NxN that is a mirrored version of the one given
//over the vertical
int **createVMirMagicSquare(int **arr, int N) {
	//Create the new array
	int **nArr = new int*[N];
	for (int i=0; i<N; i++) {
		nArr[i] = new int[N];
	}

	int tmp;
	for (int i=0; i<N; i++) {
		//i = row number
		for (int j=0; j<(N/2)+1; j++) {
			//j = col number
			nArr[i][j] = arr[i][N-j-1];
			nArr[i][N-j-1] = arr[i][j];
		}
	}
	return nArr;
}

//Returns a new 2d array of size NxN that is a mirrored version of the one given
//over the horizontal
int **createHMirMagicSquare(int **arr, int N) {
	//Create the new array
	int **nArr = new int*[N];
	for (int i=0; i<N; i++) {
		nArr[i] = new int[N];
	}

	int tmp;
	for (int i=0; i<N; i++) {
		//i = col number
		for (int j=0; j<(N/2)+1; j++) {
			//j = row number
			nArr[j][i] = arr[N-j-1][i];
			nArr[N-j-1][i] = arr[j][i];
		}
	}
	return nArr;
}

//Prints the sum of every row individually
void printRowSums(int **arr, int N) {
	for (int i=0; i<N; i++) {
		int sum = 0;
		for (int j=0; j<N; j++) {
			sum += arr[i][j];
		}
		printf("%d ", sum);
	}
}

//Prints the sum of every col individually
void printColSums(int **arr, int N) {
	for (int i=0; i<N; i++) {
		int sum = 0;
		for (int j=0; j<N; j++) {
			sum += arr[j][i];
		}
		printf("%d ", sum);
	}

}

//Prints the sum of every diagonal individually
void printDiagSums(int **arr, int N) {
	int sum = 0;
	//Print the \ diagonal
	for (int i=0; i<N; i++) {
		sum += arr[i][i];
	}
	printf("%d ", sum);

	sum = 0;
	//Print the / diagonal
	for (int i=0,j=(N-1); i<N; i++,j--) {
		sum += arr[i][j];
	}
	printf("%d ", sum);
}

//Prints the magic square
//NOTE: Maybe I should make this return a string? Leave the printing for main
void printMagicSquare(int **arr, int N) {
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}

void delete2DArray(int **arr, int N) {
	for (int i=0; i<N; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}


#endif
