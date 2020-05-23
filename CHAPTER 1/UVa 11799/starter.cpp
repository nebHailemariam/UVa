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
    int i;

    string store;
    getline(cin, store);
    count = stoi(store);
    i = count;
    while (count--)
    {
        getline(cin, store);
        stringstream ss(store);
        string num;
        int max_num = INT_MIN;
        while (ss >> num)
        {
            max_num = max(stoi(num), max_num);
        }
        cout << "Case " << i - count << ": " << max_num << endl;
    }
}