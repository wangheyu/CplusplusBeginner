#include "Matrix.h"

#define N 3

int main(int argc, char* argv[])
{
    CRAZYFISH::Matrix<double> M(3);
    for (int j = 0; j < N; j++)
    {
	for (int i = 0; i < N; i++)
	    std::cout << M.get(i, j) << "\t";
	std::cout << std::endl;
    }
    return 0;
};
