#include "BinarySearchTree.h"

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::search(TYPE _d) const
{
    const Node *x = this->root;
    while (x != this->nil && _d != x->data)
	// Here the decision rule has to accord with the one in the
	// insert function.
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::search(TYPE _d)
{
    Node *x = this->root;
    while (x != this->nil && _d != x->data)
	// Here the decision rule has to accord with the one in the
	// insert function.
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min()
{
    Node *x = this->root;
    if (x != this->nil)
	while (x->left != this->nil)
	    x = x->left;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::min() const
{
    const Node *x = this->root;
    if (x != this->nil)
	while (x->left != this->nil)
	    x = x->left;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::min_value() const
{
    const Node *x = this->root;
    if (x == this->nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->left != this->nil)
	x = x->left;
    return x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max()
{
    Node *x = this->root;
    if (x != this->nil)
	while (x->right != this->nil)
	    x = x->right;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *BinarySearchTree<TYPE>::max() const
{
    const Node *x = this->root;
    if (x != this->nil)
	while (x->right != this->nil)
	    x = x->right;
    if (x != this->nil)
	return x;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::max_value() const
{
    const Node *x = this->root;
    if (x == this->nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->right != this->nil)
	x = x->right;
    return x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::min(Node *_x)
{
    if (_x != this->nil)
	while (_x->left != this->nil)
	    _x = _x->left;
    if (_x != this->nil)
	return _x;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::min(const Node *_x) const
{
    if (_x != this->nil)
	while (_x->left != this->nil)
	    _x = _x->left;
    if (_x != this->nil)
	return _x;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::min_value(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->left != this->nil)
	_x = _x->left;
    return _x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::max(Node *_x)
{
    if (_x != this->nil)
	while (_x->right != this->nil)
	    _x = _x->right;
    if (_x != this->nil)
	return _x;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::max(const Node *_x) const
{
    if (_x != this->nil)
	while (_x->right != this->nil)
	    _x = _x->right;
    if (_x != this->nil)
	return _x;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::max_value(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->right != this->nil)
	_x = _x->right;
    return _x->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::successor(Node *_x)
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != this->nil)
	return min(_x->right);
    Node *y = _x->parent;
    while (y != this->nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y != this->nil)
	return y;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::successor(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != this->nil)
	return min(_x->right);
    // Use const for safty.
    const Node *y = _x->parent;
    while (y != this->nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y != this->nil)
	return y;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::succeeding_value(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->right != this->nil)
	return min_value(_x->right);   
    // Use const for safty.
    const Node *y = _x->parent;
    while (y != this->nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y == this->nil)
    {
	std::cerr << "There is no successor of the maximum node."
		  << std::endl;
	/// return MIN as a signal.
	return MIN;   
    }
    else
	return y->data;
};

template <class TYPE>
typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::predecessor(Node *_x)
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }

    if (_x->left != this->nil)
	return max(_x->left);
    Node *y = _x->parent;
    while (y != this->nil && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y != this->nil)
	return y;
    else
	return NULL;
};

template <class TYPE>
const typename BinarySearchTree<TYPE>::Node *
BinarySearchTree<TYPE>::predecessor(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->left != this->nil)
	return max(_x->left);
    const Node *y = _x->parent;
    while (y != this->nil && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y == this->nil)
	return y;
    else
	return NULL;
};

template <class TYPE>
TYPE BinarySearchTree<TYPE>::preceding_value(const Node *_x) const
{
    if (_x == this->nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->left != this->nil)
	return max_value(_x->left);
    const Node *y = _x->parent;
    while (y != this->nil && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y == NULL)
    {
	std::cerr << "There is no predecessor of the minimum node."
		  << std::endl;
	return MIN;
    }
    else
	return y->data;
};

template <class TYPE>
int BinarySearchTree<TYPE>::insert(Node *_new)
{
    Node *y = this->nil;
    Node *x = this->root;
    // Make sure that _new is a single node binary tree.
    _new->left = _new->right = this->nil;
    while (x != this->nil)
    {
	y = x;
	// The nodes less than to the left, then these greater than or
	// equal to to the right.
	if (_new->data < x->data)
	    x = x->left;
	else
	    x = x->right;
    }
    _new->parent = y;
    if (y == this->nil)
	this->root = _new;
    // Here the decision rule has to same as above.
    else if (_new->data < y->data)
	y->left = _new;
    else
	y->right = _new;
    return 0;
};

template <class TYPE>
int BinarySearchTree<TYPE>::insert(TYPE _d)
{
    Node *y = this->nil;
    Node *x = this->root;
    Node *z = new Node(_d);
    // Here has to reset the nil, since the Node do not contains the
    // definatio of nil.
    z->left = z->right = this->nil;
    while (x != this->nil)
    {
    	y = x;
	// The nodes less than to the left, then these greater than or
	// equal to to the right.
    	if (z->data < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    }
    z->parent = y;
    if (y == this->nil)
    	this->root = z;
    // Here the decision rule has to same as above.
    else if (z->data < y->data)
    	y->left = z;
    else
    	y->right = z;
    return 0;
};

template <class TYPE>
int BinarySearchTree<TYPE>::del(Node *_x)
{
    if (_x->left == this->nil)
	this->transplant(_x, _x->right);
    else if (_x->right == this->nil)
	this->transplant(_x, _x->left);
    else
    {
	// In this branch, _x has two children.  Find the successor of
	// _x, it exists because of the existence of right
	// child. Notice that y don't has left child otherwise it can
	// not be _x's successor(left child of y should less than y
	// and greater than _x).
	Node *y = min(_x->right);
	// If y is not a child of _x, which means y is _x's grand
	// child or lower.
	if (y->parent != _x)   
	{
	    // This actually make a circle. Dangrous! Here we
	    // transplant right child of y to y, but we didn't lose
	    // y. we just make the right child of y become y's
	    // parent's child.
	    this->transplant(y, y->right);
	    // Then make the right child of _x become y's right
	    // child. And still we didn't lose the original right
	    // child of y, it is still y's parent's child.
	    y->right = _x->right;
	    y->right->parent = y;
	    // Suppose z is y's parent in the beginning, till now, y's
	    // right child become z's child, and it's original place
	    // has taken by _x's right child.

	}
	// If y is _x's child, then y is _x's right child because it's
	// a successor of _x. And if not, _x's right child has already
	// transplant to y's right child, while the original right
	// child of y has already transplant to y's parent's
	// child(still in the right subtree of the original _x, now is
	// inside the right subtree of y). In the next we replace _x
	// with y(with the original right subtree of y together with
	// the right subtree of _x), and put the left child of _x to
	// the left child place of y(it's empty before).
	this->transplant(_x, y);
	y->left = _x->left;
	y->left->parent = y;
	// Till now every thing is at the right place excepts _x.
    }
    delete _x;
    return 0;
};                            
