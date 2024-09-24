#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Graph class to represent an unweighted graph
class Graph {
    int V;                      // Number of vertices
    list<int>* adjList;          // Pointer to an array containing adjacency lists

public:
    // Constructor to initialize the graph
    Graph(int V) {
        this->V = V;
        adjList = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adjList[v].push_back(w);  // Add w to v's list
        adjList[w].push_back(v);  // Since it's an undirected graph, add v to w's list
    }

    // Function to perform BFS and find shortest path from a given source
    void BFS(int src) {
        vector<int> dist(V, INT_MAX); // Distance vector to store the shortest distance from the source
        queue<int> q;

        // Start BFS from the source node
        dist[src] = 0;  // Distance from the source to itself is 0
        q.push(src);    // Enqueue the source node

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Traverse all adjacent vertices of the dequeued node
            for (int neighbor : adjList[node]) {
                // If the neighbor has not been visited (i.e., distance is still INT_MAX)
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;  // Update distance
                    q.push(neighbor);                 // Enqueue the neighbor
                }
            }
        }

        // Print the shortest distances from the source to all vertices
        cout << "Shortest distances from node " << src << " to all other nodes:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    // Destructor to clean up the allocated memory
    ~Graph() {
        delete[] adjList;
    }
};

int main() {
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);

    // Add edges between nodes
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 5);

    // Perform BFS from source node 0
    g.BFS(0);

    return 0;
}
