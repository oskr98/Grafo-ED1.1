#ifndef VERTICECLASS_H
#define VERTICECLASS_H

#include <iostream>
#include <vector>

using namespace std;

class AristaClass;

class VerticeClass
{
public:
    VerticeClass();
    VerticeClass(int p, int x, int y, string n);
    int peso;
    int ex;
    int ey;
    int ID;
    string name;
    vector<AristaClass*> aristas;
};

#endif // VERTICECLASS_H
