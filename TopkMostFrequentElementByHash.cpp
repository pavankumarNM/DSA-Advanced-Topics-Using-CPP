#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int presize = freq.size();
        if (freq[arr[i]] == 0 && presize == k)
        {
            break;
        }
        freq[arr[i]]++;
    }
    vector<int, int> ans;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        if (it->second != 0)
        {
            pii p;
            p->first = it->second;
            p->second = it->first;
            ans.push_back(p->first, p->second);
        }
    }
    sort(ans.begin(), ans.end(), greater<pii>);
    vector<int, int>::iterator it1;
    for (it1 = ans.begin(); it1 != ans.end(); it1++)
    {
        cout << it1->second << " : " << it1->first << endl;
    }

    return 0;
}
