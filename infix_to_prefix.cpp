#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
int pre(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string Infix_postfix(string s)
{
    reverse(s.begin(), s.end());

    stack<char> st;
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            st.push(s[i]);
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && pre(st.top()) > pre(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string temp = "(a-b/c)*(a/k-l)";

    cout << Infix_postfix(temp);
    return 0;
}