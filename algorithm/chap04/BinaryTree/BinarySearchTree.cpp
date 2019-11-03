#include "BinarySearchTree.h"

const BinarySearchTree::Node *BinarySearchTree::search(TYPE _d) const
{
    const Node *x = root;
    while (x != nil && _d != x->data)
	// Here the decision rule has to accord with the one in the
	// insert function.
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    if (x != nil)
	return x;
    else
	return NULL;
};

BinarySearchTree::Node *BinarySearchTree::search(TYPE _d)
{
    Node *x = root;
    while (x != nil && _d != x->data)
	// Here the decision rule has to accord with the one in the
	// insert function.
    	if (_d < x->data)
    	    x = x->left;
    	else
    	    x = x->right;
    if (x != nil)
	return x;
    else
	return NULL;
};

BinarySearchTree::Node *BinarySearchTree::min()
{
    Node *x = root;
    if (x != nil)
	while (x->left != nil)
	    x = x->left;
    if (x != nil)
	return x;
    else
	return NULL;
};

const BinarySearchTree::Node *BinarySearchTree::min() const
{
    const Node *x = root;
    if (x != nil)
	while (x->left != nil)
	    x = x->left;
    if (x != nil)
	return x;
    else
	return NULL;
};

TYPE BinarySearchTree::min_value() const
{
    const Node *x = root;
    if (x == nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->left != nil)
	x = x->left;
    return x->data;
};

BinarySearchTree::Node *BinarySearchTree::max()
{
    Node *x = root;
    if (x != nil)
	while (x->right != nil)
	    x = x->right;
    if (x != nil)
	return x;
    else
	return NULL;
};

const BinarySearchTree::Node *BinarySearchTree::max() const
{
    const Node *x = root;
    if (x != nil)
	while (x->right != nil)
	    x = x->right;
    if (x != nil)
	return x;
    else
	return NULL;
};

TYPE BinarySearchTree::max_value() const
{
    const Node *x = root;
    if (x == nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    while (x->right != nil)
	x = x->right;
    return x->data;
};

BinarySearchTree::Node *
BinarySearchTree::min(Node *_x)
{
    if (_x != nil)
	while (_x->left != nil)
	    _x = _x->left;
    if (_x != nil)
	return _x;
    else
	return NULL;
};

const BinarySearchTree::Node *
BinarySearchTree::min(const Node *_x) const
{
    if (_x != nil)
	while (_x->left != nil)
	    _x = _x->left;
    if (_x != nil)
	return _x;
    else
	return NULL;
};

TYPE
BinarySearchTree::min_value(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->left != nil)
	_x = _x->left;
    return _x->data;
};

BinarySearchTree::Node *
BinarySearchTree::max(Node *_x)
{
    if (_x != nil)
	while (_x->right != nil)
	    _x = _x->right;
    if (_x != nil)
	return _x;
    else
	return NULL;
};

const BinarySearchTree::Node *
BinarySearchTree::max(const Node *_x) const
{
    if (_x != nil)
	while (_x->right != nil)
	    _x = _x->right;
    if (_x != nil)
	return _x;
    else
	return NULL;
};

TYPE
BinarySearchTree::max_value(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return -1;
    }
    while (_x->right != nil)
	_x = _x->right;
    return _x->data;
};

BinarySearchTree::Node *
BinarySearchTree::successor(Node *_x)
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != nil)
	return min(_x->right);
    Node *y = _x->parent;
    while (y != nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y != nil)
	return y;
    else
	return NULL;
};

const BinarySearchTree::Node *
BinarySearchTree::successor(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->right != nil)
	return min(_x->right);
    // Use const for safty.
    const Node *y = _x->parent;
    while (y != nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y != nil)
	return y;
    else
	return NULL;
};

TYPE
BinarySearchTree::succeeding_value(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->right != nil)
	return min_value(_x->right);   
    // Use const for safty.
    const Node *y = _x->parent;
    while (y != nil && _x == y->right)
    {
	_x = y;
	y = y->parent;
    }
    if (y == nil)
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
BinarySearchTree::predecessor(Node *_x)
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }

    if (_x->left != nil)
	return max(_x->left);
    Node *y = _x->parent;
    while (y != nil && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y != nil)
	return y;
    else
	return NULL;
};

const BinarySearchTree::Node *
BinarySearchTree::predecessor(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	return NULL;
    }
    if (_x->left != nil)
	return max(_x->left);
    const Node *y = _x->parent;
    while (y != nil && _x == y->left)
    {
	_x = y;
	y = y->parent;
    }
    if (y == nil)
	return y;
    else
	return NULL;
};

TYPE
BinarySearchTree::preceding_value(const Node *_x) const
{
    if (_x == nil)
    {
	std::cerr << "Error! The node is a NULL." << std::endl;
	std::exit(-1);
    }
    if (_x->left != nil)
	return max_value(_x->left);
    const Node *y = _x->parent;
    while (y != nil && _x == y->left)
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

int BinarySearchTree::insert(Node *_new)
{
    Node *y = nil;
    Node *x = root;
    // Make sure that _new is a single node binary tree.
    _new->left = _new->right = nil;
    while (x != nil)
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
    if (y == nil)
	root = _new;
    // Here the decision rule has to same as above.
    else if (_new->data < y->data)
	y->left = _new;
    else
	y->right = _new;
    return 0;
};

int BinarySearchTree::insert(TYPE _d)
{
    Node *y = nil;
    Node *x = root;
    Node *z = new Node(_d);
    // Here has to reset the nil, since the Node do not contains the
    // definatio of nil.
    z->left = z->right = nil;
    while (x != nil)
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
    if (y == nil)
    	root = z;
    // Here the decision rule has to same as above.
    else if (z->data < y->data)
    	y->left = z;
    else
    	y->right = z;
    return 0;
};

int BinarySearchTree::del(Node *_x)
{
    if (_x->left == nil)
	transplant(_x, _x->right);
    else if (_x->right == nil)
	transplant(_x, _x->left);
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
	    transplant(y, y->right);
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
	transplant(_x, y);
	y->left = _x->left;
	y->left->parent = y;
	// Till now every thing is at the right place excepts _x.
    }
    delete _x;
    return 0;
};                            
