#include <bits/stdc++.h>
using namespace std;

vector<int> store = vector<int>(500001, 0);

void compute()
{
    store[1] = 1;
    store[2] = 2;

    int prev = 2;
    for (int i = 3; i < store.size(); i++)
    {
        if (i < prev)
            prev = 2;
        store[i] = prev;
        prev += 2;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;
    compute();
    while (cin >> n && n != 0)
    {
        cout << store[n] << "\n";
    }
}