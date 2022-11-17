
INCLUDES=-I src/ -I main/
CXXFLAGS = -std=c++20 -g -O0 -Wall -Wextra -Werror -pedantic $(INCLUDES)
CXX=clang++
main.o: ../main/main.cpp
	$(CXX) $(CXXFLAGS) ../main/main.cpp -o main.o

tests.o : ../tests/tests.cpp
	$(CXX) $(CXXFLAGS) ../tests/tests.cpp -o tests.o