#include <bits/stdc++.h>
using namespace std;

vector<string> per;
unordered_map<string, bool> dict;

void permute(string store, int l, int r)
{
    if (l == r)
    {
        if (!dict[store])
        {
            per.push_back(store);
            dict[store] = true;
            return;
        }
        else
        {
            return;
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            char store_l = store[i];
            char store_r = store[l];
            string new_store = "";
            for (int n = 0; n < store.size(); n++)
            {
                if (n == i)
                {
                    new_store += store_r;
                }
                else if (n == l)
                {
                    new_store += store_l;
                }
                else
                {
                    new_store += store[n];
                }
            }

            permute(new_store, l + 1, r);
        }
    }
}

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
    while (count--)
    {
        getline(cin, store);
        permute(store, 0, store.size() - 1);
        sort(per.begin(), per.end());
        for (int i = 0; i < per.size(); i++)
            cout << per[i] << "\n";
        cout << "\n";
        per.clear();
    }
}