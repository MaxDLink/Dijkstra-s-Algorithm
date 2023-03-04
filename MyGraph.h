#include <iostream> 
#include <unordered_map> //included for private data member adjList 
using namespace std; 
class MyGraph{ //declaration of class MyGraph 
    public: //public members accessible outside of MyGraph class 
    

    private: //private members only accessible to MyGraph class 
        //define the adjList private data member as an unordered map. 
        //This data member maps each vertex to a vector of pairs, where each pair consists of a neighboring vertex & the weight of the edge that connects them 
        unordered_map<int, vector<pair<int, float>>> adjList; 
       
        MyGraph(int n){//Create a graph with n vertices. The vertices are labelled 1..n. Can use adjacency list or adjacency matrix. 
            for(int i = 1; i < n; i++) //loop through all your n values 
            {
                addVertex(i); //call the addVertex function 
            }
        }

        void addVertex(int v){//i (the current vertice) is passed into add vertex as V 
            if (adjList.find(v) == adjList.end()){//if the vertex is not in the adjList private data member then add 
                adjList[v] = vector<pair<int, float>>{}; //add the vertex to adjList data member 
            }
        }

        MyGraph(const MyGraph& g){//Construct a new graph that is a copy of g 

        }

        bool addEdge(int a, int b, float w){//Add an edge between vertex a and b, with weight w.If the edge already exists or a vertex is not on the graph, do nothing and return false. Otherwise (addition is successful) return true.  

        }

        void output(ostream& os){//Output the graph to the ostream& specified

        }

        pair<vector<int>, float> HW2Prog(int s, int t, bool printMST){//return the route from s to t with highest capacity The return will be a pair. First item of the pair (vector) denotes the path from s to t. The second item (float) denote the actual capacity of the route

        }


};