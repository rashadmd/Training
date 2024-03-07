#include <iostream>
#include <vector>

using namespace std;

class UnweightedGraph {
private:
    int numNodes;
    vector<vector<int>> adjacencyList;

public:
    // Constructor
    UnweightedGraph(int n) : numNodes(n), adjacencyList(n) {}

    // Method to add an unweighted edge between nodes u and v
    void addUnweightedEdge(int u, int v) {
        // For an undirected graph, add edges in both directions
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    // Method to display the unweighted graph
    void displayUnweightedGraph() {
        cout << "Unweighted Graph Representation (Adjacency List):" << endl;
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
    // Create an unweighted graph with 5 nodes
    UnweightedGraph unweightedGraph(5);

    // Add unweighted edges to the graph
    unweightedGraph.addUnweightedEdge(0, 1);
    unweightedGraph.addUnweightedEdge(0, 2);
    unweightedGraph.addUnweightedEdge(1, 3);
    unweightedGraph.addUnweightedEdge(2, 4);

    // Display the unweighted graph
    unweightedGraph.displayUnweightedGraph();

    return 0;
}
