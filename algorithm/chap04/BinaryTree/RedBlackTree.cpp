#include "RedBlackTree.h"

RedBlackTree::RedBlackTree(TYPE _val) : BinarySearchTree(_val)
{
    Nil = new Node;
    *Nil = *(static_cast<Node *>(BinarySearchTree::Nil));
    Nil->color = BLACK;
    root = new Node;
    *root = *(static_cast<Node *>(BinarySearchTree::root));
    root->color = RED;
};

RedBlackTree::RedBlackTree() : BinarySearchTree()
{
    Nil = new Node;
    *Nil = *(static_cast<Node *>(BinarySearchTree::Nil));
    Nil->color = BLACK;
    root = Nil;
};

RedBlackTree::Node *RedBlackTree::search(TYPE _d)
{
    return static_cast<Node *>(BinarySearchTree::search(_d));
};
