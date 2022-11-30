#define CONFIG_CATCH_MAIN
#include "catch.hpp"

#include "../src/graph.h"
#include <queue>
#include <map> 
#include <stdexcept>

#include <iostream>
#include <vector>
#include <string>
using namespace std;



TEST_CASE("test", "") { REQUIRE(true == true);}

TEST_CASE("Simple Graph Constructor Works", "[Constructor]") {
    string emails = "./dummyUsers.txt";
    string deps = "./dummyDept.txt";
    Graph test = Graph("./dummyUsers.txt", "./dummyDept.txt");
    REQUIRE(true == true);
    cout << "Screaming into the void " << test.getSize() << endl;
    REQUIRE(test.getSize() == 10);
    // REQUIRE(test.printNetwork() == "1 2 3 4 5 6 7 8 9 10 ");
    // REQUIRE(test.printUserToDepartment(1) == 100);
    // REQUIRE(test.printUserToDepartment(11) == -1);
    // REQUIRE(test.printUserNetwork(1) == "5 4 ");
    // REQUIRE(test.hasEdge(1,5) == true);
    // REQUIRE(test.hasEdge(6,1) == false);
    
}

TEST_CASE("BFS Connected Components", "[Algorithms][BFS]") {
    string emails = "./dummyUsers.txt";
    string deps = "./dummyDept.txt";
    Graph test = Graph(emails, deps);
    // cout << test.BFS(100) << endl;
    
    REQUIRE(test.BFS(100) == 2);
    REQUIRE(test.BFS(200) == 2);
    REQUIRE(test.BFS(300) == 1);
    REQUIRE(test.BFS(568) == -1);

}


