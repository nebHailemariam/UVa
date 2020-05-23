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
    cin >> count;
    while (count != 0)
    {
        priority_queue<int> store;

        int sum = 0;
        int val = 0;
        while (count--)
        {
            int num;
            cin >> num;
            store.push(-num);
        }
        bool first = true;
        while (store.size() > 1)
        {
            int x = -store.top();
            store.pop();
            int y = -store.top();
            store.pop();
            val = val + x + y;
            sum = x + y;

            store.push(-sum);
            first = false;
        }
        cout << val << "\n";
        cin >> count;
    }
}