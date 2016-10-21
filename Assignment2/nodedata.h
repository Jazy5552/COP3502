#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>

// Custom node data structure that will be stored in the nodes
typedef struct NodeData { 
	std::string pName; // Name of the process using this node block
	bool free; // Wether the node is being used or not at the moment
	int blockSize; // Number of 4k blocks pertaining to this node.

	//Constructors
	NodeData() 
		: pName(""), free(false), blockSize(0) {}
	NodeData(std::string name, bool f, int bs) 
		: pName(name), free(f), blockSize(bs) {}

	// Overload for comparing NodeDatas
	// @Overload
	bool operator==(const NodeData &b) const {
		return (pName.compare(b.pName) == 0
				&& free == b.free
				&& blockSize == b.blockSize) ? true : false;
	}
}NodeData;

#endif
