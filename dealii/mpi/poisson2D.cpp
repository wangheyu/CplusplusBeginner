#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <iostream>

#include <lac/sparse_matrix.h>
#include <lac/sparsity_pattern.h>
#include <lac/sparse_ilu.h>
#include <lac/vector.h>
#include <lac/full_matrix.h>
#include <lac/solver_cg.h>
#include <lac/precondition.h>
#include <lac/sparse_mic.h>
#include <lac/sparse_decomposition.h>

#include <deal.II/lac/trilinos_sparse_matrix.h>
#include <deal.II/lac/trilinos_block_sparse_matrix.h>
#include <deal.II/lac/trilinos_vector.h>
#include <deal.II/lac/trilinos_block_vector.h>
#include <deal.II/lac/trilinos_precondition.h>

double real(double x, double y);

double source(double x, double y);

int main(int argc, char* argv[])
{
    dealii::Utilities::MPI::MPI_InitFinalize mpi_initialization (argc, argv, 4);
    double x0 = 0.1, x1 = 1.1, y0 = 0.1, y1 = 1.1; 
    const size_t N = 2000;  /* number of grid points */
    const size_t n = N - 2; /* subtract 2 to exclude boundaries */
    const size_t n_dof = n * n;  /* Total degree of freedoms */
    const double h = (x1 - x0) / (N - 1.0);  /* grid spacing */

    dealii::SparsityPattern sp_matrix(n_dof, 5);
    for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    sp_matrix.add(idx, idx);
	}

    for (int i = 0; i < n - 1; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    sp_matrix.add(idx, idx + 1);
	}

    for (int i = 1; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    sp_matrix.add(idx, idx - 1);
	}

    for (int i = 0; i < n; ++i)
	for (int j = 0; j < n - 1; ++j)
	{
	    int idx = j * n + i;
	    sp_matrix.add(idx, idx + n);
	}

    for (int i = 0; i < n; ++i)
	for (int j = 1; j < n; ++j)
	{
	    int idx = j * n + i;
	    sp_matrix.add(idx, idx - n);
	}

    sp_matrix.compress();
    dealii::SparseMatrix<double> A(sp_matrix);

    for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    A.add(idx, idx, -4.0);
	}

    for (int i = 0; i < n - 1; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    A.add(idx, idx + 1, 1.0);
	}

    for (int i = 1; i < n; ++i)
	for (int j = 0; j < n; ++j)
	{
	    int idx = j * n + i;
	    A.add(idx, idx - 1, 1.0);
	}

    for (int i = 0; i < n; ++i)
	for (int j = 0; j < n - 1; ++j)
	{
	    int idx = j * n + i;
	    A.add(idx, idx + n, 1.0);
	}

    for (int i = 0; i < n; ++i)
	for (int j = 1; j < n; ++j)
	{
	    int idx = j * n + i;
	    A.add(idx, idx - n, 1.0);
	}

    A /= h * h;

    dealii::Vector<double> rhs(n_dof);
    dealii::Vector<double> u(n_dof);

    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    	{
    	    double xi = x0 + (i + 1) * h;
    	    double yi = y0 + (j + 1) * h;
    	    double fi = source(xi, yi);// -2.0 * M_PI * M_PI * sin(M_PI * xi) * sin(M_PI * yi);
    	    int idx = j * n + i;
    	    rhs(idx) = fi;
    	}

    for (int i = 0; i < n; ++i)
    {
    	double xi = x0 + (i + 1) * h;
    	double bi =  sin(M_PI * xi) * sin(M_PI * y0);
    	int idx = i;
    	rhs(idx) -= bi / (h * h);
    	double ui =  sin(M_PI * xi) * sin(M_PI * y1);
    	idx = (n - 1) * n + i;
    	rhs(idx) -= ui / (h * h);
    }

    for (int j = 0; j < n; ++j)
    {
    	double yi = y0 + (j + 1) * h;
    	double li =  sin(M_PI * x0) * sin(M_PI * yi);
    	int idx = j * n;
    	rhs(idx) -= li / (h * h);
    	double ri =  sin(M_PI * x1) * sin(M_PI * yi);
    	idx = j * n + n - 1;
    	rhs(idx) -= ri / (h * h);
    }

    dealii::SparseMIC<double> mic;
    
    dealii::SparseMIC<double>::AdditionalData ad;
    mic.initialize(A, ad);

    dealii::PreconditionSSOR<dealii::SparseMatrix<double> > ssor;
    ssor.initialize (A, 1.99);


    dealii::std_cxx1x::shared_ptr<dealii::TrilinosWrappers::PreconditionAMG> Amg_preconditioner;
    Amg_preconditioner = dealii::std_cxx1x::shared_ptr<dealii::TrilinosWrappers::PreconditionAMG>(new dealii::TrilinosWrappers::PreconditionAMG());

    Amg_preconditioner->initialize(A);
