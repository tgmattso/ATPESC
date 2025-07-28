#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 100

// Function prototypes and constants for testing (which you can ignore)
#define AVAL  3.0
#define BVAL  5.0
#define TOL  0.001 

void mm_clear(int, int, double (*)[]);

int main()
{
   int Ndim = SIZE, Mdim = 3*SIZE, Pdim=2*SIZE;
   double A[Ndim][Mdim], B[Mdim][Pdim];
   double C[Ndim][Pdim], Cref[Ndim][Pdim]; 
  
   double tmp;
   double start_time, run_time;

   // describe the case you are testing 
   printf("\n==================================================\n");
   printf(" triple loop, ijk case %d %d %d\n", Ndim, Mdim, Pdim);

   // Set C to zero
   mm_clear(Ndim, Mdim, C);

}

//***********************************************************
// Clear (i.e. set to zero) the elements of a matrix
//***********************************************************
void mm_clear(int Ndim, int Mdim, double* C[]){
   for (int i=0; i<Ndim; i++)
       for (int j=0; j<Mdim; j++)
           *(C+i*Mdim+j) = (double) 0.0;
}

