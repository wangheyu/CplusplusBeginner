/**
 * @file   Point.h
 * @author Wang Heyu <wang@wukong>
 * @date   Sat Aug 10 09:23:08 2019
 * 
 * @brief  A tamplate class design for DIM-dimension points.
 * 
 * 
 */

#ifndef __CRAZYFISH__IntCell__
#define __CRAZYFISH__IntCell__

#include <iostream>
#include <vector>

template <int DIM> class Point;

/** 
 * Reload << operator to output the coordinate of the point.
 * 
 * @param os Standard output stream.
 * @param _pnt The point to output.
 * 
 * @return Standard output stream.
 */
template <int DIM> std::ostream& operator<<(std::ostream &os,
					    const Point<DIM> &_pnt);

/** 
 * Reload + operator, 
 * \f[
 *     (p_1 + p_2)_i = {p_1}_i + {p_2}_i, i = 1, 2, \cdots, DIM. 
 * \f]
 *
 * @param _p1 The first point.
 * @param _p2 The second point.
 * 
 * @return The sum point of the above two.
 */
template <int DIM> Point<DIM> operator+(const Point<DIM> &_p1,
					const Point<DIM> &_p2);

/**
 * A template class design for DIM-dimension points.
 * 
 */
template <int DIM>
class Point
{
private:
    double coordinate[DIM];	/**< Coordinate of the point. */
    
public:
    /** 
     * Default constructor.
     * 
     */
    Point(){};

    /** 
     * Special constructor for 2D.
     * 
     * @param x 
     * @param y 
     */
    Point(double x, double y);

    /** 
     * Special constructor for 3D.
     * 
     * @param x 
     * @param y 
     * @param z 
     */
    Point(double x, double y, double z);

    /** 
     * Copy constructor.
     * 
     * @param _pnt The source point.
     */
    Point(const Point<DIM> &_pnt);

    /** 
     * Read coordinate of the point.
     * 
     * 
     * @return The coordinate in a double array.
     */
    const double *read() const;

    /** 
     * Reload [] operator to get the i-th coordinate of the point. 
     * This is a read-write version.
     * 
     * @param i The i-th component.
     * 
     * @return The i-th coordinate value.
     */
    double &operator[](int i);

    /** 
     * Reload [] operator to get the i-th coordinate of the point. 
     * This is a read-only version.
     *  
     * @param i The i-th component.
     * 
     * @return The i-th coordinate value.
     */
    const double &operator[](int i) const;

    /** 
     * Reload += operator, the rule of plus is same as @ref operator+.
     * 
     * @param _pnt The point will be added.
     * 
     * @return The sum will replace the point in the left.
     */
    Point<DIM> &operator+=(const Point<DIM> &_pnt);

    /** 
     * Reload = operator. 
     * 
     * @param _pnt 
     * 
     * @return 
     */
    Point<DIM> &operator=(const Point<DIM> &_pnt);  

    friend std::ostream& operator<< <> (std::ostream&, const Point<DIM>&);
    friend Point<DIM> operator+ <> (const Point<DIM>&, const Point<DIM>&); 
};
#else

//Do nothing.

#endif

//End of file. 
