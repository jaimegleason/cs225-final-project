//not sure if this path is correct;
#include <catch2/catch_test_macros.hpp>
#include "../src/graph.h"
#include <queue>
#include <map>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string emails = "./dummyUsers.txt";
string deps = "./dummyDept.txt";
Graph test = Graph(emails, deps);

//Dummy Users
// 1 4
// 2 3
// 3 2
// 1 2
// 4 3

//Dummy Dept
// 1 1
// 2 2
// 3 3
// 4 1 
TEST_CASE("Graph Constructor Works", "[Constructor]") {

    REQUIRE(test.getSize() == 4);
    REQUIRE(test.printNetwork() == "1 2 3 4 ");
    REQUIRE(test.printUserToDepartment(1) == 1);
    REQUIRE(test.printUserToDepartment(5) == -1);
    REQUIRE(test.printUserNetwork(1) == "4 2 ");
    REQUIRE(test.hasEdge(1,2) == true);
    REQUIRE(test.hasEdge(2,1) == false);
    
}

TEST_CASE("BFS Connected Components", "[Algorithms][BFS]") {
    
    REQUIRE(test.BFS(1) == 1);
    REQUIRE(test.BFS(2) == 1);
    REQUIRE(test.BFS(3) == 1);

}
