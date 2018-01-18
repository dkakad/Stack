#pragma once
#include "Singly.h"

template <typename T>
class Queue {
protected:

	/*
	 * The singly linked list which is used as a queue. 
	 */
	Singly<T> *list;

public:
	Queue();
	Singly<T>* getList();
	void setList(Singly<T> *newList);
	void Enqueue(T data);
	T Dequeue();
	T Peek();
	bool isEmpty();
};
