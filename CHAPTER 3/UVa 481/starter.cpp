#include <bits/stdc++.h>
using namespace std;


int ceiling(vector<int> &nums, int l, int r, int k)
{
    if (nums[r] < k)
        return -1;
    if (nums[l] >= k)
        return l;
    int mid = l + (r - l) / 2;
    if (nums[mid] >= k)
        return ceiling(nums, l, mid, k);
    return ceiling(nums, mid + 1, r, k);
}

void LCS(vector<int> &nums)
{

    vector<int> tail = vector<int>(nums.size(), 0);
    int length = 1;
    tail[0] = nums[0];
    unordered_map<int, vector<int>> store;
    store[0] = vector<int>(1, nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < tail[0])
        {
            tail[0] = nums[i];
            store[0] = vector<int>(1, nums[i]);
        }
        else if (nums[i] > tail[length - 1])
        {
            tail[length] = nums[i];
            store[length] = store[length - 1];
            store[length].push_back(nums[i]);
            length++;
        }
        else
        {
            int index = ceiling(tail, 0, length - 1, nums[i]);
            tail[index] = nums[i];
            store[index] = store[index - 1];
            store[index].push_back(nums[i]);
        }
    }
    cout << length << "\n-\n";

    for (int i = 0; i < store[length - 1].size(); i++)
    {
        cout << store[length - 1][i] << "\n";
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    LCS(nums);
}