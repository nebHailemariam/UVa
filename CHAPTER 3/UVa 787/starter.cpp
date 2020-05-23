#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    vector<int> store;
    int num;
    while (cin >> num)
    {
        if (num == -999999)
        {
            long res = INT_MIN;
            for (int i = 0; i < store.size(); i++)
            {
                long temp = 1;
                for (int j = i; j < store.size(); j++)
                {
                    temp *= store[j];
                    if (temp > res)
                        res = temp;
                }
            }
            cout << res << "\n";
            store.clear();
        }
        else
            store.push_back(num);
    }
}