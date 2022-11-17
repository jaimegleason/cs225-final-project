# # EXE = main
# # TEST = test

# # EXE_OBJ = main.o
# # OBJS = main.o src/graph.o

# # main: ../main/main.cpp ../src/graph.cpp ../src/graph.h
# # 		$(CXX) $(CXXFLAGS) main.cpp

# # include ../template/cs225.mk


EXENAME = main
OBJS = main.o graph.o
OBJS_DIR = .objs


CXX = clang++
LD = clang++

CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

default_target: all
.PHONY : all test clean output_msg

all: $(EXENAME)

$(EXENAME : output_msg $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS)))
		$(LD) $(filter-out $<, $^) $(LDFLAGS) -o $@

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
		$(CXX) $(CXXFLAGS) $< -o $@

main: ../main/main.cpp ../src/graph.cpp ../src/graph.h
		$(CXX) $(CXXFLAGS) main.cpp

graph: ../src/graph.cpp ../src/graph.h
		$(CXX) $(CXXFLAGS) graph.cpp

clean:
		-rm -f *.o .txt $(EXENAME) test