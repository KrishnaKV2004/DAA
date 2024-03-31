#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(const vector<vector<int>>& graph, int start) {
    vector<int> color(graph.size(), -1);
    color[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartiteGraph(const vector<vector<int>>& graph) {
    for (int i = 0; i < graph.size(); ++i) {
        if (!isBipartite(graph, i)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        int vertex;
        while (cin >> vertex && vertex != -1) {
            graph[i].push_back(vertex);
        }
    }

    if (isBipartiteGraph(graph)) {
        cout << "Yes Bipartite" << endl;
    } else {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}
