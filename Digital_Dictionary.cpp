#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)
class node
{
public:
    node *next[26];
    bool end;
    node()
    {
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        end = false;
    }
};
class Trie
{
private:
    node *root;

public:
    Trie()
    {
        node *root = new node();
    }
    void insert(string s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
            {
                it->next[c - 'a'] = new node();
            }
            it = it->next[c - 'a'];
        }
        it->end = true;
    }
    void find(string s)
    {
        node *it = root;
        for (auto c : s)
        {
            if (!it->next[c - 'a'])
            {
                cout << "No suggestions " << endl;
                insert(s);
                return;
            }
            it = it->next[c - 'a'];
        }
        vector<string> res;
        printall(it, s, res, "");
        for (auto c : res)
        {
            cout << s << c << endl;
        }
    }
    void printall(node *it, string &s, vector<string> &res, string cur)
    {
        if (it == NULL)
        {
            return;
        }
        if (it->end)
        {
            res.push_back(cur);
        }
        for (int i = 0; i < 26; i++)
        {
            if (it->next[i])
            {
                printall(it->next[i], s, res, cur + char(i + 'a'));
            }
        }
    }
};
int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> lib(n);
    for (auto &s : lib)
    {
        cin >> s;
    }
    int q;
    cin >> q;
    while (--q)
    {
        string s;
        cin >> s;
        t.find(s);
    }

    return 0;
}