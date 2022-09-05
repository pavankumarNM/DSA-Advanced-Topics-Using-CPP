#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
class Trie
{
public:
    Trie *next[2];
    Trie()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

Trie *Build(vi &a)
{
    Trie *root = new Trie();
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        Trie *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (cur->next[bit] == NULL)
            {
                cur->next[bit] = new Trie();
            }
            cur = cur->next[bit];
        }
    }
    return root;
}

int helper(Trie *root, vi &a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int num = a[i];
        Trie *it = root;
        int cur_max = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1) ? 0 : 1;
            if (it->next[bit])
            {
                cur_max <<= 1;
                cur_max |= 1;
                it = it->next[bit];
            }
            else
            {
                cur_max <<= 1;
                cur_max |= 0;
                it = it->next[bit];
            }
        }
        res = max(res, cur_max);
    }

    return res;
}

int main()
{

    vi a = {3, 10, 5, 15, 2};
    Trie *root = Build(a);

    int ans = helper(root, a);
    cout << ans;
    return 0;
}