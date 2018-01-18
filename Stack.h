/*
* An implementation of a generic stack using a Singly Linked List.
* The core fields of the stack are:
* list-> The singly linked list which acts as a LIFO (Last In First Out)
*		 container where the last end of the linked list is top of the stack.
* minMap -> The singly linked list which acts as a separate stack to keep track
			of the smallest element of the main stack.
* @author Deepak Kakad
*/

#pragma once
#include "Singly.h"
#include "Singly.cpp"

template <typename T>
class Stack {
	/*
	* The singly linked list which acts a LIFO stack.
	*/
	Singly<T> *list;
	/*
	* The LIFO stack that keeps track of the min value of the main stack.
	*/
	Singly<T> *minMap;
public:
	Stack();
	Singly<T>* getList();
	void setList(Singly<T> *newList);
	Singly<T>* getMinMap();
	void setMinMap(Singly<T> *newMinMap);
	void push(T data);
	T pop();
	T peek();
	T getMin();
	bool isEmpty();
};