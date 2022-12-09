#include "graph.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <set>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;
/**
* constructor to build graph from files
* @param email_file txt file with all edges, separated by spaces
* @param department_file txt file with user id to department id, separated by spaces
*/
Graph::Graph(string email_file, string department_file) {
    ifstream file(department_file);
    string dep_line;
    if (file.is_open()) {
        while(getline(file, dep_line)) {
            string delimiter = " ";
            int userid = stoi(dep_line.substr(0, dep_line.find(delimiter)));
            int dep = stoi(dep_line.substr(dep_line.find(delimiter), dep_line.length()));
            insertNode(userid, dep);
            departments.insert(dep);
            users.insert(userid);
        }
    }
    ifstream efile(email_file);
    string email_line;
    if (efile.is_open()) {
        while (getline(efile, email_line)) {
            string delimiter = " ";
            int user1 = stoi(email_line.substr(0, email_line.find(delimiter)));
            int user2 = stoi(email_line.substr(email_line.find(delimiter), email_line.length()));
            insertEdge(user1, user2);
            insertEdge(user2, user1);
        }
    }
}

/**
* inserts Node into graph with empty vector
* @param user userID as int
* @param dep department as int
*/
void Graph::insertNode(int user, int dep) {
    vector<int> v;
    user_to_department.insert({user, dep});
    network.insert({user, v});
    size++;
}

/**
* inserts Edge into graph
* @param user1 user1 as an int
* @param user2 user2 as an int
*/
void Graph::insertEdge(int user1, int user2) {
    // check if nodes exist
    if (network.find(user1) == network.end()) {
        return;
    }
    vector<int>& connections = network[user1];
    // maybe check for multiple instances? 
    connections.push_back(user2);
}

/**
* BFS traversal, will count number of connected components based on department ID
* @param depID department ID
* @return number of connected components, -1 if department doesn't exist
*/
int Graph::BFS(int depID) {
    if (departments.find(depID) == departments.end()) {
        return -1;
    }
    int connected_counter = 0;
    set<int> vertices;
    set<pair<int, int>> edges;
    for (auto& pair : user_to_department) {
        if (vertices.find(pair.first) == vertices.end() && pair.second == depID) {
            BFShelper(pair.first, vertices, edges, depID);
            connected_counter++;
        }
    }
    return connected_counter;
}

