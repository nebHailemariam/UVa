#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long count;
    cin >> count;
    while (count)
    {
        multiset<long long> store;
        long long paid = 0;
        while (count--)
        {
            long long num;
            cin >> num;
            while (num--)
            {
                long long a;
                cin >> a;
                store.insert(a);
            }

            long long min = *store.begin();
            long long max = *store.rbegin();
            store.erase(store.equal_range(min).first);
            store.erase(store.equal_range(max).first);
            paid += max - min;
        }
        cout << paid << "\n";
        cin >> count;
    }
}