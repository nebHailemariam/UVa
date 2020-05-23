#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        int num;
        vector<int> nums;
        cin >> num;
        int count;
        cin >> count;
        while (count--)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        int flag = 0;
        bool yes = false;
        while (flag <= (1 << nums.size()))
        {

            int i = 1;
            int sum = 0;
            while (i <= flag)
            {
                if (flag & i)
                {
                    sum += nums[nums.size() - (log(i) / log(2)) - 1];
                }
                i = i << 1;
            }

            if (sum == num)
            {
                yes = true;
                break;
            }

            flag++;
        }
        (yes) ? cout << "YES\n" : cout << "NO\n";
    }
}