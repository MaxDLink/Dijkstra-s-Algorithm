#include <iostream> 

class MyGraph{ //declaration of class MyGraph 
    public: //public members accessible outside of MyGraph class 
    

    private: //private members only accessible to MyGraph class 
        MyGraph(int n){//Create a graph with n vertices. The vertices are labelled 1..n 
            
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