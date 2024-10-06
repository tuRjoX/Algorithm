#include <iostream>
using namespace std;

// Function to perform Breadth-First Search
char* BFS(int graph[][10], char start, char end) {
    static char path[10];
    char parent[10] = {0};

    int front = 0, rear = 0;
    char queue[10];
    queue[rear++] = start;
    parent[start - 'A'] = start;

    while (front != rear) {
        char current = queue[front++];
        if (current == end) {
            char node = end;
            int i = 0;
            while (node != start) {
                path[i++] = node;
                node = parent[node - 'A'];
            }
            path[i] = start;
            path[i + 1] = '\0';
            return path;
        }

        for (int i = 0; i < 10; ++i) {
            if (graph[current - 'A'][i] && !parent[i]) {
                queue[rear++] = 'A' + i;
                parent[i] = current;
            }
        }
    }

    return path; // If there's no path from start to end
}

int main() {
    // Adjacency matrix of the graph
    int graph[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // A
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // B
        {1, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // C
        {0, 1, 1, 0, 1, 1, 0, 0, 0, 0}, // D
        {0, 0, 1, 1, 0, 1, 0, 0, 0, 0}, // E
        {0, 0, 0, 1, 1, 0, 1, 1, 0, 0}, // F
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1}, // G
        {0, 0, 0, 0, 0, 1, 0, 0, 1, 0}, // H
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, // I
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0}  // J
    };

    // Displaying the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    // Finding the path from A to J using BFS
    cout << "\nPath from A to J using BFS: ";
    char* path = BFS(graph, 'A', 'J');
    if (path[0] == '\0') {
        cout << "No path exists." << endl;
    } else {
        cout << path<<"   " << endl;
    }

    return 0;
}
