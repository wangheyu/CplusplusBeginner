/**
 * @file   Point.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Aug 10 09:23:08 2019
 * 
 * @brief  A class design for 2D points.
 * 
 * 
 */

#ifndef __CRAZYFISH__IntCell__
#define __CRAZYFISH__IntCell__

#include <iostream>
#include <vector>

template <int DIM> class Point;
template <int DIM> std::ostream& operator<<(std::ostream&, const Point<DIM>&);
template <int DIM> Point<DIM> operator+(const Point<DIM>&, const Point<DIM>&);

template <int DIM>
class Point
{
private:
    double coordinate[DIM];
    
public:
    Point(){};
    Point(double x, double y);
    Point(double x, double y, double z);
    Point(const Point<DIM> &_pnt);  
    const double *read() const;
    double &operator[](int i);
    const double &operator[](int i) const;
    Point<DIM> &operator+=(const Point<DIM> &_pnt);
    Point<DIM> &operator=(const Point<DIM> &_pnt);  

    friend std::ostream& operator<< <> (std::ostream&, const Point<DIM>&);
    friend Point<DIM> operator+ <> (const Point<DIM>&, const Point<DIM>&); 
};

template <int DIM>
std::ostream &operator<<(std::ostream& os, const Point<DIM>& _pnt)
{
    for (int i = 0; i < DIM; i++)
	os << _pnt.coordinate[i] << "\t";
  return os;
};


template <int DIM>
Point<DIM>::Point(double x, double y) 
{
    if (DIM != 2)
    {
	std::cerr << "Dimension error!" << std::endl;
	std::exit(-1);
    }
    coordinate[0] = x;
    coordinate[1] = y;
};

template <int DIM>
Point<DIM>::Point(double x, double y, double z) 
{
    if (DIM != 3)
    {
	std::cerr << "Dimension error!" << std::endl;
	std::exit(-1);
    }
    coordinate[0] = x;
    coordinate[1] = y;
    coordinate[2] = z;
};

template <int DIM>
Point<DIM>::Point(const Point<DIM> &_pnt)
{
    for (int i = 0; i < DIM; i++)
	coordinate[i] = _pnt.coordinate[i];
};


template <int DIM>
const double *Point<DIM>::read() const
{
    return (coordinate); 
};

template <int DIM>
double &Point<DIM>::operator[](int i)
{
    if (i > DIM - 1)
    {
	std::cerr << "Dimension out range!" << std::endl;
	std::exit(-1);
    }
    return coordinate[i];
};

template <int DIM>
const double &Point<DIM>::operator[](int i) const
{
    if (i > DIM - 1)
    {
	std::cerr << "Dimension out range!" << std::endl;
	std::exit(-1);
    }
    return coordinate[i];
};

template <int DIM>
Point<DIM> operator+(const Point<DIM> &_p1, const Point<DIM> &_p2)
{
    // Here we want a default constructor.
    Point<DIM> result;
    for (int i = 0; i < DIM; i++)
	result.coordinate[i] = _p1[i] + _p2[i];
    return result;
};

template <int DIM>
Point<DIM> &Point<DIM>::operator=(const Point<DIM> &_pnt)
{
    for (int i = 0; i < DIM; i++)
	coordinate[i] = _pnt.coordinate[i];
    return *this;
};

template <int DIM>
Point<DIM> &Point<DIM>::operator+=(const Point<DIM> &_pnt)
{
    for (int i = 0; i < DIM; i++)
	coordinate[i] += _pnt.coordinate[i];
    return *this;
};
#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{
    Point<2> a(1, 2);
    const double *A = a.read();
    std::cout << A[0] << ", " << A[1] << std::endl;
    Point<3> b(1, 2, 3);
    A = b.read();
    std::cout << A[0] << ", " << A[1] << ", " << A[2] << std::endl;
    // Convenient! 
    std::cout << a[0] << ", " << a[1] << std::endl;
    Point<3> c(b);
    c = b;
    std::cout << "b + c = " << b + c << std::endl;
    // Error, dimension not match.
//    std::cout << "a + b = " << a + b << std::endl;
    return 0;
};

