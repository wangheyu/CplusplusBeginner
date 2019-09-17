/**
 * @file   Point.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Aug 10 09:23:08 2019
 * 
 * @brief  A class design for 2D points.
 * 
 * 
 */

#ifndef __CRAZYFISH__Point__
#define __CRAZYFISH__Point__

#include <iostream>
#include <vector>

class Point
{
    // A friend means has the authority to modify the private values. 
    friend std::ostream &operator<<(std::ostream&, const Point&);
    friend Point operator+(const Point &_p1, const Point &_p2);

private:
    double coordinate[2];
public:
    // A default constructor.
    Point(){};
    Point(double x, double y);
    const double *read() const;  
    double &operator[](int i);
    const double &operator[](int i) const;  // Without this, then the return of
                                            // can not be a rvalue. 
    Point &operator+=(const Point &_pnt); 
};

std::ostream &operator<<(std::ostream&, const Point&);
// Reload the << operator for output. Should a friend of Point.

Point operator+(const Point &_p1, const Point &_p2);

Point::Point(double x, double y) 
{
    coordinate[0] = x;
    coordinate[1] = y;
};

const double *Point::read() const 
{
    return (coordinate); 
};

double &Point::operator[](int i)
{
    return coordinate[i];
};

// A read-only version for [] operator.
const double &Point::operator[](int i) const
{
   return coordinate[i];
};

Point &Point::operator+=(const Point &_pnt)
{
    for (int i = 0; i < 2; i++)
	coordinate[i] += _pnt.coordinate[i];
    // Return itself.
    return *this;
};

std::ostream &operator<<(std::ostream& os, const Point& _pnt)
{
    for (int i = 0; i < 2; i++)
	os << _pnt.coordinate[i] << "\t";
  return os;
};

// A binary operator has to happen memory replication,
// since it produces new entity.
Point operator+(const Point &_p1, const Point &_p2)
{
    // Here we want a default constructor.
    Point result;
    for (int i = 0; i < 2; i++)
	result.coordinate[i] = _p1[i] + _p2[i];
    return result;
};

#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{
    Point a(1, 2);
    Point b(3, 4);
    // Convenient! 
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    // Point c = a + b;
    std::cout << "a + b = " << a + b << std::endl;

    std::cout << "a += b is " << (a += b) << std::endl;
    a += b;
    std::cout << "a += b is " << a << std::endl;
    return 0;
};

