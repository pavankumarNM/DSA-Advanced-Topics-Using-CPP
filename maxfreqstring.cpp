#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "rfrgregejgeeithj";
    int freq[26] = {};
    for (int i = 0; i < str.length(); i++)
    {
        freq[str[i] - 'a']++;
    }
    int mxfq = 0;
    char mxel;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > mxfq)
        {
            mxfq = freq[i];
            mxel = i + 'a';
        }
    }
    cout << "maximum frequency of element " << mxel << " is " << mxfq << endl;

    return 0;
}