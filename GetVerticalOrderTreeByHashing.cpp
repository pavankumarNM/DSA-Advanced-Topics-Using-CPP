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

void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->right = new Node(11);
    root->left->left = new Node(3);
    root->right->right = new Node(6);
    root->right->left = new Node(14);
    int hd = 0;
    map<int, vector<int>> m;
    getVerticalOrder(root, hd, m);
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }

    return 0;
}