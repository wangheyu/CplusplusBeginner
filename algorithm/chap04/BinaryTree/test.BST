#include "BinarySearchTree.h"

int main (int argc, char *argv[])
{
    BinarySearchTree A;
    BinarySearchTree B;
    B.insert(2);
    B.insert(3);
    B.updateDepthandPos();
    B.display();
    BinarySearchTree::Node *t = new BinarySearchTree::Node(7);
    A.insert(t);
    A.updateDepthandPos();
    A.display();
    const BinarySearchTree::Node *r = A.search(7);
    std::cout << "r->data:" << r->data << std::endl;
    BinarySearchTree::Node *s = A.search(7);
    std::cout << "s->data:" << s->data << std::endl;
    BinarySearchTree::Node *p = A.search(6);
    if (p == NULL)
	std::cout << "NULL" << std::endl;
    const BinarySearchTree::Node *q = A.search(6);
    if (q == NULL)
	std::cout << "NULL" << std::endl;
    s = B.min();
    std::cout << "min of B:" << s->data << std::endl;
    s = B.max();
    std::cout << "max of B:" << s->data << std::endl;
    s = B.min(B.getRoot());
    std::cout << "min of B:" << s->data << std::endl;
    s = B.max(B.getRoot());
    std::cout << "max of B:" << s->data << std::endl;
    B.insert(7);
    B.insert(5);
    B.insert(1);
    B.insert(1);
    B.updateDepthandPos();
    B.display();
    s = B.successor(B.getRoot());
    std::cout << "successor of root of B:" << s->data << std::endl;
    s = B.getRoot();
    s = B.successor(s->left);
    std::cout << "successor of left child of root of B:" << s->data << std::endl;
    s = B.getRoot();
    s = B.successor(s->left->right);
    std::cout << "successor of right child of left child of root of B:" << s->data << std::endl;
    s = B.getRoot();
    s = B.successor(s->right->right);
    if (s == NULL)
	std::cout << "successor of right child of right child of root of B is NULL" << std::endl;

    s = B.predecessor(B.getRoot());
    std::cout << "predecessor of root of B:" << s->data << std::endl;
    s = B.getRoot();
    s = B.predecessor(s->left);
    if (s == NULL)
	std::cout << "predecessor of left child of root of B is NULL" << std::endl;
    s = B.getRoot();
    s = B.predecessor(s->left->right);
    std::cout << "predecessor of right child of left child of root of B:" << s->data << std::endl;
    s = B.getRoot();
    s = B.predecessor(s->right->right);
    if (s == NULL)
	std::cout << "predecessor of right child of right child of root of B is NULL" << std::endl;
    B.del(B.getRoot());
    B.updateDepthandPos();
    B.display();
    return 0;
};
