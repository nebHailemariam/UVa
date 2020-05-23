#include <bits/stdc++.h>
using namespace std;


float round(float var)
{
    float value = (int)(var * 10000 + 0.5);
    return (float)value / 10000;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        double x_min = 0;
        double x_max = 1;
        double x_mid = round((x_min + x_max) / 2);
        double prev = 0;
        while (true && x_mid >= 0 && x_mid <= 1)
        {
            prev = x_mid;
            if ((p * exp(-x_mid)) + (q * sin(x_mid)) + (r * cos(x_mid)) + (s * tan(x_mid)) + (t * x_mid * x_mid) + u == round(0))
            {
                break;
            }
            else if ((p * exp(-x_mid)) + (q * sin(x_mid)) + (r * cos(x_mid)) + (s * tan(x_mid)) + (t * x_mid * x_mid) + u > round(0))
            {
                x_min = x_mid + 1;
            }
            else
            {
                x_max = x_mid - 1;
            }
            x_mid = (x_max + x_min) / 2;
            if (prev == x_mid)
                break;
            // cout << prev << " : " << x_mid << "\n";
        }
        if (x_mid < 0 || x_mid > 1)
            cout << "No solution\n";
        else
        {
            cout << fixed << setprecision(4) << (float)(int(x_mid * 10000 + 0.5)) / 10000 << "\n";
        }
        // cout << x_mid;
    }
}