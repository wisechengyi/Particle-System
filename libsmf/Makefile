######################################################################
# File   : Makefile - automates building of the project.             #
# Author : Tim Sally, adapted by Jason Cho                           #
# Notes  : Run 'make help' for usage.                                #
######################################################################

MAT = ../newmat
LD_LIBRARY_PATH=.:`cd ../libsmf;pwd`
CXX        = g++ 
CXX_FLAGS  = -g -ansi -pedantic -Wall -std=c++0x -fopenmp
LD_FLAGS   = -shared  -lglut -lGLU -L$(MAT) -lnewmat 


# - Files 
SRCS       = $(shell list=`/bin/ls . | grep -e "\.cpp"`; \
                          for i in $$list; do echo $$i; done)
OBJS       = $(SRCS:.cpp=.o)
TARGETS    = libsmf.so

# --- Suffix Rules 

.SUFFIXES: 
.SUFFIXES: .cpp .o

.cpp.o:
	$(CXX) -c -fPIC $(CXX_FLAGS) $< 

# --- Targets
all: newmat $(TARGETS) 

libsmf.so: $(OBJS)
	$(CXX)  -o $@ $^ $(LD_FLAGS)
newmat:
	cd ../newmat && make
clean:
	rm -f $(OBJS) $(TARGETS)
	
