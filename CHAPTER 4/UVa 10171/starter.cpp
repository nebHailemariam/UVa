#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;

    while (cin >> n && n != 0)
    {

        vector<vector<int>> ADJ_MAT_Y = vector<vector<int>>(26, vector<int>(26, INT_MAX));
        vector<vector<int>> ADJ_MAT_M = vector<vector<int>>(26, vector<int>(26, INT_MAX));

        int N = n;
        while (n--)
        {
            char Y_M, U_B, X, Y;
            int E;
            cin >> Y_M >> U_B >> X >> Y >> E;

            if (Y_M == 'Y')
            {
                if (U_B == 'B')
                {
                    ADJ_MAT_Y[(int)X - 65][(int)Y - 65] = E;
                    ADJ_MAT_Y[(int)Y - 65][(int)X - 65] = E;
                }
                else
                {
                    ADJ_MAT_Y[(int)X - 65][(int)Y - 65] = E;
                }
            }
            else
            {
                if (U_B == 'B')
                {
                    ADJ_MAT_M[(int)X - 65][(int)Y - 65] = E;
                    ADJ_MAT_M[(int)Y - 65][(int)X - 65] = E;
                }
                else
                {
                    ADJ_MAT_M[(int)X - 65][(int)Y - 65] = E;
                }
            }
        }

        char me_, pro_;
        cin >> me_ >> pro_;

        int me, pro;
        me = (int)me_ - 65;
        pro = (int)pro_ - 65;
        ADJ_MAT_Y[me][me] = 0;
        ADJ_MAT_M[pro][pro] = 0;
        for (int k = 0; k < ADJ_MAT_Y.size(); k++)
        {
            for (int i = 0; i < ADJ_MAT_Y.size(); i++)
            {
                for (int j = 0; j < ADJ_MAT_Y.size(); j++)
                {
                    if (ADJ_MAT_Y[i][k] != INT_MAX && ADJ_MAT_Y[k][j] != INT_MAX)
                        ADJ_MAT_Y[i][j] = min(ADJ_MAT_Y[i][j], ADJ_MAT_Y[i][k] + ADJ_MAT_Y[k][j]);
                }
            }
        }

        for (int k = 0; k < ADJ_MAT_M.size(); k++)
        {
            for (int i = 0; i < ADJ_MAT_M.size(); i++)
            {
                for (int j = 0; j < ADJ_MAT_M.size(); j++)
                {
                    if (ADJ_MAT_M[i][k] != INT_MAX && ADJ_MAT_M[k][j] != INT_MAX)
                        ADJ_MAT_M[i][j] = min(ADJ_MAT_M[i][j], ADJ_MAT_M[i][k] + ADJ_MAT_M[k][j]);
                }
            }
        }
        int min_dist = INT_MAX;
        vector<char> dest;
        for (int i = 0; i < ADJ_MAT_Y.size(); i++)
        {

            if (ADJ_MAT_Y[me][i] != INT_MAX && ADJ_MAT_M[pro][i] != INT_MAX && ADJ_MAT_Y[me][i] + ADJ_MAT_M[pro][i] <= min_dist)
            {
                min_dist = ADJ_MAT_Y[me][i] + ADJ_MAT_M[pro][i];
            }
        }
        for (int i = 0; i < ADJ_MAT_Y.size(); i++)
        {

            if (ADJ_MAT_Y[me][i] != INT_MAX && ADJ_MAT_M[pro][i] != INT_MAX && ADJ_MAT_Y[me][i] + ADJ_MAT_M[pro][i] == min_dist)
            {
                dest.push_back((char)i + 65);
            }
        }
        if (min_dist != INT_MAX)
        {
            cout << min_dist;

            for (int i = 0; i < dest.size(); i++)
            {
                cout << " " << dest[i];
            }
            cout << "\n";
        }
        else
            cout << "You will never meet.\n";
    }
}