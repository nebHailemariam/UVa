#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};
//O(n ^ 2)
// int height(struct node *root)
// {
//     if (root == NULL)
//         return 0;

//     return max(height(root->left), height(root->right)) + 1;
// }
//O(n ^ 2)
// int diameter(struct node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int left_height = height(root->left);
//     int right_height = height(root->right);

//     return max(left_height + right_height + 1, max(diameter(root->left), diameter(root->right)));
// }

//O(n)
unordered_map<struct node *, int> dict = unordered_map<struct node *, int>();
int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        if (dict.count(root) != 0)
            return dict[root];
        else
        {
            dict[root] = max(height(root->left), height(root->right)) + 1;
            return dict[root];
        }
    }
}
int diameter(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height + right_height + 1, max(diameter(root->left), diameter(root->right)));
}

int main()
{
    struct node *root_temp = new struct node;
    root_temp->key = 1;
    root_temp->left = new struct node;
    root_temp->left->key = 2;
    root_temp->right = new struct node;
    root_temp->right->key = 3;
    root_temp->right->left = NULL;
    root_temp->right->right = NULL;

    root_temp->left->left = new struct node;
    root_temp->left->left->key = 4;
    root_temp->left->right = new struct node;
    root_temp->left->right->key = 5;
    root_temp->left->left->left = NULL;
    root_temp->left->left->right = NULL;
    root_temp->left->right->left = NULL;
    root_temp->left->right->right = NULL;

    cout << diameter(root_temp) << "\n";
}
