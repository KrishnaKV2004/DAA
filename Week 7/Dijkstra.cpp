#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

struct Edge {
    int dest;
    int weight;
};

struct Vertex {
    vector<Edge> adjList;
};

void dijkstra(const vector<Vertex>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u].adjList) {
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from friend " << i << " to Akshay's house: " << dist[i] << endl;
        cout << "Shortest path: ";
        int v = i;
        while (v != -1) {
            cout << v << " ";
            v = parent[v];
        }
        cout << endl << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<Vertex> graph(n);

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        for (int j = 0; j < m; ++j) {
            Edge edge;
            cin >> edge.dest >> edge.weight;
            graph[i].adjList.push_back(edge);
        }
    }

    int akshayHouse;
    cin >> akshayHouse;

    for (int i = 0; i < n; ++i) {
        cout << "Results for friend " << i << ":" << endl;
        dijkstra(graph, i);
    }

    return 0;
}
