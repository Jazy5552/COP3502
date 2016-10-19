#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

/*
 *	TODO Description here
 */

class LinkedList {
private:
	Node *first; // The first node in the linkedlist
	Node *current; // The current node position (This will be used an iterator)

	//Move current to the next node (Return is success)
	bool moveCurrent();
	//Reset current to head
	void resetCurrent();
	//Get the current node
	Node* getCurrent();


public:
	// Insert a node at the end of the list
	void insert(Node *node); 
	// Insert node at the position
	void insert(Node *node, int pos); 

	// Delete the node (Will search list for it, returns success)
	bool delete(Node *node); 
	// Delete the node at the pos position
	void delete(int pos); 

	// Replace the old node (node) with the newNode
	void replace(Node *node, Node *newNode);
	// Replace the node at pos with the *node given
	void replace(int pos, Node *newNode); 

	//Get the list size
	int getSize();
	
	//Get the node at the given pos
	Node* operator[](int pos);
	
}

struct Node { // Custom node for this assignment
	std::string pName; // Name of the process using this node block
	bool free; // Wether the node is being used or not at the moment
	int blockSize; // Number of 4k blocks pertaining to this node.
	Node *next;
}


#endif // LINKEDLIST_HPP
