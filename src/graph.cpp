#include "graph.h"
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include <set>

using namespace std;
/**
* constructor to build graph from files
* @param email_file txt file with all edges, separated by spaces
* @param department_file txt file with user id to department id, separated by spaces
*/
Graph::Graph(string& email_file, string& department_file) {
    ifstream file(department_file);
    string dep_line;
    if (department_file.is_open()) {
        while(getline(department_file, dep_line)) {
            string delimiter = " ";
            int userid = stoi(dep_line.substr(0, dep_line.find(delimiter)));
            int dep = stoi(dep_line.substr(dep_line.find(delimiter), dep_line.length()));
            insertNode(userid, dep);
        }
    }
    ifstream file(email_file);
    string email_line;
    if (email_file.is_open()) {
        while (getline(email_file, email_line)) {
            string delimiter = " ";
            int user1 = int(email_line.substr(0, email_line.find(delimiter)));
            int user2 = int(email_line.substr(email_line.find(delimiter), email_line.length()));
            insertEdge(user1, user2);
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
    // if not, call insertNode
    vector<int> connections = network[user1];
    // maybe check for multiple instances? 
    connections.push_back(user2);
}

/**
* @return the number of connected components 
* @param depID department ID
* @return number of connected components
*/
int Graph::BFS(int depID) {
    int connected_counter = 0;
    set<int> visited;
    queue<int> q; 
    return 0;
}

/**
* @return a vector of Nodes that gives the path from user 1 to user 2, inclusive of user 2, if no path returns empty vector
* @param user1 user 1
* @param user2 user 2
*/ 
vector<int> Graph::Djisktras(int user1, int user2) {
    return vector<int>();
}

/**
* @return boolean if Eularian Cycle exists
* @param user is start/end point
*/      
bool Graph::isEularianCycle(int user) {
    return true;
}