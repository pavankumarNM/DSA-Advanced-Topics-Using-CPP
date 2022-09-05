#include <bits/stdc++.h>
using namespace std;
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
bool IsBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (root->left == false)
    {
        return false;
    }
    if (root->right == false)
    {
        return false;
    }
    int lh = HeightNode(root->left);
    int rh = HeightNode(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
}
int main()
{
    struct Node *root = new Node(1); // Balanced Tree
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // struct Node* root= new Node(1);              // Unbalanced Tree
    // root->left=new Node(2);
    // root->left->left=new Node(3);

    if (IsBalanced(root))
    {
        cout << "Tree is  Balanced";
    }
    else
    {
        cout << " UnBalanced ";
    }
    return 0;
}