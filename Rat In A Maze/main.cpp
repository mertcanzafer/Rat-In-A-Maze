#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Stack.h"
#include <string>
using namespace std;

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
	Stack<int> *StackContainer;
	Stack<int> stackCx; // Test parameter1
	Stack<int> stackCy; // Test parameter2

public:
	
	Maze()
		:row{ 14 }, col{ 15 }, StartCx{ 0 }, StartCy{ 0 }, EndCx{ 13 }, EndCy{ 14 },CurrentCx{0},CurrentCy{0},StackContainer{NULL}
	{
		StackContainer = new Stack<int>();
	}

	void Motion();

	void PrintMaze();

	friend ostream& operator<<(ostream& os, const Maze& obj);

	// Destructor
	~Maze()
	{
		delete StackContainer;
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

	// There is two possibilites at the beginning
	string MoveOrder1 = "right";
	string MoveOrder2 = "down";
	string choice;
    //0. Prompt to raze the choose one option between thoose two. 	
	//1. Show the maze
	//2. Find the possible ways in the maze.
	//3. Use your stack container to help to find exit
	cout << "right or down: ";
	cin >> choice;

	// Holding initial point
	stackCx.push(CurrentCx);
	stackCy.push(CurrentCy);

	while (CurrentCx != EndCx || CurrentCy != EndCy)
	{
		// Move order is: right, down, left and up.
		cout << "Current x: " << CurrentCx << endl;
		cout << "Current y: " << CurrentCy << endl;
		// First option selected...
		if (choice == MoveOrder1)
		{
			for (int i = CurrentCy; i < col; i++)
			{
				if (maze[CurrentCx][CurrentCy] != 'B')
				{

					if (maze[CurrentCx + 1][CurrentCy] != 'B')
					{
						stackCx.push(CurrentCx + 1);
						stackCy.push(CurrentCy);
					}
					else {
						CurrentCx = stackCx.Top();
						CurrentCy = stackCy.Top();
						stackCx.pop();
						stackCy.pop();
					}

					CurrentCy++;
				}
				else {
					choice = MoveOrder2;
					break;
				}
			}
		}

		if (choice == MoveOrder2)
		{
			// Empty for now
		}
		

	}
	cout << "Congratulations! You have reached the exit." << endl;
}

int main()
{
	Maze myMaze;

	myMaze.PrintMaze();

	return 0;
}