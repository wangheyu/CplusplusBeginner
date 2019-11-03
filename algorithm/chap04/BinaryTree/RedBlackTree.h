/**
 * @file   RedBlackTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sun Nov  3 10:43:27 2019
 * 
 * @brief A teaching demonstration for red-black trees. 
 * 
 * 
 */

#ifndef __CRAZYFISH__REDBLACKTREE__
#define __CRAZYFISH__REDBLACKTREE__


#include "BinarySearchTree.h"
#include "RedBlackTreeNode.h"

/**
 * Define a class for a red-black tree. It is based on the class of
 * BinarySearchTree, and it's node structure is based on
 * BinaryTreeNode, which is the node structure for a binary tree or
 * binary search tree.
 * 
 */
class RedBlackTree : public BinarySearchTree
{
public:
    typedef RedBlackTreeNode Node;
    
    /** 
     * Constructor. Create a new tree contains only one node which the
     * data is given.
     * 
     * @param _val The given data.
     * 
     */
    RedBlackTree(TYPE _val);

    /** 
     * Default constructor.
     * 
     * 
     */
    RedBlackTree();

    Node *search(TYPE _d);

protected:
    Node *root;
    Node *Nil;
};

#else
// DO NOTHING.
#endif
