/**
 * @file   BinarySearchTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Nov  2 11:06:42 2019
 * 
 * @brief A teaching demonstration for binary search trees. And it
 * will become the basis structure of red-black trees.
 * 
 * 
 */
#ifndef __CRAZYFISH__BINARYSEARCHTREE__
#define __CRAZYFISH__BINARYSEARCHTREE__


#include "BinaryTree.h"

template <class TYPE>
class BinarySearchTree;

/**
 * The BinarySearchTree is based on BinaryTree, providing very basic
 * oprations. The data of nodes can be at same values, then in the
 * trees, the right child can has the same value as the parent. This
 * rule is implicitly defined in the function insert.
 * 
 */
template <class TYPE>
class BinarySearchTree : public BinaryTree<TYPE>
{
public:
    typedef typename BinaryTree<TYPE>::Node Node;
    
    /** 
     * Constructor. Create a new tree contains only one node which the
     * data is given.
     * 
     * @param _val The given data.
     * 
     */
    BinarySearchTree(TYPE _val) : BinaryTree<TYPE>(_val)
    {};

    /** 
     * Default constructor.
     * 
     * 
     */
    BinarySearchTree()
    {};

    /** 
     * Seach the location of the node contains data _d. If there are
     * more than one nodes, return the first one met. This is a
     * read-only version.
     * 
     * @param _d The data for searching.
     * 
     * @return The address of the node contains _d, and nil if not
     * found.
     */
    const Node *search(TYPE _d) const;

    /** 
     * Seach the location of the node contains data _d. If there are
     * more than one nodes, return the first one met. This is a
     * read-only version.
     * 
     * @param _d The data for searching.
     * 
     * @return The address of the node contains _d, and nil if not
     * found.
     */
    Node *search(TYPE _d);

    /** 
     * Find the node whose data is the minimum in the whole tree.
     * 
     * 
     * @return The address of the node with the minimum.
     */
    Node *min();
    
    /** 
     * Find the node whose data is the minimum in the whole tree. This
     * is the read-only version.
     * 
     * 
     * @return The address of the node with the minimum.
     */
    const Node *min() const;

    /** 
     * Find the minimum data in the whole tree.
     * 
     * 
     * @return The minimum.
     */
    TYPE min_value() const;
    
    /** 
     * Find the node whose data is the minimum under the node _x.
     * 
     * 
     * @return The address of the node with the minimum.
     */
    Node *min(Node *_x);
    
    /** 
     * Find the node whose data is the minimum under the node _x. This
     * is the read-only version.
     * 
     * 
     * @return The address of the node with the minimum.
     */
    const Node *min(const Node *_x) const;

    /** 
     * Find the minimum data under the node _x.
     * 
     * 
     * @return The minimum.
     */
    TYPE min_value(const Node *_x) const;

    /** 
     * Find the node whose data is the maximum in the whole tree.
     * 
     * 
     * @return The address of the node with the maximum.
     */
    Node *max();
    
    /** 
     * Find the node whose data is the maximum in the whole tree. This
     * is the read-only version.
     * 
     * 
     * @return The address of the node with the maximum.
     */
    const Node *max() const;

    /** 
     * Find the maximum data in the whole tree.
     * 
     * 
     * @return The maximum.
     */
    TYPE max_value() const;
    
    /** 
     * Find the node whose data is the maximum under the node _x.
     * 
     * 
     * @return The address of the node with the maximum.
     */
    Node *max(Node *_x);
    
    /** 
     * Find the node whose data is the maximum under the node _x. This
     * is the read-only version.
     * 
     * 
     * @return The address of the node with the maximum.
     */
    const Node *max(const Node *_x) const;

    /** 
     * Find the maximum data under the node _x.
     * 
     * 
     * @return The maximum.
     */
    TYPE max_value(const Node *_x) const;

    /** 
     * Find the node with the smallest data greater than the data of
     * _x.
     * 
     * @param _x The start node.
     * 
     * @return The address of the successor node.
     */
    Node *successor(Node *_x);
    
    /** 
     * Find the node with the smallest data greater than the data of
     * _x. This is the read-only version.
     * 
     * @param _x The start node.
     * 
     * @return The address of the successor node.
     */
    const Node *successor(const Node *_x) const;

    /** 
     * Find the smallest data greater than the data of _x.
     * 
     * @param _x The start node.
     * 
     * @return The successor data.
     */
    TYPE succeeding_value(const Node *_x) const;
    
    /** 
     * Find the node with the largest data less than the data of
     * _x.
     * 
     * @param _x The start node.
     * 
     * @return The address of the predecessor node.
     */
    Node *predecessor(Node *_x);

    /** 
     * Find the node with the largest data less than the data of
     * _x. This is the read-only version.
     * 
     * @param _x The start node.
     * 
     * @return The address of the predecessor node.
     */
    const Node *predecessor(const Node *_x) const;
    
    /** 
     * Find the largest data less than the data of _x.
     * 
     * @param _x The start node.
     * 
     * @return The predecessor data.
     */
    TYPE preceding_value(const Node *_x) const;

    /** 
     * Insert a new node to the binary search tree, and keep it as
     * a binary search tree.
     * 
     * @param _new The new node.
     * 
     * @return 0 for OK.
     */
    int insert(Node *_new);
    
    /** 
     * Insert a new node with data _d to the binary search tree, and
     * keep it as a binary search tree.
     * 
     * @param _new The data for the new node.
     * 
     * @return 0 for OK.
     */
    int insert(TYPE _d);

    /** 
     * Delete node _x in the binary search tree, and keep it as a
     * binary search tree.
     * 
     * @param _x The node to delete.
     * 
     * @return 0 for OK.
     */
    int del(Node *_x);
};

#else
// DO NOTHING.
#endif
