#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int count;

    while (cin >> count)
    {
        int num;
        vector<int> store;
        vector<bool> check(count - 1, false);
        while (count--)
        {
            cin >> num;
            store.push_back(num);
        }

        bool is = true;
        ;
        for (int i = 1; i < store.size(); i++)
        {
            if (abs(store[i] - store[i - 1]) - 1 < check.size() && abs(store[i] - store[i - 1]) - 1 >= 0)
            {
                check[abs(store[i] - store[i - 1]) - 1] = true;
            }
        }

        for (int i = 0; i < check.size(); i++)
        {
            if (check[i] == false)
            {
                is = false;
                break;
            }
        }
        if (is || store.size() == 1)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}