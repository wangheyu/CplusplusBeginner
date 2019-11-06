#include "BinaryTreeNode.h"

BinaryTreeNode::BinaryTreeNode(const BinaryTreeNode *_t)
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

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode *_t)
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

BinaryTreeNode::BinaryTreeNode(TYPE _d)
{
    data = _d;
    parent = left = right = NULL;
};

BinaryTreeNode::~BinaryTreeNode()
{
    parent = left = right = NULL;
};
