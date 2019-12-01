#include "BinaryTree.h"

int main (int argc, char *argv[])
{
    BinaryTree<int> A(1);
    BinaryTree<int> B(3);
    B.insertLeft(B.getRoot(), 1);
    B.insertRight(B.getRoot(), 2);
    std::cout << "Height of B: " << B.height() << std::endl;
    B.display();
    BinaryTree<int>::Node *t = B.getRoot();
    t = t->left;
    t->color = BLACK;
    B.transplant(B.getRoot(), t);
    B.display();
    return 0;
};
