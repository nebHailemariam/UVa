#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    long long count = 0;
    cin >> count;
    while (count--)
    {
        long long pol;
        vector<long long> an;
        cin >> pol;
        pol++;
        while (pol--)
        {
            long long c;
            cin >> c;
            an.push_back(c);
            // cout << c << " ";
        }
        // cout << "\n";
        long long d, k;
        cin >> d >> k;
        // cout << d << " " << k << "\n";
        long long num = 0;
        long long n = 0;
        for (long long i = 1, cont = 1; cont <= k; i++)
        {
            long long temp = 0;
            for (long long j = 0; j < an.size(); j++)
            {
                temp += pow(i, j) * an[j];
            }
            cont += d * i;
            num = temp;
        }
        cout << num << "\n";
    }
}