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
int HeightNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(HeightNode(root->left), HeightNode(root->right)) + 1;
}
int CalDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int Lheight = HeightNode(root->left);
    int Rheight = HeightNode(root->right);
    int currDiameter = Lheight + Rheight + 1;
    int Rdiameter = CalDiameter(root->right);
    int Ldiameter = CalDiameter(root->left);
    return max(currDiameter, max(Rdiameter, Ldiameter));
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

    cout << HeightNode(root) << " ";
    cout << CalDiameter(root);
    return 0;
}