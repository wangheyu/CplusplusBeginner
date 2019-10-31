#include "BinarySearchTree.h"

const BinarySearchTree::Node *BinarySearchTree::search(TYPE _d) const
{
    const BinarySearchTree::Node *x = getRoot();
    while (x != NULL && _d != x->data)
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    return x;
};

BinarySearchTree::Node *BinarySearchTree::search(TYPE _d)
{
    BinarySearchTree::Node *x = getRoot();
    while (x != NULL && _d != x->data)
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    return x;
};

BinarySearchTree::Node *BinarySearchTree::min()
{
    BinarySearchTree::Node *x = getRoot();
    if (x != NULL)
	while (x->left != NULL)
	    x = x->left;
    return x;
};

const BinarySearchTree::Node *BinarySearchTree::min() const
{
    const BinarySearchTree::Node *x = getRoot();
    if (x != NULL)
	while (x->left != NULL)
	    x = x->left;
    return x;
};

TYPE BinarySearchTree::min_value() const
{
    const BinarySearchTree::Node *x = getRoot();
    if (x == NULL)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->left != NULL)
	x = x->left;
    return x->data;
};

BinarySearchTree::Node *BinarySearchTree::max()
{
    BinarySearchTree::Node *x = getRoot();
    if (x != NULL)
	while (x->right != NULL)
	    x = x->right;
    return x;
};

const BinarySearchTree::Node *BinarySearchTree::max() const
{
    const BinarySearchTree::Node *x = getRoot();
    if (x != NULL)
	while (x->right != NULL)
	    x = x->right;
    return x;
};

TYPE BinarySearchTree::max_value() const
{
    const BinarySearchTree::Node *x = getRoot();
    if (x == NULL)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->right != NULL)
	x = x->right;
    return x->data;
};

BinarySearchTree::Node *
BinarySearchTree::min(Node *_x)
{
    if (_x != NULL)
	while (_x->left != NULL)
	    _x = _x->left;
    return _x;
};

const BinarySearchTree::Node *
BinarySearchTree::min(const BinarySearchTree::Node *_x) const
{
    if (_x != NULL)
	while (_x->left != NULL)
	    _x = _x->left;
    return _x;
};

TYPE
BinarySearchTree::min_value(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->left != NULL)
	_x = _x->left;
    return _x->data;
};

BinarySearchTree::Node *
BinarySearchTree::max(Node *_x)
{
    if (_x != NULL)
	while (_x->right != NULL)
	    _x = _x->right;
    return _x;
};

const BinarySearchTree::Node *
BinarySearchTree::max(const BinarySearchTree::Node *_x) const
{
    if (_x != NULL)
	while (_x->right != NULL)
	    _x = _x->right;
    return _x;
};

TYPE
BinarySearchTree::max_value(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->right != NULL)
	_x = _x->right;
    return _x->data;
};

BinarySearchTree::Node *
BinarySearchTree::successor(BinarySearchTree::Node *_x)
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != NULL)
	return min(_x->right);
    BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    return y;
};

const BinarySearchTree::Node *
BinarySearchTree::successor(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != NULL)
	return min(_x->right);
    /// Use const for safty.
    const BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    return y;
};

TYPE
BinarySearchTree::succeeding_value(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->right != NULL)
	return min_value(_x->right);   
    /// Use const for safty.
    const BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y == NULL)
    {
	std::cerr << "There is no successor of the maximum node."
		  << std::endl;
	/// return MIN as a signal.
	return MIN;   
    }
    else
	return y->data;
};

BinarySearchTree::Node *
BinarySearchTree::predecessor(BinarySearchTree::Node *_x)
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }

    if (_x->left != NULL)
	return max(_x->left);
    BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    return y;
};

const BinarySearchTree::Node *
BinarySearchTree::predecessor(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->left != NULL)
	return max(_x->left);
    BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    return y;
};

TYPE
BinarySearchTree::preceding_value(const BinarySearchTree::Node *_x) const
{
    if (_x == NULL)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->left != NULL)
	return max_value(_x->left);
    BinarySearchTree::Node *y = _x->parent;
    while (y != NULL && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y == NULL)
    {
	std::cerr << "There is no predecessor of the minimum node."
		  << std::endl;
    }
    else
	return y->data;
};

int BinarySearchTree::insert(BinarySearchTree::Node *_new)
{
    Node *y = NULL;
    Node *x = getRoot();
    /// Make sure that _new is a single node binary tree.
    _new->left = _new->right = NULL;
    while (x != NULL)
    {
	y = x;
	if (_new->data < x->data)
	    x = x->left;
	else
	    x = x->right;
    }
    _new->parent = y;
    if (y == NULL)
	reinit(_new);
    else if (_new->data < y->data)
	y->left = _new;
    else
	y->right = _new;
    return 0;
};

int BinarySearchTree::insert(const BinarySearchTree::Node *_new)
{
    Node *y = NULL;
    Node *x = getRoot();
    Node *z = new Node(_new);
    while (x != NULL)
    {
    	y = x;
    	if (z->data < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    }
    z->parent = y;
    if (y == NULL)
    	reinit(z);
    else if (z->data < y->data)
    	y->left = z;
    else
    	y->right = z;
    return 0;
};

int BinarySearchTree::insert(TYPE _d)
{
    Node *y = NULL;
    Node *x = getRoot();
    Node *z = new Node(_d);
    while (x != NULL)
    {
    	y = x;
    	if (z->data < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    }
    z->parent = y;
    if (y == NULL)
    	reinit(z);
    else if (z->data < y->data)
    	y->left = z;
    else
    	y->right = z;
    return 0;
};

int BinarySearchTree::del(BinarySearchTree::Node *_x)
{
    if (_x->left == NULL)
	transplant(_x, _x->right);
    else if (_x->right == NULL)
	transplant(_x, _x->left);
    else
    {
	/// In this branch, _x has two children.  Find the successor
	/// of _x, it exists because of the existence of right
	/// child. Notice that y don't has left child otherwise it can
	/// not be _x's successor(left child of y should less than y
	/// and greater than _x).
	Node *y = min(_x->right);
	/// If y is not a child of _x, which means y is _x's grand
	/// child or lower.
	if (y->parent != _x)   
	{
	    /// This actually make a circle. Dangrous! Here we
	    /// transplant right child of y to y, but we didn't lose
	    /// y. we just make the right child of y become y's
	    /// parent's child. 
	    transplant(y, y->right);
	    /// Then make the right child of _x become y's right
	    /// child. And still we didn't lose the original right
	    /// child of y, it is still y's parent's child.
	    y->right = _x->right;
	    y->right->parent = y;
	    /// Suppose z is y's parent in the beginning, till now,
	    /// y's right child become z's child, and it's original
	    /// place has taken by _x's right child.

	}
	/// If y is _x's child, then y is _x's right child because
	/// it's a successor of _x. And if not, _x's right child has
	/// already transplant to y's right child, while the original
	/// right child of y has already transplant to y's parent's
	/// child(still in the right subtree of the original _x, now
	/// is inside the right subtree of y). In the next we replace
	/// _x with y(with the original right subtree of y together
	/// with the right subtree of _x), and put the left
	/// child of _x to the left child place of y(it's empty
	/// before).
	transplant(_x, y);
	y->left = _x->left;
	y->left->parent = y;
	/// Till now every thing is at the right place excepts _x.
    }
    delete _x;
    return 0;
};                            
