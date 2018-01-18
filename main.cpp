#include "Stack.h"

/*
* Start of main function.
*/

int main() {
	Stack<int> *s = new Stack<int>();
	Singly<int> *temp = s->getList();
	int min = s->getMin();
	printf("Min is %d \n", min);

	s->push(4);
	s->push(12);
	s->push(7);
	s->push(8);
	s->push(6);
	s->push(1);


	Node<int> *n = temp->getHead();
	if (n == nullptr) {
		printf("NULL \n");
		return 0;
	}
	while (n->getNext() != nullptr) {
		printf("%d->", n->getData());
		n = n->getNext();
	}
	printf("%d->NULL \n", n->getData());

	min = s->getMin();
	printf("Min is %d \n", min);
	s->pop();
	min = s->getMin();
	printf("Min is %d \n", min);
	return 0;
}
/*
* End of main function.
*/