######################################################################
# File   : Makefile - automates building of the project.             #
# Author : Tim Sally                                                 #
######################################################################

MAT = ../../newmat
SMF = ../../libsmf

CXX        = g++
CXX_FLAGS  = -g -ansi -pedantic -Wall -Waddress -std=c++0x -fopenmp
LD_FLAGS   = -lglut -lGLU -lGLEW -L$(SMF) -lsmf -L$(MAT) -lnewmat -lpng


# - Files 
SRCS       = $(shell list=`/bin/ls . | grep -e "\.cpp"`; \
                          for i in $$list; do echo $$i; done)
OBJS       = $(SRCS:.cpp=.o)
TARGETS    = pot

.PHONY: $(TARGETS)

# --- Suffix Rules 

.SUFFIXES: 
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) -c $(CXX_FLAGS) $< $(LD_FLAGS)

# --- Targets
all:	preclean newmatlib libsmf $(TARGETS) 

pot: $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(LD_FLAGS)
newmatlib:
	cd ../../newmat && make 
libsmf:
	cd ../../libsmf && make
	export LD_LIBRARY_PATH=.:`cd ../../libsmf;pwd`
clean:
	rm -f $(TARGETS) *.o
	cd ../../libsmf && make clean
	cd ../../newmat && make clean
preclean:
	rm -f *.cpp~
nlib:
	cd ../../libsmf && make clean
	make
