#include <bits/stdc++.h>
using namespace std;

string format(int num)
{
    string num_str = "     ";
    num_str.replace(5 - to_string(num).size(), 5, to_string(num));
    return num_str;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    float num;

    cout << "PERFECTION OUTPUT\n";
    while (cin >> num && num != 0)
    {
        int sum = 0;

        float i = 1;

        while (i <= num / 2)
        {
            if ((int)(num / i) == num / i)
            {
                sum += i;
            }
            i++;
        }
        if (sum == num)
            cout << format(num) << "  PERFECT\n";
        else if (sum < num)
            cout << format(num) << "  DEFICIENT\n";
        else
            cout << format(num) << "  ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}