#include <iostream>
#include "geometry.h"

#define DIM 3

int main (int argc, char* argv[])
{
    Point<DIM> pA;
    pA[0] = 1.0;
    pA[1] = 2.0;
    pA[2] = 3.0;
    double B[3] = {4.0, 5.0, 6.0};
    Point<DIM> pB(B);

    std::cout << "A = [";

    for (int i = 0; i < DIM - 1; i++)
    {
	 std::cout << pA[i] << ", ";
    }
    std::cout << pA[DIM - 1] << "]" << std::endl;

    std::cout << "B = [";
    for (int i = 0; i < DIM - 1; i++)
    {
	 std::cout << pB[i] << ", ";
    }
    std::cout << pB[DIM - 1] << "]" << std::endl;
    
    return 0;
};
