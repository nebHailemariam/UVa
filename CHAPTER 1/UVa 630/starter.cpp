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
    int count = stoi(store);
    getline(cin, store);
    int count_top = count;
    int count_bottom = 1;
    while (count--)
    {

        getline(cin, store);
        int count_dict = stoi(store);
        unordered_map<string, vector<string>> dict;
        while (count_dict--)
        {
            getline(cin, store);
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
                // sort(dict[store].begin(), dict[store].end());
            }
        }
        vector<string> keys;
        while (getline(cin, store) && store != "END")
        {
            keys.push_back(store);
        }
        getline(cin, store);
        for (int i = 0; i < keys.size(); i++)
        {
            string word = keys[i];
            cout << "Anagrams for: " << word << "\n";
            sort(keys[i].begin(), keys[i].end());

            if (dict[keys[i]].size() == 0)
            {
                cout << "No anagrams for: " << word << "\n";
            }
            else
            {
                for (int j = 0; j < dict[keys[i]].size(); j++)
                {
                    cout << "  " << j + 1 << ") " << dict[keys[i]][j] << "\n";
                }
            }
        }
        if (count_bottom != count_top)
            cout << "\n";
        count_bottom++;
    }
}