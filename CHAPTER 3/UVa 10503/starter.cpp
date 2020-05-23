#include <bits/stdc++.h>
using namespace std;



bool recurse(int first, vector<pair<int, int>> &store, pair<int, int> &last, int n)
{
    if (n == 0)
        return (first == last.first) ? true : false;
    bool res = false;
    for (int i = 0; i < store.size() && !res; i++)
    {
        if (store[i].first == first)
        {

            int temp_first = store[i].second;
            pair<int, int> temp_val = store[i];
            store[i] = pair<int, int>(INT_MAX, INT_MAX);
            res = recurse(temp_first, store, last, n - 1);
            store[i] = temp_val;
        }
        else if (store[i].second == first)
        {
            int temp_first = store[i].first;
            pair<int, int> temp_val = store[i];
            store[i] = pair<int, int>(INT_MAX, INT_MAX);
            res = recurse(temp_first, store, last, n - 1);
            store[i] = temp_val;
        }
    }
    return res;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin >> m;
        pair<int, int> first;
        pair<int, int> last;
        vector<pair<int, int>> store;
        int temp_1, temp_2;
        cin >> temp_1 >> temp_2;
        first.first = temp_1;
        first.second = temp_2;
        cin >> temp_1 >> temp_2;
        last.first = temp_1;
        last.second = temp_2;
        while (m--)
        {
            cin >> temp_1 >> temp_2;
            store.push_back(pair<int, int>(temp_1, temp_2));
        }
        vector<pair<int, int>> ans = {first};
        (recurse(first.second, store, last, n)) ? cout << "YES\n" : cout << "NO\n";
    }
}