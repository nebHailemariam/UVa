#include <bits/stdc++.h>
using namespace std;
int ceiling(vector<int> &nums, int l, int r, int k)
{
    if (nums[l] >= k)
        return l;
    if (nums[r] < k)
        return -1;
    int mid = l + (r - l) / 2;

    if (nums[mid] >= k)
        return ceiling(nums, l, mid, k);
    return ceiling(nums, mid + 1, r, k);
}

int floor(vector<int> &nums, int l, int r, int k)
{
    if (l > r)
        return -1;
    if (nums[l] > k)
        return -1;
    if (nums[r] <= k)
        return r;

    int mid = l + (r - l) / 2;
    if ((nums[mid] <= k) && (mid == nums.size() - 1 || nums[mid + 1] > k))
        return mid;
    if (nums[mid] <= k)
        return floor(nums, mid, r, k);
    return floor(nums, l, mid - 1, k);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    vector<int> nums;
    int count;
    int k;
    cin >> count >> k;
    while (count--)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    cout << "Ceiling: " << ceiling(nums, 0, nums.size() - 1, k) << "\n";
    cout << "Floor: " << floor(nums, 0, nums.size() - 1, k) << "\n";
}