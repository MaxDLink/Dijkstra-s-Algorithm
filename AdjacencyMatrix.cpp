#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 4; // number of vertices
    vector<vector<int>> adj_matrix(n, vector<int>(n)); // initialize a n x n matrix with zeros
    
    // set the adjacency matrix
    adj_matrix[0][1] = adj_matrix[1][0] = 1;
    adj_matrix[0][2] = adj_matrix[2][0] = 1;
    adj_matrix[1][2] = adj_matrix[2][1] = 1;
    adj_matrix[1][3] = adj_matrix[3][1] = 1;
    adj_matrix[2][3] = adj_matrix[3][2] = 1;
    
    // print the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
