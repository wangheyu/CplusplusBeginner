/**
 * @file   BinaryTreeNode.h
 * @author Wang Heyu <wang@wukong>
 * @date   Fri Nov  1 20:05:49 2019
 * 
 * @brief A node defination for binary trees.
 * 
 * 
 */

#ifndef __CRAZYFISH__BINARYTREENODE__
#define __CRAZYFISH__BINARYTREENODE__

#include <iostream>
#include <cstdlib>


/**
 * Temporally use typedef instead of template.
 * 
 */
typedef int TYPE;

/**
 * The node structure of the binary tree. Set all members as public
 * for efficiency.
 * 
 */
class BinaryTreeNode
{
public:
    TYPE data;		                /**< Satellite data, which is
					 * also a key value. */
    BinaryTreeNode *left;		/**< Left child. */
    BinaryTreeNode *right;	        /**< Right child. */
    BinaryTreeNode *parent;	        /**< Parent.  */
    int depth;		                /**< Depth of the node. */
    int pos;		                /**< Location in the current
					 * layer in the full binary
					 * tree (including the vacant
					 * node).*/

    /** 
     * Default constructor. 
     * 
     */
    BinaryTreeNode(){};

	
    /** 
     * Constructor. Copy a node from the given const address.
     * 
     * @param _t The const address point to a node(can not be a
     * NULL).
     */
    BinaryTreeNode(const BinaryTreeNode *_t);

    /** 
     * Constructor. Copy a node from the given address.
     * 
     * @param _t The address point to a node(can not be a NULL).
     */
    BinaryTreeNode(BinaryTreeNode *_t);

    /** 
     * Constructor. Create a node with the data is the given
     * value _d.
     * 
     * @param _d Given value.
     */
    BinaryTreeNode(TYPE _d);

    /** 
     * Destructor.
     * 
     */
    ~BinaryTreeNode();
};

#else
// DO NOTHING.
#endif
