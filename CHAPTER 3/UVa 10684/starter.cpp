#include <bits/stdc++.h>
using namespace std;


int kadane(vector<int> &bets)
{

    int max_so_far = 0;
    int max_val = 0;

    for (int i = 0; i < bets.size(); i++)
    {
        max_val += bets[i];
        if (max_val < 0)
        {
            max_val = 0;
        }
        if (max_so_far < max_val)
        {
            max_so_far = max_val;
        }
    }
    return max_so_far;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int count;
    while (cin >> count)
    {
        if (count == 0)
            break;
        vector<int> bets;
        while (count--)
        {
            int temp;
            cin >> temp;
            bets.push_back(temp);
        }
        int streak = kadane(bets);
        (streak != 0) ? cout << "The maximum winning streak is " << streak << ".\n" : cout << "Losing streak.\n";
    }
}