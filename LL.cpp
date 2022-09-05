#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{

    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void insertAthead(node *&head, int val)
{
    node *temp = new node(val);
    temp->next = head;
    head = temp;
}
void deleteAtHead(node *&head, int val)
{
    node *temp = head;
    head = head->next;
    delete temp;
}
void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head, val);
    }
    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
        if (temp->next == NULL)
        {
            cout << " NOT FOUND " << endl;
            return;
        }
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
node *recursive(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 0);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    // display(head);
    // insertAthead(head,3);
    // display(head);
    // deletion(head,4);
    // display(head);
    // display(recursive(head));
    int k = 2;
    display(reversek(head, 2));
    return 0;
}