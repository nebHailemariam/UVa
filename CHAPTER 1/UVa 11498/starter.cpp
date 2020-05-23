#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int i;
    cin >> i;
    while (i != 0)
    {
        int dx, dy;
        cin >> dx;
        cin >> dy;
        while (i != 0)
        {
            int c1, c2;
            cin >> c1;
            cin >> c2;

            if (c1 == dx || c2 == dy)
                cout << "divisa\n";
            else if (c1 > dx && c2 > dy)
                cout << "NE\n";
            else if (c1 < dx && c2 > dy)
                cout << "NO\n";
            else if (c1 < dx && c2 < dy)
                cout << "SO\n";
            else if (c1 > dx && c2 < dy)
                cout << "SE\n";
            i--;
        }
        cin >> i;
    }
}