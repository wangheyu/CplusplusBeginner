/**
 * @file   main.cpp
 * @author Wang Heyu <wang@wukong>
 * @date   Thu Aug  8 17:17:14 2019
 * 
 * @brief  To test IntCell class.
 * 
 * 
 */

#include "IntCell.h"

int main()
{
    IntCell m;
    // IntCell m = -1;  // default initialization for one-parameter constructiors.
                        // sometimes such behind-the-scenes operations
                        // should be avoid. 
    m.write(5);
    std::cout << "Cell contents: " << m.read() << std::endl;

    return 0;
};
