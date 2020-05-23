#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int times = 0;
    cin >> times;
    int i = 1;

    string store = "";
    while (times > 0)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        if ((a >= b && a <= c) || (a <= b && a >= c))
            cout << a;
        else if ((c >= b && c <= a) || (c <= b && c >= a))
            cout << c;
        else if ((b >= a && b <= c) || (b <= a && b >= c))
            cout << b;

        cout << "\n";
        times--;
        i++;
    }
}