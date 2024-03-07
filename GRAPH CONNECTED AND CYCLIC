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

    pair<bool, bool> isConnectedAndCyclic() {
        vector<bool> visited(numNodes, false);
        vector<int> parent(numNodes, -1); // Store parent of each node
        queue<int> q;

        int components = 0; // Number of connected components
        bool cyclic = false;

        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i]) {
                ++components;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    visited[node] = true;
                    for (int neighbor : adjacencyList[node]) {
                        if (!visited[neighbor]) {
                            q.push(neighbor);
                            parent[neighbor] = node;
                        } else if (parent[node] != neighbor) {
                            // If the neighbor is visited and is not the parent of current node,
                            // then there is a cycle in the graph
                            cyclic = true;
                        }
                    }
                }
            }
        }

        return make_pair(components == 1, cyclic);
    }
};

int main() {
    // Create a graph
    Graph graph(5); // Let's consider 7 nodes
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4); // Creating another connected component

    // Check if the graph is connected and cyclic
    pair<bool, bool> result = graph.isConnectedAndCyclic();

    if (result.first && result.second)
        cout << "The graph is connected and cyclic." << endl;
    else if (result.first)
        cout << "The graph is connected but acyclic." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}


