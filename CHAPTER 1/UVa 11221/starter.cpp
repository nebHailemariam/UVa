#include <bits/stdc++.h>
using namespace std;


bool is_palindrom(string word)
{
    int i = 0;
    int j = word.size() - 1;

    while (i < j)
    {
        if (word[i] != word[j])
            return false;

        i++;
        j--;
    }
    return true;
}

int is_magic_square(string word)
{
    int num = sqrt(word.length());
    if (num * num != word.length())
        return -1;
    vector<vector<char>> store(num, vector<char>(num));
    int n = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            store[i][j] = word[n];
            n++;
        }
    }
    int i_1;
    int j_1;
    int i_2;
    int j_2;
    string str_1 = "";
    string str_2 = "";
    string str_3 = "";
    string str_4 = "";

    for (i_1 = 0, i_2 = store[0].size() - 1; i_1 < store.size() && i_2 > -1; i_1++, i_2--)
    {
        for (j_1 = 0, j_2 = store[0].size() - 1; j_1 < store[0].size() && i_2 > -1; j_1++, j_2--)
        {
            str_1 += store[i_1][j_1];
            str_2 += store[j_1][i_1];
            str_3 += store[i_2][j_2];
            str_4 += store[j_2][i_2];
        }
    }
    if (is_palindrom(str_1) && is_palindrom(str_2) && is_palindrom(str_3) && is_palindrom(str_4))
        return num;
    return -1;
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
    int case_ = 1;
    while (count--)
    {
        getline(cin, store);
        string temp = "";
        for (int i = 0; i < store.size(); i++)
        {
            if (isalpha(store[i]))
                temp += store[i];
        }
        if (temp != "")
        {
            int num = is_magic_square(temp);
            cout << "Case #" << case_ << ":\n";
            case_++;
            if (num == -1)
                cout << "No magic :(\n";
            else
                cout << num << "\n";
        }
        else
        {

            cout << "Case #" << case_ << ":\n";
            case_++;
            cout << 0 << "\n";
        }
    }
}