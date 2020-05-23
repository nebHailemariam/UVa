#include <bits/stdc++.h>
using namespace std;


string res = "";

void recurse(vector<vector<char>> store, string pass, int i, int &depth, int k)
{
    if (pass.size() == 4)
    {

        for (int j = 0; j < store[i].size(); j++)
        {
            depth++;
            if (depth == k)
            {

                res = pass + "" + store[i][j];
            }
        }
        return;
    }
    for (int j = 0; j < store[i].size() && k != depth; j++)
    {
        recurse(store, pass + "" + store[i][j], i + 1, depth, k);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int k;
        cin >> k;
        vector<vector<char>> shot_1 = vector<vector<char>>(6);
        vector<vector<char>> shot_2 = vector<vector<char>>(6);
        vector<vector<char>> shot_3 = vector<vector<char>>(6);

        string store = "";
        int count = 6;
        while (count--)
        {
            cin >> store;
            for (int i = 0; i < store.size(); i++)
            {
                shot_1[i].push_back(store[i]);
            }
        }
        count = 6;
        while (count--)
        {
            cin >> store;
            for (int i = 0; i < store.size(); i++)
            {
                shot_2[i].push_back(store[i]);
            }
        }
        unordered_map<string, bool> dict;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < shot_1.size(); j++)
            {
                for (int k = 0; k < shot_2.size(); k++)
                {
                    if (shot_1[i][j] == shot_2[i][k] && dict.count(to_string(i) + " " + shot_1[i][j]) == 0)
                    {
                        shot_3[i].push_back(shot_1[i][j]);
                        dict[to_string(i) + " " + shot_1[i][j]] = true;
                        break;
                    }
                }
            }
        }
        sort(shot_3[0].begin(), shot_3[0].end());
        sort(shot_3[1].begin(), shot_3[1].end());
        sort(shot_3[2].begin(), shot_3[2].end());
        sort(shot_3[3].begin(), shot_3[3].end());
        sort(shot_3[4].begin(), shot_3[4].end());
        int size = 1;
        for (int i = 0; i < shot_3.size(); i++)
            if (shot_3[i].size() != 0)
                size *= shot_3[i].size();

        int depth = 0;

        if (size < k)
        {
            cout << "NO\n";
            continue;
        }
        recurse(shot_3, "", 0, depth, k);
        if (res == "")
        {
            cout << "NO\n";
        }
        else
        {
            cout << res << "\n";
            res = "";
        }
    }
}