CC=clang++
CFLAGS=-std=c++20


exec: build/exec


build/exec: ../src/graph.cpp ../src/graph.h
	$(CXX) $(CXXFLAGS) ../src/graph.cpp



clean:
	rm -fr build/* obj/*

# main: main.o Graph.o
# 	$(CC) $(CFLAGS) -o main main.o Graph.o

# main.o: main.cpp Graph.h 
# 	$(CC) $(CFLAGS) -c main.cpp

# Graph.o: Graph.h