#include <bits/stdc++.h>
using namespace std;

int f, mf, s, t;
vector<vector<int>> res;
vector<vector<int>> ADJ_LST;
vector<int> p;
vector<int> dist;

void augment(int v, int minEdge)
{
    if (v == s)
    {
        f = minEdge;
        return;
    }
    else if (p[v] != -1)
    {
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main()
{
    ADJ_LST = {
        {2, 3}, {2, 3}, {0, 1, 3}, {0, 1, 2}};

    res = {
        {0, 0, 70, 30},
        {0, 0, 25, 70},
        {70, 25, 0, 5},
        {30, 70, 5, 0}};
    s = 0;
    t = 1;
    int mf = 0;

    while (true)
    {
        f = 0;
        dist = vector<int>(ADJ_LST.size(), INT_MAX);
        p = vector<int>(ADJ_LST.size(), -1);
        vector<bool> vis = vector<bool>(ADJ_LST.size(), false);
        dist[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            if (u == t)
                break;
            for (int i = 0; i < ADJ_LST[u].size(); i++)
            {
                int v = ADJ_LST[u][i];
                if (res[u][v] > 0 && !vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, INT_MAX);
        if (f == 0)
            break;
        mf += f;
    }
    cout << "The max flow is " << mf << ".\n";
}