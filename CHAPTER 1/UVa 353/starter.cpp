#include <bits/stdc++.h>
using namespace std;


unordered_map<string, bool> store;
void print_string(string word, int i, int j)
{
    for (i = i; i <= j; i++)
        cout << word[i];
    cout << "\n";
}
int is_pal(string word, int i, int j)
{
    string temp = "";
    for (j = j; j >= i; j--)
    {
        temp = temp + word[j];
    }
    // print_string(temp, 0, temp.size() - 1);
    for (int n = 0; n < temp.size(); n++)
    {
        if (temp[n] != word[i])
            return 0;
        i++;
    }
    if (store[temp] == true)
        return 0;
    store[temp] = true;
    return 1;
}

int pal(string word)
{
    int count = 0;
    for (int i = 0; i < word.size(); i++)
    {
        for (int j = i; j < word.size(); j++)
        {
            count += is_pal(word, i, j);
        }
    }

    return count;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string word = "";
    while (getline(cin, word))
    {

        cout << "The string \'" << word << "\' contains " << pal(word) << " palindromes.\n";
        store.clear();
    }
}