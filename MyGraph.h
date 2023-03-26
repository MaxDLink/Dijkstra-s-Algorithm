#ifndef MYGRAPH_H
#define MYGRAPH_H


#include <iostream>
#include <unordered_map> //included for private data member adjList
#include <queue>         //included for priorityqueue declared in pair<vector<int>, float> HW2Prog(int s, int t, bool printMST)
#include <limits>        //included for HW2Prog Dijstra's algo
#include <utility>       //included for HW2Prog Dijstra's algo
#include <vector>        //included for HW2Prog Dijstra's algo
#include <algorithm>     //included for HW2Prog reverse path vector 

using namespace std;
//TODO - implement steps in syllabus's algorithm overview
class MyGraph
{       // declaration of class MyGraph
public: // public members accessible outside of MyGraph class
    MyGraph(int n); 

    MyGraph(const MyGraph &g); 

    bool AddEdge(int a, int b, float w); 

    bool vertexExists(int a, int b);   

    void output(ostream &os);

    //TODO - for testing purposes. Check if adjList is filled correctly. 
    void printAdjList(const unordered_map<int, vector<pair<int, float> > >& adjList); 

pair<vector<int>, float> HW2Prog(int s, int t, bool printMST);
    
private: 
    // private members only accessible to MyGraph class
    // define the adjList private data member as an unordered map.
    // This data member maps each vertex to a vector of pairs, where each pair consists of a neighboring vertex & the weight of the edge that connects them
    unordered_map<int, vector<pair<int, float> > > adjList;

    void addVertex(int v); 
}; 

#endif