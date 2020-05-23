#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int count = 0;
    cin >> count;
    while (count != 0)
    {
        count--;
        string cond = "+x";

        while (count--)
        {
            string store;
            cin >> store;

            if (store == "+z" && cond == "-z")
                cond = "+x";

            else if (store == "+z" && cond == "+z")
                cond = "-x";

            else if (store == "+z" && cond == "+x")
                cond = "+z";

            else if (store == "+z" && cond == "-x")
                cond = "-z";

            else if (store == "+z" && cond == "+y")
                cond = "+y";

            else if (store == "+z" && cond == "-y")
                cond = "-y";

            else if (store == "-z" && cond == "-z")
                cond = "-x";

            else if (store == "-z" && cond == "+z")
                cond = "+x";

            else if (store == "-z" && cond == "+x")
                cond = "-z";

            else if (store == "-z" && cond == "-x")
                cond = "+z";

            else if (store == "-z" && cond == "+y")
                cond = "+y";

            else if (store == "-z" && cond == "-y")
                cond = "-y";

            else if (store == "+y" && cond == "+z")
                cond = "+z";

            else if (store == "+y" && cond == "-z")
                cond = "-z";

            else if (store == "+y" && cond == "+x")
                cond = "+y";

            else if (store == "+y" && cond == "-x")
                cond = "-y";

            else if (store == "+y" && cond == "+y")
                cond = "-x";

            else if (store == "+y" && cond == "-y")
                cond = "+x";

            else if (store == "-y" && cond == "-z")
                cond = "-z";

            else if (store == "-y" && cond == "+z")
                cond = "+z";

            else if (store == "-y" && cond == "+x")
                cond = "-y";

            else if (store == "-y" && cond == "-x")
                cond = "+y";

            else if (store == "-y" && cond == "+y")
                cond = "+x";

            else if (store == "-y" && cond == "-y")
                cond = "-x";
        }
        cout << cond;
        cout << "\n";
        cin >> count;
    }
}