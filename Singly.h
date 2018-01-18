/*
* An implementation of a generic LinkedList class which constructs a singly linked list
* where each Node of the Linked List is the generic Node class defined in the headers.
* This Linked List consists of 2 fields:
* size -> The current size of the Linked List.
* head -> The pointer to the head Node of this Linked List.
*
* The reason why we use a singly linked list for the implementation of a stack is that a
* doubly linked list has more overheads than a singly linked list as we have to store 2 pointers
* in a doubly linked list compared to 1 pointer in a singly linked list.
* The only motivation for using a doubly linked list is that it offers constant time insertion and
* deletion of a middle node. Since a stack is only concerned about insertion O(1) and deletion O(n) at end, 
* we proceed with a singly linked list and use a tail pointer to point at the end of the linked list.
*
* @author Deepak Kakad
*/

#pragma once
#include "Node.h"
#include "Node.cpp"

template <typename T>
class Singly {

	/*
	* The head node of the Linked List.
	*/
	Node<T> *head;

	/*
	* The tail node of the Linked List.
	*/
	Node<T> *tail;

	/*
	 * The number of Nodes in the Linked List.
	 */
	int size;

	/*
	* A private helper function to get the penultimate node of the Linked List.
	*/
	Node<T> *getBeforeLast();
public:
	Singly();
	Node<T> *getHead();
	Node<T> *getTail();
	int getSize();
	void setHead(Node<T> *newHead);
	void setTail(Node<T> *newTail);
	Node<T> *getLast();
	void addEnd(T data);
	void deleteEnd();
};