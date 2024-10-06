#include <iostream>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        // Initialize parent and rank
        for (int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    // Find the root of the set to which node u belongs
    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
    }
};

// Function to find Minimum Spanning Tree using Kruskal's Algorithm
void kruskalMST(Edge* edges, int numEdges, int numVertices) {
    DisjointSet ds(numVertices);

    Edge MST[numVertices - 1]; // Stores the MST edges
    int mstIndex = 0;

    // Sort the edges by weight using bubble sort
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numEdges && mstIndex < numVertices - 1; i++) {
        int sourceParent = ds.find(edges[i].source);
        int destParent = ds.find(edges[i].destination);

        // If including this edge does not cause a cycle, include it in the MST
        if (sourceParent != destParent) {
            MST[mstIndex++] = edges[i];
            ds.merge(sourceParent, destParent);
        }
    }

    // Output the MST edges
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < numVertices - 1; i++) {
        cout << MST[i].source << " -- " << MST[i].destination << "   Weight: " << MST[i].weight << endl;
    }
}

int main() {
    // Example graph with 4 vertices and 5 edges
    int numVertices = 4;
    int numEdges = 5;

    // Example edges
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, numEdges, numVertices);

    return 0;
}
