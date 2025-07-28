/*

     a simple program to demo the use of locks

     This creates an array of random numbers and tests the number
     of even and odd values in the set of numbers.  They should be
     roughly equal in an unbiased random number generator.

     written by Tim Mattson, 8/2021

*/
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "random.h"

#define N 10000

int main ()
{
   double x[N],xlow = 0.0, xhi = 100.0;
   int i, ix, even_count = 0, odd_count = 0;
   omp_lock_t odd_lck, even_lck;
 
   omp_init_lock(&odd_lck);
   omp_init_lock(&even_lck);

   seed(xlow, xhi); 
   for(i=0; i<N; i++) x[i] = drandom();

   #pragma omp parallel for private(ix)
   for(i=0; i<N; i++){
     ix = (int) x[i];  //truncate to int

     if(ix%2 == 0) {   // Is even
          omp_set_lock(&even_lck);
             even_count++;
          omp_unset_lock(&even_lck);
     }
     else{             // Is odd
          omp_set_lock(&odd_lck);
             odd_count++;
          omp_unset_lock(&odd_lck);
     }
   }

   printf(" evens = %d and odds = %d \n",even_count, odd_count);
   omp_destroy_lock(&odd_lck);
   omp_destroy_lock(&even_lck);
}

