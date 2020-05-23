#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int store, count;

    cin >> count;
    while (count--)
    {
        map<int, int> dict_store;
        int in = 1;

        cin >> store;
        int index_start = 0;
        int index_end = 0;
        int max_val = 0;
        int index = 0;
        int prev_rej = 0;
        // cout << "\n";
        while (store--)
        {
            int snow;
            cin >> snow;

            // cout << "index_start: " << index_start << " : index_end: " << index_end << "\n";
            if (dict_store.count(snow) > 0)
            {
                max_val = max(max_val, index_end - index_start);
                index_start = max(dict_store[snow], index_start);
                dict_store[snow] = index;
                index_end = index;
                index++;
            }
            else
            {
                dict_store[snow] = index;
                index_end++;
                index++;
            }
        }
        max_val = max(max_val, index_end - index_start);

        cout << max_val << "\n";
    }
}