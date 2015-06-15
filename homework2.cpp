#include <iostream>
#include <string>
#include "matrix.h"
#include "path.h"
using namespace std;

bool testInputs (int argc, char **argv, Matrix &m) {
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

// return true if wentDown is smallest and above zero, OR if wentRight is -1 
bool wentDownIsSmallest(Path wentDown, Path wentRight) {
    return ((wentDown.getCost() < wentRight.getCost()) && (wentDown.getCost() > 0)) || (wentRight.getCost() < 0);
}

// recursive method that returns a Path object that contains the current path and its size
Path recurseMatrix(Matrix &m, int x, int y, int xSize, int ySize) {
    Path wentDown;
    Path wentRight;

    // base case if in the bottom-right index of the array
    if ((x == xSize) && (y == ySize)) {
        Path baseCase;
        baseCase.setCost(m.get(x - 1, y - 1));
        return baseCase;
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
        if (wentDownIsSmallest(wentDown, wentRight)) {
            int pathCost = wentDown.getCost() + m.get(x - 1, y - 1);

            wentDown.setCost(pathCost);
            wentDown.setPath("down");
            return wentDown;
        }
        else {
            int pathCost = wentRight.getCost() + m.get(x - 1, y - 1);

            wentRight.setCost(pathCost);
            wentRight.setPath("right");
            return wentRight;
        }
    }
}


int main(int argc, char **argv)
{
    Matrix m;
    Path shortestPath;
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

        cout << "Shortest Path Cost: " << shortestPath.getCost() << "\n";
        cout << "Shortest Path: " << shortestPath.getPath() << "\n";
    }
    return 0;
}
