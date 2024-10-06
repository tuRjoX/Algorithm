#include <iostream>

#define V 5 // Number of vertices

using namespace std;

// Define a pair structure
struct Pair {
    int first;
    int second;
};

// Function to add edge to adjacency matrix representation of graph
void addEdgeMatrix(int graph[V][V], int u, int v, int weight = 1) {
    graph[u][v] = weight;
}

// Function to add edge to adjacency list representation of graph
void addEdgeList(Pair* graph[], int u, int v, int weight = 1) {
    Pair edge;
    edge.first = v;
    edge.second = weight;
    Pair* temp = graph[u];
    while (temp->first != -1) temp++;
    *temp = edge;
    temp++;
    temp->first = -1; // Marking end of list
}

// Function to display adjacency matrix representation of graph
void displayMatrix(int graph[V][V]) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to display adjacency list representation of graph
void displayList(Pair* graph[]) {
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        Pair* temp = graph[i];
        while (temp->first != -1) {
            cout << "(" << temp->first << ", " << temp->second << ") ";
            temp++;
        }
        cout << endl;
    }
}

int main() {
    // Initialize adjacency matrix and adjacency list for directed graph
    int directedMatrix[V][V] = {0};
    Pair* directedList[V];
    for (int i = 0; i < V; i++) {
        directedList[i] = new Pair[V + 1];
        directedList[i][0].first = -1; // Marking end of list
    }
    // Add edges to directed graph
    addEdgeMatrix(directedMatrix, 0, 1);
    addEdgeMatrix(directedMatrix, 0, 2);
    addEdgeMatrix(directedMatrix, 1, 3);
    addEdgeMatrix(directedMatrix, 2, 4);
    addEdgeMatrix(directedMatrix, 3, 4);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (directedMatrix[i][j] != 0) {
                addEdgeList(directedList, i, j);
            }
        }
    }
    displayMatrix(directedMatrix);
    displayList(directedList);
    
    // Initialize adjacency matrix and adjacency list for undirected graph
    int undirectedMatrix[V][V] = {0};
    Pair* undirectedList[V];
    for (int i = 0; i < V; i++) {
        undirectedList[i] = new Pair[V + 1];
        undirectedList[i][0].first = -1; // Marking end of list
    }
    // Add edges to undirected graph
    addEdgeMatrix(undirectedMatrix, 0, 1);
    addEdgeMatrix(undirectedMatrix, 0, 2);
    addEdgeMatrix(undirectedMatrix, 1, 3);
    addEdgeMatrix(undirectedMatrix, 2, 4);
    addEdgeMatrix(undirectedMatrix, 3, 4);
    for (int i = 0; i < V; ++i) {
        for (int j = i; j < V; ++j) {
            if (undirectedMatrix[i][j] != 0) {
                addEdgeList(undirectedList, i, j);
                addEdgeList(undirectedList, j, i);
            }
        }
    }
    displayMatrix(undirectedMatrix);
    displayList(undirectedList);

    // Initialize adjacency matrix and adjacency list for weighted directed graph
    int weightedDirectedMatrix[V][V] = {0};
    Pair* weightedDirectedList[V];
    for (int i = 0; i < V; i++) {
        weightedDirectedList[i] = new Pair[V + 1];
        weightedDirectedList[i][0].first = -1; // Marking end of list
    }
    // Add edges to weighted directed graph
    addEdgeMatrix(weightedDirectedMatrix, 0, 1, 2);
    addEdgeMatrix(weightedDirectedMatrix, 0, 2, 3);
    addEdgeMatrix(weightedDirectedMatrix, 1, 3, 1);
    addEdgeMatrix(weightedDirectedMatrix, 2, 4, 5);
    addEdgeMatrix(weightedDirectedMatrix, 3, 4, 4);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (weightedDirectedMatrix[i][j] != 0) {
                addEdgeList(weightedDirectedList, i, j, weightedDirectedMatrix[i][j]);
            }
        }
    }
    displayMatrix(weightedDirectedMatrix);
    displayList(weightedDirectedList);

    // Initialize adjacency matrix and adjacency list for weighted undirected graph
    int weightedUndirectedMatrix[V][V] = {0};
    Pair* weightedUndirectedList[V];
    for (int i = 0; i < V; i++) {
        weightedUndirectedList[i] = new Pair[V + 1];
        weightedUndirectedList[i][0].first = -1; // Marking end of list
    }
    // Add edges to weighted undirected graph
    addEdgeMatrix(weightedUndirectedMatrix, 0, 1, 2);
    addEdgeMatrix(weightedUndirectedMatrix, 0, 2, 3);
    addEdgeMatrix(weightedUndirectedMatrix, 1, 3, 1);
    addEdgeMatrix(weightedUndirectedMatrix, 2, 4, 5);
    addEdgeMatrix(weightedUndirectedMatrix, 3, 4, 4);
    for (int i = 0; i < V; ++i) {
        for (int j = i; j < V; ++j) {
            if (weightedUndirectedMatrix[i][j] != 0) {
                addEdgeList(weightedUndirectedList, i, j, weightedUndirectedMatrix[i][j]);
                addEdgeList(weightedUndirectedList, j, i, weightedUndirectedMatrix[i][j]);
            }
        }
    }
    displayMatrix(weightedUndirectedMatrix);
    displayList(weightedUndirectedList);

    return 0;
}
