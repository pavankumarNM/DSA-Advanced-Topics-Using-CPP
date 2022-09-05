#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> ans;
void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], idx);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &j : a)
    {
        cin >> j;
    }
    permute(a, 0); // by recursion
    // sort(a.begin(),a.end());             //by inbuilt functions
    // do
    // {
    //     ans.push_back(a);
    // } while (next_permutation(a.begin(),a.end()));

    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}