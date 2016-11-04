#ifndef STACK_H
#define STACK_H
#include <vector>

//The stack class will allow any type to be stored
template <class T>
class Stack {
private:
	//The underlying vector data structure
	std::vector<T> vec;

public:
	//Do nothing?
	//Stack();
	//~Stack();
	
	//Push onto the stack
	void push(const T& elem);
	//Pop (And return) the top element of the stack
	T& pop();
	//Returns the top element without removing it from the stack
	T& top() const;

	//Returns the current size of the stack
	int size() const;
	//Returns true if emtpy
	bool isEmpty() const;
	//Prints the stack in a queue fashion
	void print() const;
};

#include "stack.tpp"

#endif //STACK_H
