/*
**  function: Matrix Multiplication ... three loop, ijk case
**            where ijk defines the order of the loops
**
**  HISTORY: Written by Tim Mattson, July 2012. 
*/
#include "mm_utils.h"

void mm_ijk(int Ndim, int Mdim, int Pdim, TYPE *A, TYPE *B, TYPE *C){
  int i, j, k;
  TYPE tmp;

//  #pragma omp parallel for
  #pragma omp tile sizes(10,10)
  for (i=0; i<Ndim; i++){
     for (j=0; j<Mdim; j++){
        tmp = 0.0;
	for(k=0;k<Pdim;k++){
	   /* C(i,j) = sum(over k) A(i,k) * B(k,j) */
           tmp += *(A+(i*Pdim+k)) *  *(B+(k*Mdim+j));
	}
	*(C+(i*Mdim+j)) += tmp;
     }
  }
}
