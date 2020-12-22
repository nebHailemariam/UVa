#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> store = vector<pair<int, int>>(pow(10, 7), pair<int, int>(1, 1));

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int i = 1;
    int flag = 0;
    int num;
    int n, d;

    n = store[i].first;
    d = store[i].second;

    while (cin >> num)
    {

        if (num < i)
        {
            cout << "TERM " << num << " IS " << store[num - 1].first << "/" << store[num - 1].second << "\n";
        }
        else
        {

            while (i <= num)
            {
                if (n == 1)
                {
                    d++;
                    flag = 0;
                    store[i].first = n;
                    store[i].second = d;
                    i++;
                }
                else if (d == 1)
                {
                    n++;
                    flag = 1;
                    store[i].first = n;
                    store[i].second = d;
                    i++;
                }
                if (flag == 1)
                {
                    n--;
                    d++;
                }
                else if (flag == 0)
                {
                    n++;
                    d--;
                }
                store[i].first = n;
                store[i].second = d;

                i++;
            }
            cout << "TERM " << num << " IS " << store[num - 1].first << "/" << store[num - 1].second << "\n";
        }
    }
}