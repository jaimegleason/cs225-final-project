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
    cout << (test.getSize() == 10) << endl; 
    cout << (test.printNetwork() == "1 2 3 4 5 6 7 8 9 10 ") << endl; 
    cout << (test.printUserToDepartment(1) == 100) << endl; 
    cout << (test.printUserToDepartment(11) == -1) << endl; 
    cout << (test.printUserNetwork(1) == "5 4 ") << endl; 
    cout << (test.hasEdge(1,5) == true) << endl; 
    cout << (test.hasEdge(6,1) == false) << endl; 


    cout << "simple BFS Tests" << endl;
    cout << (test.BFS(100) == 2) << endl;
    cout << (test.BFS(200) == 2) << endl;
    cout << (test.BFS(300) == 1) << endl;
    cout << (test.BFS(568) == -1) << endl;
    
    return 0;
}