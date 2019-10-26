#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <vector>

typedef int TYPE;

#define MIN (std::numeric_limits<TYPE>::min())

class BinaryTree
{
public:
    class Node
    {
    public:
	TYPE data;
	Node *left;
	Node *right;
	Node *parent;
	int depth;
	int pos;
	Node(){};
	Node(const Node *_t);
	Node(Node *_t);
	Node(TYPE _d);
	~Node();
    };
    BinaryTree()
    {
	__root = NULL;
    };
    BinaryTree(TYPE _new);
    const Node *getRoot() const;
    Node *getRoot();
    int reinit(Node *_r);   // ???
    int inorder_walk(const Node *_x) const;
    int release(Node *_x);
    int inorder_walk() const;
    int release();
    int transplant(Node *_u, Node *_v);
    int display() const;
    int height(Node *_x) const;
    int height() const;
    int updateDepthandPos();
    int updateDepthandPos(Node *_x, int _d, int _p);

private:
    Node *__root;
    inline int __pow2(int _x) const;
    inline int __make_space(int _x) const;
    inline int __make_both_branch(int _x) const;
    inline int __make_left_branch(int _x) const;
    inline int __make_right_branch(int _x) const;
};

BinaryTree::Node::Node(const BinaryTree::Node *_t)
{
    if (_t == NULL)
    {
	std::cerr << "Error! Can not copy a NULL."
		  << std::endl;
	std::exit(-1);
    }
    data = _t->data;
    parent = left = right = NULL;
};

BinaryTree::Node::Node(BinaryTree::Node *_t)
{
    if (_t == NULL)
    {
	std::cerr << "Error! Can not copy a NULL."
		  << std::endl;
	std::exit(-1);
    }
    data = _t->data;
    parent = left = right = NULL;
};

BinaryTree::Node::Node(TYPE _d)
{
    data = _d;
    parent = left = right = NULL;
};

BinaryTree::Node::~Node()
{
    parent = left = right = NULL;
};

class BinarySearchTree : public BinaryTree
{
public:
    const Node *search(TYPE _d) const;   // Node is inherited from the base class.
    Node *search(TYPE _d);
    Node *min();
    const Node *min() const;
    TYPE min_value() const;
    Node *max();
    const Node *max() const;
    TYPE max_value() const;
    Node *min(Node *_x);
    const Node *min(const Node *_x) const;
    TYPE min_value(const Node *_x) const;
    Node *max(Node *_x);
    const Node *max(const Node *_x) const;
    TYPE max_value(const Node *_x) const;
    Node *successor(Node *_x);
    const Node *successor(const Node *_x) const;
    TYPE succeeding_value(const Node *_x) const;
    Node *predecessor(Node *_x);
    const Node *predecessor(const Node *_x) const;
    TYPE preceding_value(const Node *_x) const;
    int insert(Node *_new);
    int insert(const Node *_new);
    int insert(TYPE _d);
    int del(Node *_x);
};

BinaryTree::Node* BinaryTree::getRoot()
{
    return __root;
};

const BinaryTree::Node* BinaryTree::getRoot() const
{
    return (dynamic_cast<const Node *>(__root));
};

BinaryTree::BinaryTree(TYPE _new)
{
    Node *r = new Node;
    r->data = _new;
    r->left = NULL;
    r->right = NULL;
    r->parent = NULL;
};

int BinaryTree::inorder_walk(const Node *_x) const
{
    if (_x != NULL)
    {
	inorder_walk(_x->left);
	std::cout << _x->data << " ";
	inorder_walk(_x->right);
    }
    return 0;
};

int BinaryTree::release(Node *_x)
{
    if (_x != NULL)
    {
	release(_x->left);
	release(_x->right);
	delete _x;
    }
    return 0;
};

int BinaryTree::release()
{
    release(__root);
    __root = NULL;
    return 0;
};

int BinaryTree::inorder_walk() const
{
    inorder_walk(__root);
    std::cout << std::endl;
};

int BinaryTree::reinit(Node *_r)
{
    /// We can not release old root since it may be still in using. 
//    Node *t = __root;
    __root = _r;
//    release(t);
    return 0;
};

int BinaryTree::transplant(BinaryTree::Node *_u,
			   BinaryTree::Node *_v)
{
    if (_u == NULL)
    {
	std::cerr << "Error! Can not transplant to a NULL."
		  << std::endl;
	std::exit(-1);
    }
    if (_u->parent == NULL)
	reinit(_v);   /// Here can not use _u = _v;
    else if (_u == _u->parent->left)
	_u->parent->left = _v;
    else
	_u->parent->right = _v;
    if (_v != NULL)
	_v->parent = _u->parent;
//    release(_u);   // ??? Dangrous!
    return 0;
};

inline int BinaryTree::__make_space(int _x) const
{
    for (int i = 0; i < _x; i++)
	std::cout << " ";
    return 0;
};

inline int BinaryTree::__make_both_branch(int _x) const
{
    std::cout << "┌";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┴";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┐"; 
};

inline int BinaryTree::__make_left_branch(int _x) const
{
    std::cout << "┌";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┘";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << " ";
    std::cout << " "; 
};

inline int BinaryTree::__make_right_branch(int _x) const
{
    std::cout << " ";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << " ";
    std::cout << "└";
    for (int i = 0; i < (_x - 3) / 2; i++)
	std::cout << "─";
    std::cout << "┐"; 
};

