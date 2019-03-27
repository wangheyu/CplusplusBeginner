#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_spmatrix.h>
#include <gsl/gsl_splinalg.h>

int main()
{
    const size_t N = 100;  /* number of grid points */
    const size_t n = N - 2; /* subtract 2 to exclude boundaries */
    const size_t n_dof = n * n;  /* Total degree of freedoms */
    const double h = 1.0 / (N - 1.0);  /* grid spacing */
    gsl_spmatrix *A = gsl_spmatrix_alloc(n_dof, n_dof); /* triplet format */
    gsl_spmatrix *C;  /* compressed format */
    gsl_vector *f = gsl_vector_alloc(n_dof); /* right hand side vector */
    gsl_vector *u = gsl_vector_alloc(n_dof); /* solution vector */
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
	    double xi = (i + 1) * h + 0.1;
	    double yi = (j + 1) * h + 0.1;
	    double fi = -2.0 * M_PI * M_PI * sin(M_PI * xi) * sin(M_PI * yi);
	    int idx = j * n + i;
	    gsl_vector_set(f, idx, fi);
	}

    for (i = 0; i < n; ++i)
    {
	double xi = (i + 1) * h + 0.1;
	double yi = 0 + 0.1;
	double bi =  sin(M_PI * xi) * sin(M_PI * yi);
	int idx = i;
	gsl_vector_set(f, idx, gsl_vector_get(f, idx) - bi / (h * h));
	yi = (n + 1) * h + 0.1;
	double ui =  sin(M_PI * xi) * sin(M_PI * yi);
	idx = (n - 1) * n + i;
	gsl_vector_set(f, idx, gsl_vector_get(f, idx) - ui / (h * h));
    }

    for (j = 0; j < n; ++j)
    {
	double xi = 0 + 0.1;
	double yi = (j + 1) * h + 0.1;
	double li =  sin(M_PI * xi) * sin(M_PI * yi);
	int idx = j * n;
	gsl_vector_set(f, idx, gsl_vector_get(f, idx) - li / (h * h));
	xi = (n + 1) * h + 0.1;
	double ri =  sin(M_PI * xi) * sin(M_PI * yi);
	idx = j * n + n - 1;
	gsl_vector_set(f, idx, gsl_vector_get(f, idx) - ri / (h * h));
    }

    /* convert to compressed column format */
    C = gsl_spmatrix_ccs(A);

    /* now solve the system with the GMRES iterative solver */
    {
	const double tol = 1.0e-15; /* solution relative tolerance */
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
	// for (i = 0; i < n; ++i)
	// 	   for (j = 0; j < n; ++j)
	// {
	// 	   double xi = (i + 1) * h;
	// 	   double yi = (j + 1) * h;
	// 	   int idx = j * n + i;
	// 	   double u_exact= sin(M_PI * xi) * sin(M_PI * yi);
	// 	   double u_gsl = gsl_vector_get(u, idx);
	// 	   printf("%f %.12e %.12e\n", xi, u_gsl, u_exact);
	// }
	// gsl_splinalg_itersolve_free(work);
    }
    gsl_spmatrix_free(A);
    gsl_spmatrix_free(C);
    gsl_vector_free(f);
    gsl_vector_free(u);
    return 0;
};
