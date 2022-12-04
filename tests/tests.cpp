#define CONFIG_CATCH_MAIN
#include "catch.hpp"

#include "../src/graph.h"
#include <queue>
#include <map> 
#include <stdexcept>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void print(string file1, string file2) {
    ifstream file(file1);
    string dep_line;
    if (file.is_open()) {
        while(getline(file, dep_line)) {
            string delimiter = " ";
            string userid = (dep_line.substr(0, dep_line.find(delimiter)));
            string dep = (dep_line.substr(dep_line.find(delimiter), dep_line.length()));
            cout << userid << " " << dep << endl;
        }
    }
    ifstream efile(file2);
    string email_line;
    if (efile.is_open()) {
        while (getline(efile, email_line)) {
            string delimiter = " ";
            string user1 = (email_line.substr(0, email_line.find(delimiter)));
            string user2 = (email_line.substr(email_line.find(delimiter), email_line.length()));
            cout << user1 << " " << user2 << endl;
        }
    }
}



TEST_CASE("test", "") { REQUIRE(true == true);}

TEST_CASE("Simple Graph Constructor Works", "[Constructor]") {
    string emails = "./dummyUsers.txt";
    string deps = "./dummyDept.txt";
    print(deps, emails);
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


