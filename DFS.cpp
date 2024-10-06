#include <iostream>
#include <stack>

using namespace std;

const int MAX_VERTICES = 100; // Maximum number of vertices

class Graph {
private:
    int V; // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency Matrix

public:
    Graph(int vertices) {
        V = vertices;
        // Initialize all values to 0
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For undirected graph
    }

    // Depth First Search traversal
    void DFS(int src, int dest) {
        bool visited[MAX_VERTICES] = {false}; // Mark all vertices as not visited
        int parent[MAX_VERTICES] = {-1}; // Array to store parent of each vertex in DFS traversal
        stack<int> s; // Create a stack for DFS

        s.push(src); // Push the source node to the stack
        visited[src] = true; // Mark source node as visited

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            // Visit all adjacent vertices of u
            for (int v = 0; v < V; ++v) {
                if (adjMatrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    s.push(v);
                }
            }
        }

        // If destination node is not reachable from source node
        if (!visited[dest]) {
            cout << "No path exists from source to destination\n";
            return;
        }

        // Reconstruct path from destination to source
        int path[MAX_VERTICES], pathLength = 0;
        for (int at = dest; at != -1; at = parent[at]) {
            path[pathLength++] = at;
        }

        // Print the path
        cout << "Path from " << src << " to " << dest << ": ";
        for (int i = pathLength - 1; i >= 0; --i)
            cout << path[i] << " ";
        cout << endl;
    }

    // Function to print adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph
    Graph g(10); // Assuming there are 10 vertices (A to J)

    // Add edges (assuming A to J corresponds to indices 0 to 9 respectively)
    g.addEdge(0, 1); // A to B
    g.addEdge(0, 2); // A to C
    g.addEdge(1, 3); // B to D
    g.addEdge(2, 4); // C to E
    g.addEdge(3, 5); // D to F
    g.addEdge(3, 6); // D to G
    g.addEdge(4, 7); // E to H
    g.addEdge(5, 8); // F to I
    g.addEdge(6, 9); // G to J
    g.addEdge(8, 9); // I to J

    // Print adjacency matrix
    g.printAdjMatrix();

    // Find path from A to J using DFS
    g.DFS(0, 9); // A corresponds to index 0, J corresponds to index 9

    return 0;
}
