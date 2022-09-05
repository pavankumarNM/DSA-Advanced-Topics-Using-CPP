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
        left = NULL;
        right = NULL;
    }
};
bool checkidenticalBST(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->data == root2->data && checkidenticalBST(root1->left, root2->left) && checkidenticalBST(root1->right, root2->right))
    {
        return true;
    }
    return false;
}
int main()
{
    Node *root1 = new Node(1);
    root1->right = new Node(3);
    root1->right->right = new Node(5);
    root1->right->left = new Node(2);
    Node *root2 = NULL;
    // Node *root2 = new Node(1);
    // root2->right = new Node(3);
    // root2->right->right = new Node(5);
    // root2->right->left = new Node(2);

    cout << checkidenticalBST(root1, root2);
    return 0;
}