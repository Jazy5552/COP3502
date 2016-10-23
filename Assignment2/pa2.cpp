#include "pa2.h"
#include <iostream>
#include "linkedlist.h"

//Menu items
#define ADD 1
#define KILL 2
#define FRAG 3
#define PRINT 4
#define QUIT 5
#define DEBUG 0


using namespace std;

const int MEMSIZE = 32;
const string FREE = "Free"; //I like constants
const string BEST = "best";
const string WORST = "worst";

int main(int argc, char **args) {
	if (argc != 2) {
		cout << "Invalid number of arguments (Should only pass one)" << endl;
		return 1;
	}

	string choice = args[1];
	LinkedList *ll = new LinkedList();
	int (*algo)(LinkedList *ll, int size); //oh god

	if (choice.compare(BEST) == 0) {
		//Best algorithm was selected
		cout << "Best algorithm was selected" << endl;
		algo = &findBestFit; //Savage
	} else if (choice.compare(WORST) == 0) {
		//Worst algoritm was selected
		cout << "Worst algorithm was selected" << endl;
		algo = &findWorstFit; //Savage
	} else {
		cout << "Invalid algorithm selected" << endl;
		return 1;
	}

	//Create the main memory pool
	NodeData nD(FREE, true, MEMSIZE);
	ll->insert(nD);

	//Print the menu
	cout << "\n"
		"\t1. Add Program\n"
		"\t2. Kill Program\n"
		"\t3. Fragmentation\n"
		"\t4. Print Memory\n"
		"\t5. Quit\n\n";
	//Main loop
	int n;
	do {
		cout << "Enter an option (1-5): ";
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			n = -1;
			cout << "Input invalid" << endl;
		} else if (n == ADD) {
			addProgram(ll, algo);
		} else if (n == KILL) {
			killProgram(ll);
		} else if (n == FRAG) {
			printFragments(ll);
		} else if (n == PRINT) {
			printMemory(ll);
		} else if (n == QUIT) {
			//Nothing?
		} else if (n == DEBUG) {
			ll->printList();
		} else {
			//Invalid input?
			cout << "Invalid input" << endl; //Dat consistency
			collapseFreeMem(ll);
		}
		cout << endl;
	} while (n != QUIT);

	cout << "Program exitting" << endl;
	//Should I delete the linked list? na
	return 0;
}

void addProgram(LinkedList *ll, int (*algo)(LinkedList *, int)) {
	string pName;
	int blockSize;
	int pos;
	//Gather the intel
	cout << "Program name: ";
	cin >> pName;
	cout << "Program size (KB): ";
	cin >> blockSize;

	//Check for duplicate or 0 size?
	if (ll->search(pName) >= 0) {
		//pName already exists!!!
		cout << "Error, Program " << pName << " already running." << endl;
		return;
	} else if (blockSize < 1) {
		//What are you trying to start there?
		cout << "Error, Program " << pName << " must have a positive size." << endl;
	}

	//Create the package
	NodeData n(pName, false, blockSize);

	//Locate position (algo will also clear Free memory!)
	pos = algo(ll, blockSize); // algo saved an if statement
	if (pos < 0) {
		//No position found!!! (Memory full)
		cout << "Error, Not enought memory for " << pName << endl;
		return;
	}

	//Modify the Free space
	(*ll)[pos].blockSize -= blockSize;

	//Store package away
	ll->insert(n, pos);

	//Let them know
	string suf = (blockSize > 1) ? "s" : "";
	cout << "Program " << pName << " added successfully, "
		<< blockSize << " page" << suf
		<< " used." << endl;
}

void killProgram(LinkedList *ll) {
	string hitList;
	int size;
	int i;

	//Ask for the name of the murderee
	cout << "Program name: ";
	cin >> hitList;

	//Scope em out
	i = ll->search(hitList);
	if (i < 0) {
		//He got away sonny
		cout << "Error, program " << hitList << " is not running." << endl;
		return;
	}

	//Get his info
	size = (*ll)[i].blockSize;

	//End the poor sod
	(*ll)[i].pName = FREE;
	(*ll)[i].free = true;

	//Report back to hq
	string suf = (size > 1) ? "s" : "";
	cout << "Program " << hitList << " successfully killed, "
		<< size << " page" << suf << " reclaimed." << endl;
}

void printFragments(LinkedList *ll) {
	collapseFreeMem(ll); //Make sure all the Frees are joined
	int fragments = 0;
	for (int i=0; i < ll->getSize(); i++) {
		if ((*ll)[i].free == false) {
			fragments++;
				//Fast forward through all the non frees
			do {
				i++;
			} while (i < ll->getSize() && (*ll)[i].free == false);
		}
	}
	
	string suf = (fragments == 0 || fragments > 1) ? "s" : "";
	cout << "There are " << fragments << " frament" << suf << "." << endl;
}

void printMemory(LinkedList *ll) {
	//This function will print the linkedlist in a special way
	//In a 4x8 grid
	int gridIndex = 0; //To know when to insert a newline
	for (int i=0; i<ll->getSize(); i++) {
		//i = NodeData object index
		NodeData n = (*ll)[i];
		for (int j=0; j<n.blockSize; j++, gridIndex++) {
			if (gridIndex % 8 == 0) { //ew magic number (8 = #columns)
				//We need a \n
				cout << endl;
			}
			cout << n.pName << "\t";
		}
	}
}

// Find the best fit using the best fit algorithm
// Returns the position in the linkedlist where the size will fit BEST
int findBestFit(LinkedList *ll, int size) {
	collapseFreeMem(ll); //Make sure all the Frees are joined

	int spot = -1; //Will hold the position of the smallest Free
	int minFound = MEMSIZE+1; //Will hold the value of the smallest Free possible spot
	
	for (int i=0; i<ll->getSize(); i++) {
		if ((*ll)[i].free) {
			int freeSize = (*ll)[i].blockSize;
			if (freeSize < minFound && freeSize >= size) {
				//The program fits in this free spot and it is a new min
				spot = i;
				minFound = freeSize;
			}
		}
	}
	
	return spot;
}

// Find the worst fit using the worst fit algorithm
// Returns the position in the linkedlist where the size will fit WORST
int findWorstFit(LinkedList *ll, int size) {
	collapseFreeMem(ll); //Make sure all the Frees are joined

	int spot = -1; //Will hold the position of the largest Free
	int maxFound = -1; //Will hold the value of the largest Free possible spot
	
	for (int i=0; i<ll->getSize(); i++) {
		if ((*ll)[i].free) {
			int freeSize = (*ll)[i].blockSize;
			if (freeSize > maxFound && freeSize >= size) {
				//The program fits in this free spot and it is a new min
				spot = i;
				maxFound = freeSize;
			}
		}
	}
	
	return spot;
}

// Will collapse adjacent Free spaces
void collapseFreeMem(LinkedList *ll) {
	NodeData *curr;
	NodeData *next;
	int j;
	for (int i = 0; i < ll->getSize(); i++) {
		curr = &(*ll)[i];
		if (curr->free) {
			j = i + 1;
			while (j < ll->getSize() && (*ll)[j].free) {
				//Next one is a free too!
				next = &(*ll)[j];
				//Now kis
				curr->blockSize += next->blockSize;
				//Til death do ye part
				ll->remove(j);
			}
			//If the free space is empty then just get rid of it
			if (curr->blockSize < 1) {
				// <1? You are a savage
				ll->remove(i);
			}
		}
	}
}

