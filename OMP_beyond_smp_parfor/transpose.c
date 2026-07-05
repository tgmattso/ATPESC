#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN(val1, val2) (((val1)>(val2)) ? (val2):(val1))
#define TILE_SIZE 50

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
//          printf(" B[%d][%d] = %f   %f\n",i,j,B[i+N*j], 5.0*j+(double)i); 
     } 
   } 
   printf(" Sequential Transpose in %f seconds with %ld errors\n",time,err);
}


void trans_tile_test(int N, double *A, double *B)
{

   double start_time, time;

   start_time = omp_get_wtime();
   for (int i=0; i<N; i+=TILE_SIZE) { 
     for (int j=0; j<N; j+=TILE_SIZE) { 
         for (int it=i; it<MIN(N,i+TILE_SIZE); it++){ 
             for (int jt=j; jt<MIN(N,j+TILE_SIZE);jt++){ 
                 B[it+N*jt] = A[jt+N*it]; 
             } 
          } 
      } 
   } 
   time = omp_get_wtime() - start_time;

// Test transpose results
   long err = 0;
   for (int i=0; i<N; i++) { 
     for (int j=0; j<N; j++) { 
          if(B[i+N*j] != (5.0*j+(double)i)) err++; 
//          printf(" B[%d][%d] = %f   %f\n",i,j,B[i+N*j], 5.0*j+(double)i); 
     } 
   } 
   printf(" Seq hand-tiled Transpose in %f seconds with %ld errors\n",time,err);
}

void transomp_test(int N, double *A, double *B)
{
   double start_time, time;

   start_time = omp_get_wtime();

   #pragma omp parallel for
   #pragma omp tile sizes(TILE_SIZE, TILE_SIZE)
   for (int i=0; i<N; i++)  
     for (int j=0; j<N; j++)  
                 B[i+N*j] = A[j+N*i]; 

   time = omp_get_wtime() - start_time;

// Test transpose results
   long err = 0;
   for (int i=0; i<N; i++) { 
     for (int j=0; j<N; j++) { 
          if(B[i+N*j] != (5.0*j+(double)i)) err++; 
     } 
   } 
   printf(" Par OMP-tiled trans in %f seconds with %ld errors\n",time,err);
}

int main()
{
   int N = 10000;
   double *A = (double*)malloc(N*N*sizeof(double));
   double *B = (double*)malloc(N*N*sizeof(double));

   init_arrs(N, A, B);
   trans_test(N, A, B);
   init_arrs(N, A, B);
   trans_tile_test(N, A, B);
   init_arrs(N, A, B);
   transomp_test(N, A, B);

}
