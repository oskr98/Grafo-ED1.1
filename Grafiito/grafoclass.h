#ifndef GRAFOCLASS_H
#define GRAFOCLASS_H
#include <iostream>
#include <vector>
#include "aristaclass.h"
#include "verticeclass.h"

using namespace std;
class GrafoClass
{
public:
    GrafoClass();
    vector<VerticeClass*> vertices;
};

#endif // GRAFOCLASS_H
