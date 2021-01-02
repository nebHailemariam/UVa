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
        vector<long long> polynomials = vector<long long>();
        stringstream ss(store);
        string word = "";
        while (ss >> word)
        {
            polynomials.push_back(stoi(word));
        }

        getline(cin, store);
        stringstream ss1(store);

        word = "";
        bool check = false;
        while (ss1 >> word)
        {
            if (check)
                cout << " ";
            long long x = stoi(word);
            long long sum = 0;
            for (long long i = 0; i < polynomials.size(); i++)
            {
                sum += pow(x, i) * polynomials[polynomials.size() - i - 1];
            }
            cout << sum;
            check = true;
        }
        cout << "\n";
    }
}