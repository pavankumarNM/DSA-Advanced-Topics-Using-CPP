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
vector<Node *> buildNode(int start, int end)
{
    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> lefttree = buildNode(start, i - 1);
        vector<Node *> righttree = buildNode(i + 1, end);
        for (int j = 0; j < lefttree.size(); j++)
        {
            Node *left = lefttree[j];
            for (int k = 0; k < righttree.size(); k++)
            {
                Node *right = righttree[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<Node *> totaltree = buildNode(1, 3);

    for (int i = 0; i < totaltree.size(); i++)
    {
        preorder(totaltree[i]);
        cout << endl;
    }

    return 0;
}