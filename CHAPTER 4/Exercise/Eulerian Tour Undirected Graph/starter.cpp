#include <bits/stdc++.h>
using namespace std;

void EulerianTour(int u, vector<vector<pair<int, bool>>> &ADJ_LST, vector<int> &tour)
{
    for (int i = 0; i < ADJ_LST[u].size(); i++)
    {
        pair<int, bool> v = ADJ_LST[u][i];

        if (v.second)
        {
            ADJ_LST[u][i].second = false;
            for (int j = 0; j < ADJ_LST[v.first].size(); j++)
            {
                if (ADJ_LST[v.first][j].first == u && ADJ_LST[v.first][j].second)
                {
                    ADJ_LST[v.first][j].second = false;
                    break;
                }
            }
            tour.push_back(v.first);
            EulerianTour(v.first, ADJ_LST, tour);
        }
    }
}

bool EulerianTourCheck(vector<vector<pair<int, bool>>> &ADJ_LST)
{
    for (int i = 0; i < ADJ_LST.size(); i++)
    {
        if (ADJ_LST[i].size() % 2 != 0)
            return false;
    }
    return true;
}

int main()
{
    vector<vector<pair<int, bool>>> ADJ_LST = {
        {pair<int, bool>(1, true), pair<int, bool>(2, true)},
        {pair<int, bool>(0, true), pair<int, bool>(2, true)},
        {pair<int, bool>(0, true), pair<int, bool>(1, true)}

    };
    if (!EulerianTourCheck(ADJ_LST))
    {
        cout << "Not possible.\n";
        return -1;
    }
    vector<int> tour = vector<int>(1, 0);
    EulerianTour(0, ADJ_LST, tour);

    for (int i = 0; i < tour.size() - 1; i++)
    {
        cout << tour[i] << " -> " << tour[i + 1] << "\n";
    }
}