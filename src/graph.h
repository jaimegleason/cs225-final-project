// code to represent data as a graph
//graph will have nodes (users), nodes will also have department label associated with it and a vector of edges to represent (communication) 

#pragma once
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

class Graph {
    public:
        Graph() = default;
        Graph(string email_file, string department_file);
        void insertNode(int user, int dep);
        void insertEdge(int user1, int user2);
        int BFS(int depID);
        vector<int> Djisktras(int user1, int user2);
        bool isEularianCycle(int user);
       
       
        //for testing purposes
        string printNetwork();
        int printUserToDepartment(int user);
        string printUserNetwork(int user);
        int getSize();
        bool hasEdge(int user1, int user2); 
        

    private:
        // userID to vector of userID
        map<int, vector<int>> network;
        // maps userID to departmentID 
        map<int, int> user_to_department;
        //number of users ids
        size_t size = 0;
        // department ids
        set<int> departments;
        // helper functions
        void BFShelper(int vertex, set<int>& vertices, set<pair<int, int>>& edges, int depID);

};