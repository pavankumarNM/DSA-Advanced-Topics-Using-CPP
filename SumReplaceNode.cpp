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
void SumReplaceNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    SumReplaceNode(root->left);
    SumReplaceNode(root->right);
    if (root->left )
    {
        root->data += root->left->data;
    }
    if (root->right )
    {
        root->data += root->right->data;
    }
}
void preOrder(Node* root){
    if (root == NULL)
    {
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
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

   preOrder(root);
   cout<<"\n";
   SumReplaceNode(root);
   preOrder(root);
 
    return 0;
}