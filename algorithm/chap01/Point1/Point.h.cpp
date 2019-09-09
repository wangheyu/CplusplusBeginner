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
private:
    double coordinate[2];
public:    
    Point(double x, double y);
    double *read();
};

Point::Point(double x, double y) 
{
    coordinate[0] = x;
    coordinate[1] = y;
};

double *Point::read()
{
    return (coordinate); 
};
#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{
    Point a(1, 2);
    double *A = a.read();
    A[0] = 3;   // Dangous! Unexpected chances to change the private values!
    std::cout << A[0] << ", " << A[1] << std::endl;
    return 0;
};

