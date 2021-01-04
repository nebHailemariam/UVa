#include <bits/stdc++.h>
using namespace std;

long long Pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y & 1)
        return x * Pow(x * x, y / 2);
    else
        return Pow(x * x, y / 2);
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

        long long x = stoi(store);

        getline(cin, store);

        stringstream ss1(store);

        string word = "";

        vector<long long> polynomials = vector<long long>();
        stringstream ss(store);
        word = "";
        while (ss >> word)
        {
            polynomials.push_back(stoi(word));
        }

        long long sum = 0;
        long long size = polynomials.size();
        for (long long i = 0; i < size - 1; i++)
        {
            sum += polynomials[i] * (size - 1 - i) * Pow(x, size - i - 2);
        }
        cout << sum << "\n";
    }
}