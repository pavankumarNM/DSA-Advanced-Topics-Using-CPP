#include <iostream>
using namespace std;
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
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (n == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}
void circularAdd(node *&head, int val)
{
    node *temp = head;
    node *n = new node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    return;
}
void deletehead(node *&head)
{
    node *todelete = head;
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    delete todelete;
}
void deletion(node8 &head, int pos)
{
    if (pos == 1)
    {
        deletehead(head);
    }
    int count = 1;
    node *temp = head;
    while (count != (pos - 1))
    {
        temp = temp->next;
        count++;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
void display(node *head)
{
    node *temp = head;

    do
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    circularAdd(head, 1);
    circularAdd(head, 2);
    circularAdd(head, 3);
    circularAdd(head, 4);
    circularAdd(head, 5);
    display(head);
    return 0;
}