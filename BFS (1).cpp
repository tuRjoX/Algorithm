#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 10;

class Graph {
private:
    int V; // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix

public:
    Graph(int vertices) : V(vertices) {
        // Initialize adjacency matrix with all 0's
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Add an edge between vertices u and v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // If undirected graph
    }

    // Print adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Breadth First Search to find a path from source to destination
    string BFS(int source, int destination) {
        bool visited[MAX_VERTICES] = {false};
        string path = "";
        queue<int> q;

        int parent[MAX_VERTICES] = {0};

        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[current][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    parent[i] = current;
                }
            }
        }

        if (!visited[destination]) {
            return "No path exists from A to J";
        }

        // Reconstruct path
        int current = destination;
        while (current != source) {
            path = (char)('A' + current) + path;
            current = parent[current];
        }
        path = (char)('A' + source) + path;

        return path;
    }
};

int main() {
    Graph g(MAX_VERTICES); // Assuming 10 vertices for nodes A to J

    // Add edges
    g.addEdge(0, 1); // A-B
    g.addEdge(0, 3); // A-D
    g.addEdge(1, 2); // B-C
    g.addEdge(1, 4); // B-E
    g.addEdge(2, 5); // C-F
    g.addEdge(3, 4); // D-E
    g.addEdge(4, 5); // E-F
    g.addEdge(3, 6); // D-G
    g.addEdge(4, 7); // E-H
    g.addEdge(5, 8); // F-I
    g.addEdge(6, 7); // G-H
    g.addEdge(7, 8); // H-I
    g.addEdge(7, 9); // H-J
    g.addEdge(8, 9); // I-J

    g.printAdjMatrix();

    // Find path from A to J
    string path = g.BFS(0, 9); // 'A' is 0, 'J' is 9

    // Print path
    cout << "Path from A to J: " << path << endl;

    return 0;
}
