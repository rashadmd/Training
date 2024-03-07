#include <iostream>
#include <vector>

using namespace std;

class WeightedGraph {
private:
    int numNodes;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    // Constructor
    WeightedGraph(int n) : numNodes(n), adjacencyList(n) {}

    // Method to add a weighted edge between nodes u and v with weight w
    void addWeightedEdge(int u, int v, int weight) {
        // For an undirected graph, add edges in both directions
        adjacencyList[u].push_back({v, weight});
        adjacencyList[v].push_back({u, weight});
    }

    // Method to display the weighted graph
    void displayWeightedGraph() {
        cout << "Weighted Graph Representation (Adjacency List):" << endl;
        for (int i = 0; i < numNodes; ++i) {
            cout << i << " -> ";
            for (const auto& neighbor : adjacencyList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a weighted graph with 5 nodes
    WeightedGraph weightedGraph(5);

    // Add weighted edges to the graph
    weightedGraph.addWeightedEdge(0, 1, 2);
    weightedGraph.addWeightedEdge(0, 2, 3);
    weightedGraph.addWeightedEdge(1, 3, 1);
    weightedGraph.addWeightedEdge(2, 4, 4);

    // Display the weighted graph
    weightedGraph.displayWeightedGraph();

    return 0;
}
