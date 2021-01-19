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

    while (cin >> store && store != "0")
    {
        int num = 0;
        for (int i = 0; i < store.size(); i++)
        {
            num += ((int)store[i] - 48) * (pow(2, store.size() - i) - 1);
        }
        cout << num << "\n";
    }
}