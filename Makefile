EXENAME = proj
# Object Types
OBJS = main.o FlightGraph.o FlightAlgorithms.o

# OBJS_DIR = .objs

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic -Wno-unused-variable -Wno-unused-private-field
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

FlightGraph.o: main.cpp FlightGraph.cpp
	$(CXX) $(CXXFLAGS) main.cpp FlightGraph.cpp

FlightAlgorithms.o: main.cpp FlightAlgorithms.cpp
	$(CXX) $(CXXFLAGS) main.cpp FlightAlgorithms.cpp

test: output_msg catch/catchmain.cpp tests/tests.cpp FlightAlgorithms.cpp FlightGraph.cpp 
	$(LD) catch/catchmain.cpp tests/tests.cpp FlightAlgorithms.cpp FlightGraph.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME) test