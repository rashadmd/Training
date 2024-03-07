#include <iostream>
#include <vector>
#include <queue>

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

    bool isConnected() {
        vector<bool> visited(numNodes, false);
        queue<int> q;
        q.push(0); // Start BFS from node 0
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adjacencyList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Check if all nodes are visited
        for (bool v : visited) {
            if (!v) return false; // Graph is not connected
        }
        return true; // Graph is connected
    }
};

int main() {
    // Create a graph
    Graph graph(5); // Let's consider 7 nodes
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4); // Creating another connected component

    // Check if the graph is connected
    if (graph.isConnected())
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
