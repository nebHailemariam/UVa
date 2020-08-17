#include <bits/stdc++.h>
using namespace std;

void BFS(int s, vector<vector<int>> &ADJ_LST)
{
    vector<bool> visited = vector<bool>(ADJ_LST.size(), false);
    vector<int> M_D = vector<int>(ADJ_LST.size(), 0);
    queue<pair<int, int>> q;

    q.push(pair<int, int>(s, 0));

    visited[s] = true;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < ADJ_LST[u.first].size(); i++)
        {
            int v = ADJ_LST[u.first][i];

            if (!visited[v])
            {
                visited[v] = true;
                q.push(pair<int, int>(v, u.second + 1));
                M_D[u.second]++;
            }
        }
    }
    int min_i;
    int max_val = 0;
    for (int i = 0; i < M_D.size(); i++)
    {
        if (M_D[i] > max_val)
        {
            min_i = i;
            max_val = M_D[i];
        }
    }
    (max_val != 0) ? cout << max_val << " " << min_i + 1 << "\n" : cout << 0 << "\n";
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int E;

    cin >> E;
    int e = 0;
    vector<vector<int>> ADJ_LST = vector<vector<int>>(E);
    while (e < E)
    {

        int F;
        cin >> F;
        while (F--)
        {
            int f;
            cin >> f;
            ADJ_LST[e].push_back(f);
        }
        e++;
    }
    int T;
    cin >> T;

    while (T--)
    {
        int t;
        cin >> t;
        BFS(t, ADJ_LST);
    }
}