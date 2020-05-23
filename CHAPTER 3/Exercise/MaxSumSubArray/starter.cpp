#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int count;
    cin >> count;
    vector<int> store;
    while (count--)
    {
        int num;
        cin >> num;
        store.push_back(num);
    }

    int max_val = 0;
    int start = 0, end = 0, s = 0;
    int max_so_far = 0;

    int i = 0;

    while (i < store.size())
    {
        max_so_far += store[i];
        if (max_so_far < 0)
        {
            max_so_far = 0;
            s = i + 1;
        }
        if (max_so_far > max_val)
        {
            max_val = max_so_far;
            start = s;
            end = i;
        }

        i++;
    }
    cout << "max val = " << max_val << " : start-end : " << start << "-" << end;
}