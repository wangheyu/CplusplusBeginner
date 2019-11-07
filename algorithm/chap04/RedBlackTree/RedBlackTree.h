/**
 * @file   RedBlackTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Wed Nov  6 10:08:28 2019
 * 
 * @brief A teaching demonstration for red-black trees.
 * 
 * 
 */

#ifndef __CRAZYFISH__REDBLACKTREE__
#define __CRAZYFISH__REDBLACKTREE__

#include "BinarySearchTree.h"

class RedBlackTree : public BinarySearchTree
{
public:
    /** 
     * Constructor. Create a new tree contains only one node which the
     * data is given.
     * 
     * @param _val The given data.
     * 
     */
    RedBlackTree(TYPE _val) : BinarySearchTree(_val)
    {
	root->color = BLACK;
    };

    /** 
     * Default constructor.
     * 
     * 
     */
    RedBlackTree()
    {};
    
    /** 
     * Insert a new node to the binary search tree, and keep it as
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
     * Delete node _x in the red-black tree, and keep it as a
     * red-black tree.
     * 
     * @param _x The node to delete.
     * 
     * @return 0 for OK.
     */
    int del(Node *_x);
};

#else
//DO NOTHING.
#endif
