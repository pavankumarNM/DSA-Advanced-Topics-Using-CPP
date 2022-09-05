#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int tele = st.top();
    st.pop();

    insertAtBottom(st, ele);

    st.push(tele);
}
void recursive(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int ele = st.top();
    st.pop();
    recursive(st);
    insertAtBottom(st, ele);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // recursive(st);
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}