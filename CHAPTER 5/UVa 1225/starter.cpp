#include <bits/stdc++.h>
using namespace std;

void count(vector<int> &arr, int num)
{
    while (num != 0)
    {
        int rem = num % 10;
        arr[rem] += 1;
        num = (num / 10);
    }
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
        int N;
        cin >> N;
        vector<int> arr = vector<int>(10, 0);
        int c = 1;
        while (c <= N)
        {

            count(arr, c);
            c++;
        }
        for (int i = 0; i < 10; i++)
        {
            cout << arr[i];
            if (i != 9)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}