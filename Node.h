/*
 * An implementation of a generic Node class which is used in a singly Linked List.
 * This node consists of :
 * data -> This field is in the form of a generic type T. Note that we should always
 *		   overload the required operators required for whatever operations that we
 *		   need.
 * next -> A pointer to the next node of 'this' in the data structure. This field is contained
 *		   in both Singly as well as Doubly Linked List.
 * @author Deepak Kakad
 */

#pragma once
#include <stdio.h>

template <typename T>
class Node {

	/*
	 * The generic data field of the Node.
	 */
	T data;

	/*
	 * The next pointer of 'this' in the linked list.
	 */
	Node<T> *next;

public:
	Node();
	Node(T data);
	T getData();
	void setData(T newData);
	Node<T> *getNext();
	void setNext(Node<T> *newNext);
};