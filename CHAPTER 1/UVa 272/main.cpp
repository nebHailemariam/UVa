#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

//    freopen("in.txt", "sr", stdin);

    string store = "";
    bool is_set = false;
    while (getline(cin, store))
    {
        string res = "";

        for (int i = 0; i < store.length(); i++)
        {
            if (store[i] == '\"')
            {
                if (!is_set)
                {
                    res += "``";
                    is_set = true;
                }
                else
                {
                    res += "\'\'";
                    is_set = false;
                }
            }
            else
            {
                res += store[i];
            }
        }
        cout << res << endl;
    }

    //

    //with space;
    // string store = "";
    // while (cin >> store)
    // {
    //     cout << store << endl;
    // }
}
