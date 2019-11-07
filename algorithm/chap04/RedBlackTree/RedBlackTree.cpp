#include "RedBlackTree.h"

int RedBlackTree::insert(Node *_new)
{
    Node *x = _new;
    BinarySearchTree::insert(x);
    if (x->parent->color == BLACK)
    {
	root->color = BLACK;
	return 0;
    }
    while (x->parent != nil && x->color == RED)
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
		    LeftRotate(x->parent);
		    x = x->left;
		}
		// case III:
		RightRotate(x->parent->parent);
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
		    RightRotate(x->parent);
		    x = x->right;
		}
		// case III:
		LeftRotate(x->parent->parent);
		x->parent->color = BLACK;
		x->parent->left->color = RED;
		x = x->parent;
		break;
	    }
	}
    root->color = BLACK;
};

int RedBlackTree::insert(TYPE _d)
{
    Node *t = new Node(_d);
    insert(t);
    return 0;
};

int RedBlackTree::del(Node *_x)
{
    Node *y = _x;
    bool original_color_y = y->color;
    Node *x;
    if (_x->left == nil)
    {
	x = _x->right;
	transplant(_x, _x->right);
    }
    else if (_x->right == nil)
    {
	x = _x->left;
	transplant(_x, _x->left);
    }
    else
    {
    	y = min(_x->right);
    	original_color_y = y->color;
    	x = y->right;
//    	if (y->parent == _x)
//    	    x->parent = y;
//    	else
	if (y->parent != _x)
    	{
    	    transplant(y, y->right);
    	    y->right = _x->right;
    	    y->right->parent = y;
    	}
    	transplant(_x, y);
    	y->left = _x->left;
    	y->left->parent = y;
    	y->color = _x->color;
    }
    if (original_color_y == BLACK)
     	while (x != root && x->color == BLACK)
    	    if (x == x->parent->left)
    	    {
    		Node *w = x->parent->right;
    		if (w->color == RED)
    		{
    		    w->color = BLACK;
    		    x->parent->color = RED;
    		    LeftRotate(x->parent);
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
			RightRotate(w);
			w = x->parent->right;
		    }
		    w->color = x->parent->color;
		    x->parent->color = BLACK;
		    w->right->color = BLACK;
		    LeftRotate(x->parent);
		    // If job finished, but x is not root, set to root
		    // for quitting.
		    x = root;
		}
	    }
	    else
     	    {
    		Node *w = x->parent->left;
    		if (w->color == RED)
    		{
    		    w->color = BLACK;
    		    x->parent->color = RED;
    		    RightRotate(x->parent);
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
			LeftRotate(w);
			w = x->parent->left;
		    }
		    w->color = x->parent->color;
		    x->parent->color = BLACK;
		    w->left->color = BLACK;
		    RightRotate(x->parent);
		    // If job finished, but x is not root, set to root
		    // for quitting.
		    x = root;
		}
     	    }
    x->color = BLACK;
    delete _x;
    return 0;    
};
