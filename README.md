# cs225-final-project

## Video Demo + Presentation
https://youtu.be/Xmje5TWrui4

## Organization

build: MakeFiles and object files

documents: contract, proposal, results, and presentation slides

email-data: email-data files

entry: main.cpp to call code

src: graph.h and graph.cpp

tests: tests.cpp, dummy data, and catch2 files to test code


## Running Instructions:

to create the makefiles, run 

```bash
mkdir build
```
in the terminal followed by 

```bash
cd build
```

then to run main, call:

```bash
make 
```
followed by
```bash
./main
```

Then, the program will prompt the user to enter search queries for the algorithms we have written. 

To run tests, call:

```bash
make
```
followed by
```bash
./test
```

These tests are run on our dummy dataset which is smaller and easier to visualize. We run tests to check the constructor, BFS algorithm, Dijkstra's algorithm, and Eulerian cycle algorithm.
