#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string store = "";

    while (getline(cin, store))
    {
        priority_queue<int> heap_d;
        stack<int> stack_d;
        queue<int> queue_d;
        bool h_b = true;
        bool s_b = true;
        bool q_b = true;
        int count;
        count = stoi(store);
        while (count--)
        {
            int query, val;
            getline(cin, store);
            stringstream ss(store);
            ss >> store;
            query = stoi(store);
            ss >> store;
            val = stoi(store);
            if (query == 1)
            {
                heap_d.push(val);
                stack_d.push(val);
                queue_d.push(val);
            }
            else
            {
                if (heap_d.size() == 0 || heap_d.top() != val)
                {
                    h_b = false;
                }
                else
                {
                    heap_d.pop();
                }
                if (stack_d.size() == 0 || stack_d.top() != val)
                {
                    s_b = false;
                }
                else
                {
                    stack_d.pop();
                }
                if (queue_d.size() == 0 || queue_d.front() != val)
                {
                    q_b = false;
                }
                else
                {
                    queue_d.pop();
                }
            }
        }
        if (h_b && !s_b && !q_b)
        {
            cout << "priority queue\n";
        }
        else if (!h_b && s_b && !q_b)
        {
            cout << "stack\n";
        }
        else if (!h_b && !s_b && q_b)
        {
            cout << "queue\n";
        }
        else if (!h_b && !s_b && !q_b)
        {
            cout << "impossible\n";
        }
        else
        {
            cout << "not sure\n";
        }
    }
}