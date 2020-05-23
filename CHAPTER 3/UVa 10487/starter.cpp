#include <bits/stdc++.h>
using namespace std;

long long abs_fun(long long a)
{
    return (a < 0) ? -a : a;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    long long n;
    long long count = 1;
    while (cin >> n && n != 0)
    {
        vector<long long> nums;
        while (n--)
        {
            long long num;
            cin >> num;
            nums.push_back(num);
        }
        long long m;
        cin >> m;

        cout << "Case " << count << ":\n";
        while (m--)
        {
            long long q;
            cin >> q;
            long long close = INT_MAX;
            for (long long i = 0; i < nums.size(); i++)
            {
                for (long long j = i + 1; j < nums.size(); j++)
                {
                    if (abs_fun(close - q) > abs_fun(nums[i] + nums[j] - q))
                        close = nums[i] + nums[j];

                    if (close == q)
                        break;
                }
                if (close == q)
                    break;
            }
            cout << "Closest sum to " << q << " is " << close << ".\n";
        }
        count++;
    }
}