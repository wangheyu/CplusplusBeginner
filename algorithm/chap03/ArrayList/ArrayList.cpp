#include "ArrayList.templates.h"

namespace CRAZYFISH{

#define TYPE char
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE

#define TYPE int
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE

#define TYPE long
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE

#define TYPE float
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE

#define TYPE double
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE

#define TYPE long double 
    template class ArrayList<TYPE>;
    template std::ostream& operator<<(std::ostream &os,
				      const ArrayList<TYPE> &_obj);
#undef TYPE
}