void Graph::BFShelper(int vertex, set<int>& vertices, set<pair<int, int>>& edges, int depID) {
    std::queue<int> q;
    vertices.insert(vertex);
    q.push(vertex);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        vector<int> neighbors = network.at(v);
        for (int neighbor : neighbors) {
            if (vertices.find(neighbor) == vertices.end() && user_to_department.at(neighbor) == depID) {
                if (v < neighbor) {
                    edges.insert({v,neighbor});
                } else {
                    edges.insert({neighbor, v});
                }
                vertices.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
} 


/**
* @return a vector of Nodes that gives the path from user 1 to user 2, inclusive of user 2, if no path returns empty vector
* @param user1 user 1
* @param user2 user 2
*/ 
vector<int> Graph::Dijkstras(int user1, int user2) {
    //check to make sure user1 and user 2 are in the dataset
    std::vector<int> to_return;
    if (users.find(user1) == users.end() || users.find(user2) == users.end()) {
       to_return.push_back(-1);
       return to_return;
    }
    
    std::vector<int> distances;
    for(size_t i = 0; i < size; i++) {
        distances.push_back(::numeric_limits<int>::max());
    }
    std::map<int, int> previous;
    std::queue<int> q;
    std::set<int> visited;
    for (auto& pair : user_to_department) {
        previous[pair.first] = -1;
    }
    distances[user1] = 0;
    q.push(user1);
    while (!q.empty() && q.front() != user2) {
        /*
        if(q.empty()) {
            return -1; 
        }
        */
        int curr = q.front();
        q.pop();
        for (int neighbor: network.at(curr)) {
            if (visited.find(neighbor) == visited.end()) {
                if (1+distances[curr] < distances[neighbor]) {
                    distances[neighbor] = 1 + distances[curr];
                    previous[neighbor] = curr;
                }
                q.push(neighbor);
            }
        }
        visited.insert(curr);
    }
    if(q.empty()) {
        to_return.push_back(-1); 
        return to_return;
    }
    // *determine what to do if user2 is not found*
    int position = user2;
    while (position != user1) {
        to_return.push_back(position);
        position = previous[position];
    }
    to_return.push_back(user1);
    std::reverse(to_return.begin(), to_return.end());
    
    return to_return;
}


/*
1. Start at an arbitrary vertex
2. Follow the outgoing edges of the start vertex,
    traverse edge if not already done
3. Repeat until at a vertex with no untraversed edges
4. Add stuck-vertex to stack
5. Backtrack to previous vertex
6. If edges to traverse, go to step 2
7. If no edges to traverse, stack holds complete Eulerian cycle
    else, go to step 5
*/
/**
* @return true if Eularian Cycle exists, else return false
*/     
bool Graph::isEulerian() {
    int oddVertices = 0;
    for (auto& pair : network) {
        if (pair.second.size() == 0) { return false; }
        if (pair.second.size() % 2 != 0) {
            ++oddVertices;
            if (oddVertices > 2) { return false; }
        }
    }
    return oddVertices == 2 || oddVertices == 0;
}

std::vector<int> Graph::findEulerianCycle(int start) {
    std::vector<int> cycle;
    if (users.find(start) == users.end()) { 
        cycle.push_back(-1);
        return cycle; 
    }
    if (isEulerian()) {
        map<int, vector<int>> dummy_network = network;
        hierholzerHelper(start, cycle, dummy_network);
    }
    std::reverse(cycle.begin(), cycle.end());
    
    if (cycle.empty()) {
        cycle.push_back(-1);
    }
    return cycle;
}

void Graph::hierholzerHelper(int src, std::vector<int>& cycle, map<int, vector<int>>& dummy_network) {
    while (!dummy_network.at(src).empty()) {
        int dest = dummy_network.at(src).front();
        dummy_network.at(src).erase(dummy_network.at(src).begin());
        for (size_t i = 0; i < dummy_network.at(dest).size(); ++i) {
            if (dummy_network.at(dest).at(i) == src) {
                dummy_network.at(dest).erase(dummy_network.at(dest).begin() + i);
                break;
            }
        }
        hierholzerHelper(dest, cycle, dummy_network);
    }
    cycle.push_back(src);
    // cycle.insert(cycle.begin(), src);
}

//for testing
string Graph::printNetwork() {
    string toReturn = "";
    for(map<int, vector<int>>::iterator it=network.begin(); it!=network.end(); ++it) {
        toReturn += to_string(it->first) + " ";

    }
    return toReturn;
}
//for testing
 int Graph::printUserToDepartment(int user) {
    std::map<int,int>::iterator it;

    it = user_to_department.find(user);
    if(it != user_to_department.end()) {
        return user_to_department.at(user);
    }
    return -1;

 }
 //for testing
 string Graph::printUserNetwork(int user) {
    string to_return = "";
    std::map<int,vector<int>>::iterator it;

    it = network.find(user);
    if(it != network.end()) {
        for(int n : network.at(user)) {
            to_return += to_string(n) + " ";
        }
        return to_return;
    }
    return "userID does not exist";

 }
//for testing
int Graph::getSize(){
    return size;
}
bool Graph::hasEdge(int user1, int user2) {
    std::map<int,vector<int>>::iterator it;

    it = network.find(user1);
    if (it != network.end()) {
       vector<int> neighbors = network.at(user1);
       for(size_t i = 0; i< neighbors.size(); i++) {
            if (user2 == neighbors[i]) {
                return true;
            }
       }
    }
    return false;
}
