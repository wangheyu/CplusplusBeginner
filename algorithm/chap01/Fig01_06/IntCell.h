/**
 * @file   IntCell.h
 * @author Wang Heyu <wang@wukong>
 * @date   Fri Aug  9 14:43:26 2019
 * 
 * @brief  A better version of IntCell.
 * 
 * 
 */

#ifndef __CRAZYFISH__IntCell__
#define __CRAZYFISH__IntCell__

#include <iostream>

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
public:
    explicit IntCell(int initialValue = 0)
	: storedValue(initialValue)
    {};

    int read() const
    {
        storedValue = -1;  // error! const!
	return storedValue;
    };
    
    void write(int x)
    {
	  storedValue = x;
    };
    
private:
    int storedValue;
};

#else

//do nothing.

#endif

