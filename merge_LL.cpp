#include <iostream>
using namespace std;
#include <iostream>
using namespace std;
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
node *mergeLL(node *&head1, node *&head2)
{
    node *dummynode = new node(-1);
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummynode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data > ptr2->data)
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummynode->next;
}
node *mergeRecursive(node *&head1, node *&head2)
{

    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}
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
void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;

    insertAtTail(head1, 0);
    insertAtTail(head1, 1);
    insertAtTail(head1, 6);
    insertAtTail(head1, 9);
    insertAtTail(head1, 22);
    insertAtTail(head1, 34);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 67);
    // display(head1);
    // display(head2);
    // display(mergeLL(head1,head2));
    // cout<<"\n";
    display(mergeRecursive(head1, head2));
    return 0;
}