//    solver.solve (stiff_matrix, solution, right_hand_side,
//		  *Amg_preconditioner);	

    
    dealii::SolverControl solver_control (10000, 1e-15, true);
    dealii::SolverCG<dealii::Vector<double> > cg (solver_control);
//    cg.solve (A,  u,  rhs, dealii::PreconditionIdentity());
//    cg.solve (A,  u,  rhs, mic);
//    cg.solve (A,  u,  rhs,  ssor);
    cg.solve (A,  u,  rhs,  *Amg_preconditioner);


    
    /* output solution*/
    double error = 0.0;
    
    for (int i = 0; i < n; ++i)
    {
	for (int j = 0; j < n; ++j)
	{
	    double xi = x0 + (i + 1) * h;
	    double yi = y0 + (j + 1) * h;
	    int idx = j * n + i;
	    double u_exact= real(xi, yi); //sin(M_PI * xi) * sin(M_PI * yi);
	    double u_gsl = u(idx);
	    error += (u_exact - u_gsl) * (u_exact - u_gsl);
	}
    }

    // 	std::cout.setf(std::ios::fixed);
    // 	std::cout << "x = linspace(" << x0 << ", " << x1 << ", " << N << ");" << std::endl;
    // 	std::cout << "y = linspace(" << x0 << ", " << x1 << ", " << N << ");" << std::endl;
    // 	std::cout << "[X, Y] = meshgrid(x, y);" << std::endl;
    // 	std::cout << "A =[" << std::endl;
    // 	std::cout << real(x0, y0) << "\t";
    // 	for (i = 0; i < n; ++i)
    // 	{
    // 	    double xi = x0 + (i + 1) * h;
    // 	    std::cout << real(xi, y0) << "\t";
    // 	}
    // 	std::cout << real(x1, y0) << "\t";
    // 	std::cout << std::endl;
    // 	for (j = 0; j < n; ++j)
    // 	{
    // 	    double yi = y0 + (j + 1) * h;
    // 	    std::cout << real(x0, yi) << "\t";
    // 	    for (i = 0; i < n; ++i)
    // 	    {
    // 		double xi = x0 + (i + 1) * h;
    // 		int idx = j * n + i;
    // 		double u_gsl = u(idx);
    // 		std::cout << u_gsl << "\t"; 
    // 	    }
    // 	    std::cout << real(x1, yi) << "\t";
    // 	    std::cout << std::endl;
    // 	}
    // 	std::cout << real(x0, y1) << "\t";
    // 	for (i = 0; i < n; ++i)
    // 	{
    // 	    double xi = x0 + (i + 1) * h;
    // 	    std::cout << real(xi, y1) << "\t";
    // 	}
    // 	std::cout << real(x1, y1) << "];" << std::endl;
    std::cerr <<  "l2norm of error = " <<  sqrt(error) / n_dof << std::endl;

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


