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
    set<pair<int, int>> argus;
    map<int, int> P;
    while (getline(cin, store) && store != "#")
    {
        stringstream ss(store);
        int Q_num, period;
        ss >> store;
        ss >> store;
        Q_num = stoi(store);
        ss >> store;
        period = stoi(store);
        argus.insert({period, Q_num});
        P.insert({Q_num, period});
    }
    int k;
    cin >> k;

    while (k--)
    {
        auto q = argus.begin();
        cout << q->second << "\n";
        argus.erase(q);
        argus.insert({(q->first + P[q->second]), q->second});
        for (auto i = argus.begin(); i != argus.end(); i++)
        {
            // cout << i->first << " " << i->second << " ";
        }
        // cout << "\n";
    }
}