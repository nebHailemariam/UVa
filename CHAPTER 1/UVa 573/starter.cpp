#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    while (true)
    {
        double H, U, D, F;
        double Height = 0;

        cin >> H >> U >> D >> F;
        F = (U) * (F / 100);
        float a = 0;
        if (H == 0)
            break;

        int day = 1;
        while (true)
        {

            Height = Height + std::max(0.0, U - a);
            if (Height > H)
            {
                cout << "success on day " << day << "\n";
                break;
            }
            Height -= D;
            if (Height < 0)
            {
                cout << "failure on day " << day << "\n";
                break;
            }
            a += F;
            day++;
        }
    }
}