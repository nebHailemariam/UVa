#include <bits/stdc++.h>
using namespace std;

vector<string> my_store;

void recurse(stack<char> anagram, list<char> anagram_store, string word, string operations, list<char> res)
{
    // cout << operations << "\n";
    if (res.size() == word.size() && operations.size() == 2 * word.size())
    {
        my_store.push_back(operations);
    }
    else
    {
        bool check = false;
        char store_top;
        if (anagram_store.size() > 0 && (*anagram_store.begin() == word[res.size()]))
        {
            check = true;
            store_top = *anagram_store.begin();
            anagram_store.pop_front();
            res.push_back(store_top);
            recurse(anagram, anagram_store, word, operations + 'o', res);
        }
        if (check == true)
        {
            anagram_store.push_front(store_top);
            res.pop_back();
        }

        if (anagram.size() > 0)
        {
            char top = anagram.top();
            anagram.pop();
            anagram_store.push_front(top);

            recurse(anagram, anagram_store, word, operations + 'i', res);
        }
    }
}

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
        stack<char> source;
        if (store.size() == 0)
        {
            while (store.size() == 0)
                getline(cin, store);
        }
        string source_temp = store;
        sort(source_temp.begin(), source_temp.end());
        for (int i = store.size() - 1; i >= 0; i--)
            source.push(store[i]);
        getline(cin, store);
        if (store.size() == 0)
        {
            while (store.size() == 0)
                getline(cin, store);
        }
        string target = store;
        string target_temp = store;
        sort(target_temp.begin(), target_temp.end());

        cout << "[\n";
        if (target.size() == source.size() && target_temp == source_temp)
        {
            list<char> source_temp;
            list<char> res;
            recurse(source, source_temp, target, "", res);

            for (int i = my_store.size() - 1; i >= 0; i--)
            {
                for (int j = 0; j < my_store[i].size(); j++)
                {
                    cout << my_store[i][j];
                    if (j != my_store[i].size() - 1)
                        cout << " ";
                }
                cout << "\n";
            }
        }
        cout << "]\n";
        my_store.clear();
    }
}