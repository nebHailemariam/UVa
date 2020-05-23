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
        if (store == "-1")
            break;
        string word = "";
        string guess = "";
        getline(cin, word);
        getline(cin, guess);
        unordered_map<char, int> dict;
        unordered_map<char, bool> guess_dict;
        for (int i = 0; i < word.size(); i++)
        {
            if (dict[word[i]])
            {
                continue;
            }
            else
            {
                dict[word[i]] = 1;
            }
        }
        string new_guess = "";
        for (int i = 0; i < guess.size(); i++)
        {
            if (!guess_dict[guess[i]])
            {
                guess_dict[guess[i]] = true;
                new_guess += guess[i];
            }
        }
        cout << "Round " << store << "\n";
        int hung = 0;
        bool win_global = false;
        for (int i = 0; i < new_guess.size(); i++)
        {
            if (dict[new_guess[i]] == 1 || dict[new_guess[i]] == 2)
            {
                dict[new_guess[i]] = 2;
            }
            else
            {
                hung++;
                if (hung == 7)
                    break;
            }
            bool win = true;
            for (int i = 0; i < word.size(); i++)
            {
                if (dict[word[i]] != 2)
                {
                    win = false;
                    break;
                }
            }
            if (win)
            {
                cout << "You win.\n";
                win_global = true;
                break;
            }
        }

        bool chick = false;
        for (int i = 0; i < word.size(); i++)
        {
            if (dict[word[i]] != 2)
            {
                chick = true;
                break;
            }
        }
        if (win_global)
        {
            continue;
        }
        if (chick && hung < 7)
        {
            cout << "You chickened out.\n";
        }
        else
        {
            cout << "You lose.\n";
        }
    }
}