#include <bits/stdc++.h>
using namespace std;
// class Stack                       //method 1 push operaation costly
// {
//     int N;
//     queue<int> q1;
//     queue<int> q2;

// public:
//     stack()
//     {
//         N = 0;
//     }
//     void push(int val)
//     {
//         q2.push(val);
//         while (!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         queue<int> temp = q1;
//         q1 = q2;
//         q2 = temp;
//         N++;
//     }
//     void pop()
//     {
//         q1.pop();
//         N--;
//     }
//     int top()
//     {
//         return q1.front();
//     }
//     bool empty()
//     {
//         if (q1.empty())
//         {
//             return true;
//         }
//         return false;
//     }
//     int size() { return N; }
// };

class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stack()
    {
        N = 0;
    }
    void push(int val)
    {
        q1.push(val);
        N++;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size() { return N; }
    bool empty()
    {
        if (q1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top();
    s.pop();
    cout << s.top();
    return 0;
}