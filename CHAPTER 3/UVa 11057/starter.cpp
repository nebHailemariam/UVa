#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &price, int left, int right, int num)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (price[mid] == num)
        return mid;
    if (price[mid] < num)
        return binary_search(price, mid + 1, right, num);
    else
        return binary_search(price, left, mid - 1, num);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int books;
    while (cin >> books)
    {
        vector<int> price;
        while (books--)
        {
            int p;
            cin >> p;
            price.push_back(p);
        }
        sort(price.begin(), price.end());
        int money;
        cin >> money;
        int book_1 = INT_MAX;
        int book_2 = 0;
        for (int i = 0; i < price.size(); i++)
        {
            if (money >= price[i])
            {
                int temp_hold = price[i];
                price[i] = INT_MIN;
                int res = binary_search(price, 0, price.size() - 1, money - temp_hold);
                price[i] = temp_hold;
                if (res != -1)
                {
                    if (abs(book_1 - book_2) > abs(money - temp_hold - price[i]))
                    {
                        book_1 = min(money - temp_hold, temp_hold);
                        book_2 = max(temp_hold, money - temp_hold);
                    }
                }
            }
        }
        cout << "Peter should buy books whose prices are " << book_1 << " and " << book_2 << ".\n\n";
    }
}