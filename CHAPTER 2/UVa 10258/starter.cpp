#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if (a[1] > b[1])
    {
        return true;
    }
    else if (a[1] < b[1])
    {
        return false;
    }
    else
    {
        if (a[2] < b[2])
        {
            return true;
        }
        else if (a[2] > b[2])
        {
            return false;
        }
        else
        {
            if (a[0] < b[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int count = 0;
    string store;
    getline(cin, store);
    count = stoi(store);
    int count_temp = 0;
    while (count--)
    {
        if (count_temp == 0)
        {
            getline(cin, store);
            count_temp++;
        }

        int people[101][11][2];
        map<int, vector<int>> people_score;
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    people[i][j][k] = INT_MAX;
                }
            }
        }
        while (getline(cin, store) && store != "")
        {
            int per_id, pro_id, pro_time;
            char pro_status;
            stringstream ss(store);
            ss >> per_id;
            ss >> pro_id;
            ss >> pro_time;
            ss >> pro_status;
            if (pro_status == 'I' && people[per_id][pro_id][1] == INT_MAX && people[per_id][pro_id][0] == INT_MAX)
                people[per_id][pro_id][1] = 1;
            else if (pro_status == 'I' && people[per_id][pro_id][1] != INT_MAX && people[per_id][pro_id][0] == INT_MAX)
                people[per_id][pro_id][1] += 1;
            else if (pro_status == 'C')
            {

                // cout << "Time: " << people[per_id][pro_id][0] << " " << per_id << " " << pro_id << " " << pro_time << "\n";
                people[per_id][pro_id][0] = min(people[per_id][pro_id][0], pro_time);
            }
            else if ((pro_status == 'R' || pro_status == 'U' || pro_status == 'E') && people[per_id][pro_id][1] == INT_MAX && people[per_id][pro_id][0] == INT_MAX)
            {
                people[per_id][pro_id][1] = 0;
            }
        }
        for (int i = 1; i < 101; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                if (people[i][j][0] != INT_MAX)
                {
                    if (people[i][j][1] == INT_MAX)
                    {
                        if (people_score[i].size() == 0)
                        {
                            vector<int> temp = {1, people[i][j][0]};
                            people_score[i] = temp;
                        }
                        else
                        {
                            people_score[i][0] += 1;
                            people_score[i][1] += people[i][j][0];
                        }
                    }
                    else
                    {
                        if (people_score[i].size() == 0)
                        {
                            vector<int> temp = {1, people[i][j][0] + 20 * people[i][j][1]};
                            people_score[i] = temp;
                        }
                        else
                        {
                            people_score[i][0] += 1;
                            people_score[i][1] += people[i][j][0] + 20 * people[i][j][1];
                        }
                    }
                }
                else
                {
                    if (people[i][j][1] != INT_MAX)
                    {
                        if (people_score[i].size() == 0)
                        {
                            vector<int> temp = {0, 0};
                            people_score[i] = temp;
                        }
                    }
                }
            }
        }
        vector<vector<int>> proccesed;
        for (auto it = people_score.begin(); it != people_score.end(); it++)
        {
            vector<int> hold;
            hold.push_back(it->first);
            hold.push_back(it->second[0]);
            hold.push_back(it->second[1]);
            proccesed.push_back(hold);
        }
        sort(proccesed.begin(), proccesed.end(), comp);

        for (int i = 0; i < proccesed.size(); i++)
        {
            cout << proccesed[i][0] << " " << proccesed[i][1] << " " << proccesed[i][2] << "\n";
        }
        if (count != 0)
        {
            cout << "\n";
        }
    }
}