#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    string store = "";

    getline(cin, store);
    int test_cases = 0;
    while (true)
    {
        stringstream storess(store);
        string zero;
        storess >> zero;
        if (stoi(zero) == 0)
        {
            storess >> zero;
            if (stoi(zero) == 0)
                break;
        }

        vector<vector<int>> ADJ_MAT = vector<vector<int>>(101, vector<int>(101, INT_MAX));
        stringstream ss(store);
        string temp;
        while (true)
        {
            ss >> temp;
            int a = stoi(temp);
            ss >> temp;
            int b = stoi(temp);
            if (a == 0 && b == 0)
                break;
            ADJ_MAT[a][b] = 1;
        }
        //Floyd Warshal
        for (int k = 0; k < 101; k++)
        {
            for (int i = 0; i < 101; i++)
            {
                for (int j = 0; j < 101; j++)
                {
                    if (ADJ_MAT[i][k] == INT_MAX || ADJ_MAT[k][j] == INT_MAX)
                        continue;
                    ADJ_MAT[i][j] = min(ADJ_MAT[i][j], ADJ_MAT[i][k] + ADJ_MAT[k][j]);
                }
            }
        }
        float num_paths = 0;
        float length_paths = 0;
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                if (i == j || ADJ_MAT[i][j] == INT_MAX)
                    continue;
                num_paths++;
                length_paths += ADJ_MAT[i][j];
            }
        }

        cout << "Case " << ++test_cases << ": average length between pages = " << fixed << setprecision(3) << float(int((length_paths / num_paths) * 1000 + 0.5)) / 1000 << " clicks\n";
        getline(cin, store);
    }
}