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
void insertionAtTail(node *&head, int val)
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
int Length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int findIntersect(node *head1, node *head2)
{
    int length1 = Length(head1);
    int length2 = Length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;
    if (length1 > length2)
    {
        ptr1 = head1;
        ptr2 = head2;
        d = length1 - length2;
    }
    else
    {
        ptr1 = head2;
        ptr2 = head1;
        d = length2 - length1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }

        d--;
    }
    while (ptr1 != NULL || ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}
void intersectHead(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    node *temp2 = head2;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
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
    node *head1 = NULL;
    node *head2 = NULL;
    insertionAtTail(head1, 0);
    insertionAtTail(head1, 1);
    insertionAtTail(head1, 2);
    insertionAtTail(head1, 3);
    insertionAtTail(head1, 4);
    insertionAtTail(head1, 5);
    insertionAtTail(head1, 6);
    insertionAtTail(head1, 7);
    insertionAtTail(head2, 9);
    insertionAtTail(head2, 10);
    insertionAtTail(head2, 11);
    intersectHead(head1, head2, 4);
    display(head1);
    display(head2);
    cout << findIntersect(head1, head2);
    return 0;
}