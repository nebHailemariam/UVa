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
    while (count--)
    {

        vector<pair<string, pair<int, int>>> price;
        int mf;
        cin >> mf;

        while (mf--)
        {

            string name;
            int lp, hp;
            cin >> name >> lp >> hp;
            price.push_back(pair<string, pair<int, int>>(name, pair<int, int>(lp, hp)));
        }
        int q;
        cin >> q;

        while (q--)
        {
            int query;
            cin >> query;
            int check = 0;
            string name = "";

            for (int i = 0; i < price.size(); i++)
            {
                if (price[i].second.first <= query && query <= price[i].second.second)
                {
                    check++;
                    name = price[i].first;
                }
            }
            (check == 1) ? cout << name << "\n" : cout << "UNDETERMINED\n";
        }
        (count == 0) ? cout << "" : cout << "\n";
    }
}