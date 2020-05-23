#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    while (cin >> m && m != 0)
    {
        vector<int> front, rear;
        cin >> n;
        while (m--)
        {
            int store;
            cin >> store;
            front.push_back(store);
        }
        while (n--)
        {
            int store;
            cin >> store;
            rear.push_back(store);
        }
        vector<double> store;
        for (int i = 0; i < front.size(); i++)
        {
            for (int j = 0; j < rear.size(); j++)
            {
                double temp = (double)rear[j] / (double)front[i];
                store.push_back(temp);
            }
        }
        double opt = INT_MIN;
        sort(store.begin(), store.end());

        for (int i = 0; i < store.size() - 1; i++)
            opt = max(store[i + 1] / store[i], opt);
        cout << fixed << setprecision(2) << opt << "\n";
    }
}