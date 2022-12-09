#include <catch2/catch_test_macros.hpp>

#include "../src/graph.h"
#include <queue>
#include <map> 
#include <stdexcept>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//test
string emails = "../tests/dummyUsers.txt";
string deps = "../tests/dummyDept.txt";
Graph test = Graph(emails, deps);

TEST_CASE("Simple Graph Constructor Works", "[Constructor]") {
   
    REQUIRE (test.getSize() == 12); 
    REQUIRE(test.printNetwork() == "1 2 3 4 5 6 7 8 9 10 11 12 "); 
    REQUIRE(test.printUserToDepartment(1) == 100); 
    REQUIRE (test.printUserToDepartment(13) == -1); 
    REQUIRE(test.printUserNetwork(1) == "5 4 "); 
    REQUIRE(test.hasEdge(1,5) == true) ; 
    REQUIRE(test.hasEdge(6,1) == false); 
}

TEST_CASE("BFS Connected Components", "[Algorithms][BFS]") {
    REQUIRE(test.BFS(100) == 2);
    REQUIRE(test.BFS(200) == 2);
    REQUIRE(test.BFS(300) == 1);
}

TEST_CASE("BFS Connected Components with Non-Existing Department", "[Algorithms][BFS]") {
    REQUIRE(test.BFS(568) == -1);
    REQUIRE(test.BFS(1) == -1);
}

TEST_CASE("Testing Dijkstra's Algorithm With Existing Path", "[Algorithms][Dijkstras]") {
    // path from 1 to 2
    vector<int> dijkstras_test1 = test.Dijkstras(1,2);
    vector<int> c = {1, 5, 2};
    REQUIRE(dijkstras_test1 == c);
    //path from 7 to 1 
    vector<int> dijkstras_test2 = test.Dijkstras(7,1);
    vector<int> c1 = {7, 6, 3, 2, 5, 1};
    REQUIRE(dijkstras_test2 == c1);
}

TEST_CASE("Testing Dijkstra's Edge Cases : Inputted User not found", "[Algorithms][Dijkstras]") {
    vector<int> dijkstras_test3 = test.Dijkstras(1, 445);
    vector<int> test = {-1};
    REQUIRE(dijkstras_test3 == test);

}

TEST_CASE("Testing Dijkstra's Edge Cases : No Path Exists", "[Algorithms][Dijkstras]") {
    vector<int> dijkstras_test4 = test.Dijkstras(1, 11);
    vector<int> test = {-1};
    REQUIRE(dijkstras_test4 == test);

}

string e_emails = "../tests/eularianUsers.txt";
string e_deps = "../tests/eularianDept.txt";
Graph e_test = Graph(e_emails, e_deps);
TEST_CASE("Eulerian Cycle Test Cases: Cycle Exists", "[Algorithms][Eulerian]") {
    vector<int> e_vect = e_test.findEulerianCycle(1);
    REQUIRE(e_test.isEulerian());
    REQUIRE(e_vect.size() == 8);
    vector<int> answer = {1, 2, 3, 4, 5, 6, 7, 1};
    REQUIRE(e_vect == answer);
}

TEST_CASE("Eulerian Cycle Test Cases: Cycle Does Not Exist", "[Algorithms][Eulerian]") {
    vector<int> e_vect1 = test.findEulerianCycle(1);
    REQUIRE(!test.isEulerian());
    REQUIRE(e_vect1.size() == 1);
    vector<int> answer = {-1};
    REQUIRE(e_vect1 == answer);
}



