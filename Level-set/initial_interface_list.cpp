#include <vector>
#include <cmath>
#include "level_set.h"

int initial_interface_list(std::vector<std::vector<double> > &Gamma0,
			   double r,
			   double t0,
			   double t1,
			   int N)
{
    Gamma0.resize(N);
    double h = (t1 - t0) / N;
    for (int i = 0; i < N; i++)
    {
	Gamma0[i].resize(2);
	double ti = t0 + i * h;
	std::vector<double> pnt(2);
	initial_interface_para(pnt, r, ti);
	Gamma0[i][0] = pnt[0];
	Gamma0[i][1] = pnt[1];
    }
    return 0;
};
