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
    scanf("%d", &times);
    int a, b;
    while (times > 0)
    {
        scanf("%d %d", &a, &b);
        if (a > b)
        {
            printf(">");
        }
        else if (b > a)
        {
            printf("<");
        }
        else
        {
            printf("=");
        }
        times--;
        printf("\n");
    }
}