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

#include "Singly.h"

/*
 * Default constructor of the Singly class.
 */
template <typename T>
Singly<T>::Singly() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

/*
 * Getter for the head node of the Linked List.
 * @return head -> The head node of the Linked List
 */
template <typename T>
Node<T>* Singly<T>::getHead() {
	return head;
}

/*
 * Setter for the head node of the Linked List.
 * @param newHead -> A pointer to the Node that is to be set as the head
 *					node of the linked list
 */
template <typename T>
void Singly<T>::setHead(Node<T> *newHead) {
	head = newHead;
}

/*
 * Getter for the tail node of the Linked List.
 * @return tail -> The tail node of the Linked List
 */
template <typename T>
Node<T>* Singly<T>::getTail() {
	return tail;
}

/*
 * Setter for the tail node of the Linked List.
 * @param newTail -> A pointer to the node that is to be set as
 *					the tail of the linked list
 */
template <typename T>
void Singly<T>::setTail(Node<T> *newTail) {
	tail = newTail;
}

/*
 * Getter for the size of the Linked List.
 * @return size -> The size of the Linked List
 */
template <typename T>
int Singly<T>::getSize() {
	return size;
}

/*
 * A function that adds a node to the end of the Linked List.
 * @param data -> The data that is contained in the node to be added to the end
 *				 The function takes care of creating a Node from the data
 */
template <typename T>
void Singly<T>::addEnd(T data) {
	Node<T> *temp = new Node<T>(data);
	if (head == nullptr) {
		head = temp;
		tail = temp;
		size++;
	}
	else {
		tail->setNext(temp);
		tail = temp;
		size++;
	}
}

/*
 * A private helper function that gets the penultimate node of the linked list.
 * @return temp -> The penultimate node of the linked list
 */
template <typename T>
Node<T>* Singly<T>::getBeforeLast() {
	Node<T> *temp = head;
	if (head->getNext() == nullptr) {
		return nullptr;
	}
	while (temp->getNext() != tail) {
		temp = temp->getNext();
	}
	return temp;
}

/*
 * A function that gets the ultimate node of the linked list.
 * @return tail -> The tail is the last node of the linked list
 */
template <typename T>
Node<T>* Singly<T>::getLast() {
	return tail;
}

/*
 * A function that deletes the end node of the linked list.
 */
template <typename T>
void Singly<T>::deleteEnd() {
	Node<T> *temp = getBeforeLast();
	if (temp == nullptr) {
		tail = nullptr;
		delete head;
		head = nullptr;
		return;
	}
	temp->setNext(nullptr);
	delete tail;
	tail = temp;
}