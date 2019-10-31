#include "BinarySearchTree.h"

namespace CRAZYFISH{
    template <typename TYPE>
    BinarySearchTree<TYPE>::BinarySearchTree(TYPE _val) : BinaryTree<TYPE>(_val)
    {
    };

    template <typename TYPE>
    int BinarySearchTree<TYPE>::insert(Node *_x)
    {
	Node *z = BinaryTree<TYPE>::root();
	Node *y = NULL;
	while (z != NULL)
	{
	    y = z;
	    if (_x->data < z->data)
		z = z->left;
	    else
		z = z->right;
	}
	if (y == NULL)
	    z = _x;
	else if (_x->data < y->data)
	    y->left = _x;
	else
	    y->right = _x;
    };
};

