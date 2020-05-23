#include <bits/stdc++.h>
using namespace std;


long reverse(long long num)
{
    long long store = 0;

    while (num > 0)
    {
        store = store * 10 + num % 10;
        num = num / 10;
    }
    return store;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t = 0;
    cin >> t;
    while (t--)
    {
        long long num;
        cin >> num;
        int count = 0;
        long long rev_num = reverse(num);
        while (num != rev_num || count == 0)
        {
            num = rev_num + num;
            rev_num = reverse(num);
            count++;
        }
        cout << count << " " << num << "\n";
    }
}