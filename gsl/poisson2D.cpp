#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_splinalg.h>
#include <vector>
#include <iostream>

double real(double x, double y);

double source(double x, double y);

int main()
{
    double x0 = 0.1, x1 = 1.1, y0 = 0.1, y1 = 1.1; 
    const size_t N = 100;  /* number of grid points */
    const size_t n = N - 2; /* subtract 2 to exclude boundaries */
    const size_t n_dof = n * n;  /* Total degree of freedoms */
    const double h = (x1 - x0) / (N - 1.0);  /* grid spacing */
    gsl_spmatrix *A = gsl_spmatrix_alloc(n_dof, n_dof); /* triplet format */
    gsl_spmatrix *C;  /* compressed format */
    gsl_vector *f = gsl_vector_alloc(n_dof); /* right hand side vector */
    gsl_vector *u = gsl_vector_alloc(n_dof); /* solution vector */
    std::vector<double> rhs(n_dof, 0.0);
    size_t i, j;
    

    for (i = 0; i < n; ++i)
	for (j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    gsl_spmatrix_set(A, idx, idx, -4.0);
	}

    for (i = 0; i < n - 1; ++i)
	for (j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    gsl_spmatrix_set(A, idx, idx + 1, 1.0);
	}

    for (i = 1; i < n; ++i)
	for (j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    gsl_spmatrix_set(A, idx, idx - 1, 1.0);
	}

    for (i = 0; i < n; ++i)
	for (j = 0; j < n - 1; ++j)
	{
	    int idx = j * n + i;
	    gsl_spmatrix_set(A, idx, idx + n, 1.0);
	}

    for (i = 0; i < n; ++i)
	for (j = 1; j < n; ++j)
	{
	    int idx = j * n + i;
	    gsl_spmatrix_set(A, idx, idx - n, 1.0);
	}


    /* scale by h^2 */
    gsl_spmatrix_scale(A, 1.0 / (h * h));
    /* construct right hand side vector */
    for (i = 0; i < n; ++i)
	for (j = 0; j < n; ++j)
	{
	    double xi = x0 + (i + 1) * h;
	    double yi = y0 + (j + 1) * h;
	    double fi = source(xi, yi);// -2.0 * M_PI * M_PI * sin(M_PI * xi) * sin(M_PI * yi);
	    int idx = j * n + i;
	    rhs[idx] = fi;
	}

    for (i = 0; i < n; ++i)
    {
	double xi = x0 + (i + 1) * h;
	double bi =  sin(M_PI * xi) * sin(M_PI * y0);
	int idx = i;
	rhs[idx] -= bi / (h * h);
	double ui =  sin(M_PI * xi) * sin(M_PI * y1);
	idx = (n - 1) * n + i;
	rhs[idx] -= ui / (h * h);
    }

    for (j = 0; j < n; ++j)
    {
	double yi = y0 + (j + 1) * h;
	double li =  sin(M_PI * x0) * sin(M_PI * yi);
	int idx = j * n;
	rhs[idx] -= li / (h * h);
	double ri =  sin(M_PI * x1) * sin(M_PI * yi);
	idx = j * n + n - 1;
	rhs[idx] -= ri / (h * h);
    }

    for (i = 0; i < n_dof; ++i)
	gsl_vector_set(f, i, rhs[i]);
    
    /* convert to compressed column format */
    C = gsl_spmatrix_ccs(A);

    /* now solve the system with the GMRES iterative solver */
    {
	const double tol = 1.0e-7; /* solution relative tolerance */
	const size_t max_iter = 1000; /* maximum iterations */
	const gsl_splinalg_itersolve_type *T = gsl_splinalg_itersolve_gmres;
	gsl_splinalg_itersolve *work =   gsl_splinalg_itersolve_alloc(T, n * n, 0);
	size_t iter = 0;
	double residual;
	int status;
	/* initial guess u = 0 */
	gsl_vector_set_zero(u);
	/* solve the system A u = f */
	do
	{
	    status = gsl_splinalg_itersolve_iterate(C, f, tol, u, work);

	    /* print out residual norm ||A*u - f|| */
	    residual = gsl_splinalg_itersolve_normr(work);
	    fprintf(stderr, "iter %zu residual = %.12e\n", iter, residual);
	    if (status == GSL_SUCCESS)
		fprintf(stderr, "Converged\n");
	}
	while (status == GSL_CONTINUE && ++iter < max_iter);
	/* output solution*/
	double error = 0.0;

	for (i = 0; i < n; ++i)
	{
	    for (j = 0; j < n; ++j)
	    {
		double xi = x0 + (i + 1) * h;
		double yi = y0 + (j + 1) * h;
		int idx = j * n + i;
		double u_exact= real(xi, yi); //sin(M_PI * xi) * sin(M_PI * yi);
		double u_gsl = gsl_vector_get(u, idx);
		error += (u_exact - u_gsl) * (u_exact - u_gsl);
	    }
	}

	std::cout.setf(std::ios::fixed);
	std::cout << "x = linspace(" << x0 << ", " << x1 << ", " << N << ");" << std::endl;
	std::cout << "y = linspace(" << x0 << ", " << x1 << ", " << N << ");" << std::endl;
	std::cout << "[X, Y] = meshgrid(x, y);" << std::endl;
	std::cout << "A =[" << std::endl;
	std::cout << real(x0, y0) << "\t";
	for (i = 0; i < n; ++i)
	{
	    double xi = x0 + (i + 1) * h;
	    std::cout << real(xi, y0) << "\t";
	}
	std::cout << real(x1, y0) << "\t";
	std::cout << std::endl;
	for (j = 0; j < n; ++j)
	{
	    double yi = y0 + (j + 1) * h;
	    std::cout << real(x0, yi) << "\t";
	    for (i = 0; i < n; ++i)
	    {
		double xi = x0 + (i + 1) * h;
		int idx = j * n + i;
		double u_gsl = gsl_vector_get(u, idx);
		std::cout << u_gsl << "\t"; 
	    }
	    std::cout << real(x1, yi) << "\t";
	    std::cout << std::endl;
	}
	std::cout << real(x0, y1) << "\t";
	for (i = 0; i < n; ++i)
	{
	    double xi = x0 + (i + 1) * h;
	    std::cout << real(xi, y1) << "\t";
	}
	std::cout << real(x1, y1) << "];" << std::endl;
	std::cerr <<  "l2norm of error = " <<  sqrt(error) / n_dof << std::endl;
	gsl_splinalg_itersolve_free(work);
    }
    gsl_spmatrix_free(A);
    gsl_spmatrix_free(C);
    gsl_vector_free(f);
    gsl_vector_free(u);
    return 0;
};


double real(double x, double y)
{
    return (sin(M_PI * x) * sin(M_PI * y));
};

double source(double x, double y)
{
    return (-2.0 * M_PI * M_PI * real(x, y));
};


