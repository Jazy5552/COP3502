#ifndef PA2_H
#define PA2_H
#include "linkedlist.h"
// Find the best fit using the best fit algorithm
// Returns the position in the linkedlist where the size will fit BEST
// NOTE: Function will also clear the appropriate Free space!
int findBestFit(LinkedList *ll, int size);

// Find the worst fit using the worst fit algorithm
// Returns the position in the linkedlist where the size will fit WORST
// NOTE: Function will also clear the appropriate Free space!
int findWorstFit(LinkedList *ll, int size);

// The menu actions in appropraite functions
void addProgram(LinkedList *ll, int (*algo)(LinkedList *, int));
void killProgram(LinkedList *ll);
void printFragments(LinkedList *ll);
void printMemory(LinkedList *ll);

// Will collapse adjacent Free spaces
void collapseFreeMem(LinkedList *ll);

#endif
