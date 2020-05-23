#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string store = "";
    while (getline(cin, store))
    {
        string screen = "";
        string beg = "";

        bool begin = false;

        for (int i = 0; i < store.size(); i++)
        {

            if (!begin && (store[i] == '['))
            {
                begin = true;
            }
            else if (begin && (store[i] == '['))
            {
                begin = true;
                screen = beg + screen;
                beg = "";
            }
            else if (begin && (store[i] == ']'))
            {
                begin = false;
                screen = beg + screen;
                beg = "";
            }
            else if (!begin && (store[i] == ']'))
            {
                begin = false;
            }
            //checked
            else if (!begin)
            {
                if (store[i] != ']' && store[i] != '[')
                    screen = screen + store[i];
            }
            //checked
            else if (begin)
            {
                if (store[i] != '[' && store[i] != ']')
                    beg = beg + store[i];
            }
        }
        if (beg.size() != 0)
        {
            if (begin)
            {
                screen = beg + screen;
            }
            else
            {
                screen = screen + beg;
            }
        }
        cout << screen << "\n";
    }
}