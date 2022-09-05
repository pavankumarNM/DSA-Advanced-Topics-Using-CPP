#include <bits/stdc++.h>
#include <stack>
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
void zigzag(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> curr;
    stack<Node *> next;
    curr.push(root);
    bool leftToright = true;
    while (!curr.empty())
    {
        Node *temp = curr.top();
        curr.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (leftToright)
            {
                if (temp->left != NULL)
                {
                    next.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    next.push(temp->right);
                }
            }
            else
            {
                if (temp->right != NULL)
                {
                    next.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    next.push(temp->left);
                }
            }
        }
        if (curr.empty())
        {
            swap(curr, next);
            leftToright = !leftToright;
        }
    }
}
int main()
{
    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    root->right = new Node(15);
    zigzag(root);

    return 0;
}