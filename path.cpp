#include <iostream>
#include <string>
#include "path.h"

using namespace std;

Path::Path() {
    string path = "";
    cost = -1;
}

string Path::getPath() const {
    return path;
}
int Path::getCost() const {
    return cost;
}

void Path::setPath(string value) {
    path = value + " " + path;
}

void Path::setCost(int value) {
    cost = value;
}