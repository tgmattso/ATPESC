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

EXES=hello pi mandel 

all: $(EXES)

hello: hello.o 
	$(CLINKER) $(OPTFLAGS) -o hello hello.o $(LIBS)

pi: pi.o 
	$(CLINKER) $(OPTFLAGS) -o pi pi.o $(LIBS)

mandel:  mandel.o 
	$(CLINKER) $(OPTFLAGS) -o mandel mandel.o $(LIBS)

test: $(EXES)
	./hello
	./pi
	./mandel

clean:
	rm -rf $(EXES) *.o

.SUFFIXES:
.SUFFIXES: .c .cpp .o

.c.o:
	$(CC) $(CFLAGS) -c $<

.cpp.o:
	$(CC) $(CFLAGS) -c $<

