#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 4; // number of vertices
    vector<vector<int> > adj_list(n); // initialize a vector of n empty vectors
    
    // add edges to the adjacency list
    adj_list[0].push_back(1);
    adj_list[1].push_back(0);
    adj_list[0].push_back(2);
    adj_list[2].push_back(0);
    adj_list[1].push_back(2);
    adj_list[2].push_back(1);
    adj_list[1].push_back(3);
    adj_list[3].push_back(1);
    adj_list[2].push_back(3);
    adj_list[3].push_back(2);
    
    // print the adjacency list
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
