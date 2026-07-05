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
CFLAGS	    = $(OPTFLAGS)

EXES= pi mandel mm_testbed pi_mc  linked hist transpose jac_solv

MM_OBJS  = mm_testbed.o mm_utils.o mm_ijk.o mm_tst_cases.o

PMC_OBJS  = pi_mc.o random.o

HIST_OBJS  = hist.o random.o

JAC_SOLV_OBJS  = jac_solv.o mm_utils.o 

all: $(EXES)

mm_testbed: $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed $(MM_OBJS) $(LIBS)

linked: linked.o 
	$(CLINKER) $(OPTFLAGS) -o linked linked.o $(LIBS)

pi: pi.o 
	$(CLINKER) $(OPTFLAGS) -o pi pi.o $(LIBS)

mandel:  mandel.o 
	$(CLINKER) $(OPTFLAGS) -o mandel mandel.o $(LIBS)

pi_mc: $(PMC_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o pi_mc $(PMC_OBJS) $(LIBS)

hist: $(HIST_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o hist $(HIST_OBJS) $(LIBS)

jac_solv: $(JAC_SOLV_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv $(JAC_SOLV_OBJS) $(LIBS)

test: $(EXES)
	./pi
	./pi_mc
	./mandel
	./mm_testbed
	./linked
	./hist
	./jac_solv

clean:
	rm -f $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<
