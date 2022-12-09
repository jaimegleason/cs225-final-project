//main file to call code 
#include "../src/graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
   //test
   string emails = "../tests/dummyUsers.txt";
   string deps = "../tests/dummyDept.txt";
   Graph test = Graph(emails, deps);
   //actual
   string eu_emails = "../email-data/email-Eu-core.txt";
   string eu_depts = "../email-data/email-Eu-core-department-labels.txt";
   Graph eu = Graph(eu_emails, eu_depts);
   cout << "BFS Algorithm" << endl;
   int dep = 0;
   cout << "Enter a department ID from 0 - 41: ";
   cin >> dep;
   cout << "\nNumber of Connected Components in Department " << dep << ": " << eu.BFS(dep) << endl;
   
   cout << "Dijkstra's Algorithm" << endl;
   int user1 = 0;
   int user2 = 0;
   cout << "Enter a User ID from 0 - 1004 for Start : ";
   cin >> user1;
   cout << "\nEnter a User ID from 0 - 1004 for End : ";
   cin >> user2;
   vector<int> eu_vect1 = eu.Dijkstras(user1, user2);
   cout << "\nShortest Path from " << user1 <<" to " << user2 << ": ";
   for(size_t i = 0; i < eu_vect1.size(); i++) {
      cout << eu_vect1[i] << " ";
   }
   cout << "" << endl;

   cout << "Eulerian Path Algorithm" << endl;
   int start = 0;
   cout << "Enter a User ID from 0 - 1004 for Start : ";
   cin >> start;
   cout << "" << endl;
   vector<int> eu_eulerian = eu.findEulerianCycle(start);
   for(size_t i = 0; i < eu_eulerian.size(); i++) {
      if (eu_eulerian[i] == -1) {
         cout << "Eulerian Cycle does not exist" << endl;
         break;
      }
      cout << eu_eulerian[i] << " ";
   }
   cout << "" << endl;
   cout << "Re run program to try other numbers!" << endl;

   return 0;
}