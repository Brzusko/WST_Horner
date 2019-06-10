

#include <iostream>
#include "SHorner.h"

using namespace std;

int main()
{
	float wspolczynniki[10] = {  2.0f, 3.1f, 1.0f, 4.0f, 0.3f, 0.2f, 0.333f, 0.00002f, 0.004f, .0003f};
	int sizeOfTable = sizeof(wspolczynniki) / sizeof(float);
    std::cout << Horner(wspolczynniki, sizeOfTable, 0.002f) << " " << Piechota(wspolczynniki, sizeOfTable, 0.002f); 

}


