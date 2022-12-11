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
   cout << "" << endl;
   cout << "" << endl;
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
   cout << "" << endl;

   cout << "Eulerian Path Algorithm" << endl;
   cout << "" << endl;
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
   


   
   // Average Shortest Path

   int departmentCheck = 0;
   cout << "Average Shortest Path of a Department";
   cout << "" << endl;
   cout << "" << endl;
   cout << "Enter a department ID from 0 - 41: ";
   cin >> departmentCheck;
   

   vector<int> users;

   for (auto pair : eu.user_to_department) {
      if (pair.second == departmentCheck) {
         users.push_back(pair.first);
      }
   }
   int size = 0;
   int num = 0;
   for (unsigned i = 0; i < users.size(); i++) {
      for (unsigned j = 0; j < users.size(); j++) {
         if (i == j)
            continue;
         vector<int> eu_vect1 = eu.Dijkstras(users[i], users[j]);
         size += eu_vect1.size();
         num++;
         //cout << "\nShortest Path from " << users[i] <<" to " << users[j] << ": ";
         for (size_t i = 0; i < eu_vect1.size(); i++) {
            //cout << eu_vect1[i] << " ";
         }
         //cout << "" << endl;
      }
   } 
   cout << "The Average length of the shortest path in department " << departmentCheck << " is : " << double(size)/num << endl;
   cout << "" << endl;


   int continueCheck = 0;
   cout << "# of connected components in a department ";
   cout << "" << endl;
   cout << "Enter 1 to Continue. Enter 0 to Exit. - ";
   cin >> continueCheck;
   cout << "" << endl;
   cout << "" << endl;


   //Centralization of Each Department (# of connected components in each department)
   if (continueCheck == 1) {
      for (int i = 0; i < 42; i++) {
         cout << "Department: " << i << " # of Connected Components: " << eu.BFS(i) << endl;
         }
   }

   cout << "Re run program to try other numbers!" << endl;

   return 0;
}