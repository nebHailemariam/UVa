#include <bits/stdc++.h>
using namespace std;

struct node
{
    char key;
    struct node *next;
};

struct node *newNode(char data)
{
    struct node *temp = new struct node;
    temp->key = data;
    temp->next = NULL;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string store = "";
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while (getline(cin, store))
    {

        bool begin = false;
        struct node *root = NULL;
        struct node *root_temp = NULL;
        struct node *root_beg = NULL;
        struct node *root_beg_temp = NULL;

        for (int i = 0; i < store.size(); i++)
        {
            if (!begin && (store[i] == '['))
            {

                begin = true;
            }
            else if (begin && (store[i] == '['))
            {

                begin = true;
                if (root == NULL)
                {
                    root = root_beg;
                    root_temp = root_beg_temp;
                }
                else
                {
                    if (root_beg_temp != NULL)
                    {
                        root_beg_temp->next = root;
                        root = root_beg;
                    }
                    else
                    {
                        continue;
                    }
                }
                root_beg = NULL;
                root_beg_temp = NULL;
            }
            else if (begin && (store[i] == ']'))
            {

                begin = false;
                if (root == NULL)
                {
                    root = root_beg;
                    root_temp = root_beg_temp;
                }
                else
                {
                    if (root_beg_temp != NULL)
                    {
                        root_beg_temp->next = root;
                        root = root_beg;
                    }
                    else
                    {
                        continue;
                    }
                }
                root_beg = NULL;
                root_beg_temp = NULL;
            }
            else if (!begin && (store[i] == ']'))
            {

                begin = false;
            }
            else if (!begin)
            {

                if (store[i] != ']' && store[i] != '[')
                {
                    if (root == NULL)
                    {
                        root_temp = newNode(store[i]);
                        root = root_temp;
                    }
                    else
                    {
                        root_temp->next = newNode(store[i]);
                        root_temp = root_temp->next;
                    }
                }
            }
            else if (begin)
            {

                if (store[i] != '[' && store[i] != ']')
                {
                    if (root_beg == NULL)
                    {
                        root_beg_temp = newNode(store[i]);
                        root_beg = root_beg_temp;
                    }
                    else
                    {
                        root_beg_temp->next = newNode(store[i]);
                        root_beg_temp = root_beg_temp->next;
                    }
                }
            }
        }
        if (root_beg != NULL)
        {
            if (begin)
            {
                if (root == NULL)
                {
                    root = root_beg;
                }
                else
                {
                    root_beg_temp->next = root;
                    root = root_beg;
                }
            }
            else
            {
                if (root == NULL)
                {
                    root = root_beg;
                }
                else
                {
                    root_temp->next = root_beg;
                }
            }
        }

        while (root != NULL)
        {

            cout << root->key;
            root = root->next;
        }
        cout << "\n";
    }
}