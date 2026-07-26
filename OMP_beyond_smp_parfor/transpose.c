#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
/*

This program will generate a matrix, transpose the matrix
and then test the result for correctness.

Set the matrix order (N) in the code.  

History: Written by Tim Mattson, March 2024.

*/


#define MIN(val1, val2) (((val1)>(val2)) ? (val2):(val1))

void init_arrs(int N, double *A, double *B)
{

// initialize arrays A and B 
   for (int i=0; i<N; i++) { 
     for (int j=0; j<N; j++) { 
          B[i+N*j] = 0.0;
          A[i+N*j] = 5.0*i+(double)j; 
     } 
   } 
}

void trans_test(int N, double *A, double *B)
{

   double start_time, time;

   start_time = omp_get_wtime();
   for (int i=0; i<N; i++) { 
     for (int j=0; j<N; j++) { 
                 B[i+N*j] = A[j+N*i]; 
      } 
   } 
   time = omp_get_wtime() - start_time;

// Test transpose results
   long err = 0;
   for (int i=0; i<N; i++) { 
     for (int j=0; j<N; j++) { 
          if(B[i+N*j] != (5.0*j+(double)i)) err++; 
     } 
   } 
   printf(" Sequential Transpose in %f seconds with %ld errors\n",time,err);
}

int main()
{
   int N = 10000;
   double *A = (double*)malloc(N*N*sizeof(double));
   double *B = (double*)malloc(N*N*sizeof(double));

   init_arrs(N, A, B);
   trans_test(N, A, B);

}
