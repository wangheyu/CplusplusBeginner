/**
 * @file   BinarySearchTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Sep 21 09:41:33 2019
 * 
 * @brief An implementation of binary search tree.  
 * This is a demo for teaching, NOT recommended 
 * for any practical job.
 * 
 */

#ifndef __CRAZYFISH__BinarySearchTree__
#define __CRAZYFISH__BinarySearchTree__

#include <iostream>
#include <limits>
#include <cstdlib>
#include "BinaryTree.h"

namespace CRAZYFISH{
    template<typename TYPE> class BinarySearchTree;

    /**
     * An implementation of binary search tree, using standard C++ 
     * dynamical memory allocation functions (new / delete). 
     * TYPE can be char, int, long, double or long double. 
     * 
     */
    template <typename TYPE>
    class BinarySearchTree : public BinaryTree<TYPE>
    {
    public:
	/** 
	 * Default constructor.
	 * 
	 */
	BinarySearchTree() : BinaryTree<TYPE>() {};
	
    	/** 
	 * Using the constructor of the base class to construct 
         * a new class with @p _val as its initial value of the 
         * satellite data.
	 * 
	 * @param _val The initial value of the satellite data.
	 */
	BinarySearchTree(TYPE _val);

	typedef typename BinaryTree<TYPE>::Node Node;
	
	/** 
	 * Insert a node into the appropriate position to keep it 
         * as a binary search tree.
	 * 
	 * @param _x The address of the new node.
	 * 
	 * @return 0 for OK, otherwise return -1.
	 */
	int insert(Node *_x);
    };
}
#include "BinarySearchTree.templates.h"
#else
// Do nothing.
#endif
