#include <iostream>
#include <vector>

using namespace std;

#define INF INT_MAX

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(const vector<Edge>& edges, int V, int source)
{
    vector<int> dist(V, INF);
    dist[source] = 0;

    for (int i = 0; i < V - 1; ++i)
    {
        for (const Edge& edge : edges)
        {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest])
            {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    for (int i = 0; i < V; ++i)
    {
        cout << i + 1 << " : " << dist[i] << endl;
    }
}

int main()
{
    int V;
    cin >> V;

    vector<Edge> edges;

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            int weight;
            cin >> weight;
            if (weight != 0) {
                Edge edge;
                edge.src = i;
                edge.dest = j;
                edge.weight = weight;
                edges.push_back(edge);
            }
        }
    }

    int source;
    cin >> source;

    bellmanFord(edges, V, source - 1);

    return 0;
}
