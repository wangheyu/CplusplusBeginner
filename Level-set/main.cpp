#include "level_set.h"

inline int l2g(int i, int j, int N)
{
    return j * N + i;
};

inline int g2i(int idx, int N)
{
    return idx % N;
};

inline int g2j(int idx, int N)
{
    return idx / N;
};

inline double distant(const std::vector<double> &pn0,
		      const std::vector<double> &pn1)
{
    return std::sqrt((pn0[0] - pn1[0]) * (pn0[0] - pn1[0])
		     + (pn0[1] - pn1[1]) * (pn0[1] - pn1[1]));
};

inline bool clockwise(const std::vector<double> &pn0,
		      const std::vector<double> &pn1,
		      const std::vector<double> &pn2)
{
    double det = (pn1[0] - pn0[0]) * (pn2[1] - pn0[1]);
    det -= (pn1[1] - pn0[1]) * (pn2[0] - pn0[0]);
    if (det > 0.0)
	return false;
    else
	return true;
};

inline double distant2l(const std::vector<double> &pn0,
			const std::vector<double> &pn1,
			const std::vector<double> &pn2)
{

};
			


/* test distant
int main (int argc, char *argv[])
{
    double p0[2] = {0.0, 0.0};
    double p1[2] = {0.0, 1.0};
    double p2[2] = {1.0, 1.0};
    std::vector<double> pnt0(2), pnt1(2), pnt2(2);
    pnt0[0] = p0[0]; 
    pnt0[1] = p0[1]; 
    pnt1[0] = p1[0]; 
    pnt1[1] = p1[1]; 
    pnt2[0] = p2[0]; 
    pnt2[1] = p2[1];
    std::cout << "distant between " << pnt0[0] << ", " << pnt0[1];
    std::cout << " and " << pnt1[0] << ", " << pnt1[1] << " is ";
    std::cout << distant(pnt0, pnt1) << std::endl;
    return 0;
};
 test end */

 /* test clockwise 
int main (int argc, char *argv[])
{
    double p0[2] = {0.0, 0.0};
    double p1[2] = {1.0e-15, 0.0};
    double p2[2] = {0.0, -1.0e-15};
    std::vector<double> pnt0(2), pnt1(2), pnt2(2);
    pnt0[0] = p0[0]; 
    pnt0[1] = p0[1]; 
    pnt1[0] = p1[0]; 
    pnt1[1] = p1[1]; 
    pnt2[0] = p2[0]; 
    pnt2[1] = p2[1];
    if (clockwise(pnt0, pnt1, pnt2))
	std::cout << "clockwise." << std::endl;
    else
	std::cout << "anti-clockwise " << std::endl;
    return 0;
};
 test end */ 

 /* main */
int main (int argc, char *argv[])
{
    double x0 = -1.0;
    double x1 = 1.0;
    double y0 = -1.0;
    double y1 = 1.0;
    int N = 11;
    double h = (x1 - x0) / (N - 1);
    int n_dof = N * N;
    std::vector<double> Phi(n_dof, 1.0);
    int T = 101;
    std::vector<std::vector<double> > Gamma0;
    double r = 0.25;
    double t = 2.0 * M_PI;
    initial_interface_list(Gamma0, r, 0.0, t, T);
    for (int i = 0; i < T; i++)
    {
	std::vector<double> g0(2), g1(2), p0(2);
	g0[0] = Gamma0[i][0];
	g0[1] = Gamma0[i][1];
	if (i < T - 1)
	{
	    g1[0] = Gamma0[i + 1][0];
	    g1[1] = Gamma0[i + 1][1];
	}
	else
	{
	    g1[0] = Gamma0[0][0];
	    g1[1] = Gamma0[0][1];
	}
	int ix = int((Gamma0[i][0] - x0) / h);
	int jy = int((Gamma0[i][1] - y0) / h);
	int di[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
	for (int k = 0; k < 4; k++)
	{
	    int idx = l2g(ix + di[k][0], jy + di[k][1], N);
	    p0[0] = x0 + (ix + di[k][0]) * h;
	    p0[1] = y0 + (jy + di[k][1]) * h;
	    double dis = distant(g0, p0);
	    if (dis < std::fabs(Phi[idx]))
	    {
		if (clockwise(g0, g1, p0))
		    Phi[idx] = dis;
		else
		    Phi[idx] = -dis;
	    }

	    double A = g0[1] - g1[1];
	    double B = g1[0] - g0[0];
	    double C = g0[0] * g1[1] - g1[0] * g0[1];
	    // double dis = A * p0[0] + B * p0[1] + C;
	    // dis += g0[0] * g1[1] - g1[0] * g0[1];
	    // dis /= std::sqrt(A * A + B * B);
	    // dis = std::fabs(dis);
	}
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(20);
    std::cout << "x = [" << std::endl;
    for (int i = 0; i < N; i++)
	std::cout << x0 + i * h << "\t";
    std::cout << "];";
    std::cout << "y = [" << std::endl;
    for (int i = 0; i < N; i++)
	std::cout << y0 + i * h << "\t";
    std::cout << "];";
    std::cout << "[X, Y] = meshgrid(x, y);" << std::endl;
    std::cout << "Phi =[" << std::endl;
    for (int j = 0; j < N; j++)
    {
	for (int i = 0; i < N; i++)
	    std::cout << Phi[l2g(i, j, N)] << "\t";
	std::cout << std::endl;
    }
    std::cout << "];" << std::endl;
    std::cout << "surf(X, Y, Phi);" << std::endl;
    std::cout << "axis equal;" << std::endl;
    return 0;
};

/* main end */
