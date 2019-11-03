/**
 * @file   BinaryTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Fri Nov  1 14:55:58 2019
 * 
 * @brief A teaching demonstration for binary trees. And it will
 * become the basis structure of binary search trees and red-black
 * trees.
 * 
 * 
 */

#ifndef __CRAZYFISH__BINARYTREE__
#define __CRAZYFISH__BINARYTREE__

#include <limits>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>
#include "BinaryTreeNode.h"

/**
 * Minimum number of TYPE type.
 * 
 */
#define MIN (std::numeric_limits<TYPE>::min())

/**
 * The basic definition of a binary tree.
 * 
 */
class BinaryTree
{
public:
    typedef BinaryTreeNode Node;

protected:
    Node *root;			/**< The address of the root node. And
				 * if the tree is empty, this root
				 * points to the sentinel node nil.*/
    Node *nil;			/**< The sentinel node, its data,
				 * children and parent are all
				 * insignificance, it is just a mark
				 * for NULL, but has the whole
				 * structure as a normal node. And for
				 * all interfaces, nil will transfer
				 * to NULL.*/

private:
    /** 
     * Quite routine for pow function with a base of 2 and integer
     * argument.
     * 
     * @param _x The argument of the function.
     * 
     * @return The pow function value.
     */
    inline int __pow2(int _x) const;

    /** 
     * Print out _x consecutive spaces.
     * 
     * @param _x The number of the spaces.
     * 
     * @return 0 for OK.
     */
    inline int __make_space(int _x) const;

    /** 
     * Print of a branch for a binary tree node has both two children.
     * 
     * @param _x The length of the branch. 
     * 
     * @return 0 for OK.
     */
    inline int __make_both_branch(int _x) const;
    
    /** 
     * Print of a branch for a binary tree node has only left child.
     * 
     * @param _x The length of the branch. 
     * 
     * @return 0 for OK.
     */
    inline int __make_left_branch(int _x) const;

    /** 
     * Print of a branch for a binary tree node has only right child.
     * 
     * @param _x The length of the branch. 
     * 
     * @return 0 for OK.
     */
    inline int __make_right_branch(int _x) const;

public:
    /** 
     * Default constructor.
     * 
     */
    BinaryTree()
    {
	nil = new Node;
	root = nil;
    };

    /** 
     * Constructor. Create a new tree with only one root node, which
     * the the data inside is the given value _new.
     * 
     * @param _new Given value.
     */
    BinaryTree(TYPE _new);

    ~BinaryTree();

    /** 
     * Get the address of the root. This is a read-only version.
     * 
     * 
     * @return The const address of the root.
     */
    const Node *getRoot() const;

    /** 
     * Get the address of the root.
     * 
     * 
     * @return The address of the root.
     */
    Node *getRoot();

    /** 
     * Set the root to the give address, still keep the old root and
     * the sub-tree pointed.
     * 
     * @param _r The new root address.
     * 
     * @return 0 for OK.
     */
    int setRoot(Node *_r);

    /** 
     * Inorder walking and printing the sub-tree root at _x.
     * 
     * @param _x The root of the sub-tree.
     * 
     * @return 0 for OK.
     */
    int inorder_walk(const Node *_x) const;

    /** 
     * Inorder walking and printing the whole tree from the root.
     * 
     * 
     * @return 0 for OK.
     */
    int inorder_walk() const;

    /** 
     * Delete the whole sub-tree root at _x, and release the memory.
     * 
     * @param _x The root of the sub-tree.
     * 
     * @return 0 for OK.
     */
    int release(Node *_x);

    /** 
     * Delete the whole tree and release the memory.
     * 
     * 
     * @return 0 for OK.
     */
    int release();

    /** 
     * Trans plant the sub-tree root at _u to _v. 
     * 
     * @param _u The root of the source sub-tree.
     * @param _v The root place of the sub-tree trans planting to.
     * 
     * @return 0 for OK.
     */
    int transplant(Node *_u, Node *_v);

    /** 
     * Display the whole binary tree as a full binary tree. The
     * efficiency of this routine is quite low: 
     * \f[
     * T(n) = O(2^n),
     * \f]
     * here \f$ n\f$ is the total nodes of the tree. It just for debugging.
     * 
     * @return 0 for OK.
     */
    int display();

    /** 
     * Comput the height of the sub-tree root at _x. The height of an
     * empty tree is 0, and one node tree is 1.
     * 
     * @param _x The root of the sub-tree.
     * 
     * @return The height value.
     */
    int height(const Node *_x) const;

    /** 
     * Comput the height of the tree.
     * 
     * 
     * @return The height value.
     */
    int height() const;

    /** 
     * Update the depth and position values of all nodes in the
     * tree.
     * 
     * @return 0 for OK.
     */
    int updateDepthandPos();

    /** 
     * Update the depth and position values of all nodes in the
     * sub-tree root at _x.
     * 
     * @param _x The root 0f the sub-tree.
     * @param _d The depth value of _x.
     * @param _p The position value of _x.
     * 
     * @return 0 for OK.
     */
    int updateDepthandPos(Node *_x, int _d, int _p);

    /** 
     * Insert a new node with data _val to the left child of _x,
     * return error if the left child is exist.
     * 
     * @param _x The node to insert under.
     * @param _val The data value for the new node.
     * 
     * @return 0 for OK.
     */
    int insertLeft(Node *_x, TYPE _val);

    /** 
     * Insert a new node with data _val to the right child of _x,
     * return error if the right child is exist.
     * 
     * @param _x The node to insert under.
     * @param _val The data value for the new node.
     * 
     * @return 0 for OK.
     */
    int insertRight(Node *_x, TYPE _val);
};

#else
// DO NOTHING.
#endif
