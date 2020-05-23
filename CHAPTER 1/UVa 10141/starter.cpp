#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    string store;
    int req, prop;
    getline(cin, store);
    stringstream ss(store);
    string word;
    ss >> word;
    req = stoi(word);
    ss >> word;
    prop = stoi(word);
    int count = 1;
    while (true)
    {
        if (req == 0 && prop == 0)
            break;
        if (count > 1)
        {
            cout << "\n";
        }

        while (req--)
            getline(cin, store);
        string name = "";
        float price;
        int check;
        while (prop--)
        {
            string name_temp;
            float price_temp;
            int check_temp;

            getline(cin, store);

            name_temp = store;
            getline(cin, store);
            stringstream ss1(store);
            ss1 >> word;
            price_temp = stof(word);
            ss1 >> word;
            check_temp = stoi(word);
            int i = 0;
            while (i < check_temp)
            {
                getline(cin, store);
                i++;
            }

            if (name == "")
            {
                name = name_temp;
                price = price_temp;
                check = check_temp;
            }
            else if (check_temp > check)
            {
                name = name_temp;
                price = price_temp;
                check = check_temp;
            }
            else if (price > price_temp && check_temp >= check)
            {
                name = name_temp;
                price = price_temp;
                check = check_temp;
            }
        }
        cout << "RFP #" << count << "\n"
             << name << "\n";
        count++;
        getline(cin, store);
        stringstream ss2(store);
        string word;
        ss2 >> word;
        req = stoi(word);
        ss2 >> word;
        prop = stoi(word);
    }
}