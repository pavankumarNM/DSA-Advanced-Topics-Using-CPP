#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
Node *Build(int preorder[], int *preidx, int key, int min, int max, int n)
{
    if (*preidx >= n)
    {
        return NULL;
    }
    Node *root = NULL;
    if (min < key && key < max)
    {
        root = new Node(key);
        *preidx += 1;
        if (*preidx < n)
        {
            root->left = Build(preorder, preidx, preorder[*preidx], min, key, n);
        }

        if (*preidx < n)
        {
            root->right = Build(preorder, preidx, preorder[*preidx], key, max, n);
        }
    }
    return root;
}
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
int main()
{
    int n = 5;
    int preorder[] = {10, 2, 1, 13, 11};
    int preidx = 0;

    Node *root = Build(preorder, &preidx, preorder[0], INT_MIN, INT_MAX, n);
    printPreorder(root);

    return 0;
}