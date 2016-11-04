#include "stack.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Hello World!\n";
	Stack<int> iS;
	iS.push(10);
	iS.push(20);
	iS.push(30);
	iS.print();
	cout << endl;
	iS.pop();
	iS.print();
	cout << endl;
	iS.pop();
	iS.pop();
	iS.pop();
	return 0;
}

