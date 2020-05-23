#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int month;
    float downpayment;
    float amount;
    int records;
    while (true)
    {

        cin >> month >> downpayment >> amount >> records;
        // cout << month << " " << downpayment << " " << amount << " " << records << "\n";
        if (month < 0)
            break;

        int prev_index = -1;
        float prev_rate = -1;

        vector<float> rates;
        while (records--)
        {
            int index = -1;
            float rate = -1;
            cin >> index;
            cin >> rate;

            if (prev_index + 1 < index)
            {
                while (prev_index + 1 < index)
                {
                    rates.push_back(prev_rate);
                    prev_index++;
                }
                rates.push_back(rate);
                prev_index = index;
                prev_rate = rate;
            }
            else
            {
                rates.push_back(rate);
                prev_index = index;
                prev_rate = rate;
            }
        }

        float cur_val;
        cur_val = (amount + downpayment) * ((1 - rates[0]));
        int count = 1;
        float pay = amount / month;

        while (amount > cur_val)
        {
            amount = amount - pay;
            if (rates.size() > count)
                cur_val = cur_val * (1 - rates[count]);
            else
                cur_val = cur_val * (1 - rates[rates.size() - 1]);
            count++;
        }
        count--;
        cout << count;
        if (count != 1)
            cout << " months\n";
        else
            cout << " month\n";
    }
}