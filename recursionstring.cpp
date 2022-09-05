#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    if (s.length() == 0)
        return;
    string ros = s.substr(1);
    reverse(ros);
    cout << s[0];
}
void replacepi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    else if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacepi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replacepi(s.substr(1));
    }
}
void toh(int n, char src, char helper, char dest)
{
    if (n == 0)
    {
        return;
    }
    toh(n - 1, src, dest, helper);
    cout << "Move from " << src << " -> " << dest << endl;
    toh(n - 1, helper, src, dest);
}
string removedup(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = removedup(s.substr(1));
    if (ch == ans[0])
    {
        return ans;
    }
    return ch + ans;
}
string movex(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    char ch = s[0];
    string ans = movex(s.substr(1));
    if (ch == 'x' || ch == 'X')
    {
        return ans + ch;
    }
    return ch + ans;
}
void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subseq(ros, ans);
    subseq(ros, ch + ans);
}
void subseqasci(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int temp = s[0];
    string ros = s.substr(1);
    subseqasci(ros, ans);
    subseqasci(ros, ans + ch);
    subseqasci(ros, ans + to_string(temp));
}
void combmobile(string s1, string s2, string ans)
{
    if (s1.length() == 0 || s2.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char c1 = s1[0];
    char c2 = s2[0];
    string ros1 = s1.substr(1);
    string ros2 = s2.substr(1);
    combmobile(ros1, ros2, ans);
    combmobile(ros1, ros2, ans + c1);
    combmobile(ros1, ros2, ans + c2);
}
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string keyarr[] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    char some = s[0];

    string code = keyarr[some - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main()
{
    // reverse("pavana");
    // replacepi("pipo22pi23pi2");
    // toh(3,'A','B','C');
    // cout<<removedup("aaabbbcccdddeee");
    // cout<<movex("abxbxbbebeweoppxpxjkx");
    // subseq("ABCD","");
    // subseqasci("AB","");
    // string arr[5]={"abc","def","PAVI","MAYANNA","DOG"};
    // combmobile(arr[0],arr[1],"");
    keypad("12", "");
    return 0;
}