#include <vector>
#include <cmath>
#include "level_set.h"

int initial_interface_para(std::vector<double> &pnt, double r, double t)
{
    pnt[0] += r * std::cos(t);
    pnt[1] += r * std::sin(t);
    return 0;
};
