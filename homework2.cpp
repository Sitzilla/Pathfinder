#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;

int recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize, bool pathArray[], int pathSize, string stringPath);

void doit(Matrix &m)
{
	int pathSize = (5 + 5) - 2; //fix this later
	int shortestPath;
	bool pathArray[pathSize]; // true is down false is right
	bool tempPathArray[pathSize];
	string stringPath = "";
	// print the whole matrix
	m.print();

	// get the number of rows/cols in the matrix
	cout << "rows: " << m.getRows() << ", cols: " << m.getCols() << endl;


	shortestPath = recurseMatrix(m, 1, 1, m.getRows(), m.getCols(), pathArray, pathSize, stringPath);

	// Answer is: 
	// false
	// false
	// true
	// true
	// true
	// false
	// true
	// false

	cout << "Ending: " << shortestPath << "\n";

	// for (int i = 0; i < pathSize; i++) {
	// 	cout << pathArray[i] << "\n";
	// }
}

int recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize, bool pathArray[], int pathSize, string stringPath) {
	int wentDown = 1000;
	int wentRight = 1000;

	if ((x == xSize) && (y == ySize)) {
		return m.get(x - 1, y - 1);
	}
	else {

		if (x < xSize) {
			stringPath += ", down";
			wentDown = recurseMatrix(m, x + 1, y, xSize, ySize, pathArray, pathSize, stringPath);
			cout << "Returned Down: " << wentDown << "\n";
		}

		if (y < ySize) {
			stringPath += ", right";
			wentRight = recurseMatrix(m, x, y + 1, xSize, ySize, pathArray, pathSize, stringPath);
			cout << "Returned Right: " << wentRight << "\n";
		}

		cout << "At Coordinates x: " << x  << ", y: " << y << "\n";
		if (wentDown < wentRight) {
			wentDown = wentDown + m.get(x - 1, y - 1);
			cout << "X-Size: " << wentDown << "\n";
			stringPath += ", down";
			pathArray[x - 1] = true;
			cout << stringPath << "\n";
			return wentDown;
		}
		else {
			wentRight = wentRight + m.get(x - 1, y - 1);
			cout << "Y-Size: " << wentRight << "\n";
			stringPath += ", right";
			pathArray[x - 1] = false;
			cout << stringPath << "\n";
			return wentRight;
		}
	}
}


int main(int argc, char **argv)
{
	Matrix m;
	cout << "Testing\n";
	if(argc < 2)
	{
		cout << "Please enter a filename when you call the program!\n";
		return 1;
	}
	
	if(!m.loadFile(argv[1]))
	{
		cout << "Invalid file!\n";
		return 1;
	}
	
	doit(m);
	
	return 0;
}
