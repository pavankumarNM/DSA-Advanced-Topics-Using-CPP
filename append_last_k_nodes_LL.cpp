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
node *appendKnode(node *&head, int k)
{
    node *temp = head;
    node *startnode = head;
    node *newhead;
    int count = 1;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }
    newhead = temp->next;
    temp->next = NULL;
    temp = newhead;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = startnode;
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
    insertionAtTail(head, 0);
    insertionAtTail(head, 1);
    insertionAtTail(head, 2);
    insertionAtTail(head, 3);
    insertionAtTail(head, 4);
    insertionAtTail(head, 5);
    insertionAtTail(head, 6);
    insertionAtTail(head, 7);
    display(head);
    display(appendKnode(head, 3));
    return 0;
}