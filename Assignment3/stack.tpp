#ifdef STACK_H
#include <iostream>
#include <vector>

//The stack class will allow any type to be stored
//template <class T>
//class Stack
//private:
//The underlying vector data structure
//vector<T> vec;

//public:
//Do nothing?
//Stack();
//~Stack();

//Push onto the stack
template <class T>
void Stack<T>::push(const T& elem) {
	vec.push_back(elem);
}

//Pop (And return) the top element of the stack
template <class T>
T& Stack<T>::pop() {
	if (isEmpty()) { //Error check
		std::cout << "Error, stack<> is empty." << std::endl;
		throw;
	}

	T& element = vec.back();
	vec.pop_back(); //WARNING May cause undefined behavior
	return element;
}

//Returns the top element without removing it from the stack
template <class T>
T& Stack<T>::top() const {
	if (isEmpty()) { //Error check
		std::cout << "Error, stack<> is empty." << std::endl;
		throw;
	}

	return vec.back();
}


//Returns the current size of the vector
template <class T>
int Stack<T>::size() const {
	return vec.size();
}

//Returns true if emtpy
template <class T>
bool Stack<T>::isEmpty() const {
	return vec.empty();
}

//Prints the stack in a queue fashion
template <class T>
void Stack<T>::print() const {
	for (int i=0; i<size(); i++) {
		std::cout << vec[i] << " ";
	}
}

#endif
