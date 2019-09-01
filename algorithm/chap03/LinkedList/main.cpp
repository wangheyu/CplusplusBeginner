#include <iostream>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    CRAZYFISH::LinkedList<double> A(2.71);
    CRAZYFISH::LinkedList<double>::Node node(3.14);
    CRAZYFISH::LinkedList<double> B(node);
    CRAZYFISH::LinkedList<double> C;
    C.insert(node);
    C.insert(2.71);
//    A.insert(node);   /// ??? What's wrong?
    CRAZYFISH::LinkedList<double>::Node node1(3.14);
    A.insert(node1);
    A.printLinkedList();
    C.printLinkedList();
    C.del();
    C.insert(1.41);
    C.printLinkedList();
    A.del();
    return 0;
};
