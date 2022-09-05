#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{
    // string s,t;                                //time complexity =O(st);
    // cin>>t>>s;
    // int S=s.size(),T=t.size();
    // for (int i = 0; i < T-S+1; i++)
    // {
    //     if (t.substr(i,S) ==  s)
    //     {
    //         cout<<" Found substr at Index "<<i<<"\n";
    //     }

    // }

    string s, t;
    cin >> t >> s;
    vector<int> prefix(t.size(), 0);
    int pos = -1;
    int i(0), j(0);

    while (i < t.size())
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = prefix[j - 1];
            }
            else
            {
                i++;
            }
            if (j == s.size())
            {
                pos = i - s.size();
                break;
            }
        }
    }
    cout << pos;

    return 0;
}