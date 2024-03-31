#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Structure to represent an edge in the graph
struct Edge {
    int to;
    int weight;
};

// Structure to represent a vertex in the graph
struct Vertex {
    int id;
    int distance;
    vector<Edge> edges;
};

// Dijkstra's algorithm to find the shortest distance and path from source to all vertices
void dijkstra(const vector<Vertex>& graph, int src) {
    int V = graph.size();

    // Initialize distances of all vertices as infinity
    vector<int> distance(V, INF);

    // Priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Push the source vertex to the priority queue
    pq.push({0, src});
    distance[src] = 0;

    // Main loop to process vertices
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u].edges) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step: Update distance if shorter path found
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print shortest distance and path for each vertex
    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from friend " << i << " to Akshay's house: " << distance[i] << endl;
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<Vertex> graph = {
        {{0}, 0, {{1, 4}, {2, 1}, {3, 2}}}, // Akshay's house (source)
        {{1}, INF, {}}, // Friend 1
        {{2}, INF, {}}, // Friend 2
        {{3}, INF, {}} // Friend 3
    };

    // Run Dijkstra's algorithm from Akshay's house (source)
    dijkstra(graph, 0);

    return 0;
}
