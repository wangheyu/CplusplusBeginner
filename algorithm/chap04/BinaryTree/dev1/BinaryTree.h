
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
