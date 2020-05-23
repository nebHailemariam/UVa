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
    for (int i = 0; i < store.size(); i++)
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
void max_subarray_sum(vector<vector<int>> &store)
{

    int max_rect_sum = 0;
    int max_rec_Left = 0;
    int max_rec_Right = 0;
    int max_rec_Top = 0;
    int max_rec_Bottom = 0;
    for (int L = 0; L < store[0].size(); L++)
    {
        vector<int> temp = vector<int>(store.size(), 0);
        for (int R = L; R < store[0].size(); R++)
        {
            for (int i = 0; i < temp.size(); i++)
            {
                temp[i] += store[i][R];
            }

            int Top, Bottom;
            int sum = kadane(temp, Top, Bottom);
            if (sum > max_rect_sum)
            {
                max_rect_sum = sum;
                max_rec_Left = L;
                max_rec_Right = R;
                max_rec_Top = Top;
                max_rec_Bottom = Bottom;
            }
        }
    }
    cout << "(Left, Right) (" << max_rec_Left
         << ", " << max_rec_Right << ")" << endl;
    cout << "(Top, Bottom) (" << max_rec_Top
         << ", " << max_rec_Bottom << ")" << endl;
    cout << "Max sum is: " << max_rect_sum << endl;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> arr = {{6, -5, -7, 4, -4},
                               {-9, 3, -6, 5, 2},
                               {-10, 4, 7, -6, 3},
                               {-8, 9, -3, 3, -7}};
    max_subarray_sum(arr);
}