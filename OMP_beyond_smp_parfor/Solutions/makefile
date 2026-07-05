#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#     make clean    ... to remove object and executable files
#

CC          = gcc-15
CLINKER     = $(CC)
OPTFLAGS    = -std=c11 -fopenmp -O3
LIBS        = -lm
CFLAGS      = $(OPTFLAGS)

EXES=hello_par pi_spmd_simple pi_spmd_final \
     pi_loop mandel_par pi_task  \
     mm_testbed jac_solv_parfor jac_solv_par_for \
     racey_tasks jac_solv_simd hist_par\
     linked_notasks linked_tasks

# pi_vec(EXE) removed since it only works with x86 processors

MM_OBJS  = mm_testbed.o mm_utils.o mm_tst_cases.o \
           mm_ijk.o mm_ikj.o mm_ikj_par.o mm_trans.o

JAC_PAR_FOR_OBJS  = jac_solv_par_for.o mm_utils.o

JAC_PARFOR_OBJS  = jac_solv_parfor.o mm_utils.o 

JAC_SIMD_OBJS  = jac_solv_simd.o mm_utils.o 

HIST_OBJS      = hist_par.o random.o

all: $(EXES)

jac_solv_par_for: $(JAC_PAR_FOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_par_for $(JAC_PAR_FOR_OBJS) $(LIBS)

jac_solv_parfor: $(JAC_PARFOR_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_parfor $(JAC_PARFOR_OBJS) $(LIBS)

jac_solv_simd: $(JAC_SIMD_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv_simd $(JAC_SIMD_OBJS) $(LIBS)

mm_testbed: $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed $(MM_OBJS) $(LIBS)

hello_par: hello_par.o 
	$(CLINKER) $(OPTFLAGS) -o hello_par hello_par.o $(LIBS)

pi_spmd_simple: pi_spmd_simple.o 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_simple pi_spmd_simple.o $(LIBS)

pi_spmd_final: pi_spmd_final.o 
	$(CLINKER) $(OPTFLAGS) -o pi_spmd_final pi_spmd_final.o $(LIBS)

pi_loop: pi_loop.o 
	$(CLINKER) $(OPTFLAGS) -o pi_loop pi_loop.o $(LIBS)

mandel_par: mandel_par.o
	$(CLINKER) $(OPTFLAGS) -o mandel_par mandel_par.o $(LIBS)

racey_tasks: racey_tasks.o 
	$(CLINKER) $(OPTFLAGS) -o racey_tasks  racey_tasks.o $(LIBS)

pi_task: pi_task.o 
	$(CLINKER) $(OPTFLAGS) -o pi_task pi_task.o $(LIBS)

pi_vec: pi_vec.o 
	$(CLINKER) $(OPTFLAGS) -o pi_vec pi_vec.o $(LIBS)

hist_par: $(HIST_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o hist_par $(HIST_OBJS) $(LIBS)

linked_notasks: linked_notasks.o 
	$(CLINKER) $(OPTFLAGS) -o linked_notasks linked_notasks.o $(LIBS)

linked_tasks: linked_tasks.o 
	$(CLINKER) $(OPTFLAGS) -o linked_tasks linked_tasks.o $(LIBS)

test: $(EXES)
	./hello_par 
	./pi_spmd_simple 
	./pi_spmd_final 
	./pi_loop 
	./mandel_par 
	./pi_task  
	./mm_testbed 
	./jac_solv_parfor 
	./jac_solv_par_for 
	./racey_tasks 
	./jac_solv_simd 
	./hist_par 
	./linked_notasks 
	./linked_tasks 


# removed since it only works on x86:	$(PRE)pi_vec$(EXE)  

clean:
	rm -f  $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp  .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<
