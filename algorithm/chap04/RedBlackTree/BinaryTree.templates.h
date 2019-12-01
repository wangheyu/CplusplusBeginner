#include "BinaryTree.h"

template <class TYPE>
typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::getRoot()
{
    if (root != nil)
	return root;
    else
	return NULL;
};

template <class TYPE>
const typename BinaryTree<TYPE>::Node* BinaryTree<TYPE>::getRoot() const
{
    if (root != nil)
	return (dynamic_cast<const Node *>(root));
    else
	return NULL;
};

template <class TYPE>
BinaryTree<TYPE>::BinaryTree(TYPE _new)
{
    nil = new Node;
    nil->color = BLACK;
    Node *r = new Node;
    r->data = _new;
    r->left = nil;
    r->right = nil;
    r->parent = nil;
    root = r;
};

template <class TYPE>
int BinaryTree<TYPE>::inorder_walk(const Node *_x) const
{
    if (_x != nil)
    {
	inorder_walk(_x->left);
	std::cout << _x->data << " ";
	inorder_walk(_x->right);
    }
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::release(Node *_x)
{
    if (_x != nil)
    {
	release(_x->left);
	release(_x->right);
	delete _x;
    }
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::release()
{
    release(root);
    root = nil;
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::inorder_walk() const
{
    inorder_walk(root);
    std::cout << std::endl;
};

template <class TYPE>
int BinaryTree<TYPE>::setRoot(Node *_r)
{
    root = _r;
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::transplant(Node *_u,
			   Node *_v)
{
    if (_u == nil)
    {
	std::cerr << "Error! Can not transplant to a NULL."
		  << std::endl;
	std::exit(-1);
    }
    if (_u->parent == nil)
	root = _v;   /// Here can not use _u = _v;
    else if (_u == _u->parent->left)
	_u->parent->left = _v;
    else
	_u->parent->right = _v;
//    if (_v != nil)
    _v->parent = _u->parent;
    return 0;
};

template <class TYPE>
inline int BinaryTree<TYPE>::__make_space(int _x) const
{
    for (int i = 0; i < _x; i++)
	std::cout << " ";
    return 0;
};

template <class TYPE>
inline int BinaryTree<TYPE>::__make_both_branch(int _x) const
{
    std::cout << "┌";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┴";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┐"; 
};

template <class TYPE>
inline int BinaryTree<TYPE>::__make_left_branch(int _x) const
{
    std::cout << "┌";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┘";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << " ";
    std::cout << " "; 
};

template <class TYPE>
inline int BinaryTree<TYPE>::__make_right_branch(int _x) const
{
    std::cout << " ";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << " ";
    std::cout << "└";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┐"; 
};

template <class TYPE>
inline int BinaryTree<TYPE>::__pow2(int _x) const
{
    return (1 << _x);
};

template <class TYPE>
int BinaryTree<TYPE>::display() 
{
    updateDepthandPos();
    // For breadth-first tree walk. 
    std::queue<Node *> val;
    // For print tree.  
    std::queue<Node *> output;	
    // Children status for a node.
    enum ChildCases {LEFT, RIGHT, BOTH, NONE};
    // The children stauts of nodes outputing.
    std::queue<ChildCases> output_cc;
    // Cache the branches between node and its children. 
    std::queue<ChildCases> branch_cache;
    // Cache the nodes for outputing. 
    std::queue<Node *> node_cache; 
    if (root != nil)
	val.push(root);
    else
    {
	std::cout << "The tree is empty." << std::endl;
	return 0;
    }
    // Height of the whole tree. 
    int h = height();
    // Record the nodes number for each tree layer. 
    std::vector<int> counter(h , 0);
    // Count the number of outputed nodes.  
    int count = 0;		
    // In this loop, we use a queue val to apply a breadth-first tree
    // walking and to record the order of nodes ouputing by another
    // queue output. In the same time, we also record the children
    // status of each outputing node by queue output_cc, and the
    // number of nodes to output in each layer of the tree by vector
    // counter.
    while (!val.empty())
    {
	bool left_exist = false;
	bool right_exist = false;
	Node *next = val.front();
	val.pop();
	if (next->left != nil)
	{
	    val.push(next->left);
	    left_exist = true;
	}
	if (next->right != nil)
	{
	    val.push(next->right);
	    right_exist = true;
	}
	if (left_exist && right_exist)
	    output_cc.push(BOTH);
	else if (left_exist)
	    output_cc.push(LEFT);
	else if (right_exist)
	    output_cc.push(RIGHT);
	else
	    output_cc.push(NONE);
	output.push(next);
	counter[next->depth]++;
    }
    // Because some of the nodes are missing in an imcomplete tree, so
    // we use the variable off to compute the offset of the display
    // positon for every outputing node. That means we actually print
    // out a complete tree! In some cases, such as each node only has
    // right child, the complexity of this function is 2 to the power
    // of n, which is terrible. However, this function obviously is
    // only for small scale debuging usages.
    
    // Offset of the position to display a node. 
    int off = 0;	
    // In this loop, we actually print the tree by using
    // std::cout. With the branches between nodes and their chidren.
    while (!output.empty())
    {
	Node *next = output.front();
	output.pop();
	// Fill the missing nodes.
	while (off < next->pos)
	{
	    __make_space(__pow2(h - next->depth + 1));
	    off++;
	}
	// Offset for centrally print every node.
	__make_space(__pow2(h - next->depth) - 2);
	if (next->color == RED)
	{
	    std::cout << RC;
	    std::cout << std::setw(3) << std::left << next->data;
	    std::cout << RESET;
	}
	else
	{
	    std::cout << WC;
	    std::cout << std::setw(3) << std::left << next->data;
	    std::cout << RESET;
	}
	__make_space(__pow2(h - next->depth) - 1);
	count++;
	off++;
	// Record the printed node, the children status of these to
	// build the branches between nodes and their childern.
	node_cache.push(next);
	branch_cache.push(output_cc.front());
	output_cc.pop();
	// The first condition means all nodes in this layer have been
	// printed, in the next we should print out a enter to start a
	// newline for branches. And the second condition says if we
	// are in the last layer, we don't do it.
	if (count == counter[next->depth] && next->depth != h - 1)
	{
	    count = 0;
	    off = 0;
	    std::cout << std::endl;
	    while (!branch_cache.empty())
	    {
		ChildCases cc = branch_cache.front();
		branch_cache.pop();
		Node *next = node_cache.front();
		node_cache.pop();
		// Again, we need comput the offset for the branches
		// of those missing node.
		while (off < next->pos)
		{
		    __make_space(__pow2(h - next->depth + 1));
		    off++;
		}
		// The offset for centrally print.
		__make_space(__pow2(h - next->depth - 1) - 2);
		// Pick the different type of the branches.
		if (cc == BOTH)
		    __make_both_branch(__pow2(h - next->depth) + 1);
		else if (cc == LEFT)
		    __make_left_branch(__pow2(h - next->depth) + 1);
		else if (cc == RIGHT)
		    __make_right_branch(__pow2(h - next->depth) + 1);
		else if (cc == NONE)
		    __make_space(__pow2(h - next->depth) + 1);
		__make_space(__pow2(h - next->depth - 1) - 2);
		std::cout << "   ";
		off++;
	    }
	    off = 0;
	    std::cout << std::endl;
	}
    }
    std::cout << std::endl;
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::updateDepthandPos(Node *_x, int _d, int _p)
{
    if (_x != nil)
    {
	_x->depth = _d;
	_x->pos = _p;
	updateDepthandPos(_x->left, _d + 1, _p * 2);
	updateDepthandPos(_x->right, _d + 1, _p *2 + 1);
    }
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::updateDepthandPos()
{
    updateDepthandPos(root, 0, 0);
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::height(const Node *_x) const
{
    if (_x == nil)
	return 0;
    else
	return std::max(height(_x->left), height(_x->right)) + 1;
};

template <class TYPE>
int BinaryTree<TYPE>::height() const
{
    return height(root);
};

template <class TYPE>
BinaryTree<TYPE>::~BinaryTree()
{
    release();
};

template <class TYPE>
int BinaryTree<TYPE>::insertLeft(Node *_x, TYPE _val)
{
    if (_x == nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    if (_x->left != nil)
    {
	std::cerr << "Error! The left child is ocuupied." << std::endl;
	return -1;
    }
    Node *t = new Node;
    t->parent = _x;
    t->data = _val;
    t->left = nil;
    t->right = nil;
    _x->left = t;
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::insertRight(Node *_x, TYPE _val)
{
    if (_x == nil)
    {
	std::cerr << "Error! The tree is empty." << std::endl;
	return -1;
    }
    if (_x->right != nil)
    {
	std::cerr << "Error! The right child is ocuupied." << std::endl;
	return -1;
    }
    Node *t = new Node;
    t->parent = _x;
    t->data = _val;
    t->left = nil;
    t->right = nil;
    _x->right = t;
    return 0;
};

template <class TYPE>
int BinaryTree<TYPE>::RightRotate(Node *_x)
{
    Node *y = _x->left;
    _x->left = y->right;
    if (y->right != nil)
	y->right->parent = _x;
    y->parent = _x->parent;
    if (_x->parent == nil)
	root = y;
    // if _x is _x's parent's left child,
    else if (_x == _x->parent->left)
	// set y as _x's parent's left child.
	_x->parent->left = y;
    else
	_x->parent->right = y;
    y->right = _x;
    _x->parent = y;
};

template <class TYPE>
int BinaryTree<TYPE>::LeftRotate(Node *_x)
{
    Node *y = _x->right;
    _x->right = y->left;
    if (y->left != nil)
	y->left->parent = _x;
    y->parent = _x->parent;
    if (_x->parent == nil)
	root = y;
    // if _x is _x's parent's left child,
    else if (_x == _x->parent->left)
	// set y as _x's parent's left child.
	_x->parent->left = y;
    else
	_x->parent->right = y;
    y->left = _x;
    _x->parent = y;
};

