#include <bits/stdc++.h>
using namespace std;


int kadane(vector<int> store, int &start, int &end)
{
    int max_val = 0;
    start = 0, end = 0;
    int s = 0;
    int max_so_far = 0;
    bool flag_pos = false;

    int i = 0;

    while (i < store.size())
    {
        max_so_far += store[i];
        if (max_so_far < 0)
        {
            max_so_far = 0;
            s = i + 1;
        }
        if (max_so_far > max_val)
        {
            max_val = max_so_far;
            start = s;
            end = i;
            flag_pos = true;
        }

        i++;
    }
    if (flag_pos)
        return max_val;
    max_val = store[0];
    start = 0;
    end = 0;
    for (int i = 1; i < store.size(); i++)
    {
        if (store[i] > max_val)
        {
            start = i;
            end = i;
            max_val = store[i];
        }
    }
    return max_val;
}
int max_subarray_sum(vector<vector<int>> &store)
{

    int max_rect_sum = INT_MIN;
    for (int L = 0; L < store[0].size(); L++)
    {
        vector<int> temp = vector<int>(store.size(), 0);
        for (int R = L; R < store[0].size(); R++)
        {
            for (int i = 0; i < temp.size(); i++)
                temp[i] += store[i][R];

            int Top, Bottom;
            int sum = kadane(temp, Top, Bottom);
            if (sum > max_rect_sum)
            {
                max_rect_sum = sum;
            }
        }
    }
    return max_rect_sum;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int N;
    while (cin >> N)
    {
        vector<vector<int>> store(N, vector<int>(N, 0));

        for (int i = 0; i < store.size(); i++)
        {
            for (int j = 0; j < store.size(); j++)
            {
                int temp;
                cin >> temp;
                store[i][j] = temp;
            }
        }
        cout << max_subarray_sum(store) << "\n";
    }
}