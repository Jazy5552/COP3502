#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int num;
	cout << "#";

	cin >> num;
	if (fmod(sqrt(num), 1) == 0) {
		cout << num << " is a power of two!\n";
	} else {
		cout << num << " is not a power of two!\n";
	}

	return 0;
}

