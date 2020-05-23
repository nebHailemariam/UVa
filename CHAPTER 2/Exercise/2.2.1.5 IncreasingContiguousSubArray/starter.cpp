#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int in;
    vector<int> store;
    while (cin >> in)
    {
        store.push_back(in);
    }

    int max = 1;
    int count = 1;
    int store_index = 0;

    for (int i = 1; i < store.size(); i++)
    {
        if (store[i] > store[i - 1])
        {
            count++;
        }

        else
            count = 1;
        if (max < count)
        {
            max = count;
            store_index = i + 1 - max;
        }
    }
    if (max < count)
        max = count;
    cout << "MAX: " << max << " Index: " << store_index << "-" << store_index + max - 1;
}