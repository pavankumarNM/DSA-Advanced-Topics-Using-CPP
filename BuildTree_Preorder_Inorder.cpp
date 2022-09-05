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
int search(int Inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (curr == Inorder[i])
        {
            return i;
        }
    }
    return -1;
}
Node *buildTree(int Preorder[], int Inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }

    int curr = Preorder[idx];
    idx++;
    struct Node *root = new Node(curr);
    if (start == end)
    {
        return root;
    }
    int pos = search(Inorder, start, end, curr);
    root->left = buildTree(Preorder, Inorder, start, pos - 1);
    root->right = buildTree(Preorder, Inorder, pos + 1, end);
    return root;
}
void inOrderprint(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderprint(root->left);
    cout << root->data << " ";
    inOrderprint(root->right);
}
int main()
{
    int Inorder[] = {4, 2, 1, 5, 3};
    int Preorder[] = {1, 2, 4, 3, 5};
    Node *Root = buildTree(Preorder, Inorder, 0, 4);
    inOrderprint(Root);
    return 0;
}