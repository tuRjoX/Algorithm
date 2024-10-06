#include <iostream>
#include <vector>
#include <limits>

#define INF std::numeric_limits<int>::max()

struct Edge {
  int source;
  int destination;
  int weight;
};

class Graph {
public:
  int V, E;
  std::vector<Edge> edges;

  Graph(int V, int E) {
    this->V = V;
    this->E = E;
  }

  void addEdge(int src, int dest, int weight) {
    Edge edge;
    edge.source = src;
    edge.destination = dest;
    edge.weight = weight;
    edges.push_back(edge);
  }

  // Function to implement Bellman-Ford algorithm
  bool BellmanFord(int src, int dest) {
    std::vector<int> distance(V, INF);
    distance[src] = 0;

    // Relax all edges V-1 times as there can be V-1 edges in the shortest path
    for (int i = 0; i < V - 1; i++) {
      for (Edge edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != INF && distance[u] + weight < distance[v]) {
          distance[v] = distance[u] + weight;
        }
      }
    }

    // Check for negative-weight cycles (optional)
    for (Edge edge : edges) {
      int u = edge.source;
      int v = edge.destination;
      int weight = edge.weight;
      if (distance[u] != INF && distance[u] + weight < distance[v]) {
        std::cout << "Graph contains negative weight cycle" << std::endl;
        return false;
      }
    }

    // Print shortest distances
    std::cout << "Vertex \t\tDistance from Source" << std::endl;
    for (int i = 0; i < V; ++i) {
      std::cout << i << "\t\t" << distance[i] << std::endl;
    }

    // Check if path exists to destination
    return distance[dest] != INF;
  }
};

int main() {
  int V = 5;  // Number of vertices in the graph
  int E = 8;  // Number of edges in the graph

  Graph graph(V, E);

  // Add edges (assuming directed graph)
  graph.addEdge(0, 1, -1);
  graph.addEdge(0, 2, 4);
  graph.addEdge(1, 2, 3);
  graph.addEdge(1, 3, 2);
  graph.addEdge(2, 1, 1);
  graph.addEdge(3, 2, 5);
  graph.addEdge(3, 4, -3);
  graph.addEdge(4, 0, 7);

  int src = 0;
  int dest = 4;

  if (graph.BellmanFord(src, dest)) {
    std::cout << "Shortest path from source " << src << " to destination " << dest << " exists" << std::endl;
  } else {
    std::cout << "Shortest path from source " << src << " to destination " << dest << " doesn't exist" << std::endl;
  }

  return 0;
}
