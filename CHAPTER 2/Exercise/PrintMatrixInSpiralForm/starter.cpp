#include <bits/stdc++.h>
using namespace std;

void spiral_print(vector<vector<int>> arr, int i, int j, int i1, int i2, int j1, int j2)
{

    if (i == arr.size() / 2 && j == arr.size() / 2)
    {
        cout << arr[i][j] << " " << endl;
        return;
    }
    // cout << "\nI1:" << i1 << " I2:" << i2 << endl;

    for (int p = i1; p < i2; p++)
        cout << arr[i][p] << " ";

    // cout << endl;
    for (int p = j1 + 1; p < j2; p++)
        cout << arr[p][arr.size() - 1 - j] << " ";
    // cout << endl;
    // cout << "\nI2:" << i2 << " sI1:" << i1 << endl;
    for (int p = i2 - 2; p >= i1; p--)
        cout << arr[arr.size() - 1 - i][p] << " ";

    for (int p = j2 - 2; p > j1; p--)
        cout << arr[p][j] << " ";

    spiral_print(arr, i + 1, j + 1, i1 + 1, i2 - 1, j1 + 1, j2 - 1);
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> store;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        vector<int> hold;
        for (int j = 0; j < 5; j++)
        {
            hold.push_back(count++);
        }
        store.push_back(hold);
    }

    for (int i = 0; i < store.size(); i++)
    {
        for (int j = 0; j < store.size(); j++)
            cout << store[i][j] << " ";
        cout << endl;
    }

    spiral_print(store, 0, 0, 0, store.size(), 0, store.size());
    cout << endl;
    for (int i = 0; i < store.size(); i++)
    {
        for (int j = 0; j < store.size(); j++)
            cout << store[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
