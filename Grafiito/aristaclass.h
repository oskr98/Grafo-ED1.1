#ifndef ARISTACLASS_H
#define ARISTACLASS_H
#include <iostream>
#include <vector>
#include "verticeclass.h"

class AristaClass
{
public:
    AristaClass();
    AristaClass(int p, VerticeClass* f, VerticeClass* t);
    float peso;
    int id;
    VerticeClass* from;
    VerticeClass* to;
};

#endif // ARISTACLASS_H
