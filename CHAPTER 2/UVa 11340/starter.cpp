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
    getline(cin, store);
    int count = stoi(store);
    while (count--)
    {
        getline(cin, store);
        int k = stoi(store);
        unordered_map<string, double> dict;

        while (k--)
        {
            getline(cin, store);
            stringstream ss(store);
            string character;
            double val;
            ss >> character;
            ss >> val;
            dict[character] = val;
        }
        long long result = 0;
        getline(cin, store);
        k = stoi(store);
        while (k--)
        {
            getline(cin, store);
            for (int i = 0; i < store.size(); i++)
            {
                string temp = "";
                temp += store[i];
                result = result + dict[temp];
            }
        }

        printf("%lld.%02lld$\n", result / 100, result % 100);
    }
}