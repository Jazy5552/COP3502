#include <iostream>
using namespace std;

void checkSums(int* magicSquare[], int size) {
  // Add up rows
  int rowSum = 0;
  int colSum = 0;
  int diagSum = 0;

  cout << "Rows: ";
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      rowSum+=magicSquare[row][col];
    }
    cout << rowSum << " ";
    rowSum = 0;
  }
  cout << endl;
  // Add up columns
  cout << "Cols: ";
  for (int col = 0; col < size; col++) {
    for (int row = 0; row < size; row++) {
      colSum+=magicSquare[row][col];
    }
    cout << colSum << " ";
    colSum = 0;
  }
  cout << endl;
  // Add up diags1
  cout << "Diags: ";
  for (int col = 0; col < size; col++) {
    for (int row = 0; row < size; row++) {
      if (row == col) {
        diagSum+=magicSquare[row][col];
      }
    }
  }
  cout << diagSum << " ";
  diagSum = 0;
  // Add up diags2
  for (int col = 0; col < size; col++) {
    for (int row = 0; row < size; row++) {
      if (row + col == size) {
        diagSum+=magicSquare[row][col];
      }
    }
  }
  cout << diagSum << " ";
  cout << endl;
}



int main() {
  cout << "Enter the size of the matrix you want to make: " << endl;
  int size;
  cin >> size;
  int** magicSquare1 = new int*[size];
  int** magicSquare2 = new int*[size];
  int** magicSquare3 = new int*[size];
  for (int i = 0; i < size; i++) {
    magicSquare1[i] = new int[size];
    magicSquare2[i] = new int[size];
    magicSquare3[i] = new int[size];
  }

  // Fill the square algorithm
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      magicSquare1[row][col] = row*col;
      magicSquare2[row][col] = row*col;
      magicSquare3[row][col] = row*col;
    }
  }

  for (int col = 0; col < size; col++) {
    for (int row = 0; row < size; row++) {
      magicSquare2[row][col] = magicSquare1[row][size-col-1];
    }
  }

  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      magicSquare3[row][col] = magicSquare1[size - row - 1][col];
    }
  }


  // Print
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      cout << magicSquare1[row][col] << "  ";
    }
    cout << endl;
  }
  checkSums(magicSquare1, size);
  cout << endl;
  cout << endl;


  // Print
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      cout << magicSquare2[row][col] << "  ";
    }
    cout << endl;
  }
  checkSums(magicSquare2, size);
  cout << endl;
  cout << endl;



  // Print
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      cout << magicSquare3[row][col] << "  ";
    }
    cout << endl;
  }
  checkSums(magicSquare3, size);


}
