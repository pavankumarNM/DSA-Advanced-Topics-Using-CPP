#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define n 20
class Queue
{

    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int val)
    {

        if (back == n - 1)
        {
            cout << "Queue Overflow";
            return;
        }
        if (front == -1)
        {
            front++;
        }
        back++;
        arr[back] = val;
    }
    void pop()
    {
        if (front > back || front == -1)
        {
            cout << "No elements in the Queue" << endl;
        }
        front++;
    }
    int peek()
    {
        if (front > back || front == -1)
        {
            cout << "No elements in the Queue" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty()
    {
        if (front > back || front == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();

    cout << q.empty();

    return 0;
}