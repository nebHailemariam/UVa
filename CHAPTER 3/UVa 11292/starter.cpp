#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        vector<int> dragon_head, knight;
        while (n--)
        {
            int temp;
            cin >> temp;
            dragon_head.push_back(temp);
        }
        while (m--)
        {
            int temp;
            cin >> temp;
            knight.push_back(temp);
        }
        if (knight.size() < dragon_head.size())
        {
            cout << "Loowater is doomed!\n";
            continue;
        }
        sort(dragon_head.begin(), dragon_head.end());
        sort(knight.begin(), knight.end());
        int i = 0;
        int j = 0;
        long long coins = 0;
        while (i < knight.size() && j < dragon_head.size() && knight.size() - i >= dragon_head.size() - j)
        {
            if (knight[i] >= dragon_head[j])
            {
                coins += knight[i];
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j < dragon_head.size())
        {
            cout << "Loowater is doomed!\n";
        }
        else
        {
            cout << coins << "\n";
        }
    }
}