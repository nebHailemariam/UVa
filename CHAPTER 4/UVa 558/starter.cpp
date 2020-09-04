#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> Adj_Lst;
vector<long long> dist;
bool BellmanFord()
{
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    for (int i = 0; i < Adj_Lst.size() - 1; i++)
    {
        for (int u = 0; u < Adj_Lst.size(); u++)
        {
            for (int j = 0; j < Adj_Lst[u].size(); j++)
            {
                pair<int, int> v = Adj_Lst[u][j];
                dist[v.first] = min(dist[v.first], dist[u] + v.second);
            }
        }
    }

    for (int u = 0; u < Adj_Lst.size(); u++)
    {
        for (int i = 0; i < Adj_Lst[u].size(); i++)
        {
            pair<int, int> v = Adj_Lst[u][i];
            if (dist[v.first] > dist[u] + v.second)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int c;
    cin >> c;

    int n, m;
    while (c--)
    {
        cin >> n >> m;
        Adj_Lst = vector<vector<pair<int, int>>>(n);
        dist = vector<long long>(n);
        int u, v, w;
        while (m--)
        {
            cin >> u >> v >> w;
            Adj_Lst[u].push_back(pair<int, int>(v, w));
        }
        (BellmanFord()) ? cout << "possible\n" : cout << "not possible\n";
    }
}