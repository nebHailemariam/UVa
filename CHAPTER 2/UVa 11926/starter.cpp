#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string store = "";
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0)
    {
        int start, end, repeat;
        bool conflict = false;
        bitset<1000001> check_var;
        while (n--)
        {
            cin >> start >> end;
            for (int i = start + 1; i <= end && conflict != true; i++)
            {
                if (!check_var.test(i))
                {
                    check_var.set(i);
                }
                else
                {
                    conflict = true;
                }
            }
        }
        while (m--)
        {
            cin >> start >> end >> repeat;
            while (start < 1000000)
            {
                for (int i = start + 1; i <= end && conflict != true; i++)
                {
                    if (!check_var.test(i))
                    {
                        check_var.set(i);
                    }
                    else
                    {
                        conflict = true;
                    }
                }
                start += repeat;
                end = min(end + repeat, 1000000);
            }
        }
        conflict ? cout << "CONFLICT\n" : cout << "NO CONFLICT\n";
        cin >> n >> m;
    }
}