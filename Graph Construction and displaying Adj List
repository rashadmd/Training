#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjacencyList;

public:
    // Constructor
    Graph(int n) : numNodes(n), adjacencyList(n) {}

    // Method to add an edge between nodes u and v
    void addEdge(int u, int v) {
        // For an undirected graph, add edges in both directions
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // Method to display the graph
    void displayGraph() {
        cout << "Graph Representation (Adjacency List):" << endl;
        for (int i = 0; i < numNodes; ++i) {
            cout << i << " -> ";
            for (int neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 nodes
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    // Display the graph
    graph.displayGraph();

    return 0;
}
