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

    while (getline(cin, store) && store != "")
    {
        stringstream ss(store);
        int n, m;
        ss >> store;
        n = stoi(store);
        ss >> store;
        m = stoi(store);
        getline(cin, store);
        stringstream ss1(store);
        unordered_map<int, vector<int>> ADJ_LST;
        int i = 1;
        while (i <= n)
        {
            ss1 >> store;
            if (ADJ_LST.count(stoi(store)) == 0)
            {
                ADJ_LST[stoi(store)] = vector<int>(1, i);
            }
            else
            {
                ADJ_LST[stoi(store)].push_back(i);
            }
            i++;
        }
        while (m--)
        {
            getline(cin, store);
            stringstream ss2(store);
            ss2 >> store;
            int pos = stoi(store);
            ss2 >> store;
            int num = stoi(store);

            (ADJ_LST[num].size() >= pos) ? cout << ADJ_LST[num][pos - 1] << "\n" : cout << "0\n";
        }
    }
}