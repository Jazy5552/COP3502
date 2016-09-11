#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	string in;
	bool pally = true;
	cout << "#";
	
	cin >> in;

	for (int i=0; i < in.size(); i++) {
		if (in[i] != in[in.size() - 1 - i])
			pally = false;
	}

	if (pally) {
		cout << in << " is a palindrome.\n";
	} else {
		cout << in << " is not a palindrome.\n";
	}

	return 0;
}

