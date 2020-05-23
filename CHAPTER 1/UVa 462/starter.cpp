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

        stringstream ss(store);
        string word = "";
        unordered_map<char, vector<int>> suits;
        vector<int> store(5, 0);
        suits['S'] = store;
        suits['H'] = store;
        suits['D'] = store;
        suits['C'] = store;

        while (ss >> word)
        {
            if (word[0] == 'A')
            {
                suits[word[1]][0]++;
            }
            else if (word[0] == 'J')
            {
                suits[word[1]][1]++;
            }
            else if (word[0] == 'Q')
            {
                suits[word[1]][2]++;
            }
            else if (word[0] == 'K')
            {
                suits[word[1]][3]++;
            }
            else
            {
                suits[word[1]][4]++;
            }
        }
        int val = 0;
        int val_copy = 0;
        string suit = "SHDC";
        string stopped = "";

        unordered_map<char, int> card_count;
        for (int i = 0; i < suit.length(); i++)
        {
            val = val + suits[suit[i]][0] * 4 + suits[suit[i]][1] * 1 + suits[suit[i]][2] * 2 + suits[suit[i]][3] * 3;
            val_copy = val_copy + suits[suit[i]][0] * 4 + suits[suit[i]][1] * 1 + suits[suit[i]][2] * 2 + suits[suit[i]][3] * 3;
            card_count[suit[i]] = suits[suit[i]][0] + suits[suit[i]][1] + suits[suit[i]][2] + suits[suit[i]][3] + suits[suit[i]][4];
            if (suits[suit[i]][0] == 1)
            {
                if (suit[i] == 'S')
                    stopped += "S";
                else if (suit[i] == 'H')
                    stopped += "H";
                else if (suit[i] == 'D')
                    stopped += "D";
                else if (suit[i] == 'C')
                    stopped += "C";
            }
            else if (suits[suit[i]][3] == 1 && ((card_count[suit[i]] - suits[suit[i]][3]) >= 1))
            {
                if (suit[i] == 'S')
                    stopped += "S";
                else if (suit[i] == 'H')
                    stopped += "H";
                else if (suit[i] == 'D')
                    stopped += "D";
                else if (suit[i] == 'C')
                    stopped += "C";
            }
            else if (suits[suit[i]][2] == 1 && ((card_count[suit[i]] - suits[suit[i]][2]) >= 2))
            {
                if (suit[i] == 'S')
                    stopped += "S";
                else if (suit[i] == 'H')
                    stopped += "H";
                else if (suit[i] == 'D')
                    stopped += "D";
                else if (suit[i] == 'C')
                    stopped += "C";
            }

            if (suits[suit[i]][3] > 0 && suits[suit[i]][4] == 0 && suits[suit[i]][0] == 0 && suits[suit[i]][1] == 0 && suits[suit[i]][2] == 0)
            {
                val -= suits[suit[i]][3];
                val_copy -= suits[suit[i]][3];
            }
            int count = suits[suit[i]][0] + suits[suit[i]][1] + suits[suit[i]][3] + suits[suit[i]][4];
            if (suits[suit[i]][2] > 0 && (count == 0 || count == 1))
            {
                val -= suits[suit[i]][2];
                val_copy -= suits[suit[i]][2];
            }
            count = (count - suits[suit[i]][1]) + suits[suit[i]][2];
            if (suits[suit[i]][1] > 0 && (count == 0 || count == 1 || count == 2))
            {
                val -= suits[suit[i]][1];
                val_copy -= suits[suit[i]][1];
            }
            count += suits[suit[i]][1];

            if (count == 2)
            {
                val++;
            }
            if (count == 1 || count == 0)
            {
                val += 2;
            }
        }
        if (val < 14)
        {
            cout << "PASS"
                 << "\n";
        }
        else if (val_copy >= 16 && stopped == "SHDC")
        {
            cout << "BID NO-TRUMP"
                 << "\n";
        }
        else
        {
            char bid = 'S';
            for (int i = 0; i < suit.size() - 1; i++)
            {
                if (card_count[bid] < card_count[suit[i + 1]])
                    bid = suit[i + 1];
            }
            cout << "BID " << bid << "\n";
        }
    }
}