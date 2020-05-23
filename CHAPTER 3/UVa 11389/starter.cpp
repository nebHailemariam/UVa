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
    int n, d, r;
    while (cin >> n >> d >> r)
    {
        if (n == 0 && d == 0 && r == 0)
            break;
        vector<int> day, night;
        int n_ = n;
        while (n_--)
        {
            int temp;
            cin >> temp;
            day.push_back(temp);
        }
        n_ = n;
        while (n_--)
        {
            int temp;
            cin >> temp;
            night.push_back(temp);
        }
        n_ = n - 1;
        int over_time = 0;
        sort(night.begin(), night.end());
        while (n_ > -1)
        {
            int temp = night[n_];
            sort(day.begin(), day.end());
            int i = 0;
            while (day[i] == -1)
            {
                i++;
            }
            if (day[i] + temp > d)
            {
                over_time += (day[i] + temp - d) * r;
            }
            day[i] = -1;
            n_--;
        }
        cout << over_time << "\n";
    }
}