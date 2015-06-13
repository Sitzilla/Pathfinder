#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;

int recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize);

void doit(Matrix &m)
{
	int shortestPath;
	string stringPath = "";
	// print the whole matrix
	m.print();

	// get the number of rows/cols in the matrix
	cout << "rows: " << m.getRows() << ", cols: " << m.getCols() << endl;


	shortestPath = recurseMatrix(m, 1, 1, m.getRows(), m.getCols());

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
}

int recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize) {
	int wentDown = 1000;
	int wentRight = 1000;

	if ((x == xSize) && (y == ySize)) {
		return m.get(x - 1, y - 1);
	}
	else {

		if (x < xSize) {
			wentDown = recurseMatrix(m, x + 1, y, xSize, ySize);
		}

		if (y < ySize) {
			wentRight = recurseMatrix(m, x, y + 1, xSize, ySize);
		}

		cout << "At Coordinates x: " << x  << ", y: " << y << "\n";
		if (wentDown < wentRight) {
			wentDown = wentDown + m.get(x - 1, y - 1);
			return wentDown;
		}
		else {
			wentRight = wentRight + m.get(x - 1, y - 1);
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
