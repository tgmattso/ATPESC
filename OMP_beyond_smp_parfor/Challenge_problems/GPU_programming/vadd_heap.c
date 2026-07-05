#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 100000
#define TOL  0.0000001
//
//  This is a simple program to add two vectors
//  and verify the results.
//  
//  This version uses malloc to dynamically allocate
//  the arrays (i.e. they reside in the process heap).
//
//  History: Written by Tim Mattson, November 2017
//
int main()
{

    float *a   = (float *) malloc(sizeof(float) * N);
    float *b   = (float *) malloc(sizeof(float) * N);
    float *c   = (float *) malloc(sizeof(float) * N);
    float *res = (float *) malloc(sizeof(float) * N);
    int err=0;

   // fill the arrays
   for (int i=0; i<N; i++){
      a[i] = (float)i;
      b[i] = 2.0*(float)i;
      c[i] = 0.0;
      res[i] = i + 2*i;
   }

   // add two vectors
   for (int i=0; i<N; i++){
      c[i] = a[i] + b[i];
   }

   // test results
   for(int i=0;i<N;i++){
      float val = c[i] - res[i];
      val = val*val;
      if(val>TOL) err++;
   }
   printf(" vectors added with %d errors\n",err);

   free(a);
   free(b);
   free(c);
   free(res);

   return 0;
}
