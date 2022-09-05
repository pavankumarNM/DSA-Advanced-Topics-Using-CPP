#include <iostream>
#define n 100
using namespace std;
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }
    void push(int val)
    {
        if (top == n - 1)
        {
            cout << " stack  overflow " << endl;
            return;
        }

        top++;
        arr[top] = val;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << " No element to pop " << endl;
            return;
        }
        top--;
    }
    bool empty()
    {
        return top == -1;
    }
    int Top()
    {
        if (top == -1)
        {
            cout << "No element in stack" << endl;
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.Top();
    st.pop();
    cout << endl;
    cout << st.Top();
    cout << st.empty();
    return 0;
}