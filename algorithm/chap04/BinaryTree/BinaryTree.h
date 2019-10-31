/**
 * @file   BinaryTree.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Sep 21 09:41:33 2019
 * 
 * @brief An implementation of binary tree.  
 * This is a demo for teaching, NOT recommended 
 * for any practical job.
 * 
 */

#ifndef __CRAZYFISH__BinaryTree__
#define __CRAZYFISH__BinaryTree__

#include <iostream>
#include <limits>
#include <cstdlib>

namespace CRAZYFISH{
    template<typename TYPE> class BinaryTree;

    /**
     * An implementation of binary tree, using standard C++ 
     * dynamical memory allocation functions (new / delete). 
     * TYPE can be char, int, long, double or long double. 
     * 
     */
    template <typename TYPE>
    class BinaryTree
    {
    public:
	/**
	 * A node of a binary tree.
	 * 
	 */
	class Node
	{
	public:
	    TYPE data;		     /**< The satellite date. */
	    Node *left;    /**< Left child. */
	    Node *right;   /**< Right child. */
	    
	    /** 
	     * The default constructor.
	     * 
	     */
	    Node()
	    {
		left = right = NULL;
	    };

	    /** 
	     * Constructor, with the initial satellite data _d.
	     * 
	     * @param _d The initial value of the satellite data.
	     */
	    Node(TYPE _d) : data(_d)
	    {
		left = right = NULL;
	    };

	    /** 
	     * The default destructor. Free children here is NOT 
             * a good idea! Node should just do the things about node, 
             * functions like add, delete should left to tree.
	     * 
	     */
	    ~Node(){};
	};
    private:
	Node *__root;		/**< The root of the binary tree. */

    public:
	/** 
	 * The default constructor. Build an empty tree.
	 * 
	 */
	BinaryTree()
	{
	    __root = NULL;
	};

	/** 
	 * Constructor, build a binary tree with the given initial 
         * satellite data _val.
	 * 
	 * @param _val The initial satellite data.
	 */
	BinaryTree(TYPE _val);

	/** 
	 * Default destructor. Free the memory before quit.
	 * 
	 */
	~BinaryTree()
	{
	    empty();
	};

	/** 
	 * Clean the subtree under node x.
	 * 
	 * @param x The root of the subtree.
	 * 
	 * @return 0 for OK, -1 for otherwise.
	 */
	int clean(Node* &x);

	/** 
	 * Empty the whole tree.
	 * 
	 * 
	 * @return 0 for OK, -1 for otherwise.
	 */
	int empty();

	/** 
	 * Return the root of the tree. Here without & the return 
         * value is a lvalue, but in some cases, we may want to 
         * modify the root. Such as function @p clean().
	 * 
	 * 
	 * @return The address of the root node.
	 */
	Node* &root();

	/** 
	 * Check if the tree is an empty tree.
	 * 
	 * 
	 * @return True for empty, otherwise return false.
	 */
	bool is_empty();
	
	/** 
	 * Print out all data by inorder tree walking.
	 * 
	 * 
	 * @return 0 for OK, otherwise return -1.
	 */
	int inorderTreeWalk(Node *_x);
    };
}

#include "BinaryTree.templates.h"
#else
//Do nothing.
#endif
