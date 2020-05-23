#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string store = "";
    getline(cin, store);
    int count = stoi(store);
    getline(cin, store);
    while (count--)
    {

        unordered_map<string, vector<string>> dict;
        vector<string> key;
        while (getline(cin, store) && store != "")
        {

            string word = store;
            store = "";
            for (int i = 0; i < word.size(); i++)
            {
                if (!isspace(word[i]))
                    store += word[i];
            }
            sort(store.begin(), store.end());
            if (dict[store].size() == 0)
            {
                vector<string> temp(1, word);
                dict[store] = temp;
                key.push_back(store);
            }
            else
            {
                dict[store].push_back(word);
                sort(dict[store].begin(), dict[store].end());
            }
        }
        vector<string> res;
        for (int i = 0; i < key.size(); i++)
        {
            if (dict[key[i]].size() > 1)
            {
                for (int j = 0; j < dict[key[i]].size(); j++)
                {
                    for (int k = j + 1; k <= dict[key[i]].size() - 1; k++)
                    {
                        res.push_back(dict[key[i]][j] + " = " + dict[key[i]][k]);
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << "\n";
        }
        if (count != 0)
            cout << "\n";
    }
}