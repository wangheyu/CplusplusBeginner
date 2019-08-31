#ifndef __CRAZYFISH_LEVEL_SET__
#define __CRAZYFISH_LEVEL_SET__

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int initial_interface_para(std::vector<double> &pnt, double r, double t);

int initial_interface_list(std::vector<std::vector<double> > &Gamma0,
			   double r,
			   double t0,
			   double t1,
			   int N);
#endif
