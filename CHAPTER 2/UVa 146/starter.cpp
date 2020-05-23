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
    while (getline(cin, store) && store != "#")
    {
        string per = store;
        int count = 0;
        do
        {
            if (count == 1)
            {

                break;
            }
            count++;
        } while (next_permutation(per.begin(), per.end()));
        sort(store.begin(), store.end());
        if (per == store)

        {
            cout << "No Successor\n";
        }
        else
            cout << per << "\n";
    }
}