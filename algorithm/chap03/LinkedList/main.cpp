#include <iostream>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    CRAZYFISH::LinkedList<double> A(2.71);
    CRAZYFISH::LinkedList<double> C;
    C.insert(3.14);
    A.printLinkedList();
    C.printLinkedList();
    C.insert(2.71);
    C.del();
    C.insert(1.41);
    C.printLinkedList();
    A.del();
    A.printLinkedList();
    A.del();
    A.printLinkedList();
    C.setCurrent(NULL);
    C.del();
    A.insert(3.14);
    C.printLinkedList();
    C.setValue(A.getValue());
    C.printLinkedList();
    return 0;
};
