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
    unordered_map<string, vector<string>> dict;
    vector<string> key;
    while (getline(cin, store) && store != "#")
    {
        stringstream ss(store);
        string word = "";
        while (ss >> word)
        {
            string word_hold = word;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            string hold = word_hold;
            sort(word.begin(), word.end());

            if (dict[word].size() == 0)

            {
                vector<string> temp(1, hold);
                dict[word] = temp;
                key.push_back(word);
            }
            else
                dict[word].push_back(hold);
        }
    }

    vector<string> result;
    for (int i = 0; i < key.size(); i++)
    {
        if (dict[key[i]].size() == 1)
            result.push_back(dict[key[i]][0]);
    }
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }
}