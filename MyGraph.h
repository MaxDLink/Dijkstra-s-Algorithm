#include <iostream>
#include <unordered_map> //included for private data member adjList
#include <queue>         //included for priorityqueue declared in pair<vector<int>, float> HW2Prog(int s, int t, bool printMST)
#include <limits>        //included for HW2Prog Dijstra's algo
#include <utility>       //included for HW2Prog Dijstra's algo
#include <vector>        //included for HW2Prog Dijstra's algo

using namespace std;
//TODO - implement steps in syllabus's algorithm overview
class MyGraph
{       // declaration of class MyGraph
public: // public members accessible outside of MyGraph class
    MyGraph(int n)
    {                               // Create a graph with n vertices. The vertices are labelled 1..n. Can use adjacency list or adjacency matrix.
        for (int i = 1; i <= n; i++) // loop through all your n values
        {
            addVertex(i); // call the addVertex function
        }
    }

    MyGraph(const MyGraph &g)
    { // Construct a new graph that is a copy of g
        adjList = g.adjList;
    }

    bool AddEdge(int a, int b, float w)
    {
        // Add an edge between vertex a and b, with weight w.
        // If the edge already exists or a vertex is not on the graph, do nothing and return false.
        // Otherwise (addition is successful) return true.

        if (adjList.find(a) == adjList.end() || adjList.find(b) == adjList.end()) // if int a is not found or int b is not found in adjList private data member then
        {
            return false; // return false because either a or b is not on the graph
        }
        //checks for an empty vector before it loops through adjList
        if (adjList[a].empty())
        {
            return false;
        }
        // check if the edge already exists on the graph
        for (const auto &neighbor : adjList[a]) // grab each vertex from the unordered map (adjList[a]) & check its neighbor value
        {
            if (neighbor.first == b)
            {                 // if the neighbor element is equal to b then
                return false; // the edge already exists on the graph
            }
            // TODO - explain how this for loop breaks down the unordered map better
        }

        // if the edge is not on the graph then it must be added to both adjacency lists a and b
        adjList[a].push_back(make_pair(b, w)); // make a pair of vertex b with its associated weight, w
        adjList[b].push_back(make_pair(a, w)); // make a pair of vertex a with its associated weight, w
        return true;
    }

    void output(ostream &os)
    { // Output the graph to the ostream& specified
        for (const auto &[vertex, neighbors] : adjList)
        {                         // go through adjList and grab vertex and neighbors
            os << vertex << ": "; // print vertex
            for (const auto &neighbor : neighbors)
            { // for each vertex, go through neighbors & print neighbor.first & neighbor.second
                os << neighbor.first << "(" << neighbor.second << ") ";
            }
            os << endl; // endl for formatting
        }
    }

    pair<vector<int>, float> HW2Prog(int s, int t, bool printMST)
    {
        //TODO - seg fault in this method 
        // initialize variables
        const int N = adjList.size(); // N is the number of nodes in the graph
        vector<int> parent(N, -1); //vector that holds parent integers 
        vector<float> dist(N, numeric_limits<float>::max()); //vector that holds floats & measures dist? 
        priority_queue<pair<float, int>, vector<pair<float, int> >, greater<pair<float, int> > > pq; //priority Queue that holds pairs 
        vector<vector<float> > capacity(N, vector<float>(N, 0)); // capacity stores the capacities of the edges in the graph

        // initialize capacity of each edge
        for (int u = 0; u < N; u++) //loops through number of Nodes 
        {
            for (auto &v : adjList[u]) //v pulls from adjList at a particular node N 
            {
                capacity[u][v.first] = v.second; //set capacity first position to the vector pair value of adjList 
            }
        }

        // Dijkstra's algorithm to find shortest path
        pq.push(make_pair(0, s)); //push to priority queue 
        dist[s] = 0; //set dist to zero 
        while (!pq.empty()) //loop through all of pq while it is full 
        {
            int u = pq.top().second; //set u to the top value in the pq. Should set to the second vector -- vector pair <float, int> 
            pq.pop(); //pop that value off the priority queue 
            for (auto &v : adjList[u]) //set v to adjList value 
            {
                float alt = dist[u] + v.second; //add dist[u] to v.second for alt 
                if (alt < dist[v.first]) //only if alt is less than dist[v.first]
                {
                    dist[v.first] = alt; //set dist[v.first] to alt 
                    parent[v.first] = u; //set parent[v.first] to u 
                    pq.push(make_pair(dist[v.first], v.first)); //push dist[v.first], v.first to priority queue 
                }
            }
        }

        // construct the path from s to t using the parent map
        vector<int> path; //path vector 
        float maxCapacity = numeric_limits<float>::max(); //create a float that stores the maximum capacity. Just a declaration here.  
        int currentNode = t; //sets currentNode = to t 
        while (currentNode != s) //loops through currentNode while currentNode does not equal the source node 
        {//TODO - these lines cause seg fault?
            path.push_back(currentNode); //pushes currentNode to the path vector 
            cout << "PATH: " << path.at(currentNode); 
            maxCapacity = min(maxCapacity, capacity[parent[currentNode]][currentNode]); //maxCapacity gets filled by putting values in the min function 
            currentNode = parent[currentNode]; //currentNode gets set to a parent integer based on the currentNode position 
        }

        path.push_back(s); //pushes the source node into the path vector 

        // reverse the path to obtain the correct order

        if (!path.empty()) {//checks if path is empty before it reverses the path 
            reverse(path.begin(), path.end());
        }

        // return the path and maximum capacity
        return make_pair(path, maxCapacity);
    }

private: // private members only accessible to MyGraph class
    // define the adjList private data member as an unordered map.
    // This data member maps each vertex to a vector of pairs, where each pair consists of a neighboring vertex & the weight of the edge that connects them
    unordered_map<int, vector<pair<int, float> > > adjList;

    void addVertex(int v)
    { // i (the current vertice) is passed into add vertex as V
        if (adjList.find(v) == adjList.end())
        {                                            // if the vertex is not in the adjList private data member then add
            adjList[v] = vector<pair<int, float> >(); // add the vertex to adjList data member
        }
    }
};