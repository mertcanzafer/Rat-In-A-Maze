#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

template<class T>
class LinkedNode {
public:
	LinkedNode* Next;
	T value;
};
template<class T>
class LinkedList {

private:
	LinkedNode<T>* head;  // A linked list pointer that points to first element of the Linked list
	LinkedNode<T>* last; // A Linked list pointer that points to last element of the linked list
	int cnt;          // easily get the current # of items in the list

public:
	LinkedList()
		:head{ NULL }, last{ NULL }, cnt{ 0 }
	{

	}
	bool Empty() { if (head == NULL) return true; }
	int get_cnt() { return cnt; }
	// append(int value) adds element into linked list
	void append(T& value);
	void insert(T value, int i); //i = 0 initially

	// Delete methods

	void deleteFirst();
	void deleteLast();
	void deleteNth(T& elt, int i); // The index of LinkedList number that is going to be removed

	void SwappLastTwoElements();  //Swapping last two top elements from the linked list

	void print_LinkedList()
	{
		if (last == NULL)
		{
			cout << "The stack is empty!!!" << endl;
		}
		else {
			cout << "The elements are: " << endl;

			LinkedNode<T>* ptr = head;

			while (ptr != NULL)
			{
				cout << ptr->value << " ";
				ptr = ptr->Next;
			}
		}

	}

	int get_last() {
		if (last == NULL) throw "Exception!";
		return last->value;
	}

};

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

		// If the linked list is empty, New node will be a head node

		if (head == NULL)
		{
			head = new_node;
		}

		// Find the last node

		LinkedNode<T>* last_node = head;

		while (last_node->Next != NULL)
		{
			last_node = last_node->Next;
		}

		// Insert new node after last node(at the end)

		last_node->Next = new_node;

		last = new_node;

	}
	cnt++;//It will be incremented after adding new element to linked list

}
template<class T>
void LinkedList<T>::deleteLast()
{
	// 1. Find the second last node.

	if (cnt == 0) throw "Out of bound Exception";

	if (head->Next == NULL)
	{
		last = NULL;
		delete head;
	}
	else {
		LinkedNode<T>* Second_lastNode = head;
		//Finding secon Node!!!!
		while (Second_lastNode->Next != last)
		{
			Second_lastNode = Second_lastNode->Next;
		}
		//Your second last node will be ur last node
		Second_lastNode->Next = NULL;
		delete last;

		last = Second_lastNode;

	}

	--cnt;
}
template<class T>
void LinkedList<T>::deleteFirst()
{
	// Create a temp pointer that holds the address of head node.
	// Find the second element in the linked list.

	if (cnt == 0) throw "Out of bound exception occured";

	if (head->Next == NULL)
	{
		last = NULL;
		delete head;
	}
	else {
		LinkedNode<T>* SecondElement = head->Next;
		delete head;

		head = SecondElement;
	}
	cnt--;
}
template<class T>
void LinkedList<T>::SwappLastTwoElements()
{
	if (cnt <= 1) throw "Exception";

	else {
		LinkedNode<T>* SecondLast = head;
		// Find the second last node

		while (SecondLast->Next != last)
		{
			SecondLast = SecondLast->Next;
		}

		LinkedNode<T>* temp = last;
		last = SecondLast;
		SecondLast = temp;
	}
}


template<class T>
class StackLL {

private:

	LinkedList<T>* data;
	int Capacity;

public:

	StackLL() :data{ nullptr }, Capacity{ 0 }
	{
		data = new LinkedList<T>;
	}

	bool IsEmpty() {
		if (data->Empty())
		{
			return true;
		}
		else {
			return false;
		}
	}

	int cntElts() { return data->get_cnt(); }

	//pop() Removes the last element from the stack
	void pop() {
		try {
			data->deleteLast();
			Capacity = data->get_cnt();
		}
		catch (const char* excpt)
		{
			cout << "Out of bound Exception occured!!!" << endl;
		}
	}

	//push() Inserts an element at the end of the stack
	void push(T n)
	{
		data->append(n);
		Capacity = data->get_cnt();
	}
	// Define Destructore If you are working with raw pointers!!!!
	~StackLL()
	{
		delete data;
	}
	void _print_stack() { data->print_LinkedList(); }

	//Top() function returns last element of the stack
	T Top()
	{
		try {

			return data->get_last();

		}
		catch (const char* expt)
		{
			cout << "Exception handled" << endl;
		}

	}

	//removeFirst() function removes first element from the stack
	void removeFirst()
	{
		try {
			data->deleteFirst();
			Capacity = data->get_cnt();
		}
		catch (const char* excpt)
		{
			cout << "Out of bound Exception occured!!!" << endl;
		}
	}

	// Swapp() function swapps last two nodes

	void swapp()
	{
		try {
			data->SwappLastTwoElements();
		}
		catch (const char* excpt)
		{
			cout << "\nYour stack contains less than two elements!!!" << endl;
		}
	}
	void size() { return data->get_cnt(); }

};


