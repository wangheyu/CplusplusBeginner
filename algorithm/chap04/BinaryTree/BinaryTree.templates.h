#include "BinaryTree.h"

namespace CRAZYFISH{
    template <typename TYPE>
    BinaryTree<TYPE>::BinaryTree(TYPE _val)
    {
	__root = new Node;
	__root->data = _val;
	__root->left = __root->right = NULL;
    };

    template <typename TYPE>
    int BinaryTree<TYPE>::clean(Node* &_x)
    {
	if (_x != NULL)
	{
	    clean(_x->left);
	    clean(_x->right);
	    delete _x;
	    _x = NULL;
	}
	return 0;
    };

    template <typename TYPE>
    int BinaryTree<TYPE>::empty()
    {
	clean(__root);
	return 0;
    };

    /// Here has to explicitly claim Node is belong to BinaryTree,
    /// and it is a typename.
    template <typename TYPE>
    typename BinaryTree<TYPE>::Node* &BinaryTree<TYPE>::root()
    {
	return __root;
    };

    template <typename TYPE>
    bool BinaryTree<TYPE>::is_empty()
    {
	return (__root == NULL);
    };

    template <typename TYPE>
    int BinaryTree<TYPE>::inorderTreeWalk(Node *_x)
    {
	if (_x != NULL)
	{
	    inorderTreeWalk(_x->left);
	    std::cout << _x->data << "\t";
	    inorderTreeWalk(_x->right);
	}
    };
}
