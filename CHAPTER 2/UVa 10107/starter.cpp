#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    //with space;
    string store = "";
    priority_queue<int> min_heap;
    priority_queue<int> max_heap;
    int median = 0;
    while (cin >> store)
    {
        int num = 0;
        num = stoi(store);

        if (min_heap.size() == 0 && max_heap.size() == 0)
        {
            if (num >= median)
            {
                min_heap.push(-num);
            }
            else
            {
                max_heap.push(num);
            }
            median = num;
            cout << median << "\n";
        }
        else
        {
            if (median <= num)
                min_heap.push(-num);
            else
                max_heap.push(num);

            if (min_heap.size() - max_heap.size() > 1 || max_heap.size() - min_heap.size() > 1)
            {
                if (min_heap.size() > max_heap.size())
                {
                    int top = -min_heap.top();
                    max_heap.push(top);
                    min_heap.pop();
                }
                else
                {
                    int top = -max_heap.top();
                    min_heap.push(top);
                    max_heap.pop();
                }
            }
            if (min_heap.size() > max_heap.size())
            {
                median = -min_heap.top();
            }
            else if (max_heap.size() > min_heap.size())
            {
                median = max_heap.top();
            }
            else
            {
                median = max_heap.top() - min_heap.top();
                median /= 2;
            }
            cout << median << "\n";
        }
    }
}
