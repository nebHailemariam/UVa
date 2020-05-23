#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int B, S;
    int cases = 1;
    while (cin >> B >> S)
    {
        if (B == 0 && S == 0)
            break;
        vector<int> bachelor, spinister;
        while (B--)
        {
            int temp;
            cin >> temp;
            bachelor.push_back(temp);
        }
        while (S--)
        {
            int temp;
            cin >> temp;
            spinister.push_back(temp);
        }
        sort(bachelor.begin(), bachelor.end());
        if (bachelor.size() <= spinister.size())
        {
            cout << "Case " << cases << ": " << 0 << "\n";
        }
        else
        {
            cout << "Case " << cases << ": " << bachelor.size() - spinister.size() << " " << bachelor[0] << "\n";
        }
        cases++;
    }
}