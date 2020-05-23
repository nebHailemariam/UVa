#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string store = "";
    while (getline(cin, store))
    {
        stringstream ss(store);
        string word = "";
        while (ss >> word)
        {
            cout << word;
        }
    }

    //

    //with space;
    // string store = "";
    // while (cin >> store)
    // {
    //     cout << store << endl;
    // }
}