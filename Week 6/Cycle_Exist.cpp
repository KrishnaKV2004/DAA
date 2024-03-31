#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(const vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int u : graph[v]) {
            if (!visited[u] && isCyclicUtil(graph, u, visited, recStack)) {
                return true;
            } else if (recStack[u]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(const vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (isCyclicUtil(graph, i, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency list of the graph: " << endl;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter the adjacency list for vertex " << i << " (-1 to end): ";
        int vertex;
        while (cin >> vertex && vertex != -1) {
            graph[i].push_back(vertex);
        }
    }

    if (isCyclic(graph)) {
        cout << "Yes Cycle Exists" << endl;
    } else {
        cout << "No Cycle Exists" << endl;
    }

    return 0;
}