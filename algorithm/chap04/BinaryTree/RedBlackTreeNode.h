/**
 * @file   RedBlackTreeNode.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sun Nov  3 09:58:24 2019
 * 
 * @brief Definition of the node structure of a red-black tree.
 * 
 * 
 */

#ifndef __CRAZYFISH__REDBLACKTREENODE__
#define __CRAZYFISH__REDBLACKTREENODE__

#include "BinaryTreeNode.h"

#define BLACK false
#define RED true

/**
 * Define the node structure of a red-black tree. The node structure
 * is base on the one of a binary tree(or same as a binary search
 * tree). With an additional attribute color. And the color is either
 * red or black. 
 * 
 */
class RedBlackTreeNode : public BinaryTreeNode
{
public:
    bool color = RED;		/**< The color is either RED or
				 * BLACK.*/

    /** 
     * Default constructor.
     * 
     * 
     */
    RedBlackTreeNode();
    
    /** 
     * Constructor. Copy a node from the given address.
     * 
     * @param _t The address point to a node(can not be a NULL).
     */
    RedBlackTreeNode(BinaryTreeNode *_t);

    /** 
     * Constructor. Create a node with the data is the given
     * value _d.
     * 
     * @param _d Given value.
     */
    RedBlackTreeNode(TYPE _d);
};

#else
// DO NOTHING.
#endif
