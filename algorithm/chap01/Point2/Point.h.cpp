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
    const double *read() const;  // The first const means can not change
                                 // the values pointed by the pointer; while
                                 // second one means never change
                                 // the private values. Here the two const have to
                                 // appear in the same time.
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
#else

//Do nothing.

#endif

int main(int argc, char *argv[])
{
    Point a(1, 2);
    const double *A = a.read();  // There must exists a const before double*.
    // A[0] = 3;   // Now the assign will get an error.
    std::cout << A[0] << ", " << A[1] << std::endl;
    return 0;
};

