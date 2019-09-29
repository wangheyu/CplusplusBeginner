#include <iostream>
#include <list>
#include <cstdlib>

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
	std::cerr << "usage: "
		  << argv[0]
		  << " size_of_the_list" << std::endl;
	std::exit(-1);
    }
    int n = std::atoi(argv[1]);
    std::list<int> A;
    if (n > 0)
    {
	int t = rand() % 100;
	A.insert(A.begin(), t);
    }
    std::list<int>::iterator A_it;
    for (int i = 1; i < n; i++)
    {
    	int t = rand() % 100;
	for (A_it = A.begin(); A_it != A.end(); ++A_it)
	    if (*A_it >= t)
		break;
	A.insert(A_it, t);
    }
    for (A_it = A.begin(); A_it != A.end(); ++A_it)
    	std::cout << *A_it << "\t";
    std::cout << std::endl;
    return 0;
};
