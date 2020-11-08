#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, k;

    while (cin >> n >> k)
    {
        int count = 0;
        while (n)
        {
            int i = 0;
            for (i = 0; i * k <= n; i++)
                continue;

            count += (i - 1) * k;
            n = (n - ((i - 1) * k)) + n / k;
            if (n < k)
            {
                count += n;
                break;
            }
        }
        cout << count << "\n";
    }
}