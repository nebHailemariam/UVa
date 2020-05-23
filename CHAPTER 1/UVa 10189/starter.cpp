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
    int field = 1;
    while (getline(cin, store))
    {
        stringstream ss(store);
        string word;
        ss >> word;
        int n = stoi(word);
        ss >> word;
        int m = stoi(word);
        if (n == 0 && m == 0)
            break;
        vector<vector<char>> mine(n, vector<char>(m, '0'));
        int n_count = 0;
        if (field != 1)
            cout << "\n";
        cout << "Field #" << field << ":\n";
        field++;
        while (n_count < n)
        {
            string step = "";
            getline(cin, step);
            for (int i = 0; i < step.size(); i++)
            {
                if (step[i] == '*')
                {
                    mine[n_count][i] = '*';
                    if (n_count - 1 > -1)
                    {
                        if (isdigit(mine[n_count - 1][i]))
                            mine[n_count - 1][i]++;
                        else if (mine[n_count - 1][i] == '_')
                            mine[n_count - 1][i] = '1';
                    }
                    if (i - 1 > -1)
                    {
                        if (isdigit(mine[n_count][i - 1]))
                            mine[n_count][i - 1]++;
                        else if (mine[n_count][i - 1] == '_')
                            mine[n_count][i - 1] = '1';
                    }
                    if (i + 1 < m)
                    {
                        if (isdigit(mine[n_count][i + 1]))
                            mine[n_count][i + 1]++;
                        else if (mine[n_count][i + 1] == '_')
                            mine[n_count][i + 1] = '1';
                    }
                    if (n_count + 1 < n)
                    {
                        if (isdigit(mine[n_count + 1][i]))
                            mine[n_count + 1][i]++;
                        else if (mine[n_count + 1][i] == '_')
                            mine[n_count + 1][i] = '1';
                    }
                    if (i - 1 > -1 && n_count - 1 > -1)
                    {
                        if (isdigit(mine[n_count - 1][i - 1]))
                            mine[n_count - 1][i - 1]++;
                        else if (mine[n_count - 1][i - 1] == '_')
                            mine[n_count - 1][i - 1] = '1';
                    }
                    if (i + 1 < m && n_count - 1 > -1)
                    {
                        if (isdigit(mine[n_count - 1][i + 1]))
                            mine[n_count - 1][i + 1]++;
                        else if (mine[n_count - 1][i + 1] == '_')
                            mine[n_count - 1][i + 1] = '1';
                    }
                    if (i - 1 > -1 && n_count + 1 < n)
                    {
                        if (isdigit(mine[n_count + 1][i - 1]))
                            mine[n_count + 1][i - 1]++;
                        else if (mine[n_count + 1][i - 1] == '_')
                        {
                            mine[n_count + 1][i - 1] = '1';
                        }
                    }
                    if (i + 1 < m && n_count + 1 < n)
                    {
                        if (isdigit(mine[n_count + 1][i + 1]))
                            mine[n_count + 1][i + 1]++;
                        else if (mine[n_count + 1][i + 1] == '_')
                        {
                            mine[n_count + 1][i + 1] = '1';
                        }
                    }
                }
            }
            n_count++;
            // }
        }
        for (int i = 0; i < mine.size(); i++)
        {
            for (int j = 0; j < mine[i].size(); j++)
            {
                cout << mine[i][j];
            }
            cout << "\n";
        }
    }
}