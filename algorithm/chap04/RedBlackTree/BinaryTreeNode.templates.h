#include "BinaryTreeNode.h"

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(const BinaryTreeNode *_t)
{
    if (_t == NULL)
    {
	std::cerr << "Error! Can not copy a NULL."
		  << std::endl;
	std::exit(-1);
    }
    data = _t->data;
    parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(BinaryTreeNode *_t)
{
    if (_t == NULL)
    {
	std::cerr << "Error! Can not copy a NULL."
		  << std::endl;
	std::exit(-1);
    }
    data = _t->data;
    parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::BinaryTreeNode(TYPE _d)
{
    data = _d;
    parent = left = right = NULL;
};

template <class TYPE>
BinaryTreeNode<TYPE>::~BinaryTreeNode()
{
    parent = left = right = NULL;
};
