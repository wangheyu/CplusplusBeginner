#include "LinkedList.h"

namespace CRAZYFISH{
    template <typename TYPE>
    LinkedList<TYPE>::LinkedList(TYPE _val)
    {
	__head = new Node;
	__head->value = _val;
	__head->next = NULL;
	__current = __head;
	__length = 1;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::printLinkedList() const
    {
	std::cout << "List all elements:" << std::endl;
	Node *p = __head;
	while (p != NULL)
	{
	    std::cout << p->value << "\t";
	    p = p->next;
	}
	std::cout << std::endl;
    };

    template <typename TYPE>
    typename LinkedList<TYPE>::Node* LinkedList<TYPE>::find(TYPE _d) const
    {
	Node *p = __head;
	if (p == NULL)
	    return NULL;
	while (p->value != _d)
	{
	    p = p->next;
	    if (p == NULL)
		return NULL;
	}
	return p;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::insert(TYPE _val)
    {
	Node *p = __current;
	if (p == NULL)
	{
	    __head = new Node;
	    __head->value = _val;
	    __head->next = NULL;
	    __current = __head;
	}
	else
	{
	    Node *q = new Node;
	    q->value = _val;
	    q->next = p->next;
	    p->next = q;
	}
	__length += 1;
	return 0;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::del()
    {
	Node *p = __current;
	if (p == NULL)
	{
	    if (__length != 0)
	    {
		p = __head;
		__head = __head->next;
		delete p;
		__length -= 0;
		__current = __head;
	    }
	}
	else if (p->next == NULL)
	{
	    __head = NULL;   // Delete the last node, it becomes an empty List.
	    __length = 0;
	    __current = __head;
	    delete p;        // Free the memory of the deleted node.
	}
	else
	{
	    Node *q = p->next;   // Have to mark it first.
	    p->next = q->next;   // Or = p->next->next, no difference.
	    delete q;
	    __length -= 1;
	}
	return 0;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::succeed()
    {
	if (__current != NULL)
	    __current = __current->next;
	return 0;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::setCurrent(Node *p)
    {
	__current = p;
	return 0;
    };

    template <typename TYPE>
    typename LinkedList<TYPE>::Node* LinkedList<TYPE>::getCurrent() const
    {
	return __current;
    };
    
    template <typename TYPE>
    typename LinkedList<TYPE>::Node* LinkedList<TYPE>::getHead() const
    {
	return __head;
    };

    template <typename TYPE>
    TYPE LinkedList<TYPE>::getValue() const
    {
	if (__current == NULL)
	    std::cerr << "Current node is Null." << std::endl;
	return __current->value;
    };

    template <typename TYPE>
    int LinkedList<TYPE>::setValue(TYPE _val) 
    {
	if (__current == NULL)
	{
	    std::cerr << "Current node is Null." << std::endl;
	    return -1;
	}
	__current->value = _val;
	return 0;
    };
}
