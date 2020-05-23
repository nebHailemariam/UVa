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
    string store = "";

    getline(cin, store);
    count = stoi(store);
    int count_temp = 0;
    while (count--)
    {
        if (count_temp == 0)
        {
            getline(cin, store);
            count_temp++;
        }
        int total = 0;
        map<string, double> dict_store;
        while (getline(cin, store) && store != "")
        {
            if (dict_store.count(store) == 0)
            {
                dict_store[store] = 1;
            }
            else
            {
                dict_store[store]++;
            }

            total++;
        }
        for (map<string, double>::iterator i = dict_store.begin(); i != dict_store.end(); i++)
        {
            cout << i->first << " " << fixed << setprecision(4) << ((i->second) * 100) / total << "\n";
        }
        if (count != 0)
            cout << "\n";
    }
}