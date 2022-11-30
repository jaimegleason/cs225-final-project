INCLUDES=-I ../src/graph.h -I ../tests/catch.hpp
CXXFLAGS=-std=c++20 -g -fstandalone-debug -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++

clean:
	rm -f bin/*

main: ../main/main.cpp ../src/graph.cpp
	$(CXX) $(CXXFLAGS) $^ -o main.o

catch: ../tests/catch.cpp ../tests/catch.hpp
	$(CXX) $(CXXFLAGS) $^ -o catch.o

tests: ../tests/tests.cpp ../src/graph.cpp ./catch.o
	$(CXX) $(CXXFLAGS) $^ -o tests.o

# tests: ../tests/catch.cpp ../tests/tests.cpp ../src/graph.cpp
# 	$(CXX) $(CXXFLAGS) $^ -o tests.o


.DEFAULT_GOAL := tests
.PHONY: tests clean main