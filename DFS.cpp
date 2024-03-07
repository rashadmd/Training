#include <iostream>
#include <vector>
using namespace std;

void DFS(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
	visited[node] = true;
	cout << node << " ";

	for (int neighbor : graph[node]) {
    	if (!visited[neighbor]) {
        	DFS(graph, visited, neighbor);
    	}
	}
}

int main() {
	// Example directed graph represented as an adjacency list
	vector<vector<int>> graph = {
    	{1, 2}, 	// Node 0 has outgoing edges to nodes 1 and 2
    	{2, 3}, 	// Node 1 has outgoing edges to nodes 2 and 3
    	{3},    	// Node 2 has an outgoing edge to node 3
    	{4},    	// Node 3 has an outgoing edge to node 4
    	{0}     	// Node 4 has an outgoing edge to node 0 (back edge)
	};

	vector<bool> visited(graph.size(), false);
	cout << "DFS Traversal: ";
	DFS(graph, visited, 0);
	cout << endl;

	return 0;
}
