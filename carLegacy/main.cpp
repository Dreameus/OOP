#include <iostream>
#include "car.h"

int main()
{
    engine carEng(10 , 10 , 10, 10, "name");

    sedan sedan(10, 10 , "ask", "aks", "ask", carEng, 12, true, 12, name);

    sedan.info();

    return 0;
}