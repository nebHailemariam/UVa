#include <bits/stdc++.h>
using namespace std;


bool is_palindrom(string S)
{
    int i = 0;
    int j = S.size() - 1;
    if (j % 2 == 0)
    {
        while (i <= j)
        {
            if (isalpha(S[i]) && isalpha(S[j]))
            {
                if (tolower(S[i]) != tolower(S[j]))
                    return false;
                i++;
                j--;
            }
            else if (!isalpha(S[i]) && !isalpha(S[j]))
            {
                i++;
                j--;
            }
            else if (!isalpha(S[i]))
            {
                i++;
            }
            else if (!isalpha(S[j]))
            {
                j--;
            }
        }
    }
    else
    {
        while (i < j)
        {
            if (isalpha(S[i]) && isalpha(S[j]))
            {
                if (tolower(S[i]) != tolower(S[j]))
                    return false;
                i++;
                j--;
            }
            else if (!isalpha(S[i]) && !isalpha(S[j]))
            {
                i++;
                j--;
            }
            else if (!isalpha(S[i]))
            {
                i++;
            }
            else if (!isalpha(S[j]))
            {
                j--;
            }
        }
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
    while (store != "DONE")
    {
        if (is_palindrom(store))
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
        getline(cin, store);
    }
}