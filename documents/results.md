## Output and Correctness

The output and correctness of each algorithm – You should summarize, visualize, or highlight some part of the full-scale run of each algorithm. Additionally, the report should briefly describe what tests you performed to confirm that each algorithm was working as intended.


Graph Representation
Our Graph takes in a file of emails and departments, where nodes are individuals represented by two int values, their user ID and a department ID. These are then connected together by unweighted edges that are the representation of an email between two users, either in the same or different departments.
In order to test our graph’s construction – we constructed a smaller dataset (./tests/dummyUsers.txt & ./tests/dummyDept.txt) and tested the values created by our constructor. Namely the size, construction, & if edges between users existed or not. We printed out the entire network, as well as a users network to check for correctness in construction.

BFS
The BFS algorithm outputs the number of connected components given a department ID as a parameter. If the department does not exist, -1 is returned. The algorithm traverses through each node and its neighbors only if they are in the specified department. In order to prevent double counting, each vertex is marked as visited the first time it is seen. To test this, we used the dummy network (as explained above), since it was easier to visualize the data.  

Dijkstra's Algorithm 
Our Dijkstra’s algorithm presents the shortest email chain between two users inputted as parameters. If either one of the users does not exist or if there is no path between the users, then the algorithm returns a vector with -1 as the only element inside. To check if the algorithm was working correctly we wrote test cases to account for the edge cases as described above. We also tested Dijkstra’s on a smaller dataset (./tests/dummyUsers.txt & ./tests/dummyDept.txt) and if a path does exist, the algorithm correctly returns the shortest path. When the user runs main, the call to our Dijkstra’s algorithm takes inputs from the user and the runtime of the algorithm varies based on how many verticies are added to the queue. 

Eulerian Cycle
To detect Eulerian cycles in our graph, we implemented Hierholzer’s algorithm and an isEulerian function. Both are a part of the findEulerianCycle function, which returns a vector of the Eulerian path. The Eulerian function returns a boolean indicating whether or not a Eulerian cycle exists at all, before calling the Hierholzer’s function. If the number of odd-degree vertices is zero or two, isEulerian returns true. Otherwise, it returns false. The worst-case running time of isEulerian is O(v), where v is the number of vertices. Hierholzer’s algorithm runs in O(e) time, where e is the number of total edges in the graph, as it functions by continuously marking edges as “traversed” until there are no more to mark. So, our findEulerianCycle function runs in O(v+e) time.

## Answer to Leading Question

The answer to your leading question – You should direct address your proposed leading question. How did you answer this question? What did you discover? If your project was ultimately unsuccessful, give a brief reflection about what worked and what you would do differently as a team.

For reference, our leading question is included below:

### Leading Question 
We will examine a network generated using email data from a large European research institution. We have anonymized information about all incoming and outgoing email between members of the research institution, along with the department IDs of invidual members.
We are interested in seeing how emails demonstrate relationships within an organization and the amount of communication within research institution. This will allow us to analyze the interconnectedness of departments and indivduals, which may be useful in tracking mutually influential interactions within academia. We want to find the shortest email path between two inputted users and the number of connected components within an inputted department to see how centralized department communication is. We also want to identify if the email connections graph can be called Eulerian, as an additional challenge and exercise.

### Answer
