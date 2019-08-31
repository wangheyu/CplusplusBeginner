/**
 * @file   IntCell.h
 * @author Wang Heyu <wang@wukong>
 * @date   Thu Aug  8 17:01:19 2019
 * 
 * @brief  A class for simulating an integer memory cell.
 * Copy from the text book. 
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
    /**
     * Construct the IntCell.
     * Initial value is 0.
     */
    IntCell()
    {
	storedValue = 0;
    };

    /**
     * Construct the IntCell.
     * Initial value is initialValue.
     */
    IntCell(int initialValue)
    {
	storedValue = initialValue;
    };

    /**
     * Return the stored value.
     */
    int read()
    {
	return storedValue;
    };

    /**
     * Change the stored value to x.
     */
    void write(int x)
    {
	storedValue = x;
    };

private:
    int storedValue;		/**< kernel data. */
};

#else

//do nothing.

#endif


