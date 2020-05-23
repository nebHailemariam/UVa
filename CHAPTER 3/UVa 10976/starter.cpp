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
    double num;
    while (getline(cin, store))
    {
        num = stoi(store);
        vector<pair<long long, long long>> res;
        long long x;
        x = 2 * num;
        while (x > 0)
        {
            long long y = (num * x) / (x - num);
            if (y >= x && num * (y + x) == y * x)
                res.push_back(pair<long long, long long>(y, x));
            x--;
        }
        cout << res.size() << "\n";
        for (auto i = res.rbegin(); i != res.rend(); i++)
        {
            cout << "1/" << num << " = "
                 << "1/" << i->first << " + 1/" << i->second << "\n";
        }
    }
}