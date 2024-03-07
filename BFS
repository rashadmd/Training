#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(const vector<vector<int>>& graph, int start) {
	vector<bool> visited(graph.size(), false);
	queue<int> q;

	visited[start] = true;
	q.push(start);

	cout << "BFS Traversal: ";
	while (!q.empty()) {
    	int node = q.front();
    	q.pop();
    	cout << node << " ";

    	for (int neighbor : graph[node]) {
        	if (!visited[neighbor]) {
            	visited[neighbor] = true;
            	q.push(neighbor);
        	}
    	}
	}
	cout << endl;
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

	BFS(graph, 0);

	return 0;
}
