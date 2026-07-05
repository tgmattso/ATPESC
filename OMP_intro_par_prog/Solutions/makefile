#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#     make clean    ... remove object files and executables
#

CC          = gcc-15
CLINKER     = $(CC)
OPTFLAGS    = -std=c11 -fopenmp -O3 
LIBS        = -lm
CFLAGS	    = $(OPTFLAGS)

EXES=hello_par pi_spmd_sumarray pi_spmd_crit pi_loop mandel_par 

all: $(EXES)

hello_par: hello_par.o 
	$(CLINKER) $(OPTFLAGS) -o hello_par hello_par.o $(LIBS)

pi_spmd_sumarray: pi_spmd_sumarray.o 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_sumarray pi_spmd_sumarray.o $(LIBS)

pi_spmd_crit: pi_spmd_crit.o 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_crit pi_spmd_crit.o $(LIBS)

pi_loop: pi_loop.o 
	$(CLINKER) $(OPTFLAGS) -o pi_loop pi_loop.o $(LIBS)

mandel_par: mandel_par.o 
	$(CLINKER) $(OPTFLAGS) -o mandel_par mandel_par.o $(LIBS)

test: $(EXES)
	./hello_par
	./pi_spmd_sumarray
	./pi_spmd_crit
	./pi_loop
	./mandel_par

clean:
	rm -f $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp  .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<
