//main file to call code 
#include "../src/graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    //Test BFS
    string emails = "../tests/dummyUsers.txt";
    string deps = "../tests/dummyDept.txt";
    Graph test = Graph(emails, deps);

    cout<< "simple graph constructor test cases" << endl;
    cout << (test.getSize() == 10) << endl; 
    cout << (test.printNetwork() == "1 2 3 4 5 6 7 8 9 10 ") << endl; 
    cout << (test.printUserToDepartment(1) == 100) << endl; 
    cout << (test.printUserToDepartment(12) == -1) << endl; 
    cout << (test.printUserNetwork(1) == "5 4 ") << endl; 
    cout << (test.hasEdge(1,5) == true) << endl; 
    cout << (test.hasEdge(6,1) == false) << endl; 


    cout << "simple BFS Tests" << endl;
    cout << (test.BFS(100) == 2) << endl;
    cout << (test.BFS(200) == 2) << endl;
    cout << (test.BFS(300) == 1) << endl;
    cout << (test.BFS(568) == -1) << endl;
    //Implementing BFS
    string eu_emails = "../email-data/email-Eu-core.txt";
    string eu_depts = "../email-data/email-Eu-core-department-labels.txt";
    Graph eu_BFS = Graph(eu_emails, eu_depts);
    
    cout << "Email Dataset Output" << endl;
    cout << "Number of Connected Components in Department 1 : " << eu_BFS.BFS(1) << endl;
    cout << "Number of Connected Components in Department 7 : " << eu_BFS.BFS(7) << endl;
    cout << "Number of Connected Components in Department 23 : " << eu_BFS.BFS(23) << endl;
    cout << "Number of Connected Components in Department 4 : " << eu_BFS.BFS(4) << endl;

    cout << "Testing Djikstra's Algorithm With Path That Exists" << endl;
    vector<int> dijkstras_test1 = test.Djisktras(1,2);
    cout << "Path from User 1 to 2 : ";
    for(size_t i = 0; i < dijkstras_test1.size(); i++) {
       cout << dijkstras_test1[i] << " ";
    }
    vector<int> dijkstras_test2 = test.Djisktras(7,1);
    cout << "Path from User 7 to 1 : ";
    for(size_t i = 0; i < dijkstras_test2.size(); i++) {
       cout << dijkstras_test2[i] << " ";
    }
    cout << "Testing Djikstra's Algorithm With UserID not found" << endl;
    vector<int> dijkstras_test3 = test.Djisktras(1, 445);
    //should return -1
    cout << dijkstras_test3[0] << endl;



    return 0;
}