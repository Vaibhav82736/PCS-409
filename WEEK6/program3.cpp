#include <iostream>
#include <vector>

using namespace std;

bool is_cycle_util(const vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& rec_stack) {
    if (!visited[v]) {
        visited[v] = true;
        rec_stack[v] = true;

        for (size_t i = 0; i < graph[v].size(); ++i) {
            if (graph[v][i] == 1) {
                if (!visited[i] && is_cycle_util(graph, i, visited, rec_stack))
                    return true;
                else if (rec_stack[i])
                    return true;
            }
        }
    }
    rec_stack[v] = false;
    return false;
}

bool is_cycle(const vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    vector<bool> rec_stack(graph.size(), false);

    for (size_t i = 0; i < graph.size(); ++i) {
        if (is_cycle_util(graph, i, visited, rec_stack))
            return true;
    }

    return false;
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if (is_cycle(graph))
        cout << "Yes Cycle Exists" << endl;
    else
        cout << "No Cycle Exists" << endl;

    return 0;
}
