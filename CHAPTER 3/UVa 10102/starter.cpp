#include <bits/stdc++.h>
using namespace std;


int abs(int a)
{
    return (a > 0) ? a : -a;
}
int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int M;

    while (cin >> M)
    {

        vector<pair<int, int>> ones;
        vector<pair<int, int>> threes;
        for (int i = 0; i < M; i++)
        {
            string temp;
            cin >> temp;
            for (int j = 0; j < M; j++)
            {

                if ((int)temp[j] - 48 == 1)
                    ones.push_back(pair<int, int>(i, j));
                else if ((int)temp[j] - 48 == 3)
                    threes.push_back(pair<int, int>(i, j));
            }
        }
        int steps = INT_MIN;
        for (auto one = ones.begin(); one != ones.end(); one++)
        {
            int steps_min = INT_MAX;
            for (auto three = threes.begin(); three != threes.end(); three++)
            {
                steps_min = min(steps_min, abs(one->first - three->first) + abs(one->second - three->second));
            }
            steps = max(steps, steps_min);
        }
        cout << steps << "\n";
    }
}