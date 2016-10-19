#ifndef NODE_H
#define NODE_H
#include <string>
// Custom node for this assignment
struct Node { 
	std::string pName; // Name of the process using this node block
	bool free; // Wether the node is being used or not at the moment
	int blockSize; // Number of 4k blocks pertaining to this node.
	Node *next;
};
#endif
