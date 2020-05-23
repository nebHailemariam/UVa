#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int count;
    cin >> count;
    while (count--)
    {
        multiset<int> SG_Troop, SB_Troop;
        int B;
        int SG;
        int SB;
        cin >> B >> SG >> SB;
        while (SG--)
        {
            int t;
            cin >> t;
            SG_Troop.insert(t);
        }
        while (SB--)
        {
            int t;
            cin >> t;
            SB_Troop.insert(t);
        }
        while (SB_Troop.size() > 0 && SG_Troop.size() > 0)
        {
            int b = B;
            vector<int> war_result;
            while (b-- && SB_Troop.size() > 0 && SG_Troop.size() > 0)
            {
                int SG_top = *SG_Troop.rbegin();
                SG_Troop.erase(SG_Troop.equal_range(SG_top).first);
                int SB_top = *SB_Troop.rbegin();
                SB_Troop.erase(SB_Troop.equal_range(SB_top).first);
                int war = SG_top - SB_top;
                // cout << SG_top << " " << SB_top << "\n";
                if (war == 0)
                {
                    continue;
                }
                else if (war > 0)
                {
                    war_result.push_back(war);
                }
                else
                {
                    war_result.push_back(war);
                }
            }
            for (int i = 0; i < war_result.size(); i++)
            {
                if (war_result[i] > 0)
                {
                    SG_Troop.insert(war_result[i]);
                }
                else
                {
                    SB_Troop.insert(-war_result[i]);
                }
            }
        }

        // cout << SB_Troop.size() << ":" << SG_Troop.size() << "\n";
        if (SB_Troop.size() == SG_Troop.size())
        {
            cout << "green and blue died\n";
        }
        else if (SB_Troop.size() > SG_Troop.size())
        {
            cout << "blue wins\n";
            for (auto i = SB_Troop.rbegin(); i != SB_Troop.rend(); i++)
            {

                cout << *i << "\n";
            }
        }
        else
        {
            cout << "green wins\n";
            for (auto i = SG_Troop.rbegin(); i != SG_Troop.rend(); i++)
            {

                cout << *i << "\n";
            }
        }
        if (count != 0)
            cout << "\n";
    }
}