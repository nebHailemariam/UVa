#include <bits/stdc++.h>
using namespace std;


unordered_map<char, char> dict;

bool is_mirrored(string word)
{
    int i = 0;
    int j = word.size() - 1;
    if (j % 2 == 0)
    {
        while (i <= j)
        {
            if (dict[word[i]] != word[j])
                return false;
            i++;
            j--;
        }
    }
    else
    {
        while (i < j)
        {
            if (dict[word[i]] != word[j])
                return false;
            i++;
            j--;
        }
    }
    return true;
}
bool is_palindrom(string word)
{
    int i = 0;
    int j = word.size() - 1;
    if (j % 2 == 0)
    {
        while (i <= j)
        {
            if (word[i] != word[j])
                return false;
            i++;
            j--;
        }
    }
    else
    {
        while (i < j)
        {
            if (word[i] != word[j])
                return false;
            i++;
            j--;
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
    string word = "";
    dict['A'] = 'A';
    dict['E'] = '3';
    dict['H'] = 'H';
    dict['I'] = 'I';
    dict['J'] = 'L';
    dict['L'] = 'J';
    dict['M'] = 'M';
    dict['O'] = 'O';
    dict['S'] = '2';
    dict['T'] = 'T';
    dict['U'] = 'U';
    dict['V'] = 'V';
    dict['W'] = 'W';
    dict['X'] = 'X';
    dict['Y'] = 'Y';
    dict['Z'] = '5';
    dict['1'] = '1';
    dict['2'] = 'S';
    dict['3'] = 'E';
    dict['5'] = 'Z';
    dict['8'] = '8';

    while (getline(cin, word))
    {

        bool pal = is_palindrom(word);
        bool mir = is_mirrored(word);

        if (!pal && !mir)
        {
            cout << word << " -- is not a palindrome.\n\n";
        }
        else if (pal && !mir)
        {
            cout << word << " -- is a regular palindrome.\n\n";
        }
        else if (!pal && mir)
        {
            cout << word << " -- is a mirrored string.\n\n";
        }
        else if (pal && mir)
        {
            cout << word << " -- is a mirrored palindrome.\n\n";
        }
    }
}