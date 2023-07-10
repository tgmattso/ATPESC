#
#  USAGE:
#     make          ... to build the program
#     make test     ... to run the default test case
#

include make.def

EXES= pi$(EXE) jac_solv$(EXE) vadd$(EXE) vadd_heap$(EXE) \
      heat$(EXE) mm_testbed$(EXE)

MM_OBJS  = mm_testbed.$(OBJ) mm_utils.$(OBJ) mm_tst_cases.$(OBJ) \
           mm_ijk.$(OBJ) mm_ijk_par.$(OBJ) mm_gpu.$(OBJ) 

JAC_OBJS  = jac_solv.$(OBJ) mm_utils.$(OBJ)

all: $(EXES)

jac_solv$(EXE): $(JAC_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o jac_solv$(EXE) $(JAC_OBJS) $(LIBS)

pi$(EXE): pi.$(OBJ)
	$(CLINKER) $(OPTFLAGS) -o pi$(EXE) pi.$(OBJ) $(LIBS)

vadd$(EXE): vadd.$(OBJ)
	$(CLINKER) $(OPTFLAGS) -o vadd$(EXE) vadd.$(OBJ) $(LIBS)

vadd_heap$(EXE): vadd_heap.$(OBJ)
	$(CLINKER) $(OPTFLAGS) -o vadd_heap$(EXE) vadd_heap.$(OBJ) $(LIBS)

heat$(EXE): heat.$(OBJ)
	$(CLINKER) $(OPTFLAGS) -o heat$(EXE) heat.$(OBJ) $(LIBS)

mm_testbed$(EXE): $(MM_OBJS) mm_utils.h
	$(CLINKER) $(CFLAGS) -o mm_testbed$(EXE) $(MM_OBJS) $(LIBS)

test: $(EXES)
	for i in $(EXES); do \
            $(PRE)$$i; \
        done

clean:
	$(RM) $(EXES) *.$(OBJ) *.ptx *.cub

jac_solv.$(OBJ) : mm_utils.h

.SUFFIXES:
.SUFFIXES: .c .cpp .$(OBJ)

.c.$(OBJ):
	$(CC) $(CFLAGS) -c $<

.cpp.$(OBJ):
	$(CC) $(CFLAGS) -c $<
