#include <bits/stdc++.h>
using namespace std;

int compute(int i, vector<int> &store, int N, vector<vector<char>> &path, vector<vector<int>> &val)
{
    if (val[N][i] != INT_MIN)
        return val[N][i];
    if (i == store.size())
        return 0;
    if (store[i] <= N)
    {
        int T = compute(i + 1, store, N - store[i], path, val) + store[i];
        int D = compute(i + 1, store, N, path, val);
        if (T >= D)
            path[N][i] = 'T';

        val[N][i] = max(T, D);
        return val[N][i];
    }
    else
        return compute(i + 1, store, N, path, val);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N, tracks;
    while (cin >> N)
    {
        vector<int> store;
        cin >> tracks;
        while (tracks--)
        {
            int temp;
            cin >> temp;
            store.push_back(temp);
        }
        vector<vector<char>> path = vector<vector<char>>(N + 1, vector<char>(store.size(), 'D'));
        vector<vector<int>> val = vector<vector<int>>(N + 1, vector<int>(store.size() + 1, INT_MIN));
        int sol = compute(0, store, N, path, val);
        int i = 0;
        while (N > 0 && i < store.size())
        {
            if (path[N][i] == 'T')
            {
                cout << store[i] << " ";
                N -= store[i];
                i++;
            }
            else
            {
                i++;
            }
        }
        cout << "sum:" << sol << "\n";
    }
}