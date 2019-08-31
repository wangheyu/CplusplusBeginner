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

class Point
{
private:
    double coordinate[2];
public:    
    Point(double x, double y);
    const double *read() const;  
    double &operator[](int i);     // Reload the [] operatior.
};

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
    return 0;
};

