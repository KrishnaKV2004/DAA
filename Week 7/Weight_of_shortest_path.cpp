#include <iostream>
#include <vector>

using namespace std;

#define INF INT_MAX

struct Edge {
    int dest;
    int weight;
};

int shortestPathWithKEdges(const vector<vector<Edge>>& graph, int source, int destination, int k) {
    int V = graph.size();
    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k + 1, INF)));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            dp[i][j][0] = (i == j) ? 0 : INF;
        }
    }

    for (int e = 1; e <= k; ++e) {
        for (int u = 0; u < V; ++u) {
            for (const Edge& edge : graph[u]) {
                int v = edge.dest;
                int weight = edge.weight;
                dp[u][v][e] = dp[u][v][e - 1];
                for (int i = 0; i < V; ++i) {
                    dp[u][v][e] = min(dp[u][v][e], dp[u][i][e - 1] + weight);
                }
            }
        }
    }

    return dp[source][destination][k];
}

int main() {
    int V;
    cin >> V;

    vector<vector<Edge>> graph(V);
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                Edge edge;
                edge.dest = j;
                edge.weight = weight;
                graph[i].push_back(edge);
            }
        }
    }

    int source, destination, k;
    cin >> source >> destination >> k;

    int shortestWeight = shortestPathWithKEdges(graph, source, destination, k);
    if (shortestWeight != INF) {
        cout << shortestWeight << endl;
    } else {
        cout << "no path of length " << k << " is available" << endl;
    }

    return 0;
}
