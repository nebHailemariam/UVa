#include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>> ADJ_LST, map<pair<int, int>, int> weight, int s)
{
    vector<int> dist = vector<int>(ADJ_LST.size(), INT_MAX);
    dist[s] = 0;
    int V = ADJ_LST.size();
    for (int e = 0; e < V - 1; e++) //Relaxing v-1 edges
    {
        for (int u = 0; u < V; u++)
        {
            for (int i = 0; i < ADJ_LST[u].size(); i++)
            {
                int v = ADJ_LST[u][i];
                int w = weight[pair<int, int>(u, v)];
                cout << u << " " << v << " - " << w << "\n";
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
    bool negative_cycle = false;
    for (int u = 0; u < V && !negative_cycle; u++)
    {
        for (int i = 0; i < ADJ_LST[u].size() && !negative_cycle; i++)
        {
            int v = ADJ_LST[u][i];
            int w = weight[pair<int, int>(u, v)];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                negative_cycle = true;
            }
        }
    }
    if (negative_cycle)
    {
        cout << "The graph has negative cycle.";
    }
    else
    {
        cout << "Vertex"
             << "   "
             << "Distance from source\n";
        for (int i = 0; i < dist.size(); i++)
        {
            cout << i << "      " << dist[i] << "\n";
        }
    }
}

int main()
{
    vector<vector<int>> ADJ_LST = {
        {1, 2},
        {2, 3, 4},
        {},
        {2, 1},
        {3}};
    map<pair<int, int>, int> weight;
    weight[pair<int, int>(0, 1)] = -1;
    weight[pair<int, int>(0, 2)] = 4;
    weight[pair<int, int>(1, 2)] = 3;
    weight[pair<int, int>(1, 3)] = 2;
    weight[pair<int, int>(1, 4)] = 2;
    weight[pair<int, int>(3, 2)] = 5;
    weight[pair<int, int>(3, 1)] = 1;
    weight[pair<int, int>(4, 3)] = -3;
    bellmanFord(ADJ_LST, weight, 0);
}