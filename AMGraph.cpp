#include <iostream>
#include <vector>

class Graph {
private:
    std::vector<std::vector<bool>> adjMatrix;
    int numVertices;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjMatrix.resize(numVertices, std::vector<bool>(numVertices, false));
    }

    void addEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        adjMatrix[src][dest] = true;
        adjMatrix[dest][src] = true;
    }

    void removeEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        adjMatrix[src][dest] = false;
        adjMatrix[dest][src] = false;
    }

    bool isEdge(int src, int dest) const {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        return adjMatrix[src][dest];
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (int i = 0; i < graph.numVertices; i++) {
            for (int j = 0; j < graph.numVertices; j++) {
                os << graph.adjMatrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};