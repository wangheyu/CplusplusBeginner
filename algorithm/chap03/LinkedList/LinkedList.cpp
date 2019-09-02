#include "LinkedList.templates.h"

namespace CRAZYFISH{

#define TYPE char
    template class LinkedList<TYPE>;
#undef TYPE

#define TYPE int
    template class LinkedList<TYPE>;
#undef TYPE

#define TYPE long
    template class LinkedList<TYPE>;
#undef TYPE

#define TYPE float
    template class LinkedList<TYPE>;
#undef TYPE

#define TYPE double
    template class LinkedList<TYPE>;
#undef TYPE

#define TYPE long double 
    template class LinkedList<TYPE>;
#undef TYPE
}
