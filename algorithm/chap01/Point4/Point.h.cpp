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
private:
    double coordinate[2];
public:    
    Point(double x, double y);
    const double *read() const;  
    double &operator[](int i);
};



std::ostream &operator<<(std::ostream&, const Point&);
// Reload the << operator for output. Should a friend of Point.


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

// This is a global function and also a friend of Point.
std::ostream &operator<<(std::ostream& os, const Point& _pnt)
{
    for (int i = 0; i < 2; i++)
	os << _pnt.coordinate[i] << "\t";
  return os;
};

#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{

    Point a(1, 2);
    // Convenient! 
    std::cout << a[0] << ", " << a[1] << std::endl;
    // Even can change the values.
    a[1] = 6;
    std::cout << a[0] << ", " << a[1] << std::endl;
    std::cout << a << std::endl;
    return 0;
};

