#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int shortest_path_with_k_edges(const vector<vector<int>>& graph, int src, int dest, int k) {
    int V = graph.size();

    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k + 1, INF)));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dp[i][j][0] = (i == j) ? 0 : graph[i][j];
        }
    }

    for (int edges = 1; edges <= k; ++edges) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                dp[u][v][edges] = dp[u][v][edges - 1];
                for (int w = 0; w < V; ++w) {
                    if (dp[u][w][edges - 1] != INF && graph[w][v] != INF) {
                        dp[u][v][edges] = min(dp[u][v][edges], dp[u][w][edges - 1] + graph[w][v]);
                    }
                }
            }
        }
    }

    return dp[src][dest][k];
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
            }
        }
    }

    int src, dest, k;
    cin >> src >> dest >> k;
    --src;
    --dest;

    int shortest_path_weight = shortest_path_with_k_edges(graph, src, dest, k);

    if (shortest_path_weight != INF) {
        cout << "Weight of shortest path from (" << src + 1 << "," << dest + 1 << ") with " << k << " edges: " << shortest_path_weight << endl;
    } else {
        cout << "no path of length " << k << " is available" << endl;
    }

    return 0;
}
