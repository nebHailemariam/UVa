#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> &dist, vector<bool> &visited)
{
    int index_i = 0, min_i = INT_MAX;

    for (int i = 0; i < dist.size(); i++)
    {
        if (!visited[i] && min_i > dist[i])
        {
            min_i = dist[i];
            index_i = i;
        }
    }
    return index_i;
}

void dijkstra(vector<vector<int>> ADJ_LST, map<pair<int, int>, int> weight, int s, int d)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist = vector<int>(ADJ_LST.size(), INT_MAX);
    vector<int> par = vector<int>(ADJ_LST.size(), -1);
    vector<bool> visited = vector<bool>(ADJ_LST.size(), false);
    int count = 0;
    dist[s] = 0;

    for (int vertex = 0; vertex < ADJ_LST.size(); vertex++)
    {
        int u = find_min(dist, visited);
        visited[u] = true;

        for (int i = 0; i < ADJ_LST[u].size(); i++)
        {
            int v = ADJ_LST[u][i];
            int w = weight[pair<int, int>(u, v)];
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    for (int i = 0; i < par.size(); i++)
    {
        cout << par[i] << " ";
    }

    cout << "\n";

    for (int i = 0; i < par.size(); i++)
    {
        cout << dist[i] << " ";
    }

    cout << "\n";
    while (d != -1)
    {
        cout << d << " ";
        d = par[d];
    }
    cout << "\n";
}

int main()
{
    vector<vector<int>> ADJ_LST = {
        {4},
        {3, 4},
        {0, 1, 3},
        {4},
        {}};
    map<pair<int, int>, int> weight;
    weight[pair<int, int>(0, 4)] = 1;
    weight[pair<int, int>(1, 3)] = 3;
    weight[pair<int, int>(1, 4)] = 6;
    weight[pair<int, int>(2, 0)] = 6;
    weight[pair<int, int>(2, 1)] = 2;
    weight[pair<int, int>(2, 3)] = 7;
    weight[pair<int, int>(3, 4)] = 5;

    dijkstra(ADJ_LST, weight, 2, 4);
}