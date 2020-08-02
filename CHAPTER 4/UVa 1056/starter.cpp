#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, edges;
    int network = 1;
    while (cin >> n >> edges && (n != 0 || edges != 0))
    {
        vector<vector<int>> ADJ_MAT = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        unordered_map<string, int> p_id;
        int id = 0;
        ;

        while (edges--)
        {
            string p1, p2;
            cin >> p1 >> p2;
            if (p_id.count(p1) == 0)
            {
                p_id[p1] = id;
                id++;
            }
            if (p_id.count(p2) == 0)
            {
                p_id[p2] = id;
                id++;
            }
            ADJ_MAT[p_id[p2]][p_id[p1]] = 1;
            ADJ_MAT[p_id[p1]][p_id[p2]] = 1;
        }

        for (int k = 0; k < ADJ_MAT.size(); k++)
        {
            for (int i = 0; i < ADJ_MAT.size(); i++)
            {
                for (int j = 0; j < ADJ_MAT.size(); j++)
                {
                    if (ADJ_MAT[i][k] != INT_MAX && ADJ_MAT[k][j] != INT_MAX)
                        ADJ_MAT[i][j] = min(ADJ_MAT[i][j], ADJ_MAT[i][k] + ADJ_MAT[k][j]);
                }
            }
        }
        int max_deg_sep = 0;
        for (int i = 0; i < ADJ_MAT.size(); i++)
        {
            for (int j = 0; j < ADJ_MAT.size(); j++)
            {
                if (i != j)
                    max_deg_sep = max(max_deg_sep, ADJ_MAT[i][j]);
            }
        }
        (max_deg_sep != INT_MAX) ? cout << "Network " << network++ << ": " << max_deg_sep << "\n\n" : cout << "Network " << network++ << ": DISCONNECTED\n\n";
    }
}