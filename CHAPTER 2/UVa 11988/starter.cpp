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
    while (getline(cin, store))
    {
        string screen = "";
        string beg = "";
        list<char> screen_list;
        list<char> beg_list;
        list<char> empty;
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

                beg_list.splice(beg_list.end(), screen_list);
                screen_list.splice(screen_list.end(), beg_list);
            }
            else if (begin && (store[i] == ']'))
            {
                begin = false;

                beg_list.splice(beg_list.end(), screen_list);
                screen_list.splice(screen_list.end(), beg_list);
            }
            else if (!begin && (store[i] == ']'))
            {
                begin = false;
            }

            else if (!begin)
            {
                if (store[i] != ']' && store[i] != '[')
                {
                    screen_list.push_back(store[i]);
                }
            }
            else if (begin)
            {
                if (store[i] != '[' && store[i] != ']')
                {
                    beg_list.push_back(store[i]);
                }
            }
        }
        if (beg_list.size() != 0)
        {
            if (begin)
            {
                beg_list.splice(beg_list.end(), screen_list);
                screen_list.splice(screen_list.end(), beg_list);
            }
            else
            {

                screen_list.splice(screen_list.end(), beg_list);
            }
        }
        for (list<char>::iterator i = screen_list.begin(); i != screen_list.end(); i++)
        {
            cout << *i;
        }
        cout << "\n";
    }
}