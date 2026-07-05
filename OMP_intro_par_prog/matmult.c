/*
**  PROGRAM: Matrix Multiplication test bed
**
**  PURPOSE: This is a simple, self contained matrix multiply
**           program that computes C:  
**
**                C  += A * B
**
**           Static memory allocation is used and everything is contained
**           in this one file to keep things as simple as possible
**
**           We multiply rectangular matrices that I call progression 
**           matrices (since they are constructed through a progression
**           of indices.  The idea is to set elemements of the matrics
**           so they have an analytic solution for testing purposes.
**
**  USAGE:   Set the single variable/macro SIZE. From SIZE we construct
**           rectangular matrices with dimensions as simple multiples of SIZE
**
**  HISTORY: Written by Tim Mattson, July 2025
*/
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define SIZE 100

// Function prototypes and constants for testing (which you can ignore)
#define AVAL  3.0
#define BVAL  5.0
#define TOL  0.001 

void mm_clear(int, int, double (*)[]);
void output_results(int, int, int, double, double*, double*);
void init_progression_matrix(int, int, int, double*, double*, double*); 

int main()
{
//   TYPE A[SIZE][2*SIZE], B[2*SIZE][3*SIZE];
//   TYPE C[SIZE][3*SIZE], Cref[SIZE][3*SIZE]; 
   int Ndim = SIZE, Mdim = 3*SIZE, Pdim=2*SIZE;
   double A[Ndim][Mdim], B[Mdim][Pdim];
   double C[Ndim][Pdim], Cref[Ndim][Pdim]; 
  
   double tmp;
   double start_time, run_time;

   // describe the case you are testing 
   printf("\n==================================================\n");
   printf(" triple loop, ijk case %d %d %d\n", Ndim, Mdim, Pdim);

   // initialize A, B and the correct result (Cref)
   init_progression_matrix (Ndim, Mdim, Pdim, A, B, Cref);

   // Set C to zero
   mm_clear(Ndim, Mdim, C);

   start_time = omp_get_wtime(); 

   //====== This is the multiplication method being tested ======

   for (int i=0; i<Ndim; i++){
     for (int j=0; j<Mdim; j++){
        tmp = 0.0;
	for(int k=0;k<Pdim;k++){
           tmp += A[i][k] * B[k][j];
	}
        C[i][j] = tmp;
     }
   }

   run_time = omp_get_wtime() - start_time;

   // test, evaluate, and output results
   output_results(Ndim, Mdim, Pdim, runtime, C, Cref);
}

//============================================================
// The rest of this file is functions to support this matrix 
// multiplication test bed.  You should be able to ignore them.
//==================================o==========================

//***********************************************************
// Clear (i.e. set to zero) the elements of a matrix
//***********************************************************
void mm_clear(int Ndim, int Mdim, double* C){
   for (int i=0; i<Ndim; i++)
       for (int j=0; j<Mdim; j++)
           *(C+i*Mdim+j) = (double) 0.0;
}

//**************************************************************
//  Generate and print error and timing results to standard out.
//**************************************************************
void output_results(int Ndim, int Mdim, int Pdim, double runtime,
                    double *C, double *Cref){

   //
   // Compare two matrices ... return the sum of the squares 
   // of the differences of the two input matrices.
   //
   double dN, tmp, errsqr, flop;
   errsqr = (double)0.0;
   for (int i=0; i<Ndim; i++){
       for (int j=0; j<Mdim; j++){
           tmp = *(C+i*Mdim+j) - (*(Cref+i*Mdim+j));
           errsqr += tmp * tmp;
       }
   }


   if(errsqr < TOL )
       printf(" Error =  %lf and within expected tolerance\n",errsqr);
   else
       printf(" Matrix Multipication failed: Error = %lf\n",errsqr);

   dN = 2.0 * (double)Ndim * (double)Mdim * (double)Pdim/(1000000.0);
   flop = dN/runtime; 
   printf(" mult A[%d][%d] time B[%d][%d]: time = %f flops=%f \n",
           Ndim,Pdim,Pdim,Mdim,runtime,flop);
}

//**************************************************************
// Gererate Test Matrices: progression matrices.   The A  and B 
// matrices generate finite series that when combined during the 
// multiplication process produces a finite series with
// a mathematically well known, closed form answer which is used
// to set the output Cref matrix we'll compare against later.
//
// since the input and results matrices are not simple 
// constants, this test matrix does a good job of catching 
// errors in matrix multiply functions.
//
// Input matrices
//   A: elements of rows run 1 to Pdim (scaled by Aval)
//   B: elements of cols run from 1 to Pdim (scaled by Bval)
//   B: columns additionally scaled by col number (1 to Pdim)
//
//**************************************************************
void init_progression_matrix(int Ndim,  int Mdim,  int Pdim, 
                  double* A, double* B, double* Cref) {

    int i,j;
    double Cval, Ctmp;

    for(i=0; i<Ndim; i++){
       for(j=0; j<Pdim; j++)
           *(A+i*Pdim+j) = AVAL*(double)(j+1);
    }

    for(i=0; i<Pdim; i++){
       for(j=0; j<Mdim; j++)
           *(B+i*Mdim+j) = (j+1)*BVAL*(double)(i+1);
    }
    
// I looked up sum of k squared for k=1 to P in 
// Gradshteyn and Ryzhik page 1.  I then scaled the C
// matrix by the AVAL and BVAL factors and accounted for
// the column scaling of B (thereby avoiding a constant
// result matrix).

    Ctmp = (double) Pdim;
    Cval = Ctmp * (Ctmp+(double)1.0) * ( (double)2.0 * Ctmp+(double)1.0);
    Cval = Cval*AVAL*BVAL/((double)6.0);

    for(i=0; i<Ndim; i++)
       for(j=0; j<Mdim; j++)
           *(Cref+i*Mdim+j) = Cval*(j+1);
}   

