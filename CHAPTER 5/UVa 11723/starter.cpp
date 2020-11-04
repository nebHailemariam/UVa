#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int R, N;
    int test_cases = 0;

    while (cin >> R >> N && (R != 0 || N != 0))
    {
        test_cases++;
        cout << "Case " << test_cases << ": ";
        if (R <= N + N * 26)
        {
            R = R - N;
            if (R < 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                int i = 0;
                while (R > N * i)
                {
                    i++;
                }
                cout << i << "\n";
            }
        }
        else
        {
            cout << "impossible\n";
        }
    }
}