#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "nodedata.h"

/*
 *	TODO Description here
 */

// Custom node for this assignment
typedef struct Node { 
	NodeData *data;
	Node *next;

	//Constructors
	Node() : data(NULL), next(NULL) {}
	Node(NodeData *d, Node *n) : data(d), next(n) {}
}Node;

class LinkedList {
private:
	Node *head; // The first node in the linkedlist
	//NOTE: Head will not hold any data!
	
	// Get the node at position pos (0 is head)
	Node* getNode(int pos);
	//Node *current; // The current node position (This will be used an iterator)

	//Move current to the next node (Return is success)
	//bool moveCurrent();
	//Reset current to head
	//void resetCurrent();
	//Get the current node
	//Node* getCurrent();

public:
	// Insert a node at the end of the list
	void insert(const NodeData &data); 
	// Insert node at the position
	void insert(const NodeData &data, int pos); 

	// Delete the node (Will search list for it, returns success)
	bool remove(const NodeData &data); 
	// Delete the node at the pos position
	void remove(int pos); 

	// Replace the old nodedata (oldData) with the newNodeData
	//void replace(NodeData *oldData, NodeData *newNodeData);
	// Replace the node at pos with the *node given
	//void replace(int pos, NodeData *newNodeData); 
	
	// Update the nodedata at the pos position with the new
	// NodeData data
	void update(int pos, const NodeData &data);

	// Will search for and return the position of the nodedata
	int search(const NodeData &data);
	// Same as above but by name only (Returns first with name!)
	int search(const std::string &pName);
	

	// Return a pointer to the NodeData at position pos
	NodeData& get(int pos);

	// Get the list size
	int getSize();

	// Print the linkedlist
	void printList();
	
	// Get the nodedata at the given pos
	// @Overload
	NodeData& operator[](int pos);

	// Constructor
	LinkedList();

	// Destructor?
	//~LinkedList(); // Let the memory leak!
	
};

#endif // LINKEDLIST_H
