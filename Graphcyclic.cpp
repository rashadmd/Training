#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjacencyList;

public:
    Graph(int n) : numNodes(n), adjacencyList(n) {}

    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // For undirected graph
    }

    bool isCyclicUtil(int node, vector<bool>& visited, int parent) {
        visited[node] = true;

        for (int neighbor : adjacencyList[node]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, node))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCyclic() {
        vector<bool> visited(numNodes, false);

        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i]) {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    // Create a graph
    Graph graph(5); // Let's consider 7 nodes
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4); // Creating another connected component

    // Check if the graph is cyclic
    if (graph.isCyclic())
        cout << "The graph is cyclic." << endl;
    else
        cout << "The graph is acyclic." << endl;

    return 0;
}
