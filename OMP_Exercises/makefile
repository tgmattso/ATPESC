#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#

include make.def

EXES=hello$(EXE) pi$(EXE) mandel$(EXE)  \
         mm_testbed$(EXE) jac_solv$(EXE) pi_mc$(EXE)   \
         linked$(EXE) hist$(EXE) 

MM_OBJS  = mm_testbed.$(OBJ) mm_utils.$(OBJ) mm_ijk.$(OBJ) mm_tst_cases.$(OBJ)

JAC_OBJS  = jac_solv.$(OBJ) mm_utils.$(OBJ) 

PMC_OBJS  = pi_mc.$(OBJ) random.$(OBJ)

HIST_OBJS  = hist.$(OBJ) random.$(OBJ)

all: $(EXES)

jac_solv$(EXE): $(JAC_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv$(EXE) $(JAC_OBJS) $(LIBS)

mm_testbed$(EXE): $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed$(EXE) $(MM_OBJS) $(LIBS)

linked$(EXE): linked.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o linked linked.$(OBJ) $(LIBS)

hello$(EXE): hello.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o hello hello.$(OBJ) $(LIBS)

pi$(EXE): pi.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o pi pi.$(OBJ) $(LIBS)

mandel$(EXE):  mandel.$(OBJ) 
	$(CLINKER) $(OPTFLAGS) -o mandel mandel.$(OBJ) $(LIBS)

pi_mc$(EXE): $(PMC_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o pi_mc $(PMC_OBJS) $(LIBS)

hist$(EXE): $(HIST_OBJS) random.h
	$(CLINKER) $(OPTFLAGS) -o hist $(HIST_OBJS) $(LIBS)

test: $(EXES)
	$(PRE)hello$(EXE) 
	$(PRE)pi$(EXE) 
	$(PRE)pi_mc$(EXE) 
	$(PRE)mandel$(EXE) 
	$(PRE)mm_testbed$(EXE) 
	$(PRE)linked$(EXE) 
	$(PRE)hist$(EXE) 
	$(PRE)jac_solv$(EXE) 

clean:
	$(RM) $(EXES) *.$(OBJ)

.SUFFIXES:
.SUFFIXES: .c .cpp .$(OBJ)

.c.$(OBJ):
	$(CC) $(CFLAGS) -c $<

.cpp.$(OBJ):
	$(CC) $(CFLAGS) -c $<
