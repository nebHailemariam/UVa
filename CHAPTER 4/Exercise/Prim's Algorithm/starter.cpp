#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<bool> visited;
vector<int> key;
vector<vector<int>> ADJ_LST;
map<pair<int, int>, int> weight;

void print_MST()
{
    for (int i = 1; i < ADJ_LST.size(); i++)
    {
        int w;
        (weight.count(pair<int, int>(i, par[i])) == 0) ? w = weight[pair<int, int>(par[i], i)] : w = weight[pair<int, int>(i, par[i])];
        cout << par[i] << " - " << i << " : " << w << "\n";
    }
}

int min_key()
{
    int min = INT_MAX;
    int i_min = 0;
    for (int i = 0; i < key.size(); i++)
    {
        if (!visited[i] && key[i] < min)
        {
            i_min = i;
            min = key[i];
        }
    }
    return i_min;
}

void prims()
{
    par = vector<int>(ADJ_LST.size(), -1);
    visited = vector<bool>(ADJ_LST.size(), false);
    key = vector<int>(ADJ_LST.size(), INT_MAX);
    key[0] = 0;

    int count_v = 0;

    while (count_v < ADJ_LST.size() - 1)
    {
        int u = min_key();
        visited[u] = true;

        for (int i = 0; i < ADJ_LST[u].size(); i++)
        {
            int v = ADJ_LST[u][i];
            int w;
            (weight.count(pair<int, int>(u, v)) == 0) ? w = weight[pair<int, int>(v, u)] : w = weight[pair<int, int>(u, v)];
            if (!visited[v] && (key[v] > w))
            {
                key[v] = w;
                par[v] = u;
            }
        }
        count_v++;
    }
    print_MST();
}

int main()
{
    int V = 5;
    ADJ_LST = {
        {1, 2},
        {0, 2},
        {0, 1}};
    weight.clear();
    weight[pair<int, int>(0, 1)] = 2;
    weight[pair<int, int>(0, 2)] = 60;
    weight[pair<int, int>(1, 2)] = 30;
    prims();
}