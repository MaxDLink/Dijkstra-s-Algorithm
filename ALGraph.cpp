#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    std::vector<std::list<int>> adjList;
    int numVertices;

public:
    Graph(int numVertices) : numVertices(numVertices) {
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void removeEdge(int src, int dest) {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        adjList[src].remove(dest);
        adjList[dest].remove(src);
    }

    bool isEdge(int src, int dest) const {
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            throw std::out_of_range("Invalid vertex");
        }
        for (int neighbor : adjList[src]) {
            if (neighbor == dest) {
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        for (int i = 0; i < graph.numVertices; i++) {
            os << i << ": ";
            for (int neighbor : graph.adjList[i]) {
                os << neighbor << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

