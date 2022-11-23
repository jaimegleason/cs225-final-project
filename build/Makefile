INCLUDES=-I ../src/graph.h
CXXFLAGS=-std=c++20 -g -fstandalone-debug -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++

clean:
	rm -f bin/*

main: ../main/main.cpp ../src/graph.cpp
	$(CXX) $(CXXFLAGS) $^ -o main.o

tests: ../tests/tests.cpp ../src/graph.cpp 
	$(CXX) $(CXXFLAGS) $^ -o tests.o


.DEFAULT_GOAL := tests
.PHONY: tests clean main