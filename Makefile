CXXFLAGS = -Wall -std=c++0x -pedantic -g 
LIBS	= 
# add more executables in PROGS if you need so - all should be main-XXX
PROGS	= main-fraction main-sample main-samplet
OBJECTS	= main-fraction.o main-sample.o main-samplet.o
SHELL	= /bin/sh

all: $(PROGS)

test:	$(PROGS:%=%.tst)

main-%.tst:	cwk.cc main-% test-%.txt
	./main-$* < test-$*.txt 2>&1 > test-$*.out
	touch main-$*.tst

clean:
	-/bin/rm -f $(PROGS) *.o Makefile.bak *.out *.tst
	-/bin/rm -rf *.dSYM

Makefile:
	./makemake

depend:
	./makedepend $(CXXFLAGS) *.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

