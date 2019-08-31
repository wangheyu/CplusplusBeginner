#include "Point.templates.h"

#define DOW 2
template class Point<DOW>;
template std::ostream& operator<<(std::ostream &os,
				  const Point<DOW> &_pnt);
template Point<DOW> operator+(const Point<DOW> &_p1,
			      const Point<DOW> &_p2);
#undef DOW

#define DOW 3
template class Point<DOW>;
template std::ostream& operator<<(std::ostream &os,
				  const Point<DOW> &_pnt);
template Point<DOW> operator+(const Point<DOW> &_p1,
			      const Point<DOW> &_p2);
#undef DOW
