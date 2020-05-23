#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int N;

    while (cin >> N && N != 0)
    {
        vector<int> store;
        int sum = 0;

        while (N--)
        {
            int temp;
            cin >> temp;
            sum += temp;
            if (temp != 0)
                store.push_back(temp);
        }
        if (sum == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        for (int i = 0; i < store.size(); i++)
            if (store[i] != 0)
            {

                (i < store.size() - 1) ? cout << store[i] << " " : cout << store[i] << "\n";
            }
    }
}