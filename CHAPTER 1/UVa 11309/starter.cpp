#include <bits/stdc++.h>
using namespace std;


string increment(string time)
{
    int carry = 0;
    int time_3 = ((int)time[3]) - 48;
    int time_4 = ((int)time[4]) - 48;
    time_3 = time_3 * 10 + time_4 + 1;
    if (time_3 > 59)
    {
        string new_time = "";
        new_time += time[0];
        new_time += time[1];
        new_time += time[2];
        new_time += "00";
        time = new_time;
        carry = 1;
    }
    else
    {
        string new_time = "";
        new_time += time[0];
        new_time += time[1];
        new_time += time[2];
        if (time_3 < 10)
            new_time += "0" + to_string(time_3);
        else
            new_time += to_string(time_3);
        time = new_time;
    }
    if (carry == 1)
    {
        int time_0 = ((int)time[0]) - 48;
        int time_1 = ((int)time[1]) - 48;
        time_0 = time_0 * 10 + time_1;
        time_0++;
        if (time_0 == 24)
        {
            return "00:00";
        }
        else
        {
            string new_time = "";
            new_time += to_string(time_0);
            new_time += time[2];
            new_time += time[3];
            new_time += time[4];
            if (new_time.size() == 4)
            {
                new_time = "0" + new_time;
            }
            time = new_time;
        }
    }
    return time;
}

string strip_zeros(string time)
{
    string new_time = "";
    bool flag = true;
    for (int i = 0; i < time.length(); i++)
    {
        if (time[i] == '0' && flag == true)
        {
            continue;
        }
        else if (time[i] == ':')
            continue;
        else
        {
            flag = false;
            new_time += time[i];
        }
    }
    return new_time;
}

bool palindrom(string time)
{
    time = strip_zeros(time);

    for (int i = 0, j = time.size() - 1; i < time.size() - 1 && j > -1; j--, i++)
    {
        if (time[i] != time[j])
            return false;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    string store = "";
    getline(cin, store);
    int count = stoi(store);
    while (count--)
    {
        getline(cin, store);
        store = increment(store);
        while (true)
        {
            if (palindrom(store))
                break;
            else
                store = increment(store);
        }
        cout << store << "\n";
    }
}