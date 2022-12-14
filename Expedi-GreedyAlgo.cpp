#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        int l, p;
        cin >> l >> p;
        for (int i = 0; i < n; i++)
        {
            a[i].first = l - a[i].first;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int curr = p;
        bool flag = 0;
        priority_queue<int, vector<int>> maxHeap;
        for (int i = 0; i < n; i++)
        {

            if (curr >= l)
            {
                break;
            }
            while (curr < a[i].first)
            {
                if (maxHeap.empty())
                {
                    flag = 1;
                }

                curr += maxHeap.top();
                maxHeap.pop();
                ans++;
            }
            if (flag)
            {
                break;
            }
            maxHeap.push(a[i].second);
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }
        if (curr < l && !maxHeap.empty())
        {
            curr += maxHeap.top();
            maxHeap.pop();
            ans++;
        }
        if (curr < l)
        {
            cout << "-1" << endl;
            continue;
        }

        cout << ans << endl;
    }

    return 0;
}