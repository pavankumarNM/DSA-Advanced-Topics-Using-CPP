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
void makecycle(node *&head, int pos)
{
    node *temp = head;
    node *startcycle = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    for (int i = 1; i != pos; i++)
    {
        startcycle = startcycle->next;
    }
    temp->next = startcycle;
}
bool detectcycle(node *head)
{
    node *slowptr = head;
    node *fastptr = head;
    while (fastptr != NULL || fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (fastptr == slowptr)
        {
            return true;
        }
    }

    return false;
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
    n->next = NULL;
}
void removecycle(node *&head)
{
    node *s = head;
    node *f = head;

    do
    {
        s = s->next;
        f = f->next->next;
    } while (s != f);
    f = head;
    while (f->next != s->next)
    {
        f = f->next;
        s = s->next;
    }
    s->next == NULL;
}
void display(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "-> ";

        temp = temp->next;
    }
    if (temp == NULL)
        cout << "NULL";
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

    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);
    insertAtTail(head, 11);
    makecycle(head, 3);

    cout << detectcycle(head);
    removecycle(head);
    display(head);
    return 0;
}