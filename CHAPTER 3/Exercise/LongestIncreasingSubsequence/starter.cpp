#include <bits/stdc++.h>
using namespace std;


int ceiling(vector<int> &tail, int l, int r, int k)
{

    while (r - l > 1)
    {
        int mid = l + (r - l) / 2;
        if (k <= tail[mid])
            r = mid;
        else
            l = mid;
    }
    return r;
}

int lcs(vector<int> &nums)
{

    if (nums.size() == 1)
        return 1;

    vector<int> tail = vector<int>(nums.size(), 0);
    int length = 1;
    tail[0] = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < tail[0])
            tail[0] = nums[i];
        else if (nums[i] > tail[length - 1])
        {
            tail[length] = nums[i];
            length++;
        }
        else
        {
            tail[ceiling(tail, -1, length - 1, nums[i])] = nums[i];
        }
    }
    return length;
}

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
        int count;
        vector<int> nums;
        cin >> count;
        while (count--)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        cout << lcs(nums) << "\n";
    }
}