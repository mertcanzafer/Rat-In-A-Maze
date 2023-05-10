#include "Stack.h"

template<class T>
Stack<T>::Stack()
	:data{NULL},Capacitiy{0}
{
	data = new LinkedList<T>();
}

template<class T>
bool Stack<T>::IsEmpty()
{
	if (data->Empty())
	{
		return true;
	}
	else {
		return false;
	}
}

template<class T>
int Stack<T>::cntElts()
{
	return data->getCnt();
}

template<class T>
void Stack<T>::pop()
{
	try {
		data->deleteLast();
		Capacitiy = data->getCnt();
	}
	catch (const char* excpt)
	{
		std::cout << "Out of bound Exception occured!!!" << std::endl;
	}
}

template<class T>
void Stack<T>::push(T value)
{
	data->append(value);
	Capacitiy = data->getCnt();
}

template<class T>
void Stack<T>::printStack()
{
	data->printLinkedList();
}

template<class T>
T Stack<T>::Top()
{
	try {
		return data->getLast();
	}
	catch (const char* excpt) {
		std::cout << "Exception handled"<<std::endl;
	}
}

template<class T>
int Stack<T>::size()
{
	return data->getCnt();
}

template<class T>
Stack<T>::~Stack()
{
	delete data;
}