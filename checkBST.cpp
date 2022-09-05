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
bool checkBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data <= min->data)
        Byui
        {
            return false;
        }
    if (max != NULL && root->data >= max->data)
    {
        return false;
    }
    bool leftvalid = checkBST(root->left, min, root);
    bool rightvalid = checkBST(root->right, root, max);

    return leftvalid && rightvalid;
}
int main()
{
    Node *root = new Node(2);
    root->right = new Node(3);
    root->left = new Node(1);
    cout << checkBST(root, NULL, NULL);
    return 0;
}