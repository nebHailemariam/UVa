#include <bits/stdc++.h>
using namespace std;


long long memo[205][205][15];

long long compute(vector<int> &nums, int i, int D, int M, int store)
{
    if (memo[i][store][M] != -1)
        return memo[i][store][M];
    if (M == 0)
    {
        if (store % D == 0)
        {
            return 1;
        }
        return 0;
    }
    if (i == nums.size())
        return 0;

    memo[i][store][M] = compute(nums, i + 1, D, M - 1, (store + nums[i]) % D) + compute(nums, i + 1, D, M, store);
    return memo[i][store][M];
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int N, Q;
    int cases = 1;
    while (cin >> N >> Q)
    {
        if (N == 0 && Q == 0)
            break;

        vector<int> nums;
        while (N--)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }

        int query = 1;
        cout << "SET " << cases << ":\n";
        while (Q--)
        {
            int D, M;
            cin >> D >> M;
            memset(memo, -1, sizeof(memo));
            // for (int i = 0; i < 205; i++)
            // {
            //     for (int j = 0; j < 205; j++)
            //     {
            //         for (int k = 0; k < 15; k++)
            //         {
            //             memo[i][j][k] = -1;
            //         }
            //     }
            // }
            cout << "QUERY " << query << ": " << compute(nums, 0, D, M, 0) << "\n";

            query++;
        }
        cases++;
    }
}