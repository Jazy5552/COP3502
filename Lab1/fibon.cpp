#include <iostream>

using namespace std;

int main() {
	int in, last, x;
	cout << "#";
	cin >> in;

	last = 0;
	x = 1;

	while (x <= in) {
		cout << x << ", ";
		x += last;
		last = x - last;
	}

	cout << endl;

	return 0;
}

