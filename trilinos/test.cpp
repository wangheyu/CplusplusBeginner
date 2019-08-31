#include "Amesos.h"
#include "Amesos_BaseSolver.h"

int main()
{

Epetra_LinearProblem *Problem;
Epetra_RowMatrix* A;            // linear system matrix
Epetra_MultiVector* LHS;        // vector that will contain the solution
Epetra_MultiVector* RHS;        // right-hand side

Amesos_BaseSolver * Solver;
Amesos Factory;
char SolverType[] = "Amesos_Klu";
Solver = Factory.Create(SolverType, *Problem);

//char* SolverType = "Amesos_Klu";
//bool IsAvailable = Factory.Query(SolverType);
};
