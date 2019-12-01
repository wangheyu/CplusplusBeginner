#include "RedBlackTree.h"

template <class TYPE>
int RedBlackTree<TYPE>::insert(Node *_new)
{
    Node *x = _new;
    BinarySearchTree<TYPE>::insert(x);
    if (x->parent->color == BLACK)
    {
	this->root->color = BLACK;
	return 0;
    }
    while (x->parent != this->nil && x->color == RED)
	if (x->parent == x->parent->parent->left)
	{
	    // y is the uncle of x.
	    Node *y = x->parent->parent->right;
	    // case I:
	    if (y->color == RED)
	    {
		x->parent->color = y->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;
		if (x->parent->color == BLACK)
		    break;
	    }
	    // y->color == BLACK.
	    else
	    {
		// tortuous...
		if (x == x->parent->right)
		{
		    // case II:
		    this->LeftRotate(x->parent);
		    x = x->left;
		}
		// case III:
		this->RightRotate(x->parent->parent);
		x->parent->color = BLACK;
		x->parent->right->color = RED;
		x = x->parent;
	    }
	}
    	else if (x->parent == x->parent->parent->right)
	{
	    Node *y = x->parent->parent->left;
	    // case I:
	    if (y->color == RED)
	    {
		x->parent->color = y->color = BLACK;
		x->parent->parent->color = RED;
		x = x->parent->parent;
		if (x->parent->color == BLACK)
		    break;
	    }
	    else
	    {
		if (x == x->parent->left)
		{
		    // case II:
		    this->RightRotate(x->parent);
		    x = x->right;
		}
		// case III:
		this->LeftRotate(x->parent->parent);
		x->parent->color = BLACK;
		x->parent->left->color = RED;
		x = x->parent;
		break;
	    }
	}
    this->root->color = BLACK;
};

template <class TYPE>
int RedBlackTree<TYPE>::insert(TYPE _d)
{
    Node *t = new Node(_d);
    insert(t);
    return 0;
};

template <class TYPE>
int RedBlackTree<TYPE>::del(Node *_x)
{
    Node *y = _x;
    bool original_color_y = y->color;
    Node *x;
    if (_x->left == this->nil)
    {
	x = _x->right;
	this->transplant(_x, _x->right);
    }
    else if (_x->right == this->nil)
    {
	x = _x->left;
	this->transplant(_x, _x->left);
    }
    else
    {
    	y = this->min(_x->right);
    	original_color_y = y->color;
    	x = y->right;
//    	if (y->parent == _x)
//    	    x->parent = y;
//    	else
	if (y->parent != _x)
    	{
    	    this->transplant(y, y->right);
    	    y->right = _x->right;
    	    y->right->parent = y;
    	}
    	this->transplant(_x, y);
    	y->left = _x->left;
    	y->left->parent = y;
    	y->color = _x->color;
    }
    if (original_color_y == BLACK)
     	while (x != this->root && x->color == BLACK)
    	    if (x == x->parent->left)
    	    {
    		Node *w = x->parent->right;
    		if (w->color == RED)
    		{
    		    w->color = BLACK;
    		    x->parent->color = RED;
    		    this->LeftRotate(x->parent);
    		    w = x->parent->right;
    		}
    		if (w->left->color == BLACK && w->right->color == BLACK)
    		{
    		    w->color = RED;
    		    x = x->parent;
    		}
    		else
		{
		    if (w->right->color == BLACK)
		    {
			w->left->color = BLACK;
			w->color = RED;
			this->RightRotate(w);
			w = x->parent->right;
		    }
		    w->color = x->parent->color;
		    x->parent->color = BLACK;
		    w->right->color = BLACK;
		    this->LeftRotate(x->parent);
		    // If job finished, but x is not root, set to root
		    // for quitting.
		    x = this->root;
		}
	    }
	    else
     	    {
    		Node *w = x->parent->left;
    		if (w->color == RED)
    		{
    		    w->color = BLACK;
    		    x->parent->color = RED;
    		    this->RightRotate(x->parent);
    		    w = x->parent->left;
    		}
    		if (w->right->color == BLACK && w->left->color == BLACK)
    		{
    		    w->color = RED;
    		    x = x->parent;
    		}
    		else
		{
		    if (w->left->color == BLACK)
		    {
			w->right->color = BLACK;
			w->color = RED;
			this->LeftRotate(w);
			w = x->parent->left;
		    }
		    w->color = x->parent->color;
		    x->parent->color = BLACK;
		    w->left->color = BLACK;
		    this->RightRotate(x->parent);
		    // If job finished, but x is not root, set to root
		    // for quitting.
		    x = this->root;
		}
     	    }
    x->color = BLACK;
    delete _x;
    return 0;    
};
