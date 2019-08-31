/**
 * @file   IntCell.cpp
 * @author Wang Heyu <wang@wukong>
 * @date   Fri Aug  9 14:43:26 2019
 * 
 * @brief  Implementation of IntCell.
 * 
 * 
 */

#include "IntCell.h"

int IntCell::read() const
{
    return storedValue;
};
    
void IntCell::write(int x)
{
    storedValue = x;
};
    
