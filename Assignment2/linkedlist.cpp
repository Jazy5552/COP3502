#include "linkedlist.h"
#include "nodedata.h"
#include <iostream>
#include <string>

using namespace std;

//class LinkedList {
//private:
//Node *head; // The first node in the linkedlist

// Get the node at position pos (0 is head)
Node* LinkedList::getNode(int pos) {
	int i = 0;
	Node *curr = head;
	Node *next = head->next;
	while (next != NULL && i < pos) {
		curr = next;
		next = next->next; // Is next even a word?
		i++;
	}
	if (i != pos) {
		// Someone made a boo boo!
		cout << "Logic error when getting node!" << endl;
		throw; //yolo fixed
		//Return the last one anyways 
		//MAYDAY! Will return the last element in list!!!
		//DONE Remedy this shit
	}
	return curr;
}


//public:
// Insert a node at the end of the list
// A const reference is used because I want the linkedlist to create
// a new NodeData object dynamically and I would prefer the calling function
// to not have a pointer to the data within my linkedlist
void LinkedList::insert(const NodeData &data) {
	insert(data, getSize()); //You deal with it
}
// Insert node at the position
void LinkedList::insert(const NodeData &data, int pos) {
	Node *prev = getNode(pos);
	Node *next = prev->next;

	//Create the new nodedata using the values from the one given
	NodeData *nData = new NodeData(data.pName, data.free, data.blockSize);
	//Create the new node pointing to next
	Node *node = new Node(nData, next);
	//Make the prev point to the new node
	prev->next = node;
}

// Delete the node (Will search list for it, returns success)
bool LinkedList::remove(const NodeData &data) {
	int i = search(data);
	if (i < 0) {
		//Not found
		return false;
	} else {
		remove(i);
		return true;
	}
}
// Delete the node at the pos position
void LinkedList::remove(int pos) {
	if (pos >=0 && pos < getSize()) {
		Node *prev = getNode(pos);
		Node *rip = getNode(pos+1); // +1 because getNode starts at head=0
		prev->next = rip->next;
		delete(rip); // Nice n Tidy
	} else {
		// You done goofed!
		cout << "Could not remove: pos out of bounds!" << endl;
		//Maybe these should throw exceptions?
	}
}

// Replace the old nodedata (oldData) with the newNodeData
//void LinkedList::replace(NodeData *oldData, NodeData *newNodeData);
// Replace the node at pos with the *node given
//void LinkedList::replace(int pos, NodeData *newNodeData); 

// Update the nodedata at the pos position with the new
// NodeData data
void LinkedList::update(int pos, const NodeData &data) {
	if (pos >= 0 && pos < getSize()) { //Safety first
		(*this)[pos].pName = data.pName;
		(*this)[pos].free = data.free;
		(*this)[pos].blockSize = data.blockSize;
	} else {
		// You done goofed
		cout << "Could not update: pos out of bounds!" << endl;
	}
}

// Will search for and return the position of the nodedata
int LinkedList::search(const NodeData &data) {
	for (int i=0; i<getSize(); i++) {
		//Compare the data given with the current nodedata
		if (data == (*this)[i]) {
			return i;
		}
	}
	return -1;
}

// Same as above but by name only (Returns first with name!)
int LinkedList::search(const std::string &pName) {
	for (int i=0; i<getSize(); i++) {
		//Compare the pName given with the NodeData's pName
		if ((*this)[i].pName.compare(pName) == 0) {
			return i;
		}
	}
	return -1;
}

// Return the NodeData at position pos where 0 is the first (Not head)
NodeData& LinkedList::get(int pos) {
	Node *n = getNode(pos+1); // +1 because getNode starts at head (Which has no data)
	return *(n->data);
}

//Get the list size (0 for an empty list)
int LinkedList::getSize() {
	int size = 0;
	Node *temp = head;
	while (temp->next != NULL) {
		size++;
		temp = temp->next;
	}
	return size; //Hopefully it ends
}
	
// Print the linkedlist
void LinkedList::printList() {
	for (int i=0; i<getSize(); i++) {
		std::cout << i << ") "
			<< (*this)[i].pName << " "
			<< (*this)[i].free << " "
			<< (*this)[i].blockSize << std::endl;
	}
}

// Get the nodedata at the given pos
// @overload
NodeData& LinkedList::operator[](int pos) {
	return get(pos); //gg
}

// Constructor
LinkedList::LinkedList() {
	//Just create a new head
	head = new Node();
}

