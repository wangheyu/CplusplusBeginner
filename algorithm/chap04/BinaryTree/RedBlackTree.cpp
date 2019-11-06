#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(TYPE _val) : BinarySearchTree(_val)
{
    nil = new Node;
    *nil = *(static_cast<Node *>(BinarySearchTree::nil));
    nil->color = BLACK;
    root = new Node;
    *root = *(static_cast<Node *>(BinarySearchTree::root));
    root->color = RED;
};

RedBlackTree::RedBlackTree() : BinarySearchTree()
{
    nil = new Node;
    *nil = *(static_cast<Node *>(BinarySearchTree::nil));
    nil->color = BLACK;
    root = nil;
};

RedBlackTree::Node *RedBlackTree::search(TYPE _d)
{
    return static_cast<Node *>(BinarySearchTree::search(_d));
};

// The Node in the formal parameter is a RedBlackTreeNode.
RedBlackTree::Node *RedBlackTree::min(Node *_x)
{
    return static_cast<Node *>(BinarySearchTree::min(static_cast<BinaryTreeNode *>(_x)));
};

int RedBlackTree::insert(TYPE _d)
{
    Node *t = new Node(_d);
    t->color = RED;
    BinarySearchTree::insert(t);
};
