#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

struct Node {
    int id;
    int distance;
    
    Node(int _id, int _distance) : id(_id), distance(_distance) {}
    bool operator<(const Node& other) const {
        return distance > other.distance;
    }
};

int* dijkstra(int** graph, int n, int source) {
    int* distances = new int[n];
    bool* visited = new bool[n];
    priority_queue<Node> pq;
    
    for (int i = 0; i < n; ++i) {
        distances[i] = INF;
        visited[i] = false;
    }
    
    distances[source] = 0;
    pq.push(Node(source, 0));
    
    while (!pq.empty()) {
        int u = pq.top().id;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pq.push(Node(v, distances[v]));
            }
        }
    }
    
    delete[] visited;
    return distances;
}

int main() {
    const int n = 5; 
    int** graph = new int*[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
    graph[0][1] = 4;
    graph[0][2] = 1;
    graph[1][3] = 2;
    graph[2][1] = 5;
    graph[2][3] = 1;
    graph[3][4] = 3;
    graph[4][0] = 7;
    
    int source = 0;
    int destination = 4;
    
    int* shortest_distances = dijkstra(graph, n, source);
    
    if (shortest_distances[destination] == INF) {
        cout << "There is no path from source to destination\n";
    } else {
        cout << "Shortest distance from source to destination: " << shortest_distances[destination] << "\n";
    }  
    return 0;
}
