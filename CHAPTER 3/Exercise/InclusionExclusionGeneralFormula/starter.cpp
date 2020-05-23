#include <bits/stdc++.h>
using namespace std;
int compute(vector<int> selected, vector<vector<int>> &union_, vector<int> &value)
{
    int sum = 0;
    if (selected.size() != 1)
    {
        for (int b = 0; b < union_.size(); b++)
        {
            bool check = true;
            for (int a = 0; a < selected.size() && check; a++)
            {
                bool temp_check = false;
                for (int c = 0; c < union_[b].size() - 1; c++)
                {
                    if (selected[a] == union_[b][c])
                    {
                        temp_check = true;
                        break;
                    }
                }
                if (temp_check)
                    continue;
                else
                    check = false;
            }
            if (check)
            {
                if (selected.size() % 2 == 0)
                {
                    sum -= union_[b][union_[b].size() - 1];
                }
                else
                {
                    sum += union_[b][union_[b].size() - 1];
                }
            }
        }
    }
    else
        sum += value[selected[0] - 1];
    return sum;
}
int recurse(vector<int> store, vector<vector<int>> &union_, vector<int> &value)
{

    int sum = 0;
    int i = 1;

    while (i <= pow(2, store.size()) - 1)
    {
        vector<int> selected;
        int flag = 1;
        while (flag <= i)
        {
            if (flag & i)
                selected.push_back(store[store.size() - (log(flag) / log(2)) - 1]);

            flag = flag << 1;
        }
        for (int a = 0; a < selected.size(); a++)
            cout << selected[a] << " ";
        cout << ": ";
        i++;
        int temp_sum = 0;

        temp_sum += compute(selected, union_, value);
        cout << temp_sum << "\n";
        sum += temp_sum;
    }
    return sum;
}
int main()
{
    vector<int> set{1, 2, 3};
    vector<int> value{10, 10, 10};
    vector<vector<int>> union_{{1, 2, 3, 5}, {1, 3, 2}, {2, 3, 4}};

    cout << "The union of the set is " << recurse(set, union_, value) << "\n";
}