inline int BinaryTree::__pow2(int _x) const
{
    return (1 << _x);
};

int BinaryTree::display() const
{
    std::queue<Node *> val;	/**< For breadth-first tree walk. */
    std::queue<Node *> output;	/**< For print tree.  */
    /// Children status for a node.
    enum ChildCases {LEFT, RIGHT, BOTH, NONE};
    std::queue<ChildCases> output_cc; /**< The children stauts 
					 of nodes outputing.*/
    std::queue<ChildCases> branch_cache; /**< Cache the branches between 
					    node and its children. */
    std::queue<Node *> node_cache; /**< Cache the nodes for outputing. */
    if (__root != NULL)
	val.push(__root);
    else
    {
	std::cout << "The tree is empty." << std::endl;
	return 0;
    }
    int h = height();		/**< Height of the whole tree. */
    std::vector<int> counter(h , 0); /**< Record the nodes number 
					for each tree layer. */
    int count = 0;		/**< Count the number of outputed nodes.  */
    /// In this loop, we use a queue val to apply a breadth-first tree
    /// walking and to record the order of nodes ouputing by another
    /// queue output. In the same time, we also record the children
    /// status of each outputing node by queue output_cc, and the
    /// number of nodes to output in each layer of the tree by vector
    /// counter.
    while (!val.empty())
    {
	bool left_exist = false;
	bool right_exist = false;
	Node *next = val.front();
	val.pop();
	if (next->left != NULL)
	{
	    val.push(next->left);
	    left_exist = true;
	}
	if (next->right != NULL)
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
    /// Because some of the nodes are missing in an imcomplete tree,
    /// so we use the variable off to compute the offset of the
    /// display positon for every outputing node. That means we
    /// actually print out a complete tree! In some cases, such as
    /// each node only has right child, the complexity of this
    /// function is 2 to the power of n, which is terrible. However,
    /// this function obviously is only for small scale debuging
    /// usages.
    int off = 0;		/**< Offset of the position to display
				 * a node. */
    /// In this loop, we actually print the tree by using
    /// std::cout. With the branches between nodes and their chidren.
    while (!output.empty())
    {
	Node *next = output.front();
	output.pop();
	/// Fill the missing nodes.
	while (off < next->pos)
	{
	    __make_space(__pow2(h - next->depth + 1));
	    off++;
	}
	/// Offset for centrally print every node.
	__make_space(__pow2(h - next->depth) - 2);
	std::cout << std::setw(3) << std::left << next->data;
	__make_space(__pow2(h - next->depth) - 1);
	count++;
	off++;
	/// Record the printed node, the children status of these to
	/// build the branches between nodes and their childern.
	node_cache.push(next);
	branch_cache.push(output_cc.front());
	output_cc.pop();
	/// The first condition means all nodes in this layer have
	/// been printed, in the next we should print out a enter to
	/// start a newline for branches. And the second condition
	/// says if we are in the last layer, we don't do it.
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
		/// Again, we need comput the offset for the branches
		/// of those missing node.
		while (off < next->pos)
		{
		    __make_space(__pow2(h - next->depth + 1));
		    off++;
		}
		/// The offset for centrally print.
		__make_space(__pow2(h - next->depth - 1) - 2);
		/// Pick the different type of the branches.
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

int BinaryTree::updateDepthandPos(Node *_x, int _d, int _p)
{
    if (_x != NULL)
    {
	_x->depth = _d;
	_x->pos = _p;
	updateDepthandPos(_x->left, _d + 1, _p * 2);
	updateDepthandPos(_x->right, _d + 1, _p *2 + 1);
    }
    return 0;
};

int BinaryTree::updateDepthandPos()
{
    updateDepthandPos(__root, 0, 0);
    return 0;
};

int BinaryTree::height(BinaryTree::Node *_x) const
{
    if (_x == NULL)
	return 0;
    else
	return std::max(height(_x->left), height(_x->right)) + 1;
};

int BinaryTree::height() const
{
    return height(__root);
}

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

int main(int argc, char *argv[])
{
    BinarySearchTree A;
    A.insert(16);
    A.insert(8);
    A.insert(24);
    A.insert(4);
    A.insert(12);
    A.insert(20);
    A.insert(28);
    A.insert(2);
    A.insert(6);
    A.insert(10);
    A.insert(14);
    A.insert(18);
    A.insert(22);
    A.insert(26);
    A.insert(30);
    A.insert(1);
    A.insert(3);
    A.insert(5);
    A.insert(7);
    A.insert(9);
    A.insert(11);
    A.insert(13);
    A.insert(15);
    A.insert(17);
    A.insert(19);
    A.insert(21);
    A.insert(23);
    A.insert(25);
    A.insert(27);
    A.insert(29);
    A.insert(31);
    
    A.updateDepthandPos();
    A.display();

    BinarySearchTree::Node *r = A.getRoot();
    std::cout << "delete " << r->data << std::endl;
    A.del(r);
    A.updateDepthandPos();
    A.display();

    r = A.getRoot();
    std::cout << "delete " << r->left->data << std::endl;
    A.del(r->left);
    A.updateDepthandPos();
    A.display();

    std::cout << "delete " << r->left->right->left->data << std::endl;
    A.del(r->left->right->left);
    A.updateDepthandPos();
    A.display();
    return 0;
};
