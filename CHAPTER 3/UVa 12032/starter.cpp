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
    cin >> test_cases;
    int cases = 1;

    while (test_cases--)
    {
        vector<int> lader;
        int l;
        cin >> l;
        while (l--)
        {
            int temp;
            cin >> temp;
            lader.push_back(temp);
        }
        int k_max = pow(10, 7);
        int k_min = 1;
        int k_mid;
        while (true)
        {
            bool set = false;
            k_mid = (k_max + k_min) / 2;
            int k_temp = k_mid;
            int ground = 0;
            for (int i = 0; i < lader.size(); i++)
            {
                if (lader[i] - ground < k_temp)
                {
                }
                else if (lader[i] - ground == k_temp)
                    k_temp--;
                else
                {
                    set = true;
                    break;
                }
                ground = lader[i];
            }
            if (k_min == k_max)
                break;
            if (set)
            {
                k_min = k_mid + 1;
            }
            else
            {
                k_max = k_mid;
            }
        }
        cout << "Case " << cases << ": " << k_mid << "\n";
        cases++;
    }
}