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
    Point(double *_pnt);
    Point(std::vector<double> &_pnt);
    int set(int i, double x_i);
    double read(int i) const;
    const std::vector<double> &read() const;
};

Point::Point(double x, double y) 
{
    coordinate[0] = x;
    coordinate[1] = y;
};

const std::vector<double> &Point::read() const
{
    return (const std::vector<double> &)(coordinate); 
};
#else

//do nothing.

#endif

int main(int argc, char *argv[])
{
    Point a(0, 0);
    std::cout << (a.read())[0] << std::endl;
    return 0;
};

