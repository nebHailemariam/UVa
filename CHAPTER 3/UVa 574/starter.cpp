#include <bits/stdc++.h>
using namespace std;


void recurse(vector<int> nums, int num, int i, vector<int> store, map<vector<int>, bool> &dict)
{
    // cout << store << "\n";
    if (i == nums.size())
    {
        if (num == 0)
        {
            if (dict.count(store) == 0)
            {
                dict[store] = true;
            }
        }
    }
    else if (num == 0)
    {
        if (dict.count(store) == 0)
        {
            // cout << store << "\n";
            dict[store] = true;
        }
    }
    else if (nums[i] <= num)
    {
        vector<int> temp = store;
        temp.push_back(nums[i]);
        recurse(nums, num - nums[i], i + 1, temp, dict);
        recurse(nums, num, i + 1, store, dict);
    }
    else
    {
        recurse(nums, num, i + 1, store, dict);
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int num, n;
    while (cin >> num >> n)
    {
        if (n == 0 && num == 0)
            break;

        vector<int> nums;
        map<vector<int>, bool> dict;
        while (n--)
        {
            int temp;
            cin >> temp;
            nums.push_back(temp);
        }
        recurse(nums, num, 0, vector<int>(), dict);
        cout << "Sums of " << num << ":\n";
        for (auto i = dict.rbegin(); i != dict.rend(); i++)
        {
            vector<int> temp = i->first;
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i];

                if (i < temp.size() - 1)
                    cout << "+";
            }
            cout << "\n";
        }
        if (dict.size() == 0)
            cout << "NONE\n";
    }
}