class Maze {

private:
	// Row and collumns
	int row;
	int col;
	vector<vector<char>> maze{
		{'O','O','O','O','O','O','O','O','O','O','B','O','O','O','O'},    // Colors Orange and Blues.
		{'O','B','O','O','B','B','B','B','B','B','O','O','O','O','O'},    // Orange is shown as 'O', Blue is 'B'
		{'O','B','O','B','B','O','O','O','O','O','O','O','O','O','O'},    //  Orange blocks are available paths for rat
		{'O','B','B','B','O','O','O','O','O','O','O','O','O','O','O'},    //  Blue blocks are closed paths for the rat can not pass over
		{'O','O','O','O','B','O','O','O','B','B','B','B','B','O','O'},
		{'O','B','B','B','O','O','O','O','O','O','O','O','B','O','O'},
		{'O','B','B','O','O','O','O','O','O','O','O','O','O','O','O'},
		{'O','B','B','O','O','O','O','B','O','B','O','B','O','B','B'},
		{'O','O','O','O','B','O','O','O','O','O','O','O','O','O','O'},
		{'O','B','B','O','O','O','B','O','O','O','O','O','O','O','O'},
		{'O','B','B','O','O','B','B','O','O','O','O','B','O','O','O'},
		{'O','B','B','O','O','O','B','B','B','B','B','B','O','O','O'},
		{'O','B','B','O','O','O','O','O','O','O','O','B','O','O','O'},
		{'O','O','B','O','O','O','O','O','O','O','O','O','B','O','O'},
	};
	// Coordinates for starting and exit points...
	int StartCx;
	int StartCy;
    int EndCx;
	int EndCy;
	int CurrentCx;
	int CurrentCy;
    StackLL<int> stackCx; // Test parameter1
	StackLL<int> stackCy; // Test parameter2

public:
	
	Maze()
		:row{ 14 }, col{ 15 }, StartCx{ 0 }, StartCy{ 0 }, EndCx{ 13 }, EndCy{ 14 },CurrentCx{0},CurrentCy{0}
	{

	}

	void Motion();

	void PrintMaze();

	friend ostream& operator<<(ostream& os, const Maze& obj);

	// Destructor
	~Maze()
	{
		
	}

};
void Maze::PrintMaze()
{
	cout << "Maze:"<<endl;
	for (size_t i = StartCx; i < maze.size(); i++)
	{
		for (size_t j = StartCy; j < maze[i].size(); j++)
		{
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
}
ostream& operator<<(ostream& os, const Maze& obj)
{
	for (size_t i = obj.StartCx; i < obj.maze.size(); i++)
	{
		for (size_t j = obj.StartCy; j < obj.maze[i].size(); j++)
		{
			os << obj.maze[i][j]<<" ";
		}
		os << endl;
	}
	return os;
}

void Maze::Motion()
{
	PrintMaze();
	//1. Find the possible ways in the maze.
	//2. Use your stack container to help to find exit
	while (CurrentCx != EndCx || CurrentCy != EndCy)
	{
		// Move order is: right, down, left and up.
		cout << "Current x: " << CurrentCx << endl;
		cout << "Current y: " << CurrentCy << endl;
        
		if (CurrentCy < 14 && maze[CurrentCx][CurrentCy + 1] != 'B')
		{
			// Moving rightward...
			if (maze[CurrentCx + 1][CurrentCy] != 'B')
			{
				stackCx.push(CurrentCx);
				stackCy.push(CurrentCy);
			}
			CurrentCy++;
		}
		else if (maze[CurrentCx + 1][CurrentCy] != 'B')
		{
			// Moving downward
			if (CurrentCy< 14 && maze[CurrentCx][CurrentCy + 1] != 'B')
			{
				stackCx.push(CurrentCx);
				stackCy.push(CurrentCy);
			}
			CurrentCx++;
		}
		else if (CurrentCx > 0 && maze[CurrentCx - 1][CurrentCy] != 'B')
		{
			// Move to up direction!!!
			CurrentCx--;
		}
		else if (maze[CurrentCx][CurrentCy + 1] == 'B' && maze[CurrentCx + 1][CurrentCy] == 'B')
		{
			// You have blocked, all paths are closed then pop your stack
			CurrentCx = stackCx.Top();
			CurrentCy = stackCy.Top();
			stackCx.pop();
			stackCy.pop();

			if (CurrentCy != 14)
			{
				maze[CurrentCx][CurrentCy + 1] = 'B';
			}
			maze[CurrentCx][CurrentCy] = 'B';
		
		}
	}
	cout << "Congratulations! You have reached the exit." << endl;
	cout << "Rat is at point (" << EndCx << " , " << EndCy << " )" << endl;
}

int main()
{
	Maze myMaze;

	myMaze.Motion();

	return 0;
}