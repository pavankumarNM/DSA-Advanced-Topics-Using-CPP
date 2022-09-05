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
int MaxSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = MaxSumUtil(root->left, ans);
    int rightsum = MaxSumUtil(root->right, ans);
    ans = max(max(root->data, root->data + leftsum + rightsum), max(root->data + leftsum, root->data + rightsum));
    int singlePathSum = max(root->data, max(leftsum + root->data, root->data + rightsum));
    return singlePathSum;
}
int MaxSumPath(Node *root)
{
    int ans = 0;
    MaxSumUtil(root, ans);
    return ans;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout << MaxSumPath(root);
    return 0;
}