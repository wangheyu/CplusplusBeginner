#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main (int argc, char *argv[])
{
    std::fstream fs;
    fs.open ("vector");
    int length = -1;
    fs >> length;
    std::vector<double> A(length);
    std::vector<double> B(length);
    std::vector<double>::iterator A_it;
    std::vector<double>::iterator B_it;
    for (A_it = A.begin(); A_it != A.end(); ++A_it)
	fs >> *A_it;
    for (B_it = B.begin(); B_it != B.end(); ++B_it)
	fs >> *B_it;
    std::cout << "vector A is: " << std::endl;
    for (A_it = A.begin(); A_it != A.end(); ++A_it)
	std::cout << *A_it << "\t";
    std::cout << std::endl;
    std::cout << "vector B is: " << std::endl;
    for (B_it = B.begin(); B_it != B.end(); ++B_it)
	std::cout << *B_it << "\t";
    std::cout << std::endl;
    double s = 0;
    for (A_it = A.begin(), B_it = B.begin();
	 A_it != A.end() && B_it != B.end();
	 ++A_it, ++B_it)
	s += (*A_it) * (*B_it);
    std::cout << "The inner prod of (A, B) is: " << s << std::endl;
    fs.close();
    return 0;
};
