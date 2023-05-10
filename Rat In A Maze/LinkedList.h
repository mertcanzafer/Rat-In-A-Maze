#pragma once
#include "LinkedNode.h"
#include <iostream>
template<class T>
class LinkedList
{
private:
	LinkedNode<T>* head;
	LinkedNode<T>* last;
	int cnt;
public:
	LinkedList();
	bool Empty();
	int getCnt();
	void append(T& value);
	void deleteLast();
	void printLinkedList();
	int getLast();
	~LinkedList();
};

