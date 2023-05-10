#include "LinkedList.h"
#include <cstddef>
template<class T>

LinkedList<T>::LinkedList()
:head{NULL},last{NULL},cnt{0}
{

}
template<class T>
bool LinkedList<T>::Empty()
{
	if (head == NULL) return true;
}
template<class T>
int LinkedList<T>::getCnt()
{
	return cnt;
}
template<class T>
void LinkedList<T>::append(T& value)
{
	if (cnt == 0)
	{
		head = new LinkedNode<T>();
		head->value = value;
		head->Next = NULL;
		last = head;
	}
	else {
		LinkedNode<T>* new_node = new LinkedNode<T>();
		new_node->value = value;
		new_node->Next = NULL;

		if (head == NULL)
		{
			head = new_node;
		}

		LinkedNode<T>* last_node = head;

		while (last_node->Next != NULL)
		{
			last_node = last_node->Next;
		}

		last_node->Next = new_node;
		last = new_node;
	}
	cnt++;
}
template<class T>
void LinkedList<T>::deleteLast()
{
	if (cnt == 0) throw "Out of bound Exception";

	if (head->Next == NULL)
	{
		last = NULL;
		delete head;
	}
	else {
		LinkedNode<T>* second_lastNode = head;
		while (second_lastNode->Next != last)
		{
			second_lastNode = second_lastNode->Next;
		}
		second_lastNode->Next = NULL;
		delete last;

		last = second_lastNode;
	}
	--cnt;
}
template<class T>
void LinkedList<T>::printLinkedList()
{
	if (last == NULL)
	{
		std::cout << "The stack is empty!!!" << std::endl;
	}
	else {
		std::cout << "The elements are:" << std::endl;

		LinkedNode<T>* ptr = head;

		while (ptr != NULL)
		{
			std::cout << ptr->value << " ";
			ptr = ptr->Next;
		}

	}
}
template<class T>
int LinkedList<T>::getLast()
{
	if (last == NULL) throw "Exception";
	return last->value;
}
template<class T>
LinkedList<T>::~LinkedList()
{
	delete head;
	delete last;
}