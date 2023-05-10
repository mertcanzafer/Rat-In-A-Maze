#pragma once
#include "LinkedList.h"
template<class T>

class Stack
{
private:
	LinkedList<T>* data;
	int Capacitiy;
public:
	Stack();
	bool IsEmpty();
	int cntElts();
	void pop();
	void push(T value);
	void printStack();
	T Top();
	int size();
	~Stack();
};

