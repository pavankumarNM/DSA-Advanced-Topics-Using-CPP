#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void insertionTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        n->next = NULL;
        n->prev = NULL;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = NULL;
}
void Display(node *head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "\n";
    return;
}
void reverseDisplay(node *tail)
{
    node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->prev;
    }
}
node *getTail(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
void deletion(node *&head, int key)
{
    node *temp = head;
    while (temp->data != key)
    {
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}
int main()
{
    node *head = NULL;
    insertionTail(head, 0);
    insertionTail(head, 1);
    insertionTail(head, 2);
    insertionTail(head, 3);
    insertionTail(head, 4);
    insertionTail(head, 5);
    insertionTail(head, 6);
    insertionTail(head, 7);
    Display(head);

    reverseDisplay(getTail(head));
    return 0;
}