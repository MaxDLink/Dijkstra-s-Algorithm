#include <iostream>
#include <unordered_map> //included for private data member adjList
#include <queue>         //included for priorityqueue declared in pair<vector<int>, float> HW2Prog(int s, int t, bool printMST)
#include <limits>        //included for HW2Prog Dijstra's algo
#include <utility>       //included for HW2Prog Dijstra's algo
#include <vector>        //included for HW2Prog Dijstra's algo

using namespace std;
class MyGraph
{       // declaration of class MyGraph
public: // public members accessible outside of MyGraph class
    MyGraph(int n)
    {                               // Create a graph with n vertices. The vertices are labelled 1..n. Can use adjacency list or adjacency matrix.
        for (int i = 1; i < n; i++) // loop through all your n values
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
        // initialize variables
        const int N = adjList.size(); // N is the number of nodes in the graph
        vector<int> parent(N, -1);
        vector<float> dist(N, numeric_limits<float>::max());
        priority_queue<pair<float, int>, vector<pair<float, int> >, greater<pair<float, int> > > pq;
        vector<vector<float> > capacity(N, vector<float>(N, 0)); // capacity stores the capacities of the edges in the graph

        // initialize capacity of each edge
        for (int u = 0; u < N; u++)
        {
            for (auto &v : adjList[u])
            {
                capacity[u][v.first] = v.second;
            }
        }

        // Dijkstra's algorithm to find shortest path
        pq.push(make_pair(0, s));
        dist[s] = 0;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto &v : adjList[u])
            {
                float alt = dist[u] + v.second;
                if (alt < dist[v.first])
                {
                    dist[v.first] = alt;
                    parent[v.first] = u;
                    pq.push(make_pair(dist[v.first], v.first));
                }
            }
        }

        // construct the path from s to t using the parent map
        vector<int> path;
        float maxCapacity = numeric_limits<float>::max();
        int currentNode = t;
        while (currentNode != s)
        {
            path.push_back(currentNode);
            maxCapacity = min(maxCapacity, capacity[parent[currentNode]][currentNode]); // <-- min is defined in <algorithm>
            currentNode = parent[currentNode];
        }

        path.push_back(s);

        // reverse the path to obtain the correct order

        if (!path.empty()) {//checks if path is empty before it reverses the path 
            reverse(path.begin(), path.end());
        }
        //reverse(path.begin(), path.end());

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