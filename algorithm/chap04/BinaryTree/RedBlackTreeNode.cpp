#include "RedBlackTreeNode.h"

RedBlackTreeNode::RedBlackTreeNode(BinaryTreeNode *_t) : BinaryTreeNode(_t)
{
    color = RED;
};

RedBlackTreeNode::RedBlackTreeNode(TYPE _d) : BinaryTreeNode(_d)
{
    color = RED;
};

RedBlackTreeNode::RedBlackTreeNode() : BinaryTreeNode()
{
    color = RED;
};

