#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int people;
    int budget;
    int hotel;
    int weeks;
    string store;

    while (getline(cin, store))
    {

        stringstream ss(store);
        string word = "";
        ss >> word;
        people = stoi(word);
        ss >> word;
        budget = stoi(word);
        ss >> word;
        hotel = stoi(word);
        ss >> word;
        weeks = stoi(word);
        int result = INT_MAX;
        while (hotel--)
        {
            string price;
            getline(cin, price);
            if (people * stoi(price) > budget)
            {

                string weekends;
                getline(cin, weekends);
                continue;
            }
            else
            {

                string weekends;
                getline(cin, weekends);

                stringstream ss(weekends);
                int days = 0;
                while (ss >> word)
                {
                    if (days == weeks)
                        break;
                    if (stoi(word) >= people)
                    {
                        result = min(result, stoi(price));
                    }
                    days++;
                }
            }
        }
        if (result == INT_MAX)
            cout << "stay home\n";
        else
            cout << result * people << "\n";
    }
}