#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    sort(v.begin(), v.end());
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int curr = v[i] + v[low] + v[high];
            if (target == curr)
            {
                ans = true;
            }
            if (curr < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    if (ans)
    {
        cout << "target triplet found" << endl;
    }
    else
    {
        cout << " Triplet Not Found" << endl;
    }

    return 0;
}