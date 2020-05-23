#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (true)
    {
        long long N, M;
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;
        set<int> store;

        while (N--)
        {
            long long val;
            cin >> val;
            store.insert(val);
        }
        int common = 0;
        while (M--)
        {
            long long val;
            cin >> val;
            if (store.find(val) != store.end())
                common++;
        }
        cout << common << "\n";
    }
}