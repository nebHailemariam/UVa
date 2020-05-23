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
    unordered_map<string, vector<string>> dict;

    while (getline(cin, store) && store != "XXXXXX")
    {
        string word = store;
        sort(store.begin(), store.end());
        if (dict[store].size() == 0)
        {
            vector<string> hold(1, word);
            dict[store] = hold;
        }
        else
        {
            dict[store].push_back(word);
            sort(dict[store].begin(), dict[store].end());
        }
    }

    while (getline(cin, store) && store != "XXXXXX")
    {
        sort(store.begin(), store.end());
        if (dict[store].size() == 0)
        {
            cout << "NOT A VALID WORD\n";
        }
        for (int i = 0; i < dict[store].size(); i++)
        {
            cout << dict[store][i] << "\n";
        }
        cout << "******\n";
    }
}