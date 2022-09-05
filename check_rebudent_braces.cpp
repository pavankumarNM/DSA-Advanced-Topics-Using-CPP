#include <bits/stdc++.h>
using namespace std;
bool check_rebudent(string s)
{
    int n = s.size();
    bool ans = false;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }
            while (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
            {
                st.pop();
            }
            st.pop();
        }
    }

    return ans;
}
int main()
{
    string temp = "(a+b)(";
    cout << check_rebudent(temp);
    return 0;
}