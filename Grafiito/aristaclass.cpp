#include "aristaclass.h"

AristaClass::AristaClass()
{
    peso=0;
    from=0;
    to=0;
    id=0;
}
AristaClass::AristaClass(int p, VerticeClass* fr, VerticeClass* t){
    peso=p;
    from=fr;
    to=t;
    id=0;
}
