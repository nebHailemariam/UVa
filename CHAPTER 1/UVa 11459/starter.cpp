#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int count = 0;
    cin >> count;
    while (count--)
    {
        int a = 0;
        cin >> a;
        vector<int> players(a, 1);
        unordered_map<int, int> rule;
        int b = 0;
        cin >> b;
        int c = 0;
        cin >> c;
        while (b--)
        {
            int sm;
            int st;
            cin >> sm;
            cin >> st;
            rule[sm] = st;
        }
        int i = 0;
        int die = 0;
        while (c--)
        {

            cin >> die;
            if (players.size() > 0 && players[i] != 100)
            {
                if (rule[players[i] + die])
                {
                    players[i] = rule[players[i] + die];
                }
                else if (players[i] != 100)
                {
                    players[i] += die;
                    if (players[i] >= 100)
                    {
                        players[i] = 100;
                    }
                }
                if (players[i] == 100)
                {
                    i--;
                }
                i++;
                if (i == players.size())
                {
                    i = 0;
                }
            }
        }
        for (i = 0; i < players.size(); i++)
        {

            cout << "Position of player " << i + 1 << " is " << players[i] << ".\n";
        }
    }
}