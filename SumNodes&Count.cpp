#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
int CountNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return CountNode(root->left) + CountNode(root->right) + 1;
}
int SumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + SumNodes(root->left) + SumNodes(root->right);
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << CountNode(root) << " ";
    cout << SumNodes(root);
    return 0;
}