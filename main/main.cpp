//main file to call code 
#include "../src/graph.h"
#include <iostream>
using namespace std;

int main() {
    //test file read, change one and two to file paths
    //string email_file = "../email-data/email-Eu-core.txt";
    //string department_file = "../email-data/email-Eu-core-department-labels.txt";
    string emails = "../tests/dummyUsers.txt";
    string deps = "../tests/dummyDept.txt";
    Graph test = Graph(emails, deps);
    
    cout<< "simple graph constructor test cases" << endl;
    cout << (test.getSize() == 4) << endl; // true
    cout << (test.printNetwork() == "1 2 3 4 ") << endl; // true
    cout << (test.printUserToDepartment(1) == 1) << endl; //true
    cout << (test.printUserToDepartment(5) == -1) << endl; //true
    cout << (test.printUserNetwork(1) == "4 2 ") << endl; //true
    cout << (test.hasEdge(1,2) == true) << endl; //true
    cout << (test.hasEdge(2,1) == false) << endl; // true


    cout << "simple BFS Tests" << endl;
    cout << (test.BFS(1) == 1) << endl;
    cout << (test.BFS(2) == 1) << endl;
    cout << (test.BFS(3) == 1) << endl;
    
    return 0;
}