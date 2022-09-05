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
Node *InsertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = InsertBST(root->left, val);
    }
    else
    {
        root->right = InsertBST(root->right, val);
    }
    return root;
}
void Inorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorderprint(root->left);
    cout << root->data << " ";
    Inorderprint(root->right);
}
int main()
{
    Node *root = NULL;
    root = new Node(5);
    InsertBST(root, 1);
    InsertBST(root, 3);
    InsertBST(root, 4);
    InsertBST(root, 2);
    InsertBST(root, 7);

    Inorderprint(root);

    return 0;
}