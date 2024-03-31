#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool is_bipartite(const vector<vector<int>>& graph, int src) {
    vector<int> colors(graph.size(), -1); // Initialize all vertices with no color
    colors[src] = 0; // Color the source vertex with 0

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (size_t v = 0; v < graph[u].size(); ++v) {
            if (graph[u][v] == 1) {
                if (colors[v] == -1) {
                    colors[v] = 1 - colors[u]; // Assign alternate color to adjacent vertex
                    q.push(v);
                } else if (colors[v] == colors[u]) {
                    return false; // If adjacent vertices have the same color, not bipartite
                }
            }
        }
    }

    return true; // All vertices are colored such that no two adjacent vertices have the same color
}

bool is_bipartite_graph(const vector<vector<int>>& graph) {
    for (size_t i = 0; i < graph.size(); ++i) {
        if (!is_bipartite(graph, i)) {
            return false; // If any component is not bipartite, the graph is not bipartite
        }
    }
    return true; // All components are bipartite
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    if (is_bipartite_graph(graph))
        cout << "Yes Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;

    return 0;
}
