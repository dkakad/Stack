/*
* An implementation of a generic stack using a Singly Linked List.
* The core fields of the stack are:
* list-> The singly linked list which acts as a LIFO (Last In First Out)
*		 container where the last end of the linked list is top of the stack.
* minMap -> The singly linked list which acts as a separate stack to keep track
			of the smallest element of the main stack.
* @author Deepak Kakad
*/

#include "Stack.h"

/*
* Explicit instantiation for int class
*/
template class Node<int>;
template class Singly<int>;
template class Stack<int>;

/*
* Default constructor to initialize the 2 singly linked lists.
*/
template <typename T>
Stack<T>::Stack() {
	list = new Singly<T>();
	minMap = new Singly<T>();
}

/*
* Getter for the Singly Linked List which is used as a stack.
* @return list -> The Singly linked list used as a stack
*/
template <typename T>
Singly<T> * Stack<T>::getList() {
	return list;
}

/*
* Setter for the Singly Linked List which is used as a stack.
* @param newList -> The new Singly Linked List
*/
template <typename T>
void Stack<T>::setList(Singly<T>* newList) {
	list = newList;
}

/*
* Getter for the Singly Linked List which is used as a map to store the
* minimum element of the stack at each instance.
* @return list -> The Singly linked list used as a minMap
*/
template <typename T>
Singly<T> * Stack<T>::getMinMap() {
	return minMap;
}

/*
* Setter for the Singly Linked List which is used as a map to store the
* minimum element of the stack at each instance.
* @param newMinMap -> The new Singly Linked List
*/
template <typename T>
void Stack<T>::setMinMap(Singly<T>* newMinMap) {
	minMap = newMinMap;
}

/*
* Function to push data on top of the stack.
* @param data -> The data that is to be pushed onto the stack
*/
template <typename T>
void Stack<T>::push(T data) {
	list->addEnd(data);
	if (minMap->getHead() == nullptr) {
		minMap->addEnd(data);
		return;
	}
	T min = minMap->getTail()->getData();
	if (data < min) {
		minMap->addEnd(data);
	}
}

/*
* Function to pop the data present at top of the stack.
* @return topData -> return NULL if popping an empty stack
*					 return top of the stack and remove the top element from the stack
*/
template <typename T>
T Stack<T>::pop() {
	if (isEmpty()) {
		printf("Attempting to pop an empty stack. Returning NULL \n");
		return NULL;
	}
	else {
		T topData = list->getTail()->getData();
		if (topData == minMap->getTail()->getData()) {
			minMap->deleteEnd();
		}
		list->deleteEnd();
		return topData;
	}
}

/*
* Function to peek at the data present at top of the stack.
* @return topData -> return NULL if peeking an empty stack
*					 return top of the stack
*/
template <typename T>
T Stack<T>::peek() {
	if (isEmpty()) {
		return NULL;
	}
	else {
		T topData = list->getTail()->getData();
		return topData;
	}
}

/*
* Function to check if the stack is empty or not.
* @return true if stack is empty, false otherwise
*/
template <typename T>
bool Stack<T>::isEmpty() {
	if (list->getHead() == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

/*
* Function that returns the minimum element of the stack.
* @return min -> The minimum element on the stack
*/
template <typename T>
T Stack<T>::getMin() {
	if (list->getHead() == nullptr) {
		printf("Called min on an empty stack. Returning NULL \n");
		return NULL;
	}
	T min = minMap->getTail()->getData();
	return min;
}

/*
* A function that sorts a stack without using any additional data structure except
* another stack.
* @return temp -> The sorted stack
*/
template <typename T>
Stack<T>* Stack<T>::sortStack() {
	Stack<T>* temp = new Stack<T>();
	int count = 0;
	while (!isEmpty()) {
		T data = pop();
		if (temp->isEmpty()) {
			temp->push(data);
		}
		else {
			while (temp->peek() > data && !(temp->isEmpty())) {
				T data_temp = temp->pop();
				count++;
				push(data_temp);
			}
			temp->push(data);
			while (count > 0) {
				T newData = pop();
				temp->push(newData);
				count--;
			}
		}
		count = 0;
	}
	return temp;
}