#include "Point.h"

int main(int argc, char *argv[])
{
    Point<2> a(1, 2);
    const double *A = a.read();
    std::cout << A[0] << ", " << A[1] << std::endl;
    Point<3> b(1, 2, 3);
    A = b.read();
    std::cout << A[0] << ", " << A[1] << ", " << A[2] << std::endl;
    // Convenient! 
    std::cout << a[0] << ", " << a[1] << std::endl;
    Point<3> c(b);
    c = b;
    std::cout << "b + c = " << b + c << std::endl;
    // Error, dimension not match.
//    std::cout << "a + b = " << a + b << std::endl;
    return 0;
};

