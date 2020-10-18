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
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int test_cases, network = 0;

    while (cin >> test_cases && test_cases != 0)
    {
        ADJ_LST = vector<vector<int>>(test_cases);
        res = vector<vector<int>>(test_cases, vector<int>(test_cases, 0));
        int c;
        cin >> s >> t >> c;
        s--;
        t--;
        while (c--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            ADJ_LST[u].push_back(v);
            ADJ_LST[v].push_back(u);
            res[u][v] += w;
            res[v][u] += w;
        }
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
        cout << "Network " << ++network << "\n";
        cout << "The bandwidth is " << mf << ".\n\n";
    }
}
