#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int test_cases;
    int count = 1;
    cin >> test_cases;

    while (test_cases--)
    {

        int n;
        cin >> n;
        vector<vector<int>> ADJ_MAT = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        int edges;
        cin >> edges;
        while (edges--)
        {
            int a, b;
            cin >> a >> b;
            ADJ_MAT[a][b] = 1;
            ADJ_MAT[b][a] = 1;
        }
        int s, d;
        cin >> s >> d;
        for (int i = 0; i < ADJ_MAT.size(); i++)
        {
            ADJ_MAT[i][i] = 0;
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

        int max_path = 0;
        for (int i = 0; i < ADJ_MAT.size(); i++)
        {
            if (ADJ_MAT[s][i] != INT_MAX && ADJ_MAT[i][d] != INT_MAX)
            {
                max_path = max(max_path, ADJ_MAT[s][i] + ADJ_MAT[i][d]);
            }
        }
        cout << "Case " << count++ << ": " << max_path << "\n";
    }
}