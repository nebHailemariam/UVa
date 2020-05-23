#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test_cases = 0;
    int cases = 1;
    cin >> test_cases;

    while (test_cases--)
    {
        vector<int> length, width;
        int count;
        cin >> count;
        int count_hold = count;
        while (count--)
        {
            int num;
            cin >> num;
            length.push_back(num);
        }
        count = count_hold;
        while (count--)
        {
            int num;
            cin >> num;
            width.push_back(num);
        }

        vector<int> lcs = width;
        vector<int> lds = width;
        for (int i = 0; i < length.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (length[j] < length[i])
                    lcs[i] = max(width[i] + lcs[j], lcs[i]);
                if (length[j] > length[i])
                    lds[i] = max(width[i] + lds[j], lds[i]);
            }
        }
        int max_lcs = 0;
        int max_lds = 0;
        for (int i = 0; i < length.size(); i++)
        {
            max_lcs = max(max_lcs, lcs[i]);
            max_lds = max(max_lds, lds[i]);
        }
        (max_lcs >= max_lds) ? cout << "Case " << cases << ". Increasing (" << max_lcs << "). "
                                    << "Decreasing (" << max_lds << ").\n"
                             : cout << "Case " << cases << ". Decreasing (" << max_lds << "). "
                                    << "Increasing (" << max_lcs << ").\n";
        cases++;
    }
}