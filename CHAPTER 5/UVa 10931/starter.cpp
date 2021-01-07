#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    long long num;

    while (cin >> num && num != 0)
    {
        long long i = 1;
        string binary = "";
        long long ones = 0;
        while (i <= num)
        {
            if (num & i)
            {
                ones++;
                binary = "1" + binary;
            }
            else
            {
                binary = "0" + binary;
            }
            i = i << 1;
        }
        cout << "The parity of " << binary << " is " << ones << " (mod 2)."
             << "\n";
    }
}