#include <bits/stdc++.h>
using namespace std;


struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = new struct node;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
}
void inorder_traversal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        inorder_traversal(root->left);
        cout << root->key << " ";
        inorder_traversal(root->right);
        return;
    }
}

void preorder_traversal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        cout << root->key << " ";
        preorder_traversal(root->left);
        preorder_traversal(root->right);
        return;
    }
}

void postorder_traversal(node *root)
{
    if (root == NULL)
        return;
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->key << " ";

        return;
    }
}
struct node *insert(node *root, int val)
{

    if (root == NULL)
        return newNode(val);
    else
    {
        if (root->key > val && root->left == NULL)
        {
            root->left = newNode(val);
        }
        else if (root->key > val && root->left != NULL)
        {
            insert(root->left, val);
        }
        else if (root->key < val && root->right == NULL)
        {
            root->right = newNode(val);
        }
        else if (root->key < val && root->right != NULL)
        {
            insert(root->right, val);
        }
    }
    return root;
}

bool find(node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->key == val)
        return true;
    if (root->key > val)
        return find(root->left, val);
    if (root->key < val)
        return find(root->right, val);
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    struct node *root = NULL;
    root = insert(root, 20);
    insert(root, 120);
    insert(root, 30);
    insert(root, 10);

    inorder_traversal(root);
    cout << "\n";
    preorder_traversal(root);
    cout << "\n";
    postorder_traversal(root);
}