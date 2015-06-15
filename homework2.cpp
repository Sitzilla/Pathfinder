#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;

bool testInputs (int argc, char **argv, Matrix &m) {
    cout << "Testing\n";
    if(argc < 2)
    {
        cout << "Please enter a filename when you call the program!\n";
        return false;
    }
    
    if(!m.loadFile(argv[1]))
    {
        cout << "Invalid file!\n";
        return false;
    }
    return true;
}

int recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize) {
    int wentDown = 1000;
    int wentRight = 1000;

    // base case if in the bottom-right index of the array
    if ((x == xSize) && (y == ySize)) {
        return m.get(x - 1, y - 1);
    }
    else {

        // else recursively call recurseMatrix to go both down and right
        if (x < xSize) {
            wentDown = recurseMatrix(m, x + 1, y, xSize, ySize);
        }

        if (y < ySize) {
            wentRight = recurseMatrix(m, x, y + 1, xSize, ySize);
        }

        // return the smaller of the two paths
        // cout << "At Coordinates x: " << x  << ", y: " << y << "\n";
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
    int shortestPath;
    string stringPath = "";
    bool legalInputs = false;

    legalInputs = testInputs(argc, argv, m);
    
    if (legalInputs) {
        // print the whole matrix
        m.print();

        // get the number of rows/cols in the matrix
        cout << "rows: " << m.getRows() << ", cols: " << m.getCols() << endl;

        // call recursive 
        shortestPath = recurseMatrix(m, 1, 1, m.getRows(), m.getCols());

        // Correct path should be: 
        // right
        // right
        // down
        // down
        // down
        // right
        // down
        // right

        cout << "Shortest Path: " << shortestPath << "\n";
    }
    return 0;
}
