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
struct Info
{
    int min;
    int max;
    int ans;
    bool isBST;
    int size;
};
Info largestBST(Node *root)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, 0, true, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {root->data, root->data, 1, true, 1};
    }
    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);
    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);
    if (leftInfo.ans && leftInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, rightInfo.min);
        curr.max = max(leftInfo.max, rightInfo.max);
        curr.isBST = true;
        curr.ans = curr.size;
        return curr;
    }
    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;
    return curr;
}
int main()
{
    Node *root = new Node(15);
    root->right = new Node(30);
    root->left = new Node(20);
    root->left->left = new Node(5);
    cout << largestBST(root).ans;
    return 0;
}