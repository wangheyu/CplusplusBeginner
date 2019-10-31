#include <iostream>
#include "BinaryTree.h"

int main(int argc, char *argv[])
{
    CRAZYFISH::BinaryTree<int> A(3);
    A.clean(A.root());
    A.empty();
    if (A.is_empty())
	std::cout << "empty!" << std::endl;
    else
	std::cout << "not empty!" << std::endl;
    return 0;
};
