#ifndef PATH_H
#define PATH_H

#include <string>
#include <iostream>
using namespace std;

class Path {
    public:
        Path();

        string getPath() const;
        int getCost() const;

        void setPath(string value);
        void setCost(int value);

    private:
        string path;
        int cost;
};

#endif
