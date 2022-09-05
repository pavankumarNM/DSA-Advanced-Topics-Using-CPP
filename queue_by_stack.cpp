#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> s1;
    stack<int> s2;

public:
    push(int val)
    {
        s1.push(val);
    }
    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    int peek()
    {
        if (s2.empty())
        {
            cout << " No elements in the Queue" << endl;
            return -1;
        }
        return s2.top();
    }
    bool empty()
    {
        if (s2.empty() && s1.empty())
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
    cout << q.pop();
    return 0;
}