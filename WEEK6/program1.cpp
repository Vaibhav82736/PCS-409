#include <iostream>
#include <vector>

using namespace std;

bool is_path(const vector<vector<int>>& graph, int src, int dest, vector<bool>& visited) {
    if (src == dest)
        return true;

    visited[src] = true;

    for (size_t neighbor = 0; neighbor < graph[src].size(); ++neighbor) {
        if (graph[src][neighbor] == 1 && !visited[neighbor]) {
            if (is_path(graph, neighbor, dest, visited))
                return true;
        }
    }

    return false;
}

bool path_exists(const vector<vector<int>>& graph, int src, int dest) {
    vector<bool> visited(graph.size(), false);
    return is_path(graph, src, dest, visited);
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    int src = 0;  // Source vertex
    int dest = 5; // Destination vertex

    if (path_exists(graph, src, dest))
        cout << "Yes, Path Exists" << endl;
    else
        cout << "No Such Path Exists" << endl;

    return 0;
}
