#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int store = 0;
    cin >> store;

    vector<vector<int>> array;
    int count_row = store;

    while (count_row--)
    {
        vector<int> temp;
        int num;
        for (int i = 0; i < store; i++)
        {
            cin >> num;
            temp.push_back(num);
        }
        array.push_back(temp);
    }

    for (int i = 0; i < store / 2; i++)
    {
        for (int j = i; j < array.size() - 1 - i; j++)
        {
            int hold = array[i][j];
            array[i][j] = array[j][array.size() - 1 - i];
            array[j][array.size() - 1 - i] = array[array.size() - 1 - i][array.size() - 1 - j];
            array[array.size() - 1 - i][array.size() - 1 - j] = array[array.size() - 1 - j][i];
            array[array.size() - 1 - j][i] = hold;
        }
    }
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size(); j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}