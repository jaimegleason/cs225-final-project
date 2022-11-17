// code to represent data as a graph
//graph will have nodes (users), nodes will also have department label associated with it and a vector of edges to represent (communication) 

#pragma once
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <set>

using namespace std;

class Graph {
    public:
        Graph() = default;
        Graph(string& email_file, string& department_file);
        void insertNode(int user, int dep);
        void insertEdge(int user1, int user2);
        
     
        int BFS(int depID);
        vector<int> Djisktras(int user1, int user2);
        bool isEularianCycle(int user);
        

    private:
        // userID to vector of userID
        map<int, vector<int> > network;
        // maps userID to departmentID 
        map<int, int> user_to_department;
        //number of users ids
        size_t size;
};