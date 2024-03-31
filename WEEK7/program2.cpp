#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from;
    int to;
    int weight;
};

vector<int> bellman_ford(const vector<Edge>& edges, int V, int src) {
    vector<int> distance(V, INF);
    distance[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
                distance[edge.to] = distance[edge.from] + edge.weight;
            }
        }
    }

    for (const Edge& edge : edges) {
        if (distance[edge.from] != INF && distance[edge.from] + edge.weight < distance[edge.to]) {
            cout << "Negative cycle detected, Bellman-Ford algorithm cannot be used." << endl;
            exit(1);
        }
    }

    return distance;
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        edges.push_back({src, dest, weight});
    }

    int src_vertex;
    cin >> src_vertex;

    vector<int> distances = bellman_ford(edges, V, src_vertex);

    for (int i = 0; i < V; ++i) {
        cout << i + 1 << " : ";
        if (distances[i] == INF) {
            cout << "No path exists" << endl;
        } else {
            cout << distances[i] << endl;
        }
    }

    return 0;
}

