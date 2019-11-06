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

    /** 
     * Convert the interface for the node type of red-black trees by
     * reload.
     * 
     * @param _d The data for searching.
     * 
     * @return The address of the node contains _d, and nil if not
     * found.
     */
    Node *search(TYPE _d);

    /** 
     * Find the node whose data is the minimum under the node _x.
     * 
     * 
     * @return The address of the node with the minimum.
     */
    Node *min(Node *_x);

    /** 
     * Insert a new node to the red-black tree, and keep it as
     * a red-black tree.
     * 
     * @param _new The new node.
     * 
     * @return 0 for OK.
     */
    int insert(Node *_new);
    
    /** 
     * Insert a new node with data _d to the red-black tree, and
     * keep it as a red-black tree.
     * 
     * @param _new The data for the new node.
     * 
     * @return 0 for OK.
     */
    int insert(TYPE _d);

    /** 
     * Delete the node _x in the red-black tree, and keep it as a
     * red-black tree.
     * 
     * @param _x The node to delete.
     * 
     * @return 0 for OK.
     */
    int del(Node *_x);

protected:
    Node *root;
    Node *nil;
};

#else
// DO NOTHING.
#